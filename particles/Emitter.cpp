#include "Emitter.h"
#include "ParticleBlueCircles.h"
#include "ParticleYellowCircles.h"
#include "ParticleRedCircles.h"
#include "Particle.h"
#include <ofGraphics.h>
#include <ofAppRunner.h>


Emitter::Emitter(float x, float y, float z)
{
	this->m_posX = x;
	this->m_posY = y;
	this->m_posZ = z;
	//std::cout << "Emitter created at " << x <<" "<< y << " "<< z << std::endl;
}


Emitter::~Emitter()
{
}

float Emitter::getPositionX()
{
	return this->m_posX;
}
float Emitter::getPositionY()
{
	return this->m_posY;
}
float Emitter::getPositionZ()
{
	return this->m_posZ;
}
void Emitter::updatePosition(float x, float y, float z)
{
	this->m_posX = x;
	this->m_posY = y;
	this->m_posZ = z;
}





void Emitter::activate(int selectedParticle)
{
	float x = this->m_posX;
	float y = this->m_posY;
	float z = this->m_posZ;
	ofVec3f v_em(x,y,z); // emitter position
	ofVec3f v_center(ofGetWidth()*0.5,ofGetHeight()*0.5,0.0); // center of the screen
	ofVec3f dist = (v_em - v_center).getNormalized();

	switch (selectedParticle)
	{
	case 0:
		particle = new ParticleBlueCircles(x, y, z, dist[0], dist[1], dist[2]);
		break;
	case 1:
		particle = new ParticleYellowCircles(x, y, z, dist[0], dist[1], dist[2]);
		break;
	case 2:
		particle = new ParticleRedCircles(x, y, z, dist[0], dist[1], dist[2]);
		break;
	default:
		particle = new ParticleBlueCircles(x, y, z, dist[0], dist[1], dist[2]);
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
	float x = this->m_posX;
	float y = this->m_posY;
	float z = this->m_posZ;
	
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
