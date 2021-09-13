#include "Swarm.h"

Swarm::Swarm(): m_LastTime(0) {
	m_pParticles = new Particle[NPARTICLES];
}

Swarm::~Swarm() {
	delete[] m_pParticles;
}

void Swarm::update(int elapsed) {
	int interval = elapsed - m_LastTime;
	m_LastTime = elapsed;

	for (int i = 0; i < Swarm::NPARTICLES; i++) {
		m_pParticles[i].update(interval);
	}
}