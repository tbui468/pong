#pragma once

struct Coordinate {
	double x, y;

	bool operator==(const Coordinate& other) {
		return (int(this->x) == int(other.x) && int(this->y) == int(other.y));
	}
};


class Entity
{
protected:
	Coordinate m_start;
	Coordinate m_end;
	double* m_horizontal_values;
	double* m_vertical_values;
public:
	Entity(double x, double y, double width, double height) : m_start{ x, y }, m_end{ x + width, y + height } {
		m_horizontal_values = new double[width];
		m_vertical_values = new double[height];
	};
	~Entity() { delete[] m_horizontal_values; delete[] m_vertical_values; };
	Coordinate get_start() const { return m_start; };
	Coordinate get_end() const { return m_end; };
	void move(double h_velocity, double v_velocity);
	bool collision(const Entity* entity);
private:
	bool collision_x(const Entity* entity);
	bool collision_y(const Entity* entity);
};

