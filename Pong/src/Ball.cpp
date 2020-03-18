#include "Ball.h"

void Ball::move(unsigned int delta_time, const Paddle* p1, const Paddle* p2) {

	//bounce
	if (collision(p1)) {
		while (collision(p1)) {
			update_location(-1*m_h_velocity, -1 * m_v_velocity, delta_time);
		}
		if (collision_y(p1)) {
			m_h_velocity *= -1;
		}
		else if (collision_x(p1)) {
			m_v_velocity *= -1;
		}
	}

	if (collision(p2)) {
		while (collision(p2)) {
			update_location(-1*m_h_velocity, -1 * m_v_velocity, delta_time);
		}
		if (collision_y(p2)) {
			m_h_velocity *= -1;
		}
		else if (collision_x(p2)) {
			m_v_velocity *= -1;
		}
	}

	if (m_start.x == 0 || m_start.x == 800 - WIDTH) {
		m_h_velocity *= -1;
	}
	else if (m_start.y == 0 || m_start.y == 600 - HEIGHT) {
		m_v_velocity *= -1;
	}
	

	update_location(m_h_velocity, m_v_velocity, delta_time);
}

void Ball::bounce_check(const Paddle* paddle) {
	if (collision(paddle)) {

	}else if (m_start.x == 0 || m_start.x == 800 - WIDTH) {
		m_h_velocity *= -1;
	}else if (m_start.y == 0 || m_start.y == 600 - HEIGHT) {
		m_v_velocity *= -1;
	}

}