#include "header.h"

int main() {
	setlocale(LC_ALL, "Russian");
	TrieNode* root = getNewTrieNode();

	addWord(root, "apt");
	addWord(root, "install");
	addWord(root, "htop");
	addWord(root, "mkfs");
	addWord(root, "shutdown");
	addWord(root, "halt");
	addWord(root, "mount");
	addWord(root, "umount");
	addWord(root, "find");
	addWord(root, "sudo");
	addWord(root, "neofetch");
	addWord(root, "vim");

	std::vector<std::string> words;
	std::cout << "Слова которые есть в словаре:\n";
	getAllWords(root, "", words);
	for (const auto& word : words) {
		std::cout << "\t" << word << " " << "\n";
	}

	std::string word;
	std::cout << "Введите слово для добавления в словарь\n (введите пустую строку для завершения ввода):\n";
	do {
		getline(std::cin, word);
		if (word.size() > 0) {
			addWord(root, word);
		}
	} while (word.size() > 0);

	std::cout << "\nВведите слова для удаления из словаря\n (введите пустую строку для завершения ввода):\n";
	do {
		getline(std::cin, word);
		if (word.size() > 0) {
			removeWord(root, word);
		}
	} while (word.size() > 0);

	std::cout << "\nНаличие слов в словаре:\n";
	std::cout << "Введите слово для поиска в словаре\n (введите пустую строку для завершения ввода):\n";
	do {
		getline(std::cin, word);
		if (word.size() > 0) {
			std::cout << word << ": " << (search(root, word) ? "такое слово есть" : "такого слова нет");
		}
	} while (word.size() > 0);
	
	std::string prefix;
	while (prefix != "q") {
		std::cout << "Введите префикс слова (или введите 'q' для выхода): ";
		std::cin >> prefix;

		if (prefix != "q") {
			std::vector<std::string> words = getAllWordsByPrefix(root, prefix);
			for (const std::string& word : words) {
				std::cout << word << " ";
			}
			std::cout << std::endl;
		}
	}


	return 0;
}