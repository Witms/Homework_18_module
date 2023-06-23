#pragma once
#include <string>
#include <iostream>
#include <fstream>

class Message {
	std::string _text;
	std::string _sender;
	std::string _receiver;

public:
	Message() {};
	Message(std::string text, std::string sender, std::string receiver) :
		_text(text), _sender(sender), _receiver(receiver) {}

	void changeData() {
		std::cin >> this->_text;
		std::cin >> this->_sender;
		std::cin >> this->_receiver;
		return;
	}

	friend std::fstream& operator >>(std::fstream file, Message& obj) {
		file >> obj._text;
		file >> obj._sender;
		file >> obj._receiver;
		return file;
	}
	friend std::ostream& operator <<(std::ostream& file, Message& obj) {
		file << obj._text << ' ';
		file << obj._sender << ' ';
		file << obj._receiver << ' ';
		return file;
	}
};