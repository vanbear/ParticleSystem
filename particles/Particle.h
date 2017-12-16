#pragma once

#include <iostream>
#include <vector>
#include <ofImage.h>

class Particle
{
public:
	Particle();
	~Particle();

	// position
	ofVec3f getPosition();
	void updatePosition();
	void setPosition(ofVec3f pos);

	// speed
	ofVec3f getSpeed();
	void setSpeed(ofVec3f pos);

	// color
	ofColor getColor();
	void setColor(ofColor color);

	// drawing
	virtual void draw() = 0;

	// lifetime
	bool isDead();
	int m_lifespan;

private:
	ofVec3f v_position;
	ofVec3f v_speed;
	ofColor v_color;
	
};