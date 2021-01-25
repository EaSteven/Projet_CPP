#pragma once

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

class Background
{
	public:
		Background(const std::string str);
		~Background();

		sf::Sprite sprite;

	private:
		sf::Texture texture;
};