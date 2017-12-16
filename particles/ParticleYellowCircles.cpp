#include "ParticleYellowCircles.h"
#include <ofGraphics.h>

#include <iostream>


ParticleYellowCircles::ParticleYellowCircles(ofVec3f pos, ofVec3f spd)
{
	this->setPosition(pos);
	this->setSpeed(2 * spd);
	this->m_lifespan = 100;
	this->setColor(ofColor(255, 255, 0));
	this->size = 5;
}


ParticleYellowCircles::~ParticleYellowCircles()
{
}

void ParticleYellowCircles::draw()
{
	ofPushMatrix();
	ofEnableBlendMode(OF_BLENDMODE_ADD); // additive blendmode
	ofTranslate(0, 0, this->getPosition().z); // tanslate the image in z-axis basing off the object's position

	// set color
	ofSetColor(this->getColor(), this->m_lifespan * 2);
	ofNoFill();
	ofDrawCircle(this->getPosition(), 3);
	ofFill();
	// set color to default
	ofSetColor(ofColor(255, 255, 255));
	ofDisableBlendMode();

	ofPopMatrix();
}