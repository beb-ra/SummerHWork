#pragma once
#include "object.h"

class Item : public Object {
    int _price;

public:
    Item();
    Item(int id);
    Item(int x, int y, int id);

    int get_price();

protected:
    virtual void use(Character* character) {} // мб виртуальный сделать, хз
};

class Products : public Item {
    int _adding_energy;

protected:
    void use(Character* character) override {
        character->eat(_adding_energy);
        delete this;
    }
};

class Fish : public Products {
    int fishing_difficulty;  // тоже по id подт€гивать
};

class Seeds : public Item {
    void use(Character* character) override {
        character->plant(this);
    }
};

