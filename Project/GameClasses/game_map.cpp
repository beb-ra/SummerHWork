#include "game_map.h"
#include "object.h"

void GameMap::highlight_cells(Tile tile) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (_tiles[i][j] == tile) {
                _highlights[i][j] = true;
            }
            else {
                _highlights[i][j] = false;
            }
        }
    }
}

void GameMap::remove_highlighting() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            _highlights[i][j] = false;
        }
    }
}

void GameMap::place_object_by_coords(Object* object, int x, int y) {
    if (_tiles[x][y] == Tile::common) {
        _map_objects[x][y] = object;
    }
}

Object* GameMap::get_object_by_coords(int x, int y) {
    return _map_objects[x][y];
}

GameMap::GameMap(size_t width, size_t height) {
    _width = width;
    _height = height;

    TVector<TVector<Object*>> _map_objects(width, TVector<Object*>(height, static_cast<Object*>(nullptr)));
    TVector<TVector<Tile>> _tiles(width, TVector<Tile>(height, Tile::common));
    TVector<TVector<bool>> _highlights(width, TVector<bool>(height, false));
}