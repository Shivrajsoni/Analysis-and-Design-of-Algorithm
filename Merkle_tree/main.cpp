#include <algorithm>
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <memory>
#include <openssl/sha.h>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct MerkleNode {
  string hash;
  shared_ptr<MerkleNode> left;
  shared_ptr<MerkleNode> right;
  string data;
  bool isLeaf;

  // Constructor for leaf nodes (contains actual data)
  MerkleNode(const string &data)
      : data(data), isLeaf(true), left(nullptr), right(nullptr) {
    hash = sha256(data);
  }

  // Constructor for internal nodes (computed from children)
  MerkleNode(shared_ptr<MerkleNode> left, shared_ptr<MerkleNode> right)
      : left(left), right(right), isLeaf(false) {
    string combined = left->hash + right->hash;
    hash = sha256(combined);
  };

private:
  // SHA-256 hash function

  string sha256(const string &input) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, input.c_str(), input.size());
    SHA256_Final(hash, &sha256);

    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
      ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
  };
};

class MerkleTree {
private:
  shared_ptr<MerkleNode> root;
  vector<string> leaves;
  int treeHeight;

public:
  MerkleTree(vector<string> &data) {
    if (data.empty()) {
      throw std::invalid_argument("Cannot create Merkle tree with empty data");
    }

    leaves = data;
    root = buildTree(data);
    treeHeight = calculateHeight(root);
  }

  // Get the Merkle root hash
  string getMerkleRoot() const { return root ? root->hash : ""; }

  // Get tree height
  int getHeight() const { return treeHeight; }

  vector<string> generateProof(const string &data) {
    vector<string> proof;
    string targetHash = sha256(data);
    generateProofHelper(root, targetHash, proof);
    return proof;
  }

  // Verify if data belongs to the tree using Merkle proof
  bool verifyProof(const string &data, const vector<string> &proof) {
    string currenthash = sha256(data);
    for (const string &siblingHash : proof) {
      string option1 = sha256(currenthash + siblingHash);
      string option2 = sha256(siblingHash + currenthash);
      // In a real implementation, you'd need to store path directions
      // For simplicity, we'll check both possibilities

      currenthash == option1; // this is simplified
    }
    return currenthash == getMerkleRoot();
  };
  // Print the tree structure (for visualization)
  void printTree() const {
    std::cout << "Merkle Tree Structure:\n";
    std::cout << "Root: " << getMerkleRoot().substr(0, 16) << "...\n";
    printTreeHelper(root, 0);
  }

  vector<string> getLeaves() const { return leaves; }

  bool update_leaf(const string &oldData, const string &newData) {
    // Find the old data in leaves
    auto it = std::find(leaves.begin(), leaves.end(), oldData);
    if (it == leaves.end()) {
      return false; // Data not found
    }
    *it = newData;
    root = buildTree(leaves);

    return true;
  }

private:
  shared_ptr<MerkleNode> buildTree(const vector<string> &data) {
    // create leaf nodes
    vector<shared_ptr<MerkleNode>> nodes;
    for (const string &item : data) {
      nodes.push_back(make_shared<MerkleNode>(item));
    }
    while (nodes.size() > 1) {
      vector<shared_ptr<MerkleNode>> nextLevel;

      // Pair up nodes and create parent nodes
      for (size_t i = 0; i < nodes.size(); i += 2) {
        if (i + 1 < nodes.size()) {
          // Pair exists
          auto parent = make_shared<MerkleNode>(nodes[i], nodes[i + 1]);
          nextLevel.push_back(parent);
        } else {
          // Odd number of nodes - duplicate the last node
          auto parent = make_shared<MerkleNode>(nodes[i], nodes[i]);
          nextLevel.push_back(parent);
        }
      }

      nodes = nextLevel;
    }

    return nodes[0]; // Root node
  }
  // Calculate tree height
  int calculateHeight(shared_ptr<MerkleNode> node) {
    if (!node)
      return 0;
    if (node->isLeaf)
      return 1;

    int leftHeight = calculateHeight(node->left);
    int rightHeight = calculateHeight(node->right);
    return 1 + std::max(leftHeight, rightHeight);
  }
  // Helper function to generate Merkle proof
  bool generateProofHelper(std::shared_ptr<MerkleNode> node,
                           const std::string &targetHash,
                           std::vector<std::string> &proof) {
    if (!node)
      return false;

    if (node->isLeaf) {
      return node->hash == targetHash;
    }

    // Check if target is in left subtree
    if (generateProofHelper(node->left, targetHash, proof)) {
      // Add right sibling to proof
      proof.push_back(node->right->hash);
      return true;
    }

    // Check if target is in right subtree
    if (generateProofHelper(node->right, targetHash, proof)) {
      // Add left sibling to proof
      proof.push_back(node->left->hash);
      return true;
    }

    return false;
  }
  void printTreeHelper(shared_ptr<MerkleNode> node, int depth) const {
    if (!node)
      return;

    string indent(depth * 2, ' ');
    cout << indent << "├─ " << node->hash.substr(0, 16) << "...";

    if (node->isLeaf) {
      cout << " (Leaf: " << node->data << ")";
    }
    cout << "\n";

    if (!node->isLeaf) {
      printTreeHelper(node->left, depth + 1);
      printTreeHelper(node->right, depth + 1);
    }
  }
  // SHA-256 hash function (same as in MerkleNode)
  string sha256(const std::string &input) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, input.c_str(), input.size());
    SHA256_Final(hash, &sha256);

    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
      ss << hex << ::setw(2) << setfill('0') << (int)hash[i];
    }
    return ss.str();
  };
};

// Blockchain Transaction class for demonstration
class Transaction {
public:
  string from;
  string to;
  double amount;
  long timestamp;

  Transaction(const string &from, const string &to, double amount)
      : from(from), to(to), amount(amount) {
    timestamp = time(nullptr);
  }

  // Convert transaction to string for hashing
  string toString() const {
    stringstream ss;
    ss << from << ":" << to << ":" << amount << ":" << timestamp;
    return ss.str();
  }
};

// Demo function to show Merkle tree usage in blockchain context
void demonstrateBlockchainUsage() {
  cout << "\n=== BLOCKCHAIN MERKLE TREE DEMONSTRATION ===\n\n";

  // Create sample transactions
  vector<Transaction> transactions = {
      Transaction("Alice", "Bob", 10.5), Transaction("Bob", "Charlie", 5.2),
      Transaction("Charlie", "David", 8.7), Transaction("David", "Alice", 3.1),
      Transaction("Alice", "Charlie", 15.0)};

  // Convert transactions to strings
  vector<string> txStrings;
  for (const auto &tx : transactions) {
    txStrings.push_back(tx.toString());
  }

  cout << "1. Creating Merkle Tree from " << transactions.size()
       << " transactions:\n";
  for (size_t i = 0; i < transactions.size(); ++i) {
    cout << "   TX" << i + 1 << ": " << transactions[i].from << " -> "
         << transactions[i].to << " (" << transactions[i].amount << ")\n";
  }

  // Create Merkle tree
  MerkleTree merkleTree(txStrings);

  cout << "\n2. Merkle Root: " << merkleTree.getMerkleRoot() << "\n";
  cout << "   Tree Height: " << merkleTree.getHeight() << "\n\n";

  // Print tree structure
  cout << "3. Tree Structure:\n";
  merkleTree.printTree();

  // Demonstrate proof generation and verification
  cout << "\n4. Merkle Proof Demonstration:\n";
  string testTx = transactions[1].toString(); // Bob -> Charlie transaction

  cout << "   Generating proof for: " << transactions[1].from << " -> "
       << transactions[1].to << "\n";

  auto proof = merkleTree.generateProof(testTx);
  cout << "   Proof length: " << proof.size() << " hashes\n";

  for (size_t i = 0; i < proof.size(); ++i) {
    std::cout << "   Proof[" << i << "]: " << proof[i].substr(0, 16) << "...\n";
  }

  // Verify the proof
  bool isValid = merkleTree.verifyProof(testTx, proof);
  cout << "   Proof verification: " << (isValid ? "VALID" : "INVALID") << "\n";

  // Demonstrate tampering detection
  cout << "\n5. Tampering Detection:\n";
  string tamperedTx =
      Transaction("Bob", "Charlie", 100.0).toString(); // Modified amount
  bool tamperedValid = merkleTree.verifyProof(tamperedTx, proof);
  cout << "   Tampered transaction verification: "
       << (tamperedValid ? "VALID" : "INVALID") << "\n";
  cout << "   (This should be INVALID, proving tamper detection works)\n";
}

// Main function with examples
int main() {
  try {
    // Basic Merkle Tree example
    cout << "=== BASIC MERKLE TREE EXAMPLE ===\n\n";

    vector<string> data = {"tx1", "tx2", "tx3", "tx4", "tx5"};
    MerkleTree tree(data);

    cout << "Original data: ";
    for (const string &item : data) {
      cout << item << " ";
    }
    cout << "\n\nMerkle Root: " << tree.getMerkleRoot() << "\n";
    cout << "Tree Height: " << tree.getHeight() << "\n\n";

    tree.printTree();

    // Blockchain demonstration
    demonstrateBlockchainUsage();

  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}
