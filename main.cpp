#include <fstream>
#include <iostream>
#include <filesystem>
#include "Users.h"
#include "Messages.h"

namespace fs = std::filesystem;

#define U "Users.txt"
#define M "Messages.txt"

inline void addPermRead(const char* pathname);
inline void addPermWrite(const char* pathname);
void remAPerm(const char* pathname);

template<typename T>
void inputFile(const char* pathname, T& obj) {
	if (!fs::exists(pathname)) return;

	addPermRead(pathname);
	std::fstream file(pathname, std::ios::in);

	if (!file.is_open()) {
		std::cout << "File was not found for in!" << std::endl;
		return;
	}
	file >> obj;
	file.close();

	remAPerm(pathname);
}

template<typename T>
void outputFile(const char* pathname, T& obj) {
	
	addPermWrite(pathname);
	std::fstream file(pathname, std::ios::out);

	if (!file.is_open()) {
		std::cout << "File was not found for out!" << std::endl;
		return;
	}
	obj.changeData();
	file << obj;
	file.close();

	remAPerm(pathname);
}

void remAPerm(const char* pathname) {
	fs::permissions(
		pathname,
		fs::perms::owner_all |
		fs::perms::group_all |
		fs::perms::others_all, fs::perm_options::remove);
}

inline void addPermRead(const char* pathname) {
	fs::permissions(pathname, fs::perms::owner_read, fs::perm_options::add);
}

inline void addPermWrite(const char* pathname) {
	fs::permissions(pathname, fs::perms::owner_write, fs::perm_options::add);
}


int main() {
	if (!fs::exists(U)) {
		std::ofstream file(U);
		file.close();
	}
	if (!fs::exists(M)) {
		std::ofstream file(M);
		file.close();
	}

	remAPerm(U);
	remAPerm(M);

	User u;
	Message m;

	inputFile(U, u);
	inputFile(M, m);

	std::cout << "Content of Users.txt: " << u << std::endl;
	std::cout << "Content of Messages.txt: " << m << std::endl;

	outputFile(U, u);
	outputFile(M, m);

	return 0;
}