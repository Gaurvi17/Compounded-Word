// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <chrono>
// #include <algorithm>
// #include <unordered_map>
#include<bits/stdc++.h>
struct TrieNode {
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
    TrieNode() : isEndOfWord(false) {}
};
class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    void insert(const std::string& word) {
        TrieNode* current = root;
        for (char c : word) {
            if (current->children.find(c) == current->children.end()) {
                current->children[c] = new TrieNode();
            }
            current = current->children[c];
        }
        current->isEndOfWord = true;
    }
    bool search(const std::string& word) {
        TrieNode* current = root;
        for (char c : word) {
            if (current->children.find(c) == current->children.end()) {
                return false;
            }
            current = current->children[c];
        }
        return current->isEndOfWord;
    }
    bool isCompounded(const std::string& word) {
        if (word.empty()) {
            return false;
        }
        TrieNode* current = root;
        for (size_t i = 1; i < word.length(); ++i) {
            std::string prefix = word.substr(0, i);
            std::string suffix = word.substr(i);
            if (search(prefix) && (search(suffix) || isCompounded(suffix))) {
                return true;
            }
        }
        return false;
    }
private:
    TrieNode* root;
};
int main() {
    auto startTime = std::chrono::high_resolution_clock::now();
    std::vector<std::string> words;
    std::ifstream inputFile("Input_01.txt");
    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            words.push_back(line);
        }
        inputFile.close();
    } else {
        std::cerr << "Error opening input file." << std::endl;
        return 1;
    }
    Trie trie;
    for (const std::string& word : words) {
        trie.insert(word);
    }
    std::string longestCompound = "";
    std::string secondLongestCompound = "";
    for (const std::string& word : words) {
        if (trie.isCompounded(word)) {
            if (word.length() > longestCompound.length()) {
                secondLongestCompound = longestCompound;
                longestCompound = word;
            } else if (word.length() > secondLongestCompound.length()) {
                secondLongestCompound = word;
            }
        }
    }
    auto endTime = std::chrono::high_resolution_clock::now();
    auto processingTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
    std::cout << "Longest Compound Word: " << longestCompound << std::endl;
    std::cout << "Second Longest Compound Word: " << secondLongestCompound << std::endl;
    std::cout << "Time taken to process file Input_02.txt: " << processingTime.count() << " milliseconds" << std::endl;
    return 0;
}
