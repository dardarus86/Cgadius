#pragma once
#include "Enemy.h"
#include <math.h>
#include <iostream>
#include "Framework/Collision.h"
#include "Framework/GameObject.h"
#include <vector>
#include "WallManager.h"
#include "Framework/Animation.h"

class EnemyManager
{
public:
	EnemyManager();
	~EnemyManager();

	void spawn();
	void update(float dt);
	void deathCheck();
	void render(sf::RenderWindow* window);
	std::vector<Enemy>& getEnemygrey() { return Enemygrey; }
	std::vector<Enemy>& getEnemygreen() { return Enemygreen; }
	std::vector<Enemy>& getEnemypurple() { return Enemypurple; }
	void setWallManager(WallManager* wm)
	{
		this->wallManager = wm;
	}

private:
	std::vector<Enemy> Enemygrey;
	std::vector<Enemy> Enemygreen;
	std::vector<Enemy> Enemypurple;
	sf::Texture Enemygreytexture;
	sf::Texture Enemygreentexture;
	sf::Texture Enemypurpletexture;
	WallManager* wallManager;
	Animation move;

	int enemygreyhp;
	int enemygreenhp;
	int enemypurplehp;
};
