#pragma once
#include "Particle.h"
#include <ofImage.h>

class ParticleLow :
	public Particle
{
public:
	ParticleLow(float x, float y, float z, float vx, float vy, float vz);
	~ParticleLow();

	void draw(ofImage* txt);
	void setDrag();
	void setPath();

};

