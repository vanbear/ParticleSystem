#include "ParticleRedCircles.h"

#include <ofGraphics.h>


ParticleRedCircles::ParticleRedCircles(ofVec3f pos, ofVec3f spd)
{
	this->setPosition(pos);
	this->setSpeed(2 * spd);
	this->m_lifespan = 100;
	this->setColor(ofColor(255,0,0));
	this->size = 5;
}

ParticleRedCircles::~ParticleRedCircles()
{
}

void ParticleRedCircles::draw()
{
	ofPushMatrix();
	ofEnableBlendMode(OF_BLENDMODE_ADD); // additive blendmode

	// tanslate the image in z-axis basing off the object's position
	ofTranslate(0, 0, this->getPosition().z);

	// set color
	ofSetColor(this->getColor(),m_lifespan*2);
	ofDrawCircle(this->getPosition(), 3);

	// set color to default
	ofSetColor(ofColor(255, 255, 255));

	ofDisableBlendMode();
	ofPopMatrix();
}

void ParticleRedCircles::setPath()
{

}

void ParticleRedCircles::setDrag()
{

}