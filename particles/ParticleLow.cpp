#include "ParticleLow.h"
#include <ofGraphics.h>
#include <ofImage.h>
#include "ofApp.h"

ParticleLow::ParticleLow(float x, float y, float z, float vx, float vy, float vz)
{
	
	this->setPosition(x, y, z);
	this->setSpeed(2*vx, 2*vy, 2*vz);
	this->m_lifespan = 100;
	this->setColor(ofRandom(128, 255), 10, 10, m_lifespan);

	
	//cout << "Particle Low created at x: " << x << " y: " << y << " z: " << z << " | with lifetime " << m_lifeTime << endl;;
}


ParticleLow::~ParticleLow()
{
}

void ParticleLow::draw(ofImage* txt)
{
	//ofSetColor(this->getColorR(), this->getColorG(), this->getColorB(), this->m_lifespan*2);
	//ofDrawCircle(this->getPositionX(), this->getPositionY(), this->getPositionZ(),5);
	
	//ofPushMatrix();
	ofEnableBlendMode(OF_BLENDMODE_ADD);
	//ofTranslate(0,0, this->getPositionZ());
	ofSetColor(ofColor(120, 0, 0));
	//txt->draw(this->getPositionX(), this->getPositionY());
	ofDrawCircle(this->getPositionX(), this->getPositionY(), this->getPositionZ(), 2);
	ofSetColor(ofColor(255, 255, 255));
	ofDisableBlendMode();
	//ofPopMatrix();
}

void ParticleLow::setPath()
{

}

void ParticleLow::setDrag()
{

}