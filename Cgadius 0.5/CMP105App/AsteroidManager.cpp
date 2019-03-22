#include "AsteroidManager.h"

AsteroidManager::AsteroidManager()
{

	texture.loadFromFile("gfx/asteroid.png");

	for (int i = 0; i < 15; i++)
	{
		asteroids.push_back(Asteroid());
		asteroids[i].setAlive(false);
		asteroids[i].setTexture(&texture);
		asteroids[i].setSize(sf::Vector2f(40, 35));
		asteroids[i].setCollisionBox(5, 5, 30, 25);

	}
}

AsteroidManager::~AsteroidManager()
{}

void AsteroidManager::update(float dt)
{
	std::vector<Wall> walls1 = wallManager->getWalls1();
	for (auto& wall : walls1)
	{
		for (auto& astroid : asteroids)
		{
			if (Collision::checkBoundingBox(&astroid, &wall))
			{

				astroid.setVelocity(astroid.getVelocity().x, astroid.getVelocity().y  * (-1));
				// AHH COLLISION!!!!
			}
		}
	}

	std::vector<Wall> walls2 = wallManager->getWalls2();
	for (auto& wall2 : walls2)
	{
		for (auto& astroid : asteroids)
		{
			if (Collision::checkBoundingBox(&astroid, &wall2))
			{
				astroid.setVelocity(astroid.getVelocity().x * (-1), astroid.getVelocity().y  * (-1));

				// AHH COLLISION!!!!
			}
		}
	}


	//call update on all ALIVE asteroids
	for (int i = 0; i < asteroids.size(); i++)
	{

		for (int j = 0; j < asteroids.size(); j++)
		{
			if (i != j)
			{


				if (asteroids[i].isAlive())
				{

					if (Collision::checkBoundingBox(&asteroids[i], &asteroids[j]))
					{
						asteroids[i].setVelocity(asteroids[i].getVelocity().x * (-1), asteroids[i].getVelocity().y);
						asteroids[i].setAlive(false);
						asteroids[i].setPosition(0, -100);
						asteroids[j].setVelocity(asteroids[j].getVelocity().x * (-1), asteroids[j].getVelocity().y);

					}

					/*
					if (asteroids[i].getPosition().x < asteroids[j].getPosition().x + 40)
					{
					asteroids[i].setVelocity(asteroids[i].getVelocity().x , asteroids[i].getVelocity().y);
					asteroids[j].setVelocity(asteroids[j].getVelocity().x * (-1), asteroids[j].getVelocity().y * (-1));
					}

					else if (asteroids[i].getPosition().x + 40 > asteroids[j].getPosition().x)
					{
					asteroids[i].setVelocity(asteroids[i].getVelocity().x * (-1), asteroids[i].getVelocity().y);
					asteroids[j].setVelocity(asteroids[j].getVelocity().x, asteroids[j].getVelocity().y * (-1));
					}

					else if (asteroids[i].getPosition().y < asteroids[j].getPosition().y + 35)
					{
					asteroids[i].setVelocity(asteroids[i].getVelocity().x , asteroids[i].getVelocity().y);
					asteroids[j].setVelocity(asteroids[j].getVelocity().x * (-1), asteroids[j].getVelocity().y * (-1));
					}

					else if (asteroids[i].getPosition().y + 35 > asteroids[j].getPosition().y)
					{
					asteroids[i].setVelocity(asteroids[i].getVelocity().x * (-1), asteroids[i].getVelocity().y * (-1));
					asteroids[j].setVelocity(asteroids[j].getVelocity().x * (-1), asteroids[j].getVelocity().y );
					}


					if (asteroids[i].getGlobalBounds().intersects(asteroids[j].getGlobalBounds()))
					{
					asteroids[i].setVelocity(asteroids[i].getVelocity().x * (-1), asteroids[i].getVelocity().y  * (-1));
					asteroids[j].setVelocity(asteroids[j].getVelocity().x * (-1), asteroids[j].getVelocity().y  * (-1));
					}
					*/
					asteroids[i].update(dt);


				}
			}
		}
	}
	deathCheck();
}

//spawn new ball
//find a dead ball, make alive, move to spawn point, give random velocity
void AsteroidManager::spawn()
{


	for (int i = 0; i < asteroids.size(); i++)
	{
		if (!asteroids[i].isAlive())
		{
			asteroids[i].setAlive(true);
			asteroids[i].setVelocity(rand() % 10 - 5, rand() % 10 - 5);
			asteroids[i].setPosition(1500 + (rand() % 500 - 250), 421 + (rand() % 370 - 200));
			return;
		}
	}

}

void AsteroidManager::deathCheck()
{

}


//Render all alive asteroids
void AsteroidManager::render(sf::RenderWindow* window)
{
	for (int i = 0; i < asteroids.size(); i++)
	{
		if (asteroids[i].isAlive())
		{
			window->draw(asteroids[i]);
		}
	}
}
