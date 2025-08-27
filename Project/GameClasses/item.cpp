#include <fstream>
#include <string>
#include <iostream>
#include "item.h"
#include "gameplay.h"
#include "object.h"

Item::Item() : Object(), _price(-1) {}

Item::Item(int id) : Object(-1, -1, id) {
	_price = -1;
	std::ifstream file("C:\\Users\\Lelya\\cc++\\SummerHWork\\Project\\GameClasses\\price_id.txt");
	if (!file.is_open()) {
		throw std::logic_error("The file is not open");
	}

	std::string line;
	while (std::getline(file, line)) {
		size_t delim_pos = line.find(' ');
		if (delim_pos == std::string::npos) {
			throw std::logic_error("There is not space");
		}

		std::string file_id = line.substr(0, delim_pos);
		std::string file_price = line.substr(delim_pos + 1);

		if (id == std::stoi(file_id)) {
			_price = std::stoi(file_price);
		}
	}
	file.close();
}

Item::Item(int x, int y, int id) : Object(x, y, id) {
	_price = 0;
	std::ifstream file("C:\\Users\\Lelya\\cc++\\SummerHWork\\Project\\Item\\price_id.txt");
	if (!file.is_open()) {
		throw std::logic_error("The file is not open");
	}

	std::string line;
	while (std::getline(file, line)) {
		size_t delim_pos = line.find(' ');
		if (delim_pos == std::string::npos) {
			throw std::logic_error("There is not space");
		}

		std::string id = line.substr(0, delim_pos);
		std::string price = line.substr(delim_pos + 1);

		for (size_t i = 0; i < price.length(); i++) {
			_price += price[i] * pow(10, price.length() - i);
		}
	}
	file.close();
}

int Item::get_price() {
	return _price;
}
