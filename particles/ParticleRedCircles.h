#pragma once
#include "Particle.h"
class ParticleRedCircles :
	public Particle
{
public:
	ParticleRedCircles(ofVec3f pos, ofVec3f spd);
	~ParticleRedCircles();

	void draw();

private:
	int size;
};

