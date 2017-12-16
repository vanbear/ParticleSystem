#pragma once
#include "Particle.h"
class ParticleYellowCircles :
	public Particle
{
public:
	ParticleYellowCircles(ofVec3f pos, ofVec3f spd);
	~ParticleYellowCircles();

	void draw();

private:
	int size;
};

