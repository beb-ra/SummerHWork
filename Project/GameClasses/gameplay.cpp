#include "gameplay.h"

int Gameplay::rand_generation(int min, int max) const noexcept {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<size_t> dist(min, max);
    return dist(gen);
}

void Gameplay::change_times_of_day(float is_morning) {
    if (is_morning) {
        _time_of_day = 0;
    }
    else {
        _time_of_day = (_time_of_day + 1) % 4; // день, вечер, ночь
    }
}

Item* Gameplay::generate_item() {
    int id = this->rand_generation(1, 27);
    // в зависимости от результата создавать разные классы
    Item item(1);
    return &item;
}

void Gameplay::create_character(TypeCharacter type) {
    // создать рюкзак, положить туда необходимые предметы, положить рюкзак в персонажа
    // проверка на тип персонажа

    //Item* item1 = new Item(1);

    /*
    TVector<Item> objects(5, { Item(1), Item(2), Item(3), Item(4), Item(5) }); //

    Item* hand_object = &Item(6);
    Item* selected_object = &Item(7);

    Backpack backpack(objects, hand_object, selected_object);

    Character main_charracter(static_cast < size_t>(100), backpack, type);
    */

}