#pragma once
#include "object.h"

// ��������� ����������� ������ ������ �� id
class Item : public Object {
    int _price;

public:
    Item();
    Item(int id);
    Item(int x, int y, int id);
};