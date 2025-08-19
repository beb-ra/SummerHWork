#pragma once
#include "object.h"
#include "npc.h"
#include "tvector.h"
#include "item.h"

class Trader : public NPC {
    TVector<Item> _goods;
};