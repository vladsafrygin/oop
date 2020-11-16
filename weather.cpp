#include "weather.h"
#include <cassert>

//Сеттеры
void Weather_Center::set_temp(const int &_temp) {
    assert(!(_temp < -273 || _temp > 100));
    temp = _temp;
}

void Weather_Center::set_pressure(const int &_press) {
    assert(!(_press < 0 || _press > 1000));
    pressure = _press;
}

void Weather_Center::set_wind_direction(int _direction) {
    if (_direction >= 360) {
        _direction = _direction % 360;
        wind_direction = _direction;
    } else if (_direction < 0) {
        while (_direction < 0) {
            _direction = _direction + 360;
        }
        wind_direction = _direction;
    }
    wind_direction = _direction;
}

void Weather_Center::set_wind_speed(const int &_speed) {
    assert(!(_speed < 0));
    wind_speed = _speed;
}

void Weather_Center::set_type(const int &_type) {
    assert(!(_type > 1 || _type < 0));
    type = _type;
}

//Геттеры

int Weather_Center::get_type() const { return type; }

int Weather_Center::get_wind_speed() const { return wind_speed; }

int Weather_Center::get_temp() const { return temp; }

int Weather_Center::get_pressure() const { return pressure; }

int Weather_Center::get_wind_direction() const { return wind_direction; }

//Конструктор по умолчанию
Weather_Center::Weather_Center() {
    set_temp(25);
    set_pressure(760);
    set_wind_direction(0);
    set_wind_speed(3);
    set_type(1);
}

//Констурктор копирования
Weather_Center::Weather_Center(const Weather_Center &wCenter) {
    set_temp(wCenter.temp);
    set_pressure(wCenter.pressure);
    set_wind_direction(wCenter.wind_direction);
    set_wind_speed(wCenter.wind_speed);
    set_type(wCenter.type);
}
Weather_Center& Weather_Center::operator=(const Weather_Center& wCenter) {
    set_temp(wCenter.temp);
    set_pressure(wCenter.pressure);
    set_wind_direction(wCenter.wind_direction);
    set_wind_speed(wCenter.wind_speed);
    set_type(wCenter.type);
    return *this;
}

//Конструктор инициализации
Weather_Center::Weather_Center(const int &temp, const int &pressure, \
int wind_direction, const int &wind_speed, const int &type) {
    set_temp(temp);
    set_pressure(pressure);
    set_wind_direction(wind_direction);
    set_wind_speed(wind_speed);
    set_type(type);
}

//Деструктор
Weather_Center::~Weather_Center() {};

void Weather_Center::test() {
    assert(temp == 30);
    assert(wind_direction == 270);
    assert(wind_speed == 6);
    assert(type == 1);
    assert(pressure == 750);
}

bool Weather_Center::operator==(const Weather_Center& wc) const {
    return 
        temp == wc.temp &&
        pressure == wc.pressure && 
        wind_direction == wc.wind_direction && 
        wind_speed == wc.wind_speed && 
        type == wc.type;
}
bool Weather_Center::operator!=(const Weather_Center& wc) const {
    return !operator==(wc);
}

std::istream& operator>>(std::istream& is, Weather_Center& wc) {
    // чтение полей класса из потока, аналогично чтению из консоли
    is >> wc.temp >> wc.pressure >> wc.wind_direction >> wc.wind_speed >> wc.type;
    return is;
}
std::ostream& operator<<(std::ostream& os, const Weather_Center& wc) {
    // запись полей класса, разделенных пробелами, в поток, аналогично записи в консоль
    os << wc.temp << " " << wc.pressure << " " << wc.wind_direction << " " << wc.wind_speed << " " << wc.type;
    return os;
}
