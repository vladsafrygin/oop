#ifndef CENTERS_ARRAY_H
#define CENTERS_ARRAY_H
#include "weather.h"
#include <string>


class Centers_Array {
private:
	Weather_Center* data;
	int width;
	int height;

public:
	Centers_Array(int w, int h);
	Centers_Array(const Centers_Array& ca);
	~Centers_Array();

	int get_size() const;
	int get_width() const;
	int get_height() const;

	// даблы они получаются из-за того, что в следствие линейной интерполяции получается дробное число
	double get_temp(double x, double y) const;
	double get_pressure(double x, double y) const;
	double get_wind_direction(double x, double y) const;
	double get_wind_speed(double x, double y) const;

	// доступ к элементу по x и y
	Weather_Center& at(int x, int y);
	const Weather_Center& at(int x, int y) const;
	// удаление всех элементов производится деструктором и его реализация не требуется
	// так как нет возможности добавления и удаления эементов (не требуется по варианту)

	// реализация опраторов сравнения
	bool operator==(const Centers_Array& wc) const;
	bool operator!=(const Centers_Array& wc) const;

	// метод сохранения коллекции в файл
	void to_file(const std::string& path) const;
	// метод загрузки из файла
	void from_file(const std::string& path);
};

#endif