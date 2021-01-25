#include "laser.hh"


Laser::Laser(const std::string str):Arme(str)
{
	sprite.scale(0.05f, 0.05f);
}

Laser::~Laser(){};
