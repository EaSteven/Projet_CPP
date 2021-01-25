#pragma once

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

class Personnage
{
	public:
		Personnage(const std::string str);
		~Personnage();


		sf::Sprite sprite;
		sf::Texture texture;
};