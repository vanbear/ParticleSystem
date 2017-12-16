#include "Emitter.h"
#include "ParticleBlueCircles.h"
#include "ParticleYellowCircles.h"
#include "ParticleRedCircles.h"
#include "Particle.h"
#include <ofGraphics.h>
#include <ofAppRunner.h>


Emitter::Emitter(ofVec3f pos)
{
	v_position = pos;
	//std::cout << "Emitter created at " << x <<" "<< y << " "<< z << std::endl;
}


Emitter::~Emitter()
{
}

ofVec3f Emitter::getPosition()
{
	return this->v_position;
}
void Emitter::updatePosition(ofVec3f pos)
{
	this->v_position = pos;
}


void Emitter::activate(int selectedParticle)
{
	float x = this->v_position.x;
	float y = this->v_position.y;
	float z = this->v_position.z;
	ofVec3f v_center(ofGetWidth()*0.5,ofGetHeight()*0.5,0.0); // center of the screen
	ofVec3f vel = (this->v_position - v_center).getNormalized(); // particle direction, away from the center of the screen

	switch (selectedParticle)
	{
	case 0:
		particle = new ParticleBlueCircles(this->v_position, vel);
		break;
	case 1:
		particle = new ParticleYellowCircles(this->v_position, vel);
		break;
	case 2:
		particle = new ParticleRedCircles(this->v_position, vel);
		break;
	default:
		particle = new ParticleBlueCircles(this->v_position, vel);
		break;
	}
	

	insertToHolder(particle);
}

void Emitter::insertToHolder(Particle* particle)
{
	particlesHolder.push_back(particle);
}

int Emitter::getParticlesCount()
{
	return (int)this->particlesHolder.size();
}

void Emitter::drawParticles()
{
	if (this->particlesHolder.size()>0)
		for (size_t i = 0; i < particlesHolder.size(); i++)
		{
			this->particlesHolder[i]->draw();
		}
}
void Emitter::drawSelf()
{
	float size = 10.0f;

	float x = this->v_position.x;
	float y = this->v_position.y;
	float z = this->v_position.z;
	
	ofSetLineWidth(4);
	ofDrawLine(x - size, y, z, x + size, y, z);
	ofDrawLine(x, y - size, z, x, y + size, z);
	ofSetLineWidth(1);
	ofSetColor(ofColor(255,255,255));
}

void Emitter::updateParticles()
{
	if (this->particlesHolder.size()>0)
		for (int i = 0; i < particlesHolder.size(); i++)
		{
			Particle* particle = this->particlesHolder[i];
			if (particle->isDead())
			{
				this->particlesHolder.erase(this->particlesHolder.begin() + i);
			}
			else
			{
				particle->m_lifespan--;
				particle->updatePosition();
			}
				
		}
}
