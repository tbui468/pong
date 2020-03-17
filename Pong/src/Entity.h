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
	const int WIDTH;
	const int HEIGHT;
	int* m_horizontal_pos;
	int* m_vertical_pos;
	unsigned int previous_time;
public:
	Entity(double x, double y, int width, int height);
	~Entity() {};
	Coordinate get_start() const { return m_start; };
	Coordinate get_end() const { return { m_start.x + WIDTH, m_start.y + HEIGHT }; };
	bool collision(const Entity* entity) const;
	void update_location(double h_velocity, double v_velocity, unsigned int elapsed_time);
private:
	bool collision_x(const Entity* entity) const;
	bool collision_y(const Entity* entity) const;
	void update_pos_array();
};

