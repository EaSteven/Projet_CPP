#pragma once

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "arme.hh"

class Missile : public Arme
{
	public:
		Missile(const std::string str);
		~Missile();
};