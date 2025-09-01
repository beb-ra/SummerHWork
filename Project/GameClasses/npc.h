#pragma once
#include "object.h"

#ifndef NPC_H
#define NPC_H

class INPC : public Object {
    size_t _move_speed;

public:
    INPC() : Object(), _move_speed(0) {}
    INPC(int id) : Object(id), _move_speed(0) {}
    INPC(int id, size_t speed) : Object(id), _move_speed(speed) {}
    virtual ~INPC() = default;
    virtual void move() = 0;
    virtual void speak() = 0;
    virtual void interact() = 0;
};

class NPC : public INPC {
public:
    NPC() : INPC() {}
    NPC(int id) : INPC(id) {}
    NPC(int id, size_t speed) : INPC(id, speed) {}
    void move() override;
    void speak() override;
};

enum ProductsType { egg, milk, wool };

class Animal : public INPC {
    ProductsType _product;

public:
    void move() override;
    void speak() override;
    void interact() override;
};

#endif NPC_H;