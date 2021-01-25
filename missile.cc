#include "missile.hh"


Missile::Missile(const std::string str):Arme(str)
{
	sprite.scale(0.05f, 0.05f);
}

Missile::~Missile(){};