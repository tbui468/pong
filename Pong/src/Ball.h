#pragma once
#include "Entity.h"
#include "Paddle.h"

enum Points { Point_noone = 0, Point_player_1, Point_player_2, Point_quit };

class Ball : public Entity
{
private:
	double m_h_velocity = .3;
	double m_v_velocity = .4;
public:
	Ball(double x, double y) : Entity(x, y, 25, 25) { m_h_velocity = x < 400 ? m_h_velocity : -m_h_velocity; };
	int move(unsigned int delta_time, const Paddle* p1, const Paddle* p2);
};

