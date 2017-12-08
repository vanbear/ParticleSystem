#pragma once
#include "Particle.h"

using namespace std;

Particle::Particle()
{
	cout << "Particle created";
}

Particle::~Particle()
{
	cout << "Particle destroyed" << endl;
}

// ---------------------------------- POSITION ----------------------------
double Particle::getPositionX()
{
	return m_posX;
}
double Particle::getPositionY()
{
	return m_posY;
}
double Particle::getPositionZ()
{
	return m_posZ;
}
void Particle::updatePosition(double x, double y, double z)
{
	m_posX = x;
	m_posY = y;
	m_posZ = z;
}

// ------------------------------------- SPEED ---------------------------
double Particle::getSpeedX()
{
	return m_speedX;
}
double Particle::getSpeedY()
{
	return m_speedY;
}
double Particle::getSpeedZ()
{
	return m_speedZ;
}
void Particle::updateSpeed(double x, double y, double z)
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