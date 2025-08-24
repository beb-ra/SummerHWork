#pragma once
#include "tvector.h"
#include "object.h"

enum Tile { river, grass, soil };

class GameMap {
    TVector<TVector<Object*>> _map_objects; //������ �������� ����������
    TVector<TVector<Tile>> _tiles; //������ �������� ������

    void place_object_by_coords();
    void place_object_by_its_coords(); //?
    void get_object_by_coords();
};
