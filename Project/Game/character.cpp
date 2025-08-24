#include "character.h"

Character::Character() : Object(), _energy(100), _backpack(), _type(TypeCharacter::farmer) {}

Character::Character(size_t energy, Backpack backpack, TypeCharacter type) : Object(),
_energy(energy), _backpack(backpack), _type(type) {}

Character::Character(int x, int y, int id, size_t energy, Backpack backpack,
	TypeCharacter type) : Object(x, y, id), _energy(energy), _backpack(backpack), _type(type) {}