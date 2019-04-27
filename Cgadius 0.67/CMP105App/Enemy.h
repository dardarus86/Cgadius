#pragma once
#include "Framework/GameObject.h"
#include "Framework/Collision.h"
#include "Framework/Animation.h"
class Enemy : public GameObject
{
public:
	Enemy();
	~Enemy();

	void update(float dt);
	void collision(float dt);

protected:
	Animation idle;
	Animation explosion;
	Animation* currentAnimation;
};