#pragma once
#include <vector>
#include "Particle.h"
#include "ParticleLow.h"

class Emitter
{
	public:
		Emitter(float x, float y, float z);
		~Emitter();

		int getParticlesCount();
		void insertToHolder(Particle* particle);
		void activate();

		float getPositionX();
		float getPositionY();
		float getPositionZ();
		void updatePosition(float x, float y, float z);

		std::vector<Particle*> particlesHolder;

		void drawParticles();
		void drawSelf();
		void updateParticles();

	private:
		float m_posX;
		float m_posY;
		float m_posZ;

};

