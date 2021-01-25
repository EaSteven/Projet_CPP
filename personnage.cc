#include "personnage.hh"

Personnage::Personnage(const std::string str)
{
	if (!texture.loadFromFile(str))
	{
		std::cout << "erreur load " + str << std::endl;
	}

	sprite.setTexture(texture);
}

Personnage::~Personnage(){};