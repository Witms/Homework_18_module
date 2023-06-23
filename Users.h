#pragma once
#include <string>
#include <iostream>
#include <fstream>

class User {
	std::string _name;
	std::string _login;
	std::string _pass;

public:
	User() {};
	User(std::string name, std::string login, std::string pass) :
		_name(name), _login(login), _pass(pass) {}

	void changeData() {
		std::cin >> this->_name;
		std::cin >> this->_login;
		std::cin >> this->_pass;
		return;
	}
	
	friend std::fstream& operator >>(std::fstream file, User& obj) {
		file >> obj._name;
		file >> obj._login;
		file >> obj._pass;
		return file;
	}
	friend std::ostream& operator <<(std::ostream& file, User& obj) {
		file << obj._name << ' ';
		file << obj._login << ' ';
		file << obj._pass << ' ';
		return file;
	}
};
