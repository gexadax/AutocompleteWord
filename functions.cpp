#include "header.h"

// Функция создания нового узла Trie
TrieNode* getNewTrieNode()
{
	TrieNode* pNode = new TrieNode;

	pNode->isEndOfWord = false;
	for (int i = 0; i < ALPHABET_SIZE; i++)
		pNode->children[i] = nullptr;

	return pNode;
}

// Функция получения всех слов в Trie
void getAllWords(TrieNode* node, std::string prefix, std::vector<std::string>& words)
{
	if (node == nullptr) {
		return;
	}

	if (node->isEndOfWord) {
		words.push_back(prefix);
	}

	for (char c = 'a'; c <= 'z'; c++) {
		int index = c - 'a';
		getAllWords(node->children[index], prefix + c, words);
	}
}

// Функция добавления слова в Trie
void addWord(TrieNode* root, const std::string& key)
{
	TrieNode* node = root;
	for (char c : key)
	{
		int index = c - 'a';
		if (!node->children[index])
			node->children[index] = getNewTrieNode();
		node = node->children[index];
	}

	node->isEndOfWord = true;
}

// Функция удаления слова из Trie
TrieNode* removeWord(TrieNode* root, const std::string& key, int depth)
{
	if (!root)
		return nullptr;

	if (depth == key.size())
	{
		if (root->isEndOfWord)
			root->isEndOfWord = false;

		if (isTrieEmpty(root))
		{
			delete root;
			root = nullptr;
		}

		return root;
	}

	int index = key[depth] - 'a';
	root->children[index] = removeWord(root->children[index], key, depth + 1);

	// Если текущий узел не помечен как конец слова и не имеет дочерних узлов, то удаляем его
	if (isTrieEmpty(root) && root->isEndOfWord == false)
	{
		delete root;
		root = nullptr;
	}

	return root;
}

// Функция проверки, пуст ли Trie
bool isTrieEmpty(TrieNode* root)
{
	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		if (root->children[i])
			return false;
	}
	return true;
}

// Функция проверки наличия слова в Trie
bool search(TrieNode* root, const std::string& key)
{
	TrieNode* node = root;
	for (char c : key)
	{
		int index = c - 'a';
		if (!node->children[index])
			return false;
		node = node->children[index];
	}

	return (node != nullptr && node->isEndOfWord);
}