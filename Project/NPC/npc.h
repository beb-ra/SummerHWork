#pragma once
#include "object.h"

class NPC : public Object {
    size_t _move_speed;

    void move();
    void speak();
    void interact(); //взаимодействие
};
