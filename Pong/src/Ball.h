#pragma once
#include "Entity.h"

class Ball : public Entity
{
private:
	double m_h_velocity;
	double m_v_velocity;
public:
	Ball(double x, double y) : Entity(x, y, 25, 25) { m_h_velocity = 2; m_v_velocity = 2; movement_loop(); };
	void movement_loop();
};

