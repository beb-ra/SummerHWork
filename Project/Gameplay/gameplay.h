#pragma once
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

    void create_character(TypeCharacter type);
    void generate_game_object();
    void game_initialization();
    void start_random_event();
    void change_times_of_day();
};