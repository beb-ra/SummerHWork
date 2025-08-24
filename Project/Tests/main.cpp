#include <windows.h>
#include <iostream>
#include "/Users/Lelya/cc++/SummerHWork/Project/Tvector/tvector.h"
//#include "/Users/Lelya/cc++/SummerHWork/Project/Gameplay/gameplay.h"
#include "/Users/Lelya/cc++/SummerHWork/Project/Item/item.h"

void set_color(int text_color, int bg_color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bg_color << 4) | text_color);
}

namespace TestSystem {
    int count_success = 0, count_failed = 0;

    void start_test(bool(*test)(), const char* name_of_test) {
        set_color(2, 0);
        std::cout << "[ RUN      ]";
        set_color(7, 0);
        std::cout << name_of_test << std::endl;

        bool status = test();

        if (status == true) {
            set_color(2, 0);
            std::cout << "[       OK ]" << std::endl;
            count_success++;
        }
        else {
            set_color(4, 0);
            std::cout << "[  FAILED  ]" << std::endl;
            count_failed++;
        }
        set_color(7, 0);
    }

    template <class T>
    bool check(const T& expected, const T& actual) {
        if (expected == actual) {
            return true;
        }
        else {
            std::cerr << "Expected result is " << expected <<
                ", but actual is " << actual << "." << std::endl;
            return false;
        }
    }

    template <class T>
    bool check_not_equal(const T& expected, const T& actual) {
        if (expected == actual) {
            std::cerr << "Expected result and actual result" <<
                "are equal." << std::endl;
            return false;
        }
        else {
            return true;
        }
    }

    void print_init_info() {
        set_color(2, 0);
        std::cout << "[==========] " << std::endl;
        set_color(7, 0);
    }

    void print_final_info() {
        set_color(2, 0);
        std::cout << "[==========] ";
        set_color(7, 0);
        std::cout << count_success + count_failed << " test" <<
            (count_success + count_failed > 1 ? "s" : "") << " ran." << std::endl;
        set_color(2, 0);
        std::cout << "[  PASSED  ] ";
        set_color(7, 0);
        std::cout << count_success << " test" <<
            (count_success > 1 ? "s" : "") << std::endl;
        if (count_failed > 0) {
            set_color(4, 0);
            std::cout << "[  FAILED  ] ";
            set_color(7, 0);
            std::cout << count_failed << " test" <<
                (count_failed > 1 ? "s." : ".") << std::endl;
        }
    }
};  // namespace TestSystem

bool test1_try_create_default_object() {
    bool expected_result = true;
    bool actual_result = true;

    try {
        TVector<int> object;
    }
    catch (const std::exception& ex) {
        std::cerr << ex.what();
        actual_result = false;
    }

    return TestSystem::check(expected_result, actual_result);
}

bool test2_try_create_with_default_object() {
    TVector<int> object;

    return TestSystem::check(static_cast <size_t>(0), object.size()) &&
        TestSystem::check(static_cast <size_t>(STEP_OF_CAPACITY),
            object.capacity()) &&
        TestSystem::check(static_cast <size_t>(0), object.deleted()) &&
        TestSystem::check(State::empty, object.states()[0]);
}

bool test3_check_create_object_with_initialization() {
    int size = 2;
    int* mass = new int[size];
    mass[0] = 1; mass[1] = 2;

    TVector<int> object(size, mass);

    return TestSystem::check(1, object.data()[0]) &&
        TestSystem::check(2, object.data()[1]) &&
        TestSystem::check(static_cast <size_t>(size), object.size()) &&
        TestSystem::check(static_cast <size_t>(15), object.capacity()) &&
        TestSystem::check(static_cast <size_t>(0), object.deleted()) &&
        TestSystem::check(State::busy, object.states()[0]) &&
        TestSystem::check(State::busy, object.states()[1]) &&
        TestSystem::check(State::empty, object.states()[2]);
}

bool test4_try_create_object() {
    bool expected_result = true;
    bool actual_result = true;

    try {
        TVector<int> object(3);
    }
    catch (const std::exception& ex) {
        std::cerr << ex.what();
        actual_result = false;
    }

    return TestSystem::check(expected_result, actual_result);
}

bool test4_2_check_create_object() {
    TVector<int> object(3, { 1, 2, 3 });

    return TestSystem::check(1, object.data()[0]) &&
        TestSystem::check(2, object.data()[1]) &&
        TestSystem::check(3, object.data()[2]) &&
        TestSystem::check(State::busy, object.states()[0]) &&
        TestSystem::check(State::busy, object.states()[1]) &&
        TestSystem::check(State::busy, object.states()[2]) &&
        TestSystem::check(State::empty, object.states()[3]) &&
        TestSystem::check(static_cast <size_t>(0), object.deleted()) &&
        TestSystem::check(static_cast <size_t>(3), object.size()) &&
        TestSystem::check(static_cast <size_t>(15), object.capacity());
}

bool test4_2_2_check_create_object() {
    TVector<int> object(3, { 1, 2 });

    return TestSystem::check(1, object.data()[0]) &&
        TestSystem::check(2, object.data()[1]) &&
        TestSystem::check(State::busy, object.states()[0]) &&
        TestSystem::check(State::busy, object.states()[1]) &&
        TestSystem::check(State::busy, object.states()[2]) &&
        TestSystem::check(State::empty, object.states()[3]) &&
        TestSystem::check(static_cast <size_t>(0), object.deleted()) &&
        TestSystem::check(static_cast <size_t>(3), object.size()) &&
        TestSystem::check(static_cast <size_t>(15), object.capacity());
}

bool test4_2_3_check_create_object() {
    TVector<int> object(3, { 1, 2, 3, 4 });

    return TestSystem::check(1, object.data()[0]) &&
        TestSystem::check(2, object.data()[1]) &&
        TestSystem::check(3, object.data()[2]) &&
        TestSystem::check(State::busy, object.states()[0]) &&
        TestSystem::check(State::busy, object.states()[1]) &&
        TestSystem::check(State::busy, object.states()[2]) &&
        TestSystem::check(State::empty, object.states()[3]) &&
        TestSystem::check(static_cast <size_t>(0), object.deleted()) &&
        TestSystem::check(static_cast <size_t>(3), object.size()) &&
        TestSystem::check(static_cast <size_t>(15), object.capacity());
}

bool test4_3_check_create_object_with_copy() {
    TVector<int> object1(3, { 1, 2, 3 });

    TVector<int> object(object1);

    return TestSystem::check(1, object.data()[0]) &&
        TestSystem::check(2, object.data()[1]) &&
        TestSystem::check(3, object.data()[2]) &&
        TestSystem::check(State::busy, object.states()[0]) &&
        TestSystem::check(State::busy, object.states()[1]) &&
        TestSystem::check(State::busy, object.states()[2]) &&
        TestSystem::check(State::empty, object.states()[3]) &&
        TestSystem::check(static_cast <size_t>(0), object.deleted()) &&
        TestSystem::check(static_cast <size_t>(3), object.size()) &&
        TestSystem::check(static_cast <size_t>(15), object.capacity());
}

bool test5_check_assign_operator() {
    TVector<int> object1(2, { 1, 2 });
    TVector<int> object2(1, { 3 });

    object2 = object1;

    return TestSystem::check(true, object1 == object2) &&
        TestSystem::check(1, object2.data()[0]) &&
        TestSystem::check(2, object2.data()[1]) &&
        TestSystem::check(static_cast <size_t>(2), object2.size()) &&
        TestSystem::check(static_cast <size_t>(15), object2.capacity()) &&
        TestSystem::check(static_cast <size_t>(0), object2.deleted()) &&
        TestSystem::check(State::busy, object2.states()[0]) &&
        TestSystem::check(State::busy, object2.states()[1]);
}

bool test6_check_indexing_operator() {
    TVector<int> object(6, { 0, 0, 0, 0, 0, 0 });
    object[0] = 1;
    object[1] = 2;
    object[2] = 3;
    object[4] = 5;
    object[5] = 6;

    TVector<int> object2(6, { 1, 2, 3, 0, 5, 6 });

    return TestSystem::check(1, object.data()[0]) &&
        TestSystem::check(2, object.data()[1]) &&
        TestSystem::check(3, object.data()[2]) &&
        TestSystem::check(5, object.data()[4]) &&
        TestSystem::check(6, object.data()[5]) &&
        TestSystem::check(true, object == object2);
}

bool test6_2_check_indexing_operator() {
    TVector<int> object(8, { 0, 0, 0, 0, 0, 0, 0, 0 });
    object[0] = 1;
    object[2] = 2;
    object[3] = 3;
    object[5] = 4;
    object[7] = 5;

    TVector<int> object2(8, { 1, 0, 2, 3, 0, 4, 0, 5, 0 });

    return TestSystem::check(1, object.data()[0]) &&
        TestSystem::check(2, object.data()[2]) &&
        TestSystem::check(3, object.data()[3]) &&
        TestSystem::check(4, object.data()[5]) &&
        TestSystem::check(5, object.data()[7]) &&
        TestSystem::check(true, object == object2);
}

bool test6_3_check_const_indexing_operator() {
    TVector<int> object(5);
    for (size_t i = 0; i < 5; i++) {
        object[i] = i + 1;
    }
    const TVector<int> const_object(object);

    return TestSystem::check(1, const_object[0]) &&
        TestSystem::check(2, const_object[1]) &&
        TestSystem::check(3, const_object[2]) &&
        TestSystem::check(4, const_object[3]) &&
        TestSystem::check(5, const_object[4]);
}

bool test_7_check_reserve() {
    TVector<int> object(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
    object.reserve(5);
    object.reserve(15);
    TVector<int> object2(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });

    return TestSystem::check(true, object == object2);
}

bool test_7_2_check_reserve() {
    TVector<int> object(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
    object.reserve(30);
    TVector<int> object2(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });

    return TestSystem::check(true, object == object2) &&
        TestSystem::check(static_cast <size_t>(30), object.capacity());
}

bool test_7_3_check_resize() {
    TVector<int> object(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
    object.resize(5);
    TVector<int> object2(5, { 1, 2, 3, 4, 5 });

    return TestSystem::check(true, object == object2);
}

bool test_7_4_check_resize() {
    TVector<int> object(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
    object.resize(15);
    TVector<int> object2(15, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0, 0, 0, 0, 0 });

    return TestSystem::check(true, object == object2);
}

bool test_7_5_check_resize() {
    TVector<int> object(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
    object.resize(0);
    TVector<int> object2;
    object2.clear();

    return TestSystem::check(true, object == object2);
}

bool test_7_6_check_resize() {
    TVector<int> object(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
    object.resize(16);
    TVector<int> object2(16, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        0, 0, 0, 0, 0, 0 });

    return TestSystem::check(static_cast<size_t>(16), object.size()) &&
        TestSystem::check(static_cast<size_t>(30), object.capacity()) &&
        TestSystem::check(true, object == object2);
}

bool test8_check_pop_front() {
    TVector<int> object(15);
    object[0] = 1;
    object[2] = 2;
    object[3] = 3;
    object[5] = 4;

    object.pop_front();
    object.pop_front();

    return TestSystem::check(State::deleted, object.states()[0]) &&
        TestSystem::check(State::deleted, object.states()[1]) &&
        TestSystem::check(3, object.data()[3]) &&
        TestSystem::check(4, object.data()[5]) &&
        TestSystem::check(3, object[1]) &&
        TestSystem::check(4, object[3]) &&
        TestSystem::check(static_cast <size_t>(15), object.size());
}

bool test8_2_check_pop_front_with_resize() {
    TVector<int> object(10, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 });
    object[0] = 1;
    object[2] = 2;
    object[3] = 3;
    object[5] = 4;

    object.pop_front();
    object.pop_front();

    TVector<int> object2(8, { 2, 3, 0, 4, 0, 0, 0, 0, 0 });

    return TestSystem::check(true, object == object2) &&
        TestSystem::check(static_cast <size_t>(8), object.size());
}

bool test9_check_pop_back() {
    TVector<int> object(15);
    object[0] = 1;
    object[2] = 2;
    object[3] = 3;
    object[5] = 5;

    object.pop_back();
    object.pop_back();

    return TestSystem::check(State::empty, object.states()[14]) &&
        TestSystem::check(State::empty, object.states()[13]) &&
        TestSystem::check(3, object.data()[3]) &&
        TestSystem::check(5, object.data()[5]) &&
        TestSystem::check(3, object[3]) &&
        TestSystem::check(5, object[5]) &&
        TestSystem::check(static_cast <size_t>(15), object.size());
}

bool test9_2_check_pop_back_with_resize() {
    TVector<int> object(10);
    object[0] = 1;
    object[2] = 2;
    object[3] = 3;
    object[5] = 4;

    object.pop_back();
    object.pop_back();

    return TestSystem::check(1, object.data()[0]) &&
        TestSystem::check(2, object.data()[2]) &&
        TestSystem::check(1, object[0]) &&
        TestSystem::check(2, object[2]) &&
        TestSystem::check(static_cast <size_t>(8), object.size());
}

bool test10_check_erase() {
    TVector<int> object(15);
    object[0] = 1;
    object[2] = 2;
    object[3] = 3;
    object[5] = 4;

    object.erase(2);
    object.erase(2);

    return TestSystem::check(State::deleted, object.states()[2]) &&
        TestSystem::check(State::deleted, object.states()[3]) &&
        TestSystem::check(1, object.data()[0]) &&
        TestSystem::check(4, object.data()[5]) &&
        TestSystem::check(1, object[0]) &&
        TestSystem::check(4, object[3]) &&
        TestSystem::check(static_cast <size_t>(15), object.size());
}

bool test10_2_check_erase_with_resize() {
    TVector<int> object(15);
    object[0] = 1;
    object[2] = 2;
    object[3] = 3;
    object[5] = 4;

    object.erase(2);
    object.erase(2);
    object.erase(2);
    object.erase(3);

    return TestSystem::check(1, object.data()[0]) &&
        TestSystem::check(4, object.data()[2]) &&
        TestSystem::check(1, object[0]) &&
        TestSystem::check(4, object[2]) &&
        TestSystem::check(static_cast <size_t>(12), object.size());
}

bool test10_3_check_erase_last_elem() {
    TVector<int> object(10);

    object.erase(9);

    return TestSystem::check(static_cast <size_t>(10), object.size()) &&
        TestSystem::check(State::empty, object.states()[9]);
}

bool test_10_4_try_and_check_erases_in_empty_vector() {
    bool expected_result = false;
    bool actual_result = true;

    TVector<int> object1;
    try {
        object1.pop_front();
    }
    catch (const std::exception& ex) {
        // std::cerr << ex.what();
        actual_result = false;
    }
    TVector<int> res1;

    TVector<int> object2;
    try {
        object2.pop_back();
    }
    catch (const std::exception& ex) {
        // std::cerr << ex.what();
        actual_result = false;
    }
    TVector<int> res2;

    TVector<int> object3;
    try {
        object3.erase(0);
    }
    catch (const std::exception& ex) {
        // std::cerr << ex.what();
        actual_result = false;
    }
    TVector<int> res3;

    return ((object1 == res1) && (object2 == res2) && (object3 == res3)) &&
        TestSystem::check(expected_result, actual_result);
}

bool test11_check_resize_with_lowest_size() {
    TVector<int> object(10);

    for (size_t i = 0; i < 10; i++) {
        object[i] = i + 1;
    }

    object.resize(5);

    TVector<int> object2(5, { 1, 2, 3, 4, 5 });

    return TestSystem::check(static_cast <size_t>(5), object.size()) &&
        TestSystem::check(static_cast <size_t>(15), object.capacity()) &&
        TestSystem::check(State::empty, object.states()[5]) &&
        TestSystem::check(true, object == object2);
}

bool test11_2_check_resize_with_largest_size() {
    TVector<int> object(10);

    object.resize(20);

    return TestSystem::check(static_cast <size_t>(20), object.size()) &&
        TestSystem::check(static_cast <size_t>(30), object.capacity()) &&
        TestSystem::check(State::busy, object.states()[10]) &&
        TestSystem::check(State::busy, object.states()[19]) &&
        TestSystem::check(0, object.data()[10]) &&
        TestSystem::check(0, object.data()[19]);
}

bool test12_check_push_back() {
    TVector<int> object(10);

    object.push_back(5);
    object.push_back(6);

    return TestSystem::check(static_cast <size_t>(12), object.size()) &&
        TestSystem::check(5, object[10]) &&
        TestSystem::check(6, object[11]);
}

bool test12_2_check_push_back() {
    TVector<int> object(5, { 1, 0, 2, 3, 4 });

    object.push_back(5);

    TVector<int> object2(6, { 1, 0, 2, 3, 4, 5 });

    return TestSystem::check(static_cast <size_t>(6), object.size()) &&
        TestSystem::check(true, object == object2);
}

bool test12_3_check_push_back() {
    TVector<int> object(10, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 });
    object[1] = 1;
    object[2] = 2;
    object[4] = 4;
    object[5] = 5;

    object.push_back(6);
    object.push_back(7);

    TVector<int> object2(12, { 0, 1, 2, 0, 4, 5, 0, 0, 0, 0, 6, 7 });

    return TestSystem::check(static_cast <size_t>(12), object.size()) &&
        TestSystem::check(true, object == object2);
}

bool test12_4_check_push_back() {
    TVector<int> object(14, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 });

    object.push_back(55);

    TVector<int> object2(15,
        { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 55 });

    return TestSystem::check(static_cast<size_t>(30), object.capacity()) &&
        TestSystem::check(true, object == object2);
}

bool test12_5_check_push_back_in_empty_vector() {
    TVector<int> object;
    object.push_back(11);

    TVector<int> object2(1, { 11 });

    return TestSystem::check(true, object == object2);
}

bool test_12_6_check_push_back() {
    TVector<int> object(29, { 1, 2, 3, 4, 5, 6, 7, 8,
        9, 10, 11, 12, 13, 14, 15, 16,
        17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29 });

    object.erase(2);
    object.erase(3);
    object.push_back(11);
    object.push_back(22);

    return (object.back() == 22) && (object[27] == 11)
        && TestSystem::check(static_cast<size_t>(30), object.capacity());
}

bool test13_check_push_front() {
    TVector<int> object(10, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 });
    object[0] = 1;
    object[1] = 2;
    object[3] = 4;
    object[4] = 5;

    object.push_front(11);
    object.push_front(10);

    TVector<int> object2(12, { 10, 11, 1, 2, 0, 4, 5, 0, 0, 0, 0, 0, 0 });

    return TestSystem::check(static_cast <size_t>(12), object.size()) &&
        TestSystem::check(true, object == object2);
}

bool test13_2_check_push_front_with_increasing_capacity() {
    TVector<int> object(14, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 });

    object.push_front(55);

    TVector<int> object2(15,
        { 55, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 });

    return TestSystem::check(static_cast<size_t>(30), object.capacity()) &&
        TestSystem::check(true, object == object2);
}

bool test13_3_check_push_front_in_empty_vector() {
    TVector<int> object;
    object.push_front(11);

    TVector<int> object2(1, { 11 });

    return TestSystem::check(true, object == object2);
}

bool test_13_4_check_push_front() {
    TVector<int> vec(29, { 1, 2, 3, 4, 5, 6, 7, 8, 9,
        10, 11, 12, 13, 14, 15, 16,
        17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29 });

    vec.erase(2);
    vec.erase(3);
    vec.push_front(11);
    vec.push_front(22);
    return (vec.front() == 22) && (vec[1] == 11)
        && TestSystem::check(static_cast<size_t>(30), vec.capacity());
}

bool test14_check_insert() {
    TVector<int> object(10, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 });
    object[1] = 1;
    object[2] = 2;
    object[4] = 4;
    object[5] = 5;

    object.insert(3, 3);
    object.insert(3, 13);

    TVector<int> object2(12, { 0, 1, 2, 13, 3, 0, 4, 5, 0, 0, 0, 0 });

    return TestSystem::check(static_cast <size_t>(12), object.size()) &&
        TestSystem::check(true, object == object2);
}

bool test14_2_check_insert_with_reserve() {
    TVector<int> object(10, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 });
    object[1] = 1;
    object[3] = 2;
    object[4] = 4;
    object[6] = 5;

    object.insert(3, 10);
    object.insert(3, 11);
    object.insert(1, 12);
    object.insert(7, 13);
    object.insert(0, 14);

    TVector<int> object2(15, { 14, 0, 12, 1, 0, 11, 10,
        2, 13, 4, 0, 5, 0, 0, 0 });

    return TestSystem::check(static_cast <size_t>(15), object.size()) &&
        TestSystem::check(static_cast <size_t>(30), object.capacity()) &&
        TestSystem::check(true, object == object2);
}

bool test14_3_check_insert() {
    TVector<int> object(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
    object.insert(3, { 11, 12, 13 });

    TVector<int> object2(13, { 1, 2, 3, 11, 12, 13, 4, 5, 6, 7, 8, 9, 10 });

    return TestSystem::check(static_cast <size_t>(15), object.capacity()) &&
        TestSystem::check(true, object == object2);
}

bool test14_4_check_insert() {
    TVector<int> object(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });

    object.insert(0, { 11, 12, 13 });
    object.insert(7, { 21, 22, 23 });
    object.insert(16, { 31, 32, 33 });

    TVector<int> object2(19, { 11, 12, 13, 1, 2, 3, 4, 21,
        22, 23, 5, 6, 7, 8, 9, 10, 31, 32, 33 });

    return TestSystem::check(static_cast <size_t>(30), object.capacity()) &&
        TestSystem::check(true, object == object2);
}

bool test14_5_try_throw_insert() {
    bool expected_result = false;
    bool actual_result = true;

    TVector<int> object(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
    try {
        object.insert(11, 11);
    }
    catch (const std::exception& ex) {
        // std::cerr << ex.what();
        actual_result = false;
    }

    return TestSystem::check(expected_result, actual_result);
}

bool test14_6_check_insert() {
    TVector<int> object(10, { 6, 2, 3, 4, 5, 6, 7, 8, 5, 6 });
    object.insert(2, 4, 99);

    TVector<int> object2(14, { 6, 2, 99, 99, 99, 99, 3, 4, 5, 6, 7, 8, 5, 6 });
    return TestSystem::check(static_cast<size_t>(15), object.capacity()) &&
        TestSystem::check(static_cast<size_t>(14), object.size()) &&
        TestSystem::check(true, object == object2);
}

bool test14_7_check_insert_with_resize() {
    TVector<int> object(14, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 });

    object.insert(2, { 11, 22, 33 });

    TVector<int> object2(17,
        { 1, 2, 11, 22, 33, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 });

    return TestSystem::check(static_cast<size_t>(30), object.capacity()) &&
        TestSystem::check(true, object == object2);
}

bool test14_8_check_insert_in_empty_vector() {
    TVector<int> object;
    object.insert(0, { 11, 22 });

    TVector<int> object2(2, { 11, 22 });

    return TestSystem::check(true, object == object2);
}

bool test14_9_try_throw_insert_in_empty_vector() {
    bool expected_result = false;
    bool actual_result = true;

    TVector<int> object;
    try {
        object.insert(1, { 11, 22 });
    }
    catch (const std::exception& ex) {
        // std::cerr << ex.what();
        actual_result = false;
    }

    return TestSystem::check(expected_result, actual_result);
}

bool test_14_10_check_inserts_in_empty_vector() {
    TVector<int> object1;
    object1.push_front(1);
    TVector<int> res1(1, { 1 });

    TVector<int> object2;
    object2.push_back(11);
    TVector<int> res2(1, { 11 });

    TVector<int> object3;
    object3.insert(0, 111);
    TVector<int> res3(1, { 111 });

    return ((object1 == res1) && (object2 == res2) && (object3 == res3));
}

bool test_14_11_check_insert_with_delete() {
    TVector<int> object(29, { 1, 2, 3, 4, 5, 6, 7, 8, 9,
        10, 11, 12, 13, 14, 15, 16,
        17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29 });

    object.erase(2);
    object.erase(5);
    object.insert(5, 88);
    object.insert(7, 99);

    TVector<int> object2(29, { 1, 2, 4, 5, 6, 88, 8, 99,
        9, 10, 11, 12, 13, 14, 15, 16,
        17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29 });

    return (object == object2) &&
        TestSystem::check(static_cast<size_t>(30), object.capacity());
}

bool test14_12_check_insert_with_resize() {
    TVector<int> object(14, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 });

    object.insert(2, 3, 111);

    TVector<int> object2(17,
        { 1, 2, 111, 111, 111, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 });

    return TestSystem::check(static_cast<size_t>(30), object.capacity()) &&
        TestSystem::check(true, object == object2);
}

bool test14_13_check_insert_with_reserve() {
    TVector<int> object(14, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 });

    object.push_front(111);

    TVector<int> object2(15,
        { 111, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 });

    return TestSystem::check(static_cast<size_t>(30), object.capacity()) &&
        TestSystem::check(true, object == object2);
}

bool test14_14_check_insert_with_reserve() {
    TVector<int> object(14, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 });

    object.push_back(111);

    TVector<int> object2(15,
        { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 111 });

    return TestSystem::check(static_cast<size_t>(30), object.capacity()) &&
        TestSystem::check(true, object == object2);
}

bool test14_15_check_insert_with_reserve() {
    TVector<int> object(14, { 1, 2, 3, 4, 5, 6, 7, 8, 9,
        10, 11, 12, 13, 14 });

    object.insert(4, 111);

    TVector<int> object2(15,
        { 1, 2, 3, 4, 111, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 });

    return TestSystem::check(static_cast<size_t>(30), object.capacity()) &&
        TestSystem::check(true, object == object2);
}

bool test_14_16_check_insert() {
    TVector<int> object(29, { 1, 2, 3, 4, 5, 6, 7, 8, 9,
        10, 11, 12, 13, 14, 15, 16,
        17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29 });

    object.erase(2);
    object.erase(5);
    object.insert(3, 2, 77);

    TVector<int> object2(29, { 1, 2, 4, 77, 77, 5, 6, 8, 9,
        10, 11, 12, 13, 14, 15, 16,
        17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29 });

    return object == object2;
}

bool test15_check_compare_operator() {
    TVector<int> object(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
    TVector<int> object2(12, { 1, 2, 3, 4, 21, 5, 6, 7, 8, 9, 10, 31 });
    object2.pop_back();
    object2.erase(4);

    return TestSystem::check(true, object == object2);
}

bool test15_2_check_compare_operator() {
    TVector<int> object(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
    TVector<int> object2(12, { 1, 2, 3, 4, 21, 5, 6, 7, 8, 9, 10, 31 });

    return TestSystem::check(false, object == object2);
}

bool test15_3_check_compare_operator() {
    TVector<int> object(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
    TVector<int> object2(12, { 1, 2, 3, 4, 21, 5, 6, 7, 8, 9, 10, 31 });

    return TestSystem::check(true, object != object2);
}

bool test15_4_check_compare_operator() {
    TVector<int> object(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
    TVector<int> object2(12, { 1, 2, 3, 4, 21, 5, 6, 7, 8, 9, 10, 31 });
    object2.pop_back();
    object2.erase(4);

    return TestSystem::check(false, object != object2);
}

bool test16_check_at() {
    TVector<int> object(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });

    object.erase(2);
    object.erase(5);
    object.erase(6);

    return TestSystem::check(1, object.at(0)) &&
        TestSystem::check(2, object.at(1)) &&
        TestSystem::check(4, object.at(2)) &&
        TestSystem::check(5, object.at(3)) &&
        TestSystem::check(6, object.at(4)) &&
        TestSystem::check(8, object.at(5)) &&
        TestSystem::check(10, object.at(6)) &&
        TestSystem::check(static_cast <size_t>(8), object.size());
}

bool test16_2_check_at_with_deleted() {
    TVector<int> object(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });

    object.pop_front();
    object.erase(1);
    object.erase(4);
    object.erase(6);
    object.pop_back();

    return TestSystem::check(2, object.at(0)) &&
        TestSystem::check(4, object.at(1)) &&
        TestSystem::check(5, object.at(2)) &&
        TestSystem::check(6, object.at(3)) &&
        TestSystem::check(8, object.at(4));
}

bool test_16_3_try_throw_at() {
    TVector<int> object(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });

    bool expected_result = false;
    bool actual_result = true;
    try {
        size_t res = object.at(10);
    }
    catch (const std::exception& ex) {
        // std::cerr << ex.what();
        actual_result = false;
    }
    return TestSystem::check(expected_result, actual_result);
}

bool test_17_check_the_assignment_operator() {
    TVector<int> object(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
    TVector<int> object2;
    object2 = object;

    return TestSystem::check(true, object == object2);
}

bool test18_check_find() {
    TVector<int> object(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });

    object.pop_front();
    object.erase(1);
    object.erase(4);
    object.erase(6);
    object.pop_back();

    return TestSystem::check(0, find_first_elem(object, 2)) &&
        TestSystem::check(1, find_first_elem(object, 4)) &&
        TestSystem::check(2, find_first_elem(object, 5)) &&
        TestSystem::check(3, find_first_elem(object, 6)) &&
        TestSystem::check(4, find_first_elem(object, 8));
}

bool test18_2_check_find() {
    TVector<int> object(15, { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 });

    object.pop_front();
    object.erase(1);
    object.erase(4);
    object.erase(6);
    object.pop_back();

    /*
    std::cout << find_last_elem(object, 1) << " " << find_last_elem(object, 2) << " " <<
        find_last_elem(object, 3) << " " << find_last_elem(object, 4) << " " <<
        find_last_elem(object, 5) << std::endl;

    std::cout << object[6] << " " << object[7] << " " << object[8] << " " << object[9] << " " << object[2] << std::endl;
    */
    return TestSystem::check(6, find_last_elem(object, 1)) &&
        TestSystem::check(7, find_last_elem(object, 2)) &&
        TestSystem::check(8, find_last_elem(object, 3)) &&
        TestSystem::check(9, find_last_elem(object, 4)) &&
        TestSystem::check(2, find_last_elem(object, 5));
}

bool test18_3_check_find() {
    bool expected_result = true;
    bool actual_result = true;

    TVector<int> object(15, { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 });

    object.pop_front();
    object.erase(1);
    object.erase(4);
    object.erase(6);
    object.pop_back();

    size_t size_1 = find_elem(object, 2)[0];
    int expected_1[3] = { 2, 3, 6 };
    int expected_2[3] = { 2, 0, 7 };

    for (size_t i = 0; i < size_1 + 1; i++) {
        if (expected_2[i] != find_elem(object, 2)[i]
            || expected_1[i] != find_elem(object, 1)[i]) {
            actual_result = false;
            break;
        }
    }

    size_t size_4 = find_elem(object, 4)[0];
    int expected_4[4] = { 3, 1, 5, 9 };

    for (size_t i = 0; i < size_4 + 1; i++) {
        if (expected_4[i] != find_elem(object, 4)[i]) {
            actual_result = false;
            break;
        }
    }

    return TestSystem::check(expected_result, actual_result);
}

bool test18_4_check_find() {
    TVector<int> object(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });

    int pos1 = find_first_elem(object, 55);
    int pos2 = find_last_elem(object, 55);
    return TestSystem::check(-1, pos1) &&
        TestSystem::check(-1, pos2);
}

bool test18_5_check_find() {
    TVector<int> object(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });

    size_t size = find_elem(object, 55)[0];

    return TestSystem::check(static_cast <size_t>(0), size);
}

bool test_18_6_check_find_after_delete() {
    TVector<int> object(100, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25,
        26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
        40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52,
        53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65,
        66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78,
        79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91,
        92, 93, 94, 95, 96, 7, 97, 98, 99, 100 });
    object.erase(3);
    object.pop_front();
    object.pop_back();
    object.erase(3);

    return (object.front() == 2) && (object.back() == 99) &&
        (object[3] == 7) && TestSystem::check(93, find_last_elem(object, 7));
}

bool test_18_7_check_find_after_delete() {
    bool actual_result = true;
    bool expected_result = true;

    TVector<int> object(100, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18, 19, 20, 7, 21, 22, 23, 24, 25, 26,
        27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41,
        42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 7, 55,
        56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70,
        71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86,
        7, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100 });

    object.erase(3);
    object.pop_front();
    object.pop_back();
    object.erase(30);
    object.erase(3);

    int* indexes = find_elem(object, 7);
    int right_indexes[] = { 4, 3, 17, 51, 84 };

    for (size_t i = 0; i < 5; i++) {
        if (indexes[i] != right_indexes[i]) {
            actual_result = false;
            break;
        }
    }
    return TestSystem::check(expected_result, actual_result);
}

bool test_19_check_find_by_pointer() {
    TVector<int> object(9, { 1, 2, 5, 4, 5, 3, 6, 7, 9 });
    int* ptr = find_first_elem_by_pointer(object, 5);

    return TestSystem::check(&object[2], ptr) &&
        TestSystem::check(5, *ptr);
}

bool test_19_2_check_find_by_pointer() {
    TVector<int> object(10, { 1, 2, 5, 4, 5, 3, 6, 7, 5, 9 });
    TVector<int*> ptr = find_elem_by_pointer(object, 55);

    return TestSystem::check(static_cast <size_t>(0), ptr.size());
}

bool test_19_3_check_find_by_pointer() {
    TVector<int> object(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
    object.erase(3);
    object.pop_front();
    object.pop_back();
    object.erase(3);

    int* ptr = find_first_elem_by_pointer(object, 7);
    return TestSystem::check(&object[3], ptr) &&
        TestSystem::check(7, *ptr);
}

bool test_19_4_check_find_by_pointer() {
    TVector<int> object(9, { 1, 2, 5, 4, 5, 3, 6, 7, 9 });
    int* ptr = find_last_elem_by_pointer(object, 5);

    return TestSystem::check(&object[4], ptr) &&
        TestSystem::check(5, *ptr);
}

bool test_19_5_check_find_by_pointer() {
    TVector<int> object(9, { 1, 2, 5, 4, 5, 3, 6, 7, 9 });
    int* ptr = find_first_elem_by_pointer(object, 111);
    int* null_ptr = nullptr;

    return TestSystem::check(null_ptr, ptr);
}

bool test_19_6_check_find_by_pointer() {
    TVector<int> object(9, { 1, 2, 5, 4, 5, 3, 6, 7, 9 });
    int* ptr = find_last_elem_by_pointer(object, 111);
    int* null_ptr = nullptr;

    return TestSystem::check(null_ptr, ptr);
}

bool test_19_6_2_check_find_by_pointer() {
    TVector<int> object(9, { 1, 2, 5, 4, 5, 3, 6, 7, 5, 9 });
    TVector<int*> ptrs = find_elem_by_pointer(object, 100);
    return TestSystem::check(static_cast<size_t>(0), ptrs.size());
}

bool test_19_7_check_find_by_pointer() {
    bool expected_result = true;
    bool actual_result = true;

    TVector<int> object(9, { 1, 2, 5, 4, 5, 3, 6, 7, 5, 9 });
    TVector<int*> ptrs = find_elem_by_pointer(object, 5);
    TVector<int*> res_ptrs(3, { &object[2], &object[4], &object[8] });

    for (size_t i = 0; i < ptrs.size(); i++) {
        if (ptrs[i] != res_ptrs[i]) {
            actual_result = false;
            break;
        }
    }
    return TestSystem::check(static_cast<size_t>(3), ptrs.size()) &&
        TestSystem::check(expected_result, actual_result);
}

bool test_19_8_check_find_by_pointer() {
    int* mass = new int[100];
    for (int i = 0; i < 100; i++) {
        mass[i] = i + 1;
    }
    TVector<int> object(100, mass);
    object.erase(3);
    object.pop_front();
    object.pop_back();
    object.erase(3);
    int* ptr = find_first_elem_by_pointer(object, 7);

    return TestSystem::check(&object[3], ptr) &&
        TestSystem::check(7, *ptr);
}
bool test_19_9_check_find_by_pointer() {
    int* mass = new int[100];
    for (int i = 0; i < 100; i++) {
        mass[i] = i + 1;
    }
    TVector<int> object(100, mass);
    object.erase(3);
    object.pop_front();
    object.pop_back();
    object.erase(3);
    int* ptr = find_last_elem_by_pointer(object, 7);

    return TestSystem::check(&object[3], ptr) &&
        TestSystem::check(7, *ptr);
}

bool test_19_10_check_find_by_pointer() {
    bool expected_result = true;
    bool actual_result = true;

    TVector<int> object(100, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12, 13, 14, 15, 16, 17, 18, 19, 20, 7, 21, 22, 23, 24,
        25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38,
        39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52,
        53, 54, 7, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66,
        67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80,
        81, 82, 83, 84, 85, 86, 7, 87, 88, 89, 90, 91, 92, 93,
        94, 95, 96, 97, 98, 99, 100 });

    object.erase(3);
    object.pop_front();
    object.pop_back();
    object.erase(30);
    object.erase(3);

    TVector<int*> ptrs = find_elem_by_pointer(object, 7);
    TVector<int*> res_ptrs(4, { &object[3], &object[17],
        &object[51], &object[84] });

    for (size_t i = 0; i < ptrs.size(); i++) {
        if (ptrs[i] != res_ptrs[i]) {
            actual_result = false;
            break;
        }
    }
    return TestSystem::check(static_cast<size_t>(4), ptrs.size()) &&
        TestSystem::check(expected_result, actual_result);
}

bool test_20_check_shrink_to_fit() {
    TVector<int> object(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
    object.erase(3);
    object.pop_back();
    object.pop_front();
    object.shrink_to_fit();

    TVector<int> object2(7, { 2, 3, 5, 6, 7, 8, 9 });

    return TestSystem::check(static_cast<size_t>(7), object.size()) &&
        TestSystem::check(static_cast<size_t>(7), object.capacity()) &&
        TestSystem::check(true, object == object2);
}

bool test_21_check_insert_after_delete() {
    TVector<int> object(20, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12, 13, 14, 15, 16, 17, 18, 19, 20 });
    object.erase(3);
    object.pop_front();
    object.pop_back();
    for (size_t i = 0; i < 3; i++) {
        object.erase(4);
    }
    object.insert(2, 55);
    object.insert(6, { 33, 44, 55 });

    TVector<int> object2(18, { 2, 3, 55, 5, 6, 10, 33, 44, 55, 11,
        12, 13, 14, 15, 16, 17, 18, 19 });

    return object == object2;
}

bool test_21_2_check_insert_after_delete() {
    TVector<int> object(20, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18, 19, 20 });
    object.erase(3);
    object.pop_front();
    object.pop_back();
    for (size_t i = 0; i < 3; i++) {
        object.erase(2);
    }
    object.insert(2, 22);
    object.insert(6, { 33, 44, 55 });
    for (size_t i = 0; i < 3; i++) {
        object.erase(4);
    }
    object.pop_back();
    object.pop_front();
    object.insert(2, 66);
    object.insert(4, { 77, 88, 99 });

    TVector<int> object2(17, { 3, 22, 66, 8, 77, 88, 99, 44, 55, 11,
        12, 13, 14, 15, 16, 17, 18 });

    return object == object2;
}

bool test_21_3_check_insert_after_delete() {
    int* mass = new int[100];
    for (int i = 0; i < 100; i++) {
        mass[i] = i + 1;
    }
    TVector<int> object(100, mass);

    object.erase(3);
    object.pop_front();
    object.pop_back();
    for (size_t i = 0; i < 4; i++) {
        object.erase(3);
    }
    object.pop_back();
    object.push_back(111);
    object.insert(4, 55);
    object.insert(6, { 33, 44, 55 });
    object.push_front(222);

    TVector<int> object2(98, { 222, 2, 3, 5, 10, 55, 11, 33, 44, 55, 12,
        13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44,
        45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60,
        61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76,
        77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92,
        93, 94, 95, 96, 97, 98, 111 });

    return object == object2;
}

bool test_22_check_assign() {
    TVector<int> object(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
    object.assign(4, 66);
    TVector<int> object2(4, { 66, 66, 66, 66 });

    return object == object2;
}

bool test_22_2_check_assign() {
    TVector<int> object(6, { 1, 2, 3, 4, 5, 6 });
    object.assign({ 11, 22, 33, 44, 55, 66 });

    TVector<int> object2(6, { 11, 22, 33, 44, 55, 66 });

    return object == object2;
}

bool test_23_check_replace() {
    TVector<int> object(10, { 1, 4, 3, 4, 5, 6, 7, 4, 9, 4 });
    object.replace(4, 11);
    TVector<int> object2(10, { 1, 11, 3, 11, 5, 6, 7, 11, 9, 11 });

    return object == object2;
}

bool test_24_check_shuffle_vector() {
    TVector<int> object(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
    TVector<int> object2(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
    shuffle(object2);

    return TestSystem::check(true, (object != object2));
}

bool test_25_check_hoara_sort() {
    TVector<int> object(11, { 2, 7, 3, 9, 28, 38, 93, 9, 6, 4, 2 });
    hoara_sort(object);
    TVector<int> object2(11, { 2, 2, 3, 4, 6, 7, 9, 9, 28, 38, 93 });

    return TestSystem::check(true, object == object2);
}

bool test_26_insert_after_clear() {
    TVector<int> object(11, { 2, 7, 3, 9, 28, 38, 93, 9, 6, 4, 2 });
    object.clear();
    object.insert(0, 5);

    TVector<int> object2(1, { 5 });

    return TestSystem::check(true, object == object2);
}

bool test_26_2_push_front_after_clear() {
    TVector<int> object(11, { 2, 7, 3, 9, 28, 38, 93, 9, 6, 4, 2 });
    object.clear();
    object.push_front(5);

    TVector<int> object2(1, { 5 });

    return TestSystem::check(true, object == object2);
}

bool test_26_3_push_back_after_clear() {
    TVector<int> object(11, { 2, 7, 3, 9, 28, 38, 93, 9, 6, 4, 2 });
    object.clear();
    object.push_back(5);

    TVector<int> object2(1, { 5 });

    return TestSystem::check(true, object == object2);
}

bool test_27_create_Item() {
    Item item;
    Item item2(24);

    return TestSystem::check(true, item.get_price() == -1) &&
        TestSystem::check(true, item2.get_price() == 50);;
}

int main() {
    /*
    TestSystem::start_test(test1_try_create_default_object,
        "TVector.test1_try_create_default_object");
    TestSystem::start_test(test2_try_create_with_default_object,
        "TVector.test2_try_create_with_default_object");
    TestSystem::start_test(test3_check_create_object_with_initialization,
        "TVector.test3_check_create_object_with_initialization");
    TestSystem::start_test(test4_try_create_object,
        "TVector.test4_try_create_object");
    TestSystem::start_test(test4_2_check_create_object,
        "TVector.test4_2_check_create_object");
    TestSystem::start_test(test4_2_2_check_create_object,
        "TVector.test4_2_2_check_create_object");
    TestSystem::start_test(test4_2_3_check_create_object,
        "TVector.test4_2_3_check_create_object");
    TestSystem::start_test(test4_3_check_create_object_with_copy,
        "TVector.test4_3_check_create_object_with_copy");
    TestSystem::start_test(test5_check_assign_operator,
        "TVector.test5_check_assign_operator");
    TestSystem::start_test(test6_check_indexing_operator,
        "TVector.test6_check_indexing_operator");
    TestSystem::start_test(test6_2_check_indexing_operator,
        "TVector.test6_2_check_indexing_operator");
    TestSystem::start_test(test6_3_check_const_indexing_operator,
        "TVector.test6_3_check_const_indexing_operator");
    TestSystem::start_test(test_7_check_reserve,
        "TVector.test_7_check_reserve");
    TestSystem::start_test(test_7_2_check_reserve,
        "TVector.test_7_2_check_reserve");
    TestSystem::start_test(test_7_3_check_resize,
        "TVector.test_7_3_check_resize");
    TestSystem::start_test(test_7_4_check_resize,
        "TVector.test_7_4_check_resize");
    TestSystem::start_test(test_7_5_check_resize,
        "TVector.test_7_5_check_resize");
    TestSystem::start_test(test_7_6_check_resize,
        "TVector.test_7_6_check_resize");
    TestSystem::start_test(test8_check_pop_front,
        "TVector.test8_check_pop_front");
    TestSystem::start_test(test8_2_check_pop_front_with_resize,
        "TVector.test8_2_check_pop_front_with_resize");
    TestSystem::start_test(test9_check_pop_back,
        "TVector.test9_check_pop_back");
    TestSystem::start_test(test9_2_check_pop_back_with_resize,
        "TVector.test9_2_check_pop_back_with_resize");
    TestSystem::start_test(test10_check_erase, "TVector.test10_check_erase");
    TestSystem::start_test(test10_2_check_erase_with_resize,
        "TVector.test10_2_check_erase_with_resize");
    TestSystem::start_test(test10_3_check_erase_last_elem,
        "TVector.test10_3_check_erase_last_elem");
    TestSystem::start_test(test_10_4_try_and_check_erases_in_empty_vector,
        "TVector.test_10_4_try_and_check_erases_in_empty_vector");
    TestSystem::start_test(test11_check_resize_with_lowest_size,
        "TVector.test11_check_resize_with_lowest_size");
    TestSystem::start_test(test11_2_check_resize_with_largest_size,
        "TVector.test11_2_check_resize_with_largest_size");
    TestSystem::start_test(test12_check_push_back,
        "TVector.test12_check_push_back");
    TestSystem::start_test(test12_2_check_push_back,
        "TVector.test12_2_check_push_back");
    TestSystem::start_test(test12_3_check_push_back,
        "TVector.test12_3_check_push_back");
    TestSystem::start_test(test12_4_check_push_back,
        "TVector.test12_4_check_push_back");
    TestSystem::start_test(test12_5_check_push_back_in_empty_vector,
        "TVector.test12_5_check_push_back_in_empty_vector");
    TestSystem::start_test(test_12_6_check_push_back,
        "TVector.test_12_6_check_push_back");
    TestSystem::start_test(test13_check_push_front,
        "TVector.test13_check_push_front");
    TestSystem::start_test(test13_2_check_push_front_with_increasing_capacity,
        "TVector.test13_2_check_push_front_with_increasing_capacity");
    TestSystem::start_test(test13_3_check_push_front_in_empty_vector,
        "TVector.test13_3_check_push_front_in_empty_vector");
    TestSystem::start_test(test_13_4_check_push_front,
        "TVector.test_13_4_check_push_front");
    TestSystem::start_test(test14_check_insert, "TVector.test14_check_insert");
    TestSystem::start_test(test14_2_check_insert_with_reserve,
        "TVector.test14_2_check_insert_with_reserve");
    TestSystem::start_test(test14_3_check_insert,
        "TVector.test14_3_check_insert");
    TestSystem::start_test(test14_4_check_insert,
        "TVector.test14_4_check_insert");
    TestSystem::start_test(test14_5_try_throw_insert,
        "TVector.test14_5_try_throw_insert");
    TestSystem::start_test(test14_6_check_insert,
        "TVector.test14_6_check_insert");
    TestSystem::start_test(test14_7_check_insert_with_resize,
        "TVector.test14_7_check_insert_with_resize");
    TestSystem::start_test(test14_8_check_insert_in_empty_vector,
        "TVector.test14_8_check_insert_in_empty_vector");
    TestSystem::start_test(test14_9_try_throw_insert_in_empty_vector,
        "TVector.test14_9_try_throw_insert_in_empty_vector");
    TestSystem::start_test(test_14_10_check_inserts_in_empty_vector,
        "TVector.test_14_10_check_inserts_in_empty_vector");
    TestSystem::start_test(test_14_11_check_insert_with_delete,
        "TVector.test_14_11_check_insert_with_delete");
    TestSystem::start_test(test14_12_check_insert_with_resize,
        "TVector.test14_12_check_insert_with_resize");
    TestSystem::start_test(test14_13_check_insert_with_reserve,
        "TVector.test14_13_check_insert_with_reserve");
    TestSystem::start_test(test14_14_check_insert_with_reserve,
        "TVector.test14_14_check_insert_with_reserve");
    TestSystem::start_test(test14_15_check_insert_with_reserve,
        "TVector.test14_15_check_insert_with_reserve");
    TestSystem::start_test(test_14_16_check_insert,
        "TVector.test_14_16_check_insert");
    TestSystem::start_test(test15_check_compare_operator,
        "TVector.test15_check_compare_operator");
    TestSystem::start_test(test15_2_check_compare_operator,
        "TVector.test15_2_check_compare_operator");
    TestSystem::start_test(test15_3_check_compare_operator,
        "TVector.test15_3_check_compare_operator");
    TestSystem::start_test(test15_4_check_compare_operator,
        "TVector.test15_4_check_compare_operator");
    TestSystem::start_test(test16_check_at, "TVector.test16_check_at");
    TestSystem::start_test(test16_2_check_at_with_deleted,
        "TVector.test16_2_check_at_with_deleted");
    TestSystem::start_test(test_16_3_try_throw_at,
        "TVector.test_16_3_try_throw_at");
    TestSystem::start_test(test_17_check_the_assignment_operator,
        "TVector.test_17_check_the_assignment_operator");
    TestSystem::start_test(test18_check_find, "TVector.test18_check_find");
    TestSystem::start_test(test18_2_check_find, "TVector.test18_2_check_find");
    TestSystem::start_test(test18_3_check_find, "TVector.test18_3_check_find");
    TestSystem::start_test(test18_4_check_find, "TVector.test18_4_check_find");
    TestSystem::start_test(test18_5_check_find, "TVector.test18_5_check_find");
    TestSystem::start_test(test_18_6_check_find_after_delete,
        "TVector.test_18_6_check_find_after_delete");
    TestSystem::start_test(test_18_7_check_find_after_delete,
        "TVector.test_18_7_check_find_after_delete");
    TestSystem::start_test(test_19_check_find_by_pointer,
        "TVector.test_19_check_find_by_pointer");
    TestSystem::start_test(test_19_2_check_find_by_pointer,
        "TVector.test_19_2_check_find_by_pointer");
    TestSystem::start_test(test_19_3_check_find_by_pointer,
        "TVector.test_19_3_check_find_by_pointer");
    TestSystem::start_test(test_19_4_check_find_by_pointer,
        "TVector.test_19_4_check_find_by_pointer");
    TestSystem::start_test(test_19_5_check_find_by_pointer,
        "TVector.test_19_5_check_find_by_pointer");
    TestSystem::start_test(test_19_6_check_find_by_pointer,
        "TVector.test_19_6_check_find_by_pointer");
    TestSystem::start_test(test_19_6_2_check_find_by_pointer,
        "TVector.test_19_6_2_check_find_by_pointer");
    TestSystem::start_test(test_19_7_check_find_by_pointer,
        "TVector.test_19_7_check_find_by_pointer");
    TestSystem::start_test(test_19_8_check_find_by_pointer,
        "TVector.test_19_8_check_find_by_pointer");
    TestSystem::start_test(test_19_9_check_find_by_pointer,
        "TVector.test_19_9_check_find_by_pointer");
    TestSystem::start_test(test_19_10_check_find_by_pointer,
        "TVector.test_19_10_check_find_by_pointer");
    TestSystem::start_test(test_20_check_shrink_to_fit,
        "TVector.test_20_check_shrink_to_fit");
    TestSystem::start_test(test_21_check_insert_after_delete,
        "TVector.test_21_check_insert_after_delete");
    TestSystem::start_test(test_21_2_check_insert_after_delete,
        "TVector.test_21_2_check_insert_after_delete");
    TestSystem::start_test(test_21_3_check_insert_after_delete,
        "TVector.test_21_3_check_insert_after_delete");
    TestSystem::start_test(test_22_check_assign,
        "TVector.test_22_check_assign");
    TestSystem::start_test(test_22_2_check_assign,
        "TVector.test_22_2_check_assign");
    TestSystem::start_test(test_23_check_replace,
        "TVector.test_23_check_replace");
    TestSystem::start_test(test_24_check_shuffle_vector,
        "TVector.test_24_check_shuffle_vector");
    TestSystem::start_test(test_25_check_hoara_sort,
        "TVector.test_25_check_hoara_sort");
    TestSystem::start_test(test_26_insert_after_clear,
        "TVector.test_26_insert_after_clear");
    TestSystem::start_test(test_26_2_push_front_after_clear,
        "TVector.test_26_2_push_front_after_clear");
    TestSystem::start_test(test_26_3_push_back_after_clear,
        "TVector.test_26_3_push_back_after_clear");
    */

    TestSystem::start_test(test_27_create_Item,
    "Item.test_27_create_Item");
    TestSystem::print_final_info();
    system("pause");
    return 0;
}
