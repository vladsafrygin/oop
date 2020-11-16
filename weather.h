#ifndef WEATHER_H
#define WEATHER_H
#include <iostream>

using namespace std;



class Weather_Center {
private:
    int temp;
    int pressure;
    int wind_direction;
    int wind_speed;
    int type;
public:
//Конструктор по умолчанию
    Weather_Center();

//Конструктор копирования
    Weather_Center(const Weather_Center &wCenter);
// оператор копирования
    Weather_Center& operator=(const Weather_Center& wCenter);

//Конструктор инизиализации
    Weather_Center(const int &temp, const int &pressure, \
    int wind_direction, const int &wind_speed, const int &type);

//Деструктор
    ~Weather_Center();

//Геттеры
    int get_temp() const;

    int get_pressure() const;

    int get_wind_direction() const;

    int get_wind_speed() const;

    int get_type() const;

//Cеттеры
    void set_temp(const int &_temp);

    void set_pressure(const int &_press);

    void set_wind_direction(int _direction);

    void set_wind_speed(const int &_speed);

    void set_type(const int &_type);

    void test();

    // реализация опраторов сравнения
    bool operator==(const Weather_Center& wc) const;
    bool operator!=(const Weather_Center& wc) const;

    // перегрузка операторов для ввода / вывода для удобной работы с файлами
    friend std::istream& operator>>(std::istream& is, Weather_Center& wc);
    friend std::ostream& operator<<(std::ostream& is, const Weather_Center& wc);
};

#endif
