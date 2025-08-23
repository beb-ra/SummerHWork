#pragma once
#include "tvector.h"
#include "item.h"
#include "object.h"

class Backpack {
    TVector<Item*> _things; //вектор указателей
    Item* _hand_object;
    Item* _selected_object; //?

public:
    void put_item();
    void throw_away_selected_item();
    void take_selected_item_in_hand();

    Backpack();
    Backpack(TVector<Item*> things, Item* hand_obj, Item* selected_obj);
};
