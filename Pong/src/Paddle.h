#pragma once
#include "Entity.h"

class Paddle : public Entity
{
private:
	double m_h_velocity = 0;
	double m_v_velocity = 1;
public:
	Paddle(double x, double y) :Entity(x, y, 25, 100) {};
	void move(int key, unsigned int elapsed_time);
};

