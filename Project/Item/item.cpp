#include "item.h"

Item::Item() : Object(), _price(0) {}

Item::Item(int id) : Object(-1, -1, id) {
	this->_price = id * 10; //
}

Item::Item(int x, int y, int id) : Object(x, y, id) {
	this->_price = id * 10; //подт€гивать из какого-нибудь файлика цену по айди
}