#include <SFML/Graphics.hpp>
#include "vaisseau.hh"
#include "background.hh"
#include "vague.hh"


int main()
{
	Personnage stop("over.png");
	stop.sprite.setPosition(200.f,200.f);

	sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
	window.setFramerateLimit(60);
	
	Background space("space_2.jpeg");

	Vaisseau ship("ship_1.png");

	Vague *test= new Vague("alien_1.png","alien_2.png","alien_3.png");

	while (window.isOpen())
	{

		if(!test->isAlive())
		{
			delete test;
			test= new Vague("alien_1.png","alien_2.png","alien_3.png");
		}

		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				// fenêtre fermée
				case sf::Event::Closed:
					window.close();
					break;

				// touche pressée
				case sf::Event::KeyPressed:
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
					{
						ship.move_haut();
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
					{
						ship.move_droite();
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
					{
						ship.move_bas();
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
					{
						ship.move_gauche();
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
					{
						ship.move_gauche();
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
					{
						ship.arme2.tire();
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
					{
						ship.arme1.tire();
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					{
						window.close();
					}
					break;

				// on ne traite pas les autres types d'évènements
				default:
					break;
			}
		}

		window.clear();
		window.draw(space.sprite);

		if(!ship.arme2.dispo)
			window.draw(ship.arme2.sprite);

		if(!ship.arme1.dispo)
			window.draw(ship.arme1.sprite);

		for( size_t j = 0; j<10*test->cpt; j++)
		{
			if(test->v[j].isAlive())
				window.draw(test->v[j].sprite);
		}
		window.draw(ship.sprite);

		if(!ship.alive)
		{
			window.draw(stop.sprite);
		}
		window.display();

		if(ship.alive)
		{
			test->deplaceAlien();
			ship.updatearme(ship.arme1);
			ship.updatearme(ship.arme2);
			test->updatestatus(ship.arme1);
			test->updatestatus(ship.arme2);
			test->updategamestatus(ship);
		}
	}

	return 0;
}