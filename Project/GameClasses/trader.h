#pragma once
#include "object.h"
#include "npc.h"
#include "tvector.h"
#include "item.h"

#ifndef TRADER_H
#define TRADER_H

class Trader : public NPC {
    TVector<Item> _goods;
};

#endif TRADER_H