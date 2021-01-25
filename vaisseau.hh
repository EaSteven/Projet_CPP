#pragma once

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "personnage.hh"
#include "missile.hh"
#include "laser.hh"

class Vaisseau : public Personnage
{
	public:
		Vaisseau(const std::string str);
		~Vaisseau();

		void move_haut();
		void move_bas();
		void move_droite();
		void move_gauche();

		void updatearme(Arme& x);

		bool alive;

		Laser arme1;
		Missile arme2;
};