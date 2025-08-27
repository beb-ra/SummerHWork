#pragma once
#include "object.h"
#include "backpack.h"

#ifndef CHARACTER_H
#define CHARACTER_H

enum TypeCharacter { farmer, fisher, stockbreeder };

class Character : public Object {
private:
    size_t _energy;
    Backpack _backpack;
    TypeCharacter _type;

public:
    Character();
    Character(size_t, Backpack, TypeCharacter);
    Character(int x, int y, int id, size_t energy, Backpack backpack, TypeCharacter type);

    friend class Gameplay;
};

#endif // CHARACTER_H

