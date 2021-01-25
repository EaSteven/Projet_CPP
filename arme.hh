#pragma once

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "personnage.hh"

class Arme : public Personnage
{
	public:
		Arme(const std::string str);
		~Arme();

		void tire();

		int dispo;
};