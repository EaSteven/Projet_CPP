#include "background.hh"


Background::Background(const std::string str)
{
	if (!texture.loadFromFile(str))
	{
		std::cout << "erreur loading " + str << std::endl;
	}

	sprite.setTexture(texture);
	sprite.scale(0.2f,0.3f);
}

Background::~Background(){};