#include "Ball.h"

void Ball::movement_loop() {
	move(m_h_velocity, m_v_velocity);
	if (m_start.x < 0 || (m_start.x + WIDTH) > 800) m_h_velocity *= -1;
	if (m_start.y < 0 || (m_start.y + HEIGHT) > 600) m_v_velocity *= -1;
}