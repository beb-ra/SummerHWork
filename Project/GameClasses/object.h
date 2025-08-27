#pragma once
#include "gameplay.h"

#ifndef OBJECT_H
#define OBJECT_H

class Character;
class Item;

class Object {
    int x_coord;
    int y_coord;
    int _id;

public:
    Object();
    Object(int, int, int);

protected:
    //virtual void use(class Character* character) {}
};

class Door : public Object {
    void use(class Gameplay* gameplay) {
        // при нажатии плашка "хотите уйти домой спать? если выбирается да, вызывается эта функция"
        gameplay->change_times_of_day(true);
    }
};

class LocationTransitions : public Object {
    int _location_id; // в которую ведет переход

    void use(class Character* character) {
        // перейти в другую локацию
    }
};

class Chest : public Object {
    TVector<Item*> _things;

    void use(class Character* character) {
        // че тут должно быть хз
    }

    void add_item(Item* item) {
        _things.push_back(item);
    }

    TVector<Item*> get_items() { //
        TVector<Item*> result(_things);
        return result;
    }
};

#endif OBJECT_H
