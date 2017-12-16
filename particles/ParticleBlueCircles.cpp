#include "ParticleBlueCircles.h"
#include <ofGraphics.h> // for drawing shapes
#include <ofImage.h> // for drawing images

ParticleBlueCircles::ParticleBlueCircles(ofVec3f pos, ofVec3f spd)
{
	this->setPosition(pos);
	this->setSpeed(2*spd);
	this->m_lifespan = 100;
	this->setColor(ofColor(ofRandom(100, 110), ofRandom(100, 200), ofRandom(200, 255)));
}


ParticleBlueCircles::~ParticleBlueCircles()
{
}

void ParticleBlueCircles::draw()
{
	ofPushMatrix();
	ofEnableBlendMode(OF_BLENDMODE_ADD); // additive blendmode
	ofTranslate(0,0, this->getPosition().z); // tanslate the image in z-axis basing off the object's position
	// set color
	ofSetColor(this->getColor(), m_lifespan*2);
	// circle
	ofDrawCircle(this->getPosition(),3);
	// set color to default
	ofSetColor(ofColor(255, 255, 255));
	ofDisableBlendMode(); 
	ofPopMatrix();
}