#pragma once

#include <string>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <SFML/Graphics.hpp>
#include "alien.hh"

class Vague
{
	public:
		Vague(const std::string str1, const std::string str2, const std::string str3);
		~Vague();

		static int cpt;

		std::vector<Alien> v;

		bool isAlive();

		void deplaceAlien();

		void movedroite();

		void movegauche();

		void verslebas();

		void updatestatus(Arme& x);
	
		void updategamestatus(Vaisseau& x);

	private:
		Alien alien1, alien2, alien3;

		int direction;

};