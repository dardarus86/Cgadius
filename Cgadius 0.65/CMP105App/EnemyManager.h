#pragma once
#include "Enemy.h"
#include <math.h>
#include <iostream>
#include "Framework/Collision.h"
#include "Framework/GameObject.h"
#include <SFML/Audio.hpp>
#include "Framework/AudioManager.h"
#include <vector>
#include "WallManager.h"
#include "Framework/Animation.h"
#include "BulletManager.h"

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

	void setBulletManager(BulletManager* bm)
	{
		this->bulletManager = bm;
	}


private:
	std::vector<Enemy> Enemygrey;
	std::vector<Enemy> Enemygreen;
	std::vector<Enemy> Enemypurple;
	sf::Texture Enemygreytexture;
	sf::Texture Enemygreentexture;
	sf::Texture Enemypurpletexture;
	WallManager* wallManager;
	BulletManager* bulletManager;
	AudioManager audioManager;
	Animation move;

	int enemygreyhp;
	int enemygreenhp;
	int enemypurplehp;
};
