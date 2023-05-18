#pragma once
#include <iostream>
#include <string>
#include <vector>

const int ALPHABET_SIZE = 26; // Константа, определяющая размер алфавита (английский)

struct TrieNode
{
	TrieNode* children[ALPHABET_SIZE]; 
	bool isEndOfWord; 
};

TrieNode* getNewTrieNode();
void getAllWords(TrieNode* node, std::string prefix, std::vector<std::string>& words);
void addWord(TrieNode* root, const std::string& key);
TrieNode* removeWord(TrieNode* root, const std::string& key, int depth = 0);
bool isTrieEmpty(TrieNode* root);
bool search(TrieNode* root, const std::string& key);

