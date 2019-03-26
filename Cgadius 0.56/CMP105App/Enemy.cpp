#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{}

void Enemy::update(float dt)
{
	move(velocity*dt);


	if (getPosition().y <= 105 || getPosition().y >= 646)
	{
		velocity = -velocity;
	}

}
