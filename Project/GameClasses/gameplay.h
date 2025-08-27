#pragma once
#include <random>
#include "game_map.h"

#ifndef GAMEPLAY_H
#define GAMEPLAY_H

class Object;
class Item;
class NPC;
enum TypeCharacter { farmer, fisher, stockbreeder };

class Gameplay {
    TVector<NPC*> _npc_list;
    TVector<Object> _object_list;
    GameMap _map;
    int _time_of_day;
    int rand_generation(int min, int max) const noexcept;

public:
    void create_character(TypeCharacter type);
    //Object* generate_game_object();
    Item* generate_item();
    void game_initialization();
    void start_random_event();
    void change_times_of_day(float);
};

#endif GAMEPLAY_H