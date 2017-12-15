#pragma once
#include "Particle.h"
#include <ofImage.h>

class ParticleBlueCircles :
	public Particle
{
public:
	ParticleBlueCircles(float x, float y, float z, float vx, float vy, float vz);
	~ParticleBlueCircles();

	void draw();
	void setDrag();
	void setPath();

};

