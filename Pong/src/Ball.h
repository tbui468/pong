#pragma once
#include "Entity.h"
#include "Paddle.h"

class Ball : public Entity
{
private:
	double m_h_velocity = .2;
	double m_v_velocity = .2;
public:
	Ball(double x, double y) : Entity(x, y, 25, 25) {};
	void move(unsigned int delta_time, const Paddle* p1, const Paddle* p2);
	void bounce_check(const Paddle* paddle);
};

