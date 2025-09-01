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

void Backpack::throw_away_item(Item* item) {
    //Item** ptr = find_first_elem_by_pointer(_things, item);
    int index = find_first_elem(_things, item);
    _things.erase(index);
    delete item;
}

Backpack::~Backpack() {
    /*
    for (auto it = _things.begin(); it != _things.end(); ++it) {
    Item* item = *it;
    */
    for (Item* item : _things) {
        delete item;
    }
    /*
    for (size_t i = 0; i < _map_objects.size(); i++) {
        for (size_t j = 0; j < _map_objects[i].size(); j++) {
            delete _map_objects[i][j];  
            _map_objects[i][j] = nullptr;
        }
    }
    */
}
