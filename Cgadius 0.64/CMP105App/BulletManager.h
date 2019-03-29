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
	void update(const float& dt);
	void deathCheck(sf::RenderWindow* window1);
	void render(sf::RenderWindow* window);
	std::vector<Bullet>& getBullets() { return bullet; }


private:

	std::vector<Bullet> bullet;
	sf::Texture texture;
	sf::RenderWindow* window;
	
};
