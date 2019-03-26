#pragma once
#include "Wall.h"
#include <math.h>
#include <iostream>
#include "Framework/Collision.h"
#include "Framework/GameObject.h"
#include <vector>

class WallManager
{
public:
	WallManager();
	~WallManager();

	void spawn();
	void render(sf::RenderWindow* window);

	std::vector<Wall>& getWalls1() { return walls1; }
	std::vector<Wall>& getWalls2() { return walls2; }

private:
	std::vector<Wall> walls1;
	std::vector<Wall> walls2;
	GameObject wall3;
	sf::Texture wall1texture;
	sf::Texture wall2texture;
	sf::Texture wall3texture;
};
