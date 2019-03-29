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
	
		/*bullet[i].setOutlineColor(sf::Color::Green);
		bullet[i].setOutlineThickness(3.f);*/
	}


}
BulletManager::~BulletManager(){}

void BulletManager::spawn(float x, float y)
{
	
	
	for (int i = 0; i < bullet.size(); i++)
	{
		if (!bullet[i].isAlive())
		{
			bullet[i].setPosition(x, y);
			bullet[i].setAlive(true);
			bullet[i].setVelocity(1000,0);
			return;
				
		}
	}
}
void BulletManager::update(const float& dt)
{
	for (int i = 0; i < bullet.size(); i++)
	{
		if (bullet[i].isAlive())
		{
			bullet[i].update(dt);
		}
	}
	deathCheck(this->window);
}
void BulletManager::deathCheck(sf::RenderWindow* window1)
{
	for (int i = 0; i < bullet.size(); i++)
	{
		if (bullet[i].isAlive())
		{
			if (bullet[i].getPosition().x > window1->getSize().x)
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
