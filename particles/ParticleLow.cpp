#include "ParticleLow.h"
#include <ofGraphics.h>


ParticleLow::ParticleLow(float x, float y, float z, float vx, float vy, float vz)
{
	
	this->setPosition(x, y, z);
	this->setSpeed(vx, vy, vz);
	this->m_lifespan = 200;
	this->setColor(ofRandom(128, 255), 10, 10, m_lifespan);

	//cout << "Particle Low created at x: " << x << " y: " << y << " z: " << z << " | with lifetime " << m_lifeTime << endl;;
}


ParticleLow::~ParticleLow()
{
}

void ParticleLow::draw()
{
	ofSetColor(this->getColorR(), this->getColorG(), this->getColorB(), this->m_lifespan);
	ofDrawCircle(this->getPositionX(), this->getPositionY(), this->getPositionZ(),5);
	ofSetColor(ofColor(255, 255, 255));
}

void ParticleLow::setPath()
{

}

void ParticleLow::setDrag()
{

}