#include <cstddef>

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

struct TrieNode {
  TrieNode *childNode[26];
  int wordCount;

  TrieNode() {
    wordCount = 0;
    for (int i = 0; i < 26; i++) {
      childNode[i] = NULL;
    }
  }
};

void insert_key(TrieNode *root, string &key) {
  TrieNode *currentNode = root;

  for (auto c : key) {
    if (currentNode->childNode[c - 'a'] == NULL) {
      // means current character of the string does not exist
      TrieNode *newNode = new TrieNode();
      // Keep the reference for the newly created node.
      currentNode->childNode[c - 'a'] = newNode;
    }
    // Now, move the current node pointer to the newly created node.
    currentNode = currentNode->childNode[c - 'a'];
  }
  currentNode->wordCount++;
}

bool search_key(TrieNode *root, string &key) {
  TrieNode *currentNode = root;
  for (auto c : key) {
    if (currentNode->childNode[c - 'a'] == NULL) {
      return false;
    }
    currentNode = currentNode->childNode[c - 'a'];
  }
  return (currentNode->wordCount > 0);
}

bool delete_key(TrieNode *root, string &key) {
  TrieNode *currentNode = root;
  TrieNode *lastBranchNode = NULL;
  char lastBranchChar = 'a';
  for (auto c : key) {
    if (currentNode->childNode[c - 'a'] == NULL) {
      return false;
    } else {
      int count = 0;
      for (int i = 0; i < 26; i++) {
        if (currentNode->childNode[i] != NULL) {
          count++;
        }
      }
      if (count > 1) {
        lastBranchNode = currentNode;
        lastBranchChar = c;
      }
      currentNode = currentNode->childNode[c - 'a'];
    }
  }

  int count = 0;
  for (int i = 0; i < 26; i++) {
    if (currentNode->childNode[i] != NULL)
      count++;
  }
  // Case 1: The deleted word is a prefix of other words
  // in Trie.
  if (count > 0) {
    currentNode->wordCount--;
    return true;
  }

  // Case 2: The deleted word shares a common prefix with
  // other words in Trie.
  if (lastBranchNode != NULL) {
    lastBranchNode->childNode[lastBranchChar] = NULL;
    return true;
  }
  // Case 3: The deleted word does not share any common
  // prefix with other words in Trie.
  else {
    root->childNode[key[0]] = NULL;
    return true;
  }
}

int main() {
  // Make a root node for the Trie
  TrieNode *root = new TrieNode();

  // Stores the strings that we want to insert in the
  // Trie
  vector<string> inputStrings = {"and", "ant", "do", "geek", "dad", "ball"};

  // number of insert operations in the Trie
  int n = inputStrings.size();

  for (int i = 0; i < n; i++) {
    insert_key(root, inputStrings[i]);
  }

  // Stores the strings that we want to search in the Trie
  vector<string> searchQueryStrings = {"do", "geek", "bat"};

  // number of search operations in the Trie
  int searchQueries = searchQueryStrings.size();

  for (int i = 0; i < searchQueries; i++) {
    cout << "Query String: " << searchQueryStrings[i] << "\n";
    if (search_key(root, searchQueryStrings[i])) {
      // the queryString is present in the Trie
      cout << "The query string is present in the "
              "Trie\n";
    } else {
      // the queryString is not present in the Trie
      cout << "The query string is not present in "
              "the Trie\n";
    }
  }

  // stores the strings that we want to delete from the
  // Trie
  vector<string> deleteQueryStrings = {"geek", "tea"};

  // number of delete operations from the Trie
  int deleteQueries = deleteQueryStrings.size();

  for (int i = 0; i < deleteQueries; i++) {
    cout << "Query String: " << deleteQueryStrings[i] << "\n";
    if (delete_key(root, deleteQueryStrings[i])) {
      // The queryString is successfully deleted from
      // the Trie
      cout << "The query string is successfully "
              "deleted\n";
    } else {
      // The query string is not present in the Trie
      cout << "The query string is not present in "
              "the Trie\n";
    }
  }

  return 0;
}
