#include "Emitter.h"
#include "ParticleLow.h"
#include "Particle.h"


Emitter::Emitter(float x, float y, float z)
{
	this->m_posX = x;
	this->m_posY = y;
	this->m_posZ = z;
	std::cout << "Emitter created" << std::endl;
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



void Emitter::insertToHolder(Particle* particle)
{
	particlesHolder.push_back(particle);
}

void Emitter::activate()
{
	ParticleLow* particle = new ParticleLow(this->getPositionX(), this->getPositionY(), this->getPositionZ());
	particle->setSpeed(5.0f, 0, 0);
	insertToHolder(particle);
	std::cout << "Emitter activated" << std::endl;
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

void Emitter::updateParticles()
{
	if (this->particlesHolder.size()>0)
		for (size_t i = 0; i < particlesHolder.size(); i++)
		{
			this->particlesHolder[i]->updatePosition();
		}
}
