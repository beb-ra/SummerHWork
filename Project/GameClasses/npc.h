#pragma once
#include "object.h"

#ifndef NPC_H
#define NPC_H

//class Object;

class NPC : public Object {
    size_t _move_speed;

    void move();
    void speak();
    void interact(); //взаимодействие
};

#endif NPC_H;