#include "BulletManager.h"


BulletManager::BulletManager()
{
	texture.loadFromFile("gfx/playerbullet.png");
	for (int i = 0; i < 10; i++)
	{
		bullet.push_back(Bullet());
		bullet[i].setAlive(false);
		bullet[i].setTexture(&texture);
		bullet[i].setSize(sf::Vector2f(6, 24));
	
		bullet[i].setOutlineColor(sf::Color::Green);
		bullet[i].setOutlineThickness(3.f);
	}


}
BulletManager::~BulletManager(){}

void BulletManager::spawn()
{
	
	
	for (int i = 0; i < bullet.size(); i++)
	{
		if (!bullet[i].isAlive())
		{
			bullet[i].setAlive(true);
			bullet[i].setVelocity(1000,0);
			bullet[i].setPosition(100, 400);
			move(velocity);
			return;
				
		}
	}
}
void BulletManager::update(float dt)
{
	
	for (int i = 0; i < bullet.size(); i++)
	{
		if (bullet[i].isAlive())
		{
			bullet[i].update(dt);
		}
	}
	deathCheck();
	
}
void BulletManager::deathCheck()
{
	
	for (int i = 0; i < bullet.size(); i++)
	{
		if (bullet[i].isAlive())
		{
			if (bullet[i].getPosition().x > 700);
			{
				bullet[i].setAlive(false);
			}

		}
	}
}



void BulletManager::render(sf::RenderWindow* window)
{
	for (int i = 0; i < bullet.size(); i++)
	{
		if (bullet[i].isAlive())
		{
			window->draw(bullet[i]);
		}
	}
}
