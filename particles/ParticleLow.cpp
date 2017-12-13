#include "ParticleLow.h"
#include <ofGraphics.h>
#include <ofImage.h>
#include "ofApp.h"

ParticleLow::ParticleLow(float x, float y, float z, float vx, float vy, float vz)
{
	
	this->setPosition(x, y, z);
	this->setSpeed(2*vx, 2*vy, 2*vz);
	this->m_lifespan = 100;
	this->setColor(ofRandom(100, 255), ofRandom(100, 255), ofRandom(100, 255), m_lifespan);

	
	//cout << "Particle Low created at x: " << x << " y: " << y << " z: " << z << " | with lifetime " << m_lifeTime << endl;;
}


ParticleLow::~ParticleLow()
{
}

void ParticleLow::draw(ofImage* txt)
{
	
	//ofDrawCircle(this->getPositionX(), this->getPositionY(), this->getPositionZ(),5);
	
	ofPushMatrix();
	ofTranslate(0,0, this->getPositionZ());

	ofEnableBlendMode(OF_BLENDMODE_ADD);
	ofSetColor(this->getColorR(), this->getColorG(), this->getColorB(), this->m_lifespan * 2);
	//txt->draw(this->getPositionX(), this->getPositionY());
	ofDrawCircle(this->getPositionX(), this->getPositionY(), this->getPositionZ(),3);
	ofSetColor(ofColor(255, 255, 255));
	ofDisableBlendMode();
	ofPopMatrix();

}

void ParticleLow::setPath()
{

}

void ParticleLow::setDrag()
{

}