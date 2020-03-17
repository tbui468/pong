#include "Paddle.h"


void Paddle::move(int key, unsigned int delta_time) {
	update_location(m_h_velocity * key, m_v_velocity * key, delta_time);
}