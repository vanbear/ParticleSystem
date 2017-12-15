#pragma once
#include "Particle.h"
class ParticleYellowCircles :
	public Particle
{
public:
	ParticleYellowCircles(float x, float y, float z, float vx, float vy, float vz);
	~ParticleYellowCircles();

	void draw();
	void setDrag();
	void setPath();

private:
	int size;
};

