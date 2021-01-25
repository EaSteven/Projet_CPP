#include "vague.hh"

int Vague::cpt = 0;

Vague::Vague(const std::string str1, const std::string str2, const std::string str3):alien1(str1),alien2(str2),alien3(str3)
{
	direction=1;
	std::srand(std::time(nullptr));
	cpt++;
	for( int j = 0; j<10*cpt; j++)
	{
		switch(std::rand()%3)
		{
			case 0:
				v.push_back(alien1);
				break;
			case 1:
				v.push_back(alien2);
				break;
			case 2:
				v.push_back(alien3);
				break;

			default:
				break;
		}
		switch(std::rand()%4)
		{
			case 0:
				v[j].sprite.setColor(sf::Color(255, 0, 0));
				break;
			case 1:
				v[j].sprite.setColor(sf::Color(0, 255, 0));
				break;
			case 2:
				v[j].sprite.setColor(sf::Color(0, 0, 255));
				break;
			default:
				break;
		}
		v[j].sprite.setPosition((j%10)*60.f,-(j/10)*60.f);

		//std::cout << v[j].sprite.getPosition().x << "\t" << v[j].sprite.getPosition().y << std::endl;
	}
	//std::cout << v.size() << std::endl;
}


Vague::~Vague(){};

bool Vague::isAlive()
{
	for(size_t i = 0; i<v.size(); i++)
	{
		if(v[i].isAlive())
			return true;
	}
	return false;
}

void Vague::deplaceAlien()
{
	sf::Vector2f position;

	switch(direction)
	{
		
		case 0:
			position=v[0].sprite.getPosition();
			if(position.x - 3.f >=0)
				this->movegauche();
			else
			{
				direction=1;
				this->verslebas();
			}
			break;

		case 1:
			position=v[9].sprite.getPosition();
			if(position.x + 3.f + 42 <= 800)
				this->movedroite();
			else
			{
				direction=0;
				this->verslebas();
			}
			break;

		default:
			break;

	}
}

void Vague::movedroite()
{
	for(size_t i=0; i<v.size(); i++)
	{
		v[i].sprite.move(3.f,0.f);
	}
}

void Vague::movegauche()
{
	for(size_t i=0; i<v.size(); i++)
	{
		v[i].sprite.move(-3.f,0.f);
	}
}

void Vague::verslebas()
{
	for(size_t i=0; i<v.size(); i++)
	{
		v[i].sprite.move(0.f,20.f);
	}
}

void Vague::updatestatus(Arme& x)
{
	for(size_t i = 0; i<v.size(); i++)
	{
		if(v[i].isAlive())
			v[i].updatestatus(x);
	}
}

void Vague::updategamestatus(Vaisseau& x)
{
	for(size_t i = 0; i<v.size(); i++)
	{
		if(v[i].isAlive())
			v[i].updategamestatus(x);
	}
}