#pragma once
#include <random>
#include "tvector.h"
#include "object.h"
#include "item.h"
#include "npc.h"
#include "game_map.h"
#include "character.h"
#include "backpack.h"

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
