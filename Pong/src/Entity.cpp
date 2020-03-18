#include "Entity.h"
#include "Screen.h"

Entity::Entity(double x, double y, int width, int height) : m_start{ x, y }, WIDTH(width), HEIGHT(height) {
	m_horizontal_pos = new int[width];
	m_vertical_pos = new int[height];
	update_pos_array();
};


void Entity::update_location(double h_velocity, double v_velocity, unsigned int delta_time) {
	m_start.x += (h_velocity * delta_time);
	m_start.y += (v_velocity * delta_time);

	//keep in screen
	if (m_start.x < 0) m_start.x = 0;
	if (m_start.y < 0) m_start.y = 0;
	if (m_start.x > Screen::SCREEN_WIDTH - WIDTH) m_start.x = (Screen::SCREEN_WIDTH - WIDTH);
	if (m_start.y > Screen::SCREEN_HEIGHT - HEIGHT) m_start.y = (Screen::SCREEN_HEIGHT - HEIGHT);
	update_pos_array();
}


bool Entity::collision(const Entity* entity) const {
	return (collision_x(entity) && collision_y(entity));
}

//check for overlap in horizontal positions of two entities
bool Entity::collision_x(const Entity* entity) const {
	for (int i = 0; i < WIDTH; ++i) {
		for (int j = 0; j < entity->WIDTH; ++j) {
			if (m_horizontal_pos[i] == entity->m_horizontal_pos[j]) {
				return true;
			}
		}
	}
	return false;
}

//check for overlap in vertical positions of two entities
bool Entity::collision_y(const Entity* entity) const {
	for (int i = 0; i < HEIGHT; ++i) {
		for (int j = 0; j < entity->HEIGHT; ++j) {
			if (m_vertical_pos[i] == entity->m_vertical_pos[j]) {
				return true;
			}
		}
	}
	return false;
}

void Entity::update_pos_array() {
	int x = int(m_start.x);
	int y = int(m_start.y);
	for (int i = 0; i < WIDTH; ++i) {
		m_horizontal_pos[i] = x + i;
	}
	for (int i = 0; i < HEIGHT; ++i) {
		m_vertical_pos[i] = y + i;
	}
}
