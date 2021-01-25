#include "vaisseau.hh"


Vaisseau::Vaisseau(const std::string str):Personnage(str),arme1("laser.png"),arme2("missile.png")
{
	sprite.scale(0.1f, 0.1f);
	sprite.setPosition(375,600);
	alive=true;
}

Vaisseau::~Vaisseau(){};

void Vaisseau::move_haut()
{	
	sf::Vector2f position=sprite.getPosition();
	if(position.y - 10.f >= 0)
		sprite.move(0.f,-10.f);
}

void Vaisseau::move_bas()
{
	sf::Vector2f position=sprite.getPosition();
	if(position.y + 10.f + 51 <= 800)
		sprite.move(0.f,10.f);
}

void Vaisseau::move_droite()
{
	sf::Vector2f position=sprite.getPosition();
	if(position.x + 10.f + 51 <= 800)
		sprite.move(10.f,0.f);
}

void Vaisseau::move_gauche()
{
	sf::Vector2f position=sprite.getPosition();
	if(position.x - 10.f >= 0)
		sprite.move(-10.f,0.f);
}

void Vaisseau::updatearme(Arme& x)
{
	sf::Vector2f position=x.sprite.getPosition();
	sf::Vector2f position_vaisseau=sprite.getPosition();
	switch(x.dispo)
	{
		case 0:
			if(position.y<0)
			{
				x.dispo=1;
				x.sprite.setPosition(position_vaisseau.x+18, position_vaisseau.y+10);
			}
			else
			{
				x.sprite.move(0.f,-10.f);
			}
			break;

		case 1:
			x.sprite.setPosition(position_vaisseau.x+18, position_vaisseau.y+10);
			break;

		default:
			break;
	}
}