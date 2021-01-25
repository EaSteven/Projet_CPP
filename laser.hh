#pragma once

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "arme.hh"

class Laser : public Arme
{
	public:
		Laser(const std::string str);
		~Laser();
};