#include "backpack.h"
#include "item.h"

Backpack::Backpack() : _things(), _hand_object(nullptr), _selected_object(nullptr) {}
Backpack::Backpack(TVector<Item*> things, Item* hand_obj, Item* selected_obj) :
	_things(things), _hand_object(hand_obj), _selected_object(selected_obj) {}