#pragma once
class Entity
{
protected:
	/*
	const int WIDTH;
	const int HEIGHT;
	const double MAX_SPEED;
	//m_x and m_y are the top left coordinates of the entity
	int m_x;
	int m_y;
	*/
public:
	Entity();
	bool collision(Entity* entity);
	void update();
};

