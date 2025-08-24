#pragma once
#include "object.h"

class Item : public Object {
    int _price;

public:
    Item();
    Item(int id);
    Item(int x, int y, int id);

    int get_price();
    void use(Character* character) override = 0;
};
