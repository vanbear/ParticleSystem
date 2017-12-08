#pragma once

#include <iostream>
#include <vector>

class Particle
{
public:
	Particle();
	virtual ~Particle();


	// GETTERS SETTERS
	// position
	double getPositionX();
	double getPositionY();
	double getPositionZ();
	void updatePosition(double x, double y, double z);
	// speed
	double getSpeedX();
	double getSpeedY();
	double getSpeedZ();
	void updateSpeed(double x, double y, double z);
	// color
	int getColorR();
	int getColorG();
	int getColorB();
	int getColorA();
	void setColor(int r, int g, int b, int a);
	// lifetime
	int getLifeTime();
	void setLifeTime(int);

	// moving mutators
	virtual void setPath() = 0;
	virtual void setDrag() = 0;

	// drawing
	void draw();

private:
	double m_posX;
	double m_posY;
	double m_posZ;
	double m_speedX;
	double m_speedY;
	double m_speedZ;
	int m_colorR;
	int m_colorG;
	int m_colorB;
	int m_colorA;
	int m_lifeTime;

	
};