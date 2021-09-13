#define _USE_MATH_DEFINES

#include <cmath>
#include <stdlib.h>
#include "Particle.h"

Particle::Particle(): m_x(0), m_y(0){
	init();
}

void Particle::init() {
	m_x = 0;
	m_y = 0;
	// Uncomment next line for partitle explosion
	//m_direction = (2 * M_PI * rand()) / RAND_MAX;
	// For the spiral code, point always initialised at the centre (origin)
	m_direction = 0.0;
	m_speed = 0.04 * rand() / RAND_MAX;
	m_speed *= m_speed;
}

Particle::~Particle() {
	//
}

void Particle::update(int interval) {

	// Uncomment the following lines to get an explosion
	
	//m_direction += interval * 0.0001
	//double xspeed = m_speed * cos(m_direction);
	//double yspeed = m_speed * sin(m_direction);

	//m_x += xspeed * interval;
	//m_y += yspeed * interval;

	// Spiral code
	m_direction += m_speed + interval * 0.0001;
	m_x = cos(m_direction * 50 * M_PI) * m_direction;
	m_y = sin(m_direction * 50 * M_PI) * m_direction;

	if (m_x < -1 || m_x > 1 || m_y < -1 || m_y > 1) {
		init();
	}

	if (rand() < RAND_MAX / 100) {
		init();
	}
}