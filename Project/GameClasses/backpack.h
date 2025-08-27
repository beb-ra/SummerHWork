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
    //void put_item();
    void throw_away_item();
    void select_item(Character*, Item*);

    Backpack();
    Backpack(TVector<Item*> things);
};

#endif BACKPACK_H
