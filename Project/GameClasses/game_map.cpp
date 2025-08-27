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