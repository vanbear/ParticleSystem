#pragma once
#include <vector>
#include "Particle.h"

class Emitter
{
	public:
		Emitter(ofVec3f pos);
		~Emitter();

		int getParticlesCount();
		void insertToHolder(Particle* particle);
		void activate(int selectedParticle);

		ofVec3f getPosition();
		void updatePosition(ofVec3f pos);

		Particle* particle;
		std::vector<Particle*> particlesHolder;

		void drawParticles();
		void drawSelf();
		void updateParticles();

	private:
		ofVec3f v_position;

};

