#include "WallManager.h"

//collisons to be checked

// wall -> asteroids
// wall -> enemies


WallManager::WallManager()
{
	wall1texture.loadFromFile("gfx/wall1.png");
	wall2texture.loadFromFile("gfx/wall2.png");
	wall3texture.loadFromFile("gfx/wall3.png");

	for (int i = 0; i < 4; i++)
	{
		walls1.push_back(Wall());
		walls1[i].setTexture(&wall1texture);
		walls1[i].setSize(sf::Vector2f(150, 125));
		walls1[i].setCollisionBox(0, 0, 150, 125);
	}

	for (int i = 0; i < 7; i++)
	{
		walls2.push_back(Wall());
		walls2[i].setTexture(&wall2texture);
		walls2[i].setSize(sf::Vector2f(600, 50));
		walls2[i].setCollisionBox(0, 0, 600, 50);
		walls2[i].setOutlineColor(sf::Color::Blue);
		walls2[i].setOutlineThickness(5.f);
	}

	wall3.setTexture(&wall3texture);
	wall3.setSize(sf::Vector2f(50, 400));
}

WallManager::~WallManager() {}

//spawn the walls(collidable segments the player can hit)
void WallManager::spawn()
{

	walls1[0].setPosition(500, 340);
	walls1[1].setPosition(1210, 105);
	walls1[2].setPosition(1210, 340);
	walls1[3].setPosition(1210, 571);
	walls2[0].setPosition(1480, 105);
	walls2[1].setPosition(2065, 105);
	walls2[2].setPosition(1480, 646);
	walls2[3].setPosition(2065, 646);
	walls2[4].setPosition(3460, 250);
	walls2[5].setPosition(3460, 400);
	walls2[6].setPosition(3460, 550);
	wall3.setPosition(4160, 225);

}

//Render all alive asteroids
void WallManager::render(sf::RenderWindow* window)
{
	for (int i = 0; i < walls1.size(); i++)
	{
		window->draw(walls1[i]);
	}

	for (int i = 0; i < walls2.size(); i++)
	{
		window->draw(walls2[i]);
	}

	window->draw(wall3);
}
