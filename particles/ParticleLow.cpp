#include "ParticleLow.h"
#include <ofGraphics.h>


ParticleLow::ParticleLow(float x, float y, float z)
{
	
	this->setPosition(x, y, z);
	this->m_lifeTime = ofRandom(100, 1000);

	//cout << "Particle Low created at x: " << x << " y: " << y << " z: " << z << " | with lifetime " << m_lifeTime << endl;;
}


ParticleLow::~ParticleLow()
{
	cout << "Particle Low destroyed." << endl;
}

void ParticleLow::draw()
{
	ofDrawCircle(this->getPositionX(), this->getPositionY(), this->getPositionZ(),10);
}

void ParticleLow::setPath()
{

}

void ParticleLow::setDrag()
{

}