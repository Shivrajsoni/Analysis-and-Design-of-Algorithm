#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

class TextSimilarity {
private:
    // Lowercase conversion function
    static string toLower(const string& str) {
        string result = str;
        for (size_t i = 0; i < result.length(); ++i) {
            result[i] = tolower(result[i]);
        }
        return result;
    }

    // Read file content
    static string readFile(const string& filename) {
        ifstream file(filename.c_str());
        if (!file.is_open()) {
            cerr << "Error opening file: " << filename <<endl;
            return "";
        }
        
        stringstream buffer;
        buffer << file.rdbuf();
        return buffer.str();
    }

    // Tokenize text into words
    static vector<string> tokenize(const string& text) {
        vector<string> tokens;
        istringstream iss(text);
        string word;

        while (iss >> word) {
            // Remove non-alphanumeric characters
            word.erase(
                remove_if(word.begin(), word.end(), 
                    static_cast<int(*)(int)>(ispunct)
                ), 
                word.end()
            );

            if (!word.empty()) {
                tokens.push_back(toLower(word));
            }
        }
        return tokens;
    }

    // Create word frequency map
    static map<string, int> createFrequencyMap(const vector<string>& tokens) {
        map<string, int> frequencyMap;
        for (size_t i = 0; i < tokens.size(); ++i) {
            frequencyMap[tokens[i]]++;
        }
        return frequencyMap;
    }

public:
    // Compute cosine similarity
    static double computeSimilarity(const string& file1, const string& file2) {
        // Read files
        string content1 = readFile(file1);
        string content2 = readFile(file2);

        // Tokenize
        vector<string> tokens1 = tokenize(content1);
        vector<string> tokens2 = tokenize(content2);

        // Create frequency maps
        map<string, int> freq1 = createFrequencyMap(tokens1);
        map<string, int> freq2 = createFrequencyMap(tokens2);

        // Create unified vocabulary
        map<string, int> combinedFreq;
        for (map<string, int>::iterator it = freq1.begin(); it != freq1.end(); ++it) {
            combinedFreq[it->first] += it->second;
        }
        for (map<std::string, int>::iterator it = freq2.begin(); it != freq2.end(); ++it) {
            combinedFreq[it->first] += it->second;
        }

        // Create vectors
        vector<double> vec1, vec2;
        for (map<string, int>::iterator it = combinedFreq.begin(); it != combinedFreq.end(); ++it) {
            map<string, int>::iterator find1 = freq1.find(it->first);
            map<string, int>::iterator find2 = freq2.find(it->first);
            
            vec1.push_back(find1 != freq1.end() ? find1->second : 0);
            vec2.push_back(find2 != freq2.end() ? find2->second : 0);
        }

        // Compute dot product
        double dotProduct = 0.0;
        double mag1 = 0.0, mag2 = 0.0;
        for (size_t i = 0; i < vec1.size(); ++i) {
            dotProduct += vec1[i] * vec2[i];
            mag1 += vec1[i] * vec1[i];
            mag2 += vec2[i] * vec2[i];
        }

        // Prevent division by zero
        if (mag1 == 0 || mag2 == 0) return 0.0;

        return dotProduct / (sqrt(mag1) * sqrt(mag2));
    }
};

int main() {
    try {
        // File paths
        string file1 = "document1.txt";
        string file2 = "document2.txt";

        // Compute similarity
        double similarity = TextSimilarity::computeSimilarity(file1, file2);

        // Output results
        cout.precision(4);
        cout << "Cosine Similarity: " << similarity <<endl;

        // Interpret similarity
        if (similarity > 0.8) 
            cout << "Very high similarity" <<endl;
        else if (similarity > 0.6) 
            cout << "High similarity" << endl;
        else if (similarity > 0.4) 
            cout << "Moderate similarity" <<endl;
        else if (similarity > 0.2) 
            cout << "Low similarity" << endl;
        else 
            cout << "Very low similarity" << endl;
    }
    catch (const std::exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
