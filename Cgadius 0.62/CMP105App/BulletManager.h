#pragma once
#include "Framework/GameObject.h"
#include "Framework/Input.h"
#include "Bullet.h"


class BulletManager : public GameObject
{
public:
	BulletManager();
	~BulletManager();


	void spawn();
	void update(float dt);
	void deathCheck();
	void render(sf::RenderWindow* window);
	std::vector<Bullet>& getBullets() { return bullet; }


private:

	std::vector<Bullet> bullet;
	sf::Texture texture;
	
};
