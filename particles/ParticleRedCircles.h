#pragma once
#include "Particle.h"
class ParticleRedCircles :
	public Particle
{
public:
	ParticleRedCircles(float x, float y, float z, float vx, float vy, float vz);
	~ParticleRedCircles();

	void draw();
	void setDrag();
	void setPath();

private:
	int size;
};

