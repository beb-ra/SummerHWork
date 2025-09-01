#pragma once
#include "object.h"
#include "igameplay_actions.h"

class Character;

#ifndef ITEM_H
#define ITEM_H

class Item : public Object {
    int _price;

public:
    virtual ~Item() = default;
    Item();
    Item(int id);
    Item(int x, int y, int id);

    int get_price();

    virtual void use(IGameplayActions* gameplay) {} // мб виртуальным сделать, хз
};

class Products : public Item {
    int _adding_energy;

public:
    virtual ~Products() = default;
    void use(IGameplayActions* gameplay) override {
        gameplay->eat(_adding_energy);
        delete this; // мб лучше в gameplay удал€ть
    }
};

class Fish : public Products {
    int fishing_difficulty;  // тоже по id подт€гивать
};

class Seeds : public Item {
public:
    void use(IGameplayActions* gameplay) override {
        gameplay->plant(this);
    }
};

class FishingRod : public Item {
public:
    void use(IGameplayActions* gameplay) override {
        gameplay->fish(this);
    }
};

class Hoe : public Item {
public:
    void use(IGameplayActions* gameplay) override {
        gameplay->dig(this);
    }
};

class Bailer : public Item {
public:
    void use(IGameplayActions* gameplay) override {
        gameplay->water(this);
    }
};

#endif ITEM_H