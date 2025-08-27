#pragma once
#include "backpack.h"

#ifndef CHARACTER_H
#define CHARACTER_H

class Seeds;

//enum TypeCharacter { farmer, fisher, stockbreeder };

class Character : public Object {
private:
    size_t _energy;
    Backpack _backpack;
    TypeCharacter _type;

public:
    void plant(Seeds*);
    void uproot();
    void water();
    void fish();
    void feed();
    void eat(int energy);

    Character();
    Character(size_t, Backpack, TypeCharacter);
    Character(int x, int y, int id, size_t energy, Backpack backpack, TypeCharacter type);
};

#endif // CHARACTER_H

