#pragma once
#include "Particle.h"

using namespace std;

Particle::Particle()
{
}

Particle::~Particle()
{
}

// ---------------------------------- POSITION ----------------------------
float Particle::getPositionX()
{
	return m_posX;
}
float Particle::getPositionY()
{
	return m_posY;
}
float Particle::getPositionZ()
{
	return m_posZ;
}
void Particle::updatePosition()
{
	m_posX += m_speedX;
	m_posY += m_speedY;
	m_posZ += m_speedZ;
}
void Particle::setPosition(float x, float y, float z)
{
	m_posX = x;
	m_posY = y;
	m_posZ = z;
}

// ------------------------------------- SPEED ---------------------------
float Particle::getSpeedX()
{
	return m_speedX;
}
float Particle::getSpeedY()
{
	return m_speedY;
}
float Particle::getSpeedZ()
{
	return m_speedZ;
}
void Particle::setSpeed(float x, float y, float z)
{
	m_speedX = x;
	m_speedY = y;
	m_speedZ = z;
}

int Particle::getColorR()
{
	return m_colorA;
}
int Particle::getColorG()
{
	return m_colorG;
}
int Particle::getColorB()
{
	return m_colorB;
}
int Particle::getColorA()
{
	return m_colorA;
}
void Particle::setColor(int r, int g, int b, int a)
{
	m_colorR = r;
	m_colorG = g;
	m_colorB = b;
	m_colorA = a;
}

bool Particle::isDead()
{
	if (m_lifespan <= 0)
	{
		cout << "Particle should be dead now." << endl;
		return true;
	}
	
	else return false;
}


