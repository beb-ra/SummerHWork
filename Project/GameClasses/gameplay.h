#pragma once
#include <random>
#include "game_map.h"
#include "character.h"
#include "igameplay_actions.h"

#ifndef GAMEPLAY_H
#define GAMEPLAY_H

class Object;
class Item;
class NPC;

class Gameplay : public IGameplayActions {
    TVector<NPC*> _npc_list;
    TVector<Object> _object_list;
    GameMap _map;
    Character _character;
    int _time_of_day;
    int rand_generation(int min, int max) const noexcept;

public:
    void create_character(TypeCharacter type);
    Item* generate_item();
    void game_initialization();
    void start_random_event();
    void change_times_of_day(float);

    void plant(Seeds* seed) override;
    void dig(Hoe* hoe) override;
    void water(Bailer* bailer) override;
    void fish(FishingRod* rod) override;
    void eat(int energy) override;
    
    void feed();
};

#endif GAMEPLAY_H