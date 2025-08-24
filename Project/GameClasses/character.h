#pragma once
#include "object.h"
#include "backpack.h"

enum TypeCharacter { farmer, fisher, stockbreeder };

class Character : public Object {
    size_t _energy;
    Backpack _backpack;
    TypeCharacter _type;

public:
    void plant();
    void uproot();
    void water();
    void fish();
    void feed();

    Character();
    Character(size_t, Backpack, TypeCharacter);
    Character(int x, int y, int id, size_t energy, Backpack backpack, TypeCharacter type);
};

