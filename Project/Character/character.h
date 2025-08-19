#pragma once
#include "object.h"
#include "backpack.h"

class Character : public Object {
    size_t _energy;
    Backpack _backpack;

    void plant();
    void uproot();
    void water();
    void fish();
    void feed();
};
