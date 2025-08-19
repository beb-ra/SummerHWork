#pragma once
#include "tvector.h"
#include "item.h"
#include "object.h"

class Backpack {
    TVector<Item*> things; //вектор указателей
    Item* hand_object;
    Item* selected_object; //?

    void put_item();
    void throw_away_selected_item();
    void take_selected_item_in_hand();
};
