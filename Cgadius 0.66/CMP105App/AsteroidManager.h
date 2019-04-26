#pragma once
#include "Asteroid.h"
#include <math.h>
#include <iostream>
#include "Framework/Collision.h"
#include "Framework/GameObject.h"
#include <vector>
#include "WallManager.h"
#include "EnemyManager.h"
#include "WallManager.h"

class AsteroidManager
{
public:
	AsteroidManager();
	~AsteroidManager();

	void spawn();
	void update(float dt);
	void deathCheck();
	void render(sf::RenderWindow* window);
	void setWallManager(WallManager* wm)
	{
		wallManager = wm;
	}




private:
	std::vector<Asteroid> asteroids;
	sf::Texture texture;
	WallManager* wallManager;
};
