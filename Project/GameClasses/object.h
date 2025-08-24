#pragma once

class Character;

class Object {
    int x_coord;
    int y_coord;
    int _id;

public:
    Object();
    Object(int, int, int);
    virtual void use(class Character* character) = 0;
};
