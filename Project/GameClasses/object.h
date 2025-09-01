#pragma once
#include "igameplay_actions.h"
#include "tvector.h"

#ifndef OBJECT_H
#define OBJECT_H

class Character;
class Item;

class Object {
    int x_coord;
    int y_coord;
    int _id;

public:
    virtual ~Object() = default;
    Object();
    Object(int id);
    Object(int x, int y, int id);

    //virtual void use(IGameplayActions* gameplay) {}
};


class Door : public Object {
    void use(IGameplayActions* gameplay) {
        // ��� ������� ������ "������ ���� ����� �����? ���� ���������� ��, ���������� ��� �������"
        gameplay->change_times_of_day(true);
    }
};

class LocationTransitions : public Object {
    int _location_id; // � ������� ����� �������

    void use(IGameplayActions* gameplay) {
        // ������� � ������ �������
        gameplay->go_to_another_location(_location_id);
    }
};

class Chest : public Object {
    TVector<Item*> _things;

    void use(IGameplayActions* gameplay) {
        // �� ��� ������ ���� ��
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
