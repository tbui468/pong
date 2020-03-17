#include "Ball.h"

void Ball::move(unsigned int delta_time) {
	update_location(m_h_velocity, m_v_velocity, delta_time);
	//bounce if adjacent to wall
	if (m_start.x < 0 || (m_start.x + WIDTH) > 800) m_h_velocity *= -1;
	if (m_start.y < 0 || (m_start.y + HEIGHT) > 600) m_v_velocity *= -1;
}