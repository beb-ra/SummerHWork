#pragma once
#ifndef IGAMEPLAY_ACTIONS_H
#define IGAMEPLAY_ACTIONS_H

class Seeds;
class Hoe;
class Bailer;
class FishingRod;

class IGameplayActions {
public:
    virtual ~IGameplayActions() = default;

    virtual void plant(Seeds* seed) = 0;
    virtual void dig(Hoe* hoe) = 0;
    virtual void water(Bailer* bailer) = 0;
    virtual void fish(FishingRod* rod) = 0;
    virtual void eat(int energy) = 0;
    virtual void change_times_of_day(float is_morning) = 0;
};

#endif // IGAMEPLAY_ACTIONS_H
