#pragma once
#include "Framework/GameObject.h"
#include "Framework/Input.h"
#include "Bullet.h"
#include <math.h>
#include <iostream>
#include "Framework/Collision.h"
#include <vector>


class BulletManager : public GameObject
{
public:
	BulletManager();
	~BulletManager();


	void spawn(float x, float y);
	float getPlayerPosX();
	void setPlayerPosX(float x);
	void update(const float& dt);
	void deathCheck();
	void render(sf::RenderWindow* window);
	std::vector<Bullet>* getBullets() { return  &bullet; }
	std::vector<Bullet>& getEnemyBullets() { return eBullet; }
	float PlayerX;


private:

	std::vector<Bullet> bullet;
	std::vector<Bullet> eBullet;
	sf::Texture texture;
	sf::Texture enemyTexture;
	sf::RenderWindow* window;
	
};
