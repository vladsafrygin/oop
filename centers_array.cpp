#include "centers_array.h"
#include <cassert>
#include <fstream>
#include <cmath>



Centers_Array::Centers_Array(int w, int h) {
	assert(w > 0 && h > 0);
	width = w;
	height = h;
	// выделение памяти под таблицу с количеством ячеек w * h
	data = new Weather_Center[width * height];
}

Centers_Array::Centers_Array(const Centers_Array& ca) {
	width = ca.width;
	height = ca.height;
	// выделение памяти под таблицу с количеством ячеек w * h
	data = new Weather_Center[width * height];
	for (int i = 0; i < width * height; i++)
		data[i] = ca.data[i];
}
Centers_Array::~Centers_Array() {
	width = 0;
	height = 0;
	delete[] data;
	data = nullptr;
}

int Centers_Array::get_size() const
{
	return width * height;
}
int Centers_Array::get_width() const {
	return width;
}
int Centers_Array::get_height() const {
	return height;
}

double Centers_Array::get_temp(double x, double y) const {
	assert(x >= 0 && y >= 0 && x < width - 1 && y < height - 1);
	// линейная интерполяция 4х соседних сущностей, чистый матан
	int lx = std::floor(x);
	int dy = std::floor(y);
	int rx = std::ceil(x);
	int uy = std::ceil(y);
	double cx = x - lx;
	double cy = y - dy;
	double vx0 = (1 - cx) * at(lx, dy).get_temp() + cx * at(rx, dy).get_temp();
	double vx1 = (1 - cx) * at(lx, uy).get_temp() + cx * at(rx, uy).get_temp();
	return (1 - cy) * vx0 + cy * vx1;
}
double Centers_Array::get_pressure(double x, double y) const {
	assert(x >= 0 && y >= 0 && x < width - 1 && y < height - 1);
	// линейная интерполяция 4х соседних сущностей, чистый матан
	int lx = std::floor(x);
	int dy = std::round(y);
	int rx = std::ceil(x);
	int uy = std::ceil(y);
	double cx = x - lx;
	double cy = y - dy;
	double vx0 = (1 - cx) * at(lx, dy).get_pressure() + cx * at(rx, dy).get_pressure();
	double vx1 = (1 - cx) * at(lx, uy).get_pressure() + cx * at(rx, uy).get_pressure();
	return (1 - cy) * vx0 + cy * vx1;
}
double Centers_Array::get_wind_direction(double x, double y) const {
	assert(x >= 0 && y >= 0 && x < width - 1 && y < height - 1);
	// линейная интерполяция 4х соседних сущностей, чистый матан
	int lx = std::floor(x);
	int dy = std::round(y);
	int rx = std::ceil(x);
	int uy = std::ceil(y);
	double cx = x - lx;
	double cy = y - dy;
	double vx0 = (1 - cx) * at(lx, dy).get_wind_direction() + cx * at(rx, dy).get_wind_direction();
	double vx1 = (1 - cx) * at(lx, uy).get_wind_direction() + cx * at(rx, uy).get_wind_direction();
	return (1 - cy) * vx0 + cy * vx1;
}
double Centers_Array::get_wind_speed(double x, double y) const {
	assert(x >= 0 && y >= 0 && x < width - 1 && y < height - 1);
	// линейная интерполяция 4х соседних сущностей, чистый матан
	int lx = std::floor(x);
	int dy = std::round(y);
	int rx = std::ceil(x);
	int uy = std::ceil(y);
	double cx = x - lx;
	double cy = y - dy;
	double vx0 = (1 - cx) * at(lx, dy).get_wind_speed() + cx * at(rx, dy).get_wind_speed();
	double vx1 = (1 - cx) * at(lx, uy).get_wind_speed() + cx * at(rx, uy).get_wind_speed();
	return (1 - cy) * vx0 + cy * vx1;
}

Weather_Center& Centers_Array::at(int x, int y) {
	assert(x >= 0 && y >= 0 && x < width && y < height);
	return data[y * width + x];
}
const Weather_Center& Centers_Array::at(int x, int y) const {
	assert(x >= 0 && y >= 0 && x < width&& y < height);
	return data[y * width + x];
}

bool Centers_Array::operator==(const Centers_Array& wc) const {
	if (width != wc.width) return false;
	if (height != wc.height) return false;
	for (int i = 0; i < width * height; i++)
		if (data[i] != wc.data[i]) return false;
	return true;
}
bool Centers_Array::operator!=(const Centers_Array& wc) const {
	return !operator==(wc);
}

void Centers_Array::to_file(const std::string& path) const
{
	std::ofstream fout(path);
	for (int i = 0; i < width * height; i++)
	{
		fout << data[i] << '\n';
	}
}
void Centers_Array::from_file(const std::string& path)
{
	std::ifstream fin(path);
	for (int i = 0; i < width * height; i++)
	{
		fin >> data[i];
	}
}

