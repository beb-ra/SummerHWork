#include "gameplay.h"
#include "object.h"
#include "item.h"
#include "npc.h"

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
        _time_of_day = (_time_of_day + 1) % 4; // ����, �����, ����
    }
}

Item* Gameplay::generate_item() {
    int id = this->rand_generation(1, 27);
    // � ����������� �� ���������� ��������� ������ ������
    Item item(1);
    return &item;
}

void Gameplay::create_character(TypeCharacter type) {
    // ������� ������, �������� ���� ����������� ��������, �������� ������ � ���������
    // �������� �� ��� ���������

    //Item* item1 = new Item(1);

    /*
    TVector<Item> objects(5, { Item(1), Item(2), Item(3), Item(4), Item(5) }); //

    Item* hand_object = &Item(6);
    Item* selected_object = &Item(7);

    Backpack backpack(objects, hand_object, selected_object);

    Character main_charracter(static_cast < size_t>(100), backpack, type);
    */
}


void Gameplay::go_to_another_location(int id_location) {
    // �� ��, ������� � ������ �������
}

void Gameplay::plant(Seeds* seed) {
    // ���� �� soil � unwatering_plant
    _map.highlight_cells(Tile::soil);
    // �����-�� ���������� �������, �������� ���������� �� �����-�� �������
    // while (���� �� ���������� ������)
    int x = 5, y = 5;
    _map._highlights[x][y] = false;
    _map._tiles[x][y] = Tile::unwatered_plant;
    _map._map_objects[x][y] = seed;
    // break ���� ������������� �� ������ ���� � ��������� ��� ������ ��������� �� ��� ���� ������ �����������
}

void Gameplay::dig(Hoe*) {
    // ���� �� grass � soil
}

void Gameplay::eat(int energy) {
    _character._energy += energy;
}

void Gameplay::water(Bailer* bailer) {

}

void Gameplay::fish(FishingRod* rod) {

}