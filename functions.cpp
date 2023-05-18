#include "header.h"

// ������� �������� ������ ���� Trie
TrieNode* getNewTrieNode()
{
	TrieNode* pNode = new TrieNode;

	pNode->isEndOfWord = false;
	for (int i = 0; i < ALPHABET_SIZE; i++)
		pNode->children[i] = nullptr;

	return pNode;
}

// ������� ��������� ���� ���� � Trie
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

// ������� ���������� ����� � Trie
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

// ������� �������� ����� �� Trie
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

	// ���� ������� ���� �� ������� ��� ����� ����� � �� ����� �������� �����, �� ������� ���
	if (isTrieEmpty(root) && root->isEndOfWord == false)
	{
		delete root;
		root = nullptr;
	}

	return root;
}

// ������� ��������, ���� �� Trie
bool isTrieEmpty(TrieNode* root)
{
	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		if (root->children[i])
			return false;
	}
	return true;
}

// ������� �������� ������� ����� � Trie
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