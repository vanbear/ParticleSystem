#pragma once
#include "Particle.h"
class ParticleRedCircles :
	public Particle
{
public:
	ParticleRedCircles(ofVec3f pos, ofVec3f spd);
	~ParticleRedCircles();

	void draw();
	void setDrag();
	void setPath();

private:
	int size;
};

