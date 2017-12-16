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
ofVec3f Particle::getPosition()
{
	return this->v_position;
}

void Particle::updatePosition()
{
	this->v_position += this->v_speed;
}

void Particle::setPosition(ofVec3f pos)
{
	this->v_position = pos;
}

// ------------------------------------- SPEED ---------------------------
ofVec3f Particle::getSpeed()
{
	return this->v_speed;
}

void Particle::setSpeed(ofVec3f spd)
{
	this->v_speed = spd;
}

// ------------------------------------- COLOR ---------------------------
ofColor Particle::getColor()
{
	return this->v_color;
}

void Particle::setColor(ofColor color)
{
	this->v_color = color;
}

// ------------------------------------- OTHERS ---------------------------
bool Particle::isDead()
{
	if (m_lifespan <= 0) return true;
	else return false;
}

void draw()
{
}


