#include <iostream>
#include "weather.h"
#include "centers_array.h"
#include <vector>
#include <cassert>



void print_array(const Centers_Array& ca) {
    for (int y = 0; y < ca.get_height(); y++) {
        for (int x = 0; x < ca.get_width(); x++) {
            // тут используется оператор вывода, перегруженный в классе Weather_Center
            std::cout << "[" << x << ", " << y << "]: " << ca.at(x, y) << '\n';
        }
    }
}

int main() {
//Проверка геттеров и конструктора инициализации
    Weather_Center Center1(30, 750, 270, 6, 1);
    std::cout << Center1.get_wind_direction() << endl;
    assert(Center1.get_temp() == 30);
    assert(Center1.get_pressure() == 750);
    assert(Center1.get_wind_direction() == 270);
    assert(Center1.get_wind_speed() == 6);

//Проверка сеттеров
    Center1.test();

//Проверка конструктора копирования
    Weather_Center Center2 = Center1;
    assert(Center2.get_temp() == 30);
    assert(Center2.get_pressure() == 750);
    assert(Center2.get_wind_direction() == 270);
    assert(Center2.get_wind_speed() == 6);

//Проверка констркутора по умолчанию
    Weather_Center Center3;
    assert(Center3.get_wind_direction() == 0);
    assert(Center3.get_temp() == 25);
    assert(Center3.get_pressure() == 760);
    assert(Center3.get_wind_speed() == 3);

    Centers_Array centers(3, 3);
    assert(centers.get_width() == 3);
    assert(centers.get_height() == 3);

    for (int x = 0; x < 3; x++)
    {
        centers.at(x, 0).set_temp(30);
        centers.at(x, 0).set_pressure(750);
        centers.at(x, 0).set_wind_direction(270);
        centers.at(x, 0).set_wind_speed(6);
        centers.at(x, 0).set_type(0);
    }
    for (int x = 0; x < 3; x++)
    {
        centers.at(x, 1).set_temp(40);
        centers.at(x, 1).set_pressure(760);
        centers.at(x, 1).set_wind_direction(280);
        centers.at(x, 1).set_wind_speed(7);
        centers.at(x, 1).set_type(1);
    }
    for (int x = 0; x < 3; x++)
    {
        centers.at(x, 2).set_temp(50);
        centers.at(x, 2).set_pressure(770);
        centers.at(x, 2).set_wind_direction(290);
        centers.at(x, 2).set_wind_speed(8);
        centers.at(x, 2).set_type(0);
    }

    // проверка копирования и изменения
    Centers_Array centers_copy = centers;
    assert(centers_copy == centers);
    centers_copy.at(1, 1).set_type(0);
    assert(centers_copy != centers);

    // проверка на то, что из файла прочиталость тоже, что и записалось
    centers_copy.to_file("file.txt");
    Centers_Array centers_from_file(3, 3);
    centers_from_file.from_file("file.txt");
    assert(centers_copy == centers_from_file);

    print_array(centers_from_file);
    std::cout << "Temp at [0.5; 0.5]: " << centers.get_temp(0.5, 0.5) << '\n';

    std::cout << "Все тесты пройдены\n";

}
