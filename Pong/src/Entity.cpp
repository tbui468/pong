#include "Entity.h"


void Entity::move(double h_velocity, double v_velocity) {
	m_start.x += h_velocity;
	m_end.x += h_velocity;
	m_start.y += v_velocity;
	m_end.y += v_velocity;
}

bool Entity::collision(const Entity* entity) {
	///////////////NEED TO KEEP INTEGER WIDTH VALUE
	return (collision_x(entity) && collision_y(entity));
}

bool Entity::collision_x(const Entity* entity) {
	return true;
}

bool Entity::collision_y(const Entity* entity) {
	return true;
}
