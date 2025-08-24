#pragma once
#include "/Users/Lelya/cc++/SummerHWork/Project/Object/object.h"

class Item : public Object {
    int _price;

public:
    Item();
    Item(int id);
    Item(int x, int y, int id);
    virtual void use(Character& owner) = 0; // Чисто виртуальный метод

    int get_price();
};
