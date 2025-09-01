#pragma once
#include "tvector.h"

#ifndef BACKPACK_H
#define BACKPACK_H

class Item;
class Character;

class Backpack {
private:
    TVector<Item*> _things; //вектор указателей
    //Item* _selected_object; //?

public:
    ~Backpack();
    Backpack();
    Backpack(TVector<Item*> things);

    void throw_away_item(Item*);
    void select_item(Character*, Item*);
};

#endif BACKPACK_H
