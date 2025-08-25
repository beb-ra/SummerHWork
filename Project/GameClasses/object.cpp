#include "object.h"
#include "character.h"
#include "gameplay.h"

Object::Object() : x_coord(-1), y_coord(-1), _id(-1) {}
Object::Object(int x, int y, int id) : x_coord(x), y_coord(y), _id(id) {}