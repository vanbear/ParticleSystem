#pragma once
#include "Particle.h"
#include <ofImage.h>

class ParticleBlueCircles :
	public Particle
{
public:
	ParticleBlueCircles(ofVec3f pos, ofVec3f spd);
	~ParticleBlueCircles();

	void draw();

};

