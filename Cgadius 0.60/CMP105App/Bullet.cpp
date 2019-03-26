#include "Bullet.h"

Bullet::Bullet()
{
	bullettexture.loadFromFile("gfx/playershot1.png");
	setSize(sf::Vector2f(6, 24));
	setTexture(&bullettexture);
	setVelocity(1000, 0);
	setPosition(0, -50);
}

Bullet::~Bullet()
{
}

void Bullet::update(float dt)
{
	
	move(velocity*dt);

}
