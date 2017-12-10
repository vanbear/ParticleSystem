#pragma once
#include "Particle.h"

class ParticleLow :
	public Particle
{
public:
	ParticleLow(float x, float y, float z, float vx, float vy, float vz);
	~ParticleLow();

	void draw();
	void setDrag();
	void setPath();
};

