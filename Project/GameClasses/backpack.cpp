#include "backpack.h"
#include "character.h"
#include "item.h"

/*
Backpack::Backpack() : _things(), _hand_object(nullptr), _selected_object(nullptr) {}
Backpack::Backpack(TVector<Item*> things, Item* hand_obj, Item* selected_obj) :
    _things(things), _hand_object(hand_obj), _selected_object(selected_obj) {}
*/
Backpack::Backpack() : _things() {}
Backpack::Backpack(TVector<Item*> things) : _things(things) {}

void Backpack::select_item(Character* character, Item* item) {
    // вылезает окошко, если выбрали использовать:
    //item->use();
    // если выбрали другое действие:
    // другое действие
}
