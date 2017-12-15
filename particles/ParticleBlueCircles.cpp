#include "ParticleBlueCircles.h"
#include <ofGraphics.h> // for drawing shapes
#include <ofImage.h> // for drawing images

ParticleBlueCircles::ParticleBlueCircles(float x, float y, float z, float vx, float vy, float vz)
{
	this->setPosition(x, y, z);
	this->setSpeed(2*vx, 2*vy, 2*vz);
	this->m_lifespan = 100;
	this->setColor(ofRandom(100, 255), ofRandom(100, 255), ofRandom(100, 255), m_lifespan);
}


ParticleBlueCircles::~ParticleBlueCircles()
{
}

void ParticleBlueCircles::draw()
{
	ofPushMatrix();
	ofEnableBlendMode(OF_BLENDMODE_ADD); // additive blendmode
	ofTranslate(0,0, this->getPositionZ()); // tanslate the image in z-axis basing off the object's position
	// set color
	ofSetColor(this->getColorR(), this->getColorG(), this->getColorB(), this->m_lifespan * 2);
	// circle
	ofDrawCircle(this->getPositionX(), this->getPositionY(), this->getPositionZ(),3);
	// set color to default
	ofSetColor(ofColor(255, 255, 255));
	ofDisableBlendMode(); 
	ofPopMatrix();
}

void ParticleBlueCircles::setPath()
{

}

void ParticleBlueCircles::setDrag()
{

}