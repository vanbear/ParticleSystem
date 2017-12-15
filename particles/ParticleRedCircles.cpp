#include "ParticleRedCircles.h"

#include <ofGraphics.h>


ParticleRedCircles::ParticleRedCircles(float x, float y, float z, float vx, float vy, float vz)
{
	this->setPosition(x, y, z);
	this->setSpeed(2 * vx, 2 * vy, 2 * vz);
	this->m_lifespan = 100;
	this->setColor(255, 0, 0, m_lifespan);
	this->size = 5;
}


ParticleRedCircles::~ParticleRedCircles()
{
}


void ParticleRedCircles::draw()
{
	ofPushMatrix();
	//ofEnableBlendMode(OF_BLENDMODE_ADD); // additive blendmode
	ofTranslate(0, 0, this->getPositionZ()); // tanslate the image in z-axis basing off the object's position

											 // set color
	ofSetColor(this->getColorR(), this->getColorG(), this->getColorB(), this->m_lifespan * 2);
	ofDrawCircle(this->getPositionX(), this->getPositionY(), this->getPositionZ(), 3);
	// set color to default
	ofSetColor(ofColor(255, 255, 255));
	//ofDisableBlendMode();

	ofPopMatrix();
}

void ParticleRedCircles::setPath()
{

}

void ParticleRedCircles::setDrag()
{

}