
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

// Function to count word occurrences from a file
unordered_map<string, int> countWords(const string& filePath) {
    unordered_map<string, int> wordCount;
    ifstream file(filePath);
    string word;

    while (file >> word) {
        wordCount[word]++;
    }

    return wordCount;
}

// Function to read unique words from a file
vector<string> readUniqueWords(const string& filePath) {
    vector<string> uniqueWords;
    ifstream file(filePath);
    string word;

    while (file >> word) {
        uniqueWords.push_back(word);
    }

    return uniqueWords;
}

int dotProduct(vector<int>&A,vector<int>&B){
  int product = 0;
  for(int i = 0;i<A.size();i++){
    product +=(A[i]*B[i]);
  }
  return product;
}

int mode(vector<int>&A){
  int sum =0;
  for(int i =0;i<A.size();i++){
    sum+=(A[i]*A[i]);
  }
  return sqrt(sum);
}
int main() {
    // File paths
    string fileAPath = "cosinedemo1.txt";
    string fileBPath = "cosinedemo2.txt";
    string uniqueWordsPath = "uniquewords.txt";

    // Step 1: Read word counts from File A and File B
    unordered_map<string, int> wordCountA = countWords(fileAPath);
    unordered_map<string, int> wordCountB = countWords(fileBPath);

    // Step 2: Read unique words from the unique words file
    vector<string> uniqueWords = readUniqueWords(uniqueWordsPath);

    // Step 3: Create vectors for the word counts from File A and File B
    vector<int> vectorA;
    vector<int> vectorB;

    // Step 4: For each unique word, store its count in both vectors
    for (const string& word : uniqueWords) {
        // For File A, check if the word exists, otherwise count as 0
        vectorA.push_back(wordCountA.count(word) ? wordCountA[word] : 0);
        
        // For File B, check if the word exists, otherwise count as 0
        vectorB.push_back(wordCountB.count(word) ? wordCountB[word] : 0);
    }

    // Step 5: Display the vectors for debugging
    cout << "Vector A: ";
    for (int count : vectorA) {
        cout << count << " ";
    }
    cout << endl;

    cout << "Vector B: ";
    for (int count : vectorB) {
        cout << count << " ";
    }
    cout << endl;

   int dp = dotProduct(vectorA,vectorB);
   int modA = mode(vectorA);
   int modB = mode(vectorB);
   int result = dp/(modA*modB);
   cout<<result;
    return 0;
}