#pragma once

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "personnage.hh"
#include "arme.hh"
#include "vaisseau.hh"

class Alien : public Personnage
{
	public:
		Alien(const std::string str);
		~Alien();

		bool isAlive() {return alive;};

		void kill() {alive=false;};

		void updatestatus(Arme& x);

		void updategamestatus(Vaisseau& x);

	private:
		bool alive;
};