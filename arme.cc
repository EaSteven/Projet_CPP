#include "arme.hh"


Arme::Arme(const std::string str):Personnage(str)
{
	sprite.setPosition(375,600);
	dispo=1;
}

Arme::~Arme(){};

void Arme::tire()
{
	dispo=0;
}