#include "alien.hh"


Alien::Alien(const std::string str):Personnage(str)
{
	sprite.scale(0.05f, 0.05f);
	alive=true;
}

Alien::~Alien(){};

void Alien::updatestatus(Arme& x)
{
	sf::FloatRect pos_alien = this->sprite.getGlobalBounds();
	sf::FloatRect pos_arme = x.sprite.getGlobalBounds();

	bool test = pos_alien.intersects(pos_arme);

	if(test)
	{
		x.dispo=1;
		kill();
	}
}

void Alien::updategamestatus(Vaisseau& x)
{
	sf::FloatRect pos_alien = this->sprite.getGlobalBounds();
	sf::FloatRect pos_vaisseau = x.sprite.getGlobalBounds();

	if(pos_alien.top+pos_alien.height>800)
	{
		if(x.alive)
			x.alive=false;
	}
	bool test = pos_alien.intersects(pos_vaisseau);
	if(test)
	{
		if(x.alive)
			x.alive=false;
	}
}