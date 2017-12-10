#include "Emitter.h"
#include "ParticleLow.h"
#include "Particle.h"
#include <ofGraphics.h>


Emitter::Emitter(float x, float y, float z)
{
	this->m_posX = x;
	this->m_posY = y;
	this->m_posZ = z;
	std::cout << "Emitter created at " << x <<" "<< y << " "<< z << std::endl;
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



void Emitter::insertToHolder(Particle* particle)
{
	particlesHolder.push_back(particle);
}

void Emitter::activate()
{
	ParticleLow* particle = new ParticleLow(this->m_posX, this->m_posY, this->m_posZ, 1, 1, 1);
	insertToHolder(particle);
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
	
	ofDrawLine(x - size, y, z, x + size, y, z);
	ofDrawLine(x, y - size, z, x, y + size, z);
}

void Emitter::updateParticles()
{
	if (this->particlesHolder.size()>0)
		for (size_t i = 0; i < particlesHolder.size(); i++)
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
