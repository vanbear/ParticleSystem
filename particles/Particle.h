#pragma once

#include <iostream>
#include <vector>
#include <ofImage.h>

class Particle
{
public:
	Particle();
	~Particle();

	int m_lifespan;

	// GETTERS SETTERS
	// position
	float getPositionX();
	float getPositionY();
	float getPositionZ();
	void updatePosition();
	void setPosition(float x, float y, float z);
	// speed
	float getSpeedX();
	float getSpeedY();
	float getSpeedZ();
	void setSpeed(float x, float y, float z);
	// color
	int getColorR();
	int getColorG();
	int getColorB();
	int getColorA();
	void setColor(int r, int g, int b, int a);

	// moving mutators
	virtual void setPath() = 0;
	virtual void setDrag() = 0;
	bool isDead();

	// drawing
	virtual void draw() = 0;

private:
	float m_posX;
	float m_posY;
	float m_posZ;
	float m_speedX;
	float m_speedY;
	float m_speedZ;
	int m_colorR;
	int m_colorG;
	int m_colorB;
	int m_colorA;
	
};