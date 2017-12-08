#include "ParticleLow.h"
#include <ofGraphics.h>


ParticleLow::ParticleLow(float x, float y, float z)
{
	cout << "Particle Low created at x: " << x << " y: "<< y << " z: " << z << endl;
	this->setPosition(x, y, z);
}


ParticleLow::~ParticleLow()
{
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