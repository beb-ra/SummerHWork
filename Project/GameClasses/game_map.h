#pragma once
#include "tvector.h"

#define ROWS 10
#define COLS 10

#ifndef GAME_MAP_H
#define GAME_MAP_H

class Object;

enum Tile { river, grass, soil, unwatered_plant, plant, common };

class GameMap {
    size_t _width;
    size_t _height;

    TVector<TVector<Object*>> _map_objects; //вектор векторов указателей
    TVector<TVector<Tile>> _tiles; //вектор векторов тайлов
    TVector<TVector<bool>> _highlights;

public:
    GameMap(size_t width = ROWS, size_t height = COLS);

    void place_object_by_coords(Object*, int, int);
    Object* get_object_by_coords(int, int);
    void highlight_cells(Tile tile);
    void remove_highlighting();

    friend class Gameplay;
};

#endif GAME_MAP_H
