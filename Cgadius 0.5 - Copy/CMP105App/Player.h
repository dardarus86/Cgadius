#include "Framework/GameObject.h"
#include "Framework/Input.h"
#include "Bullet.h"
#include "Framework/Animation.h"

class Player : public GameObject
{
public:
	Player();
	~Player();

	void handleInput(float dt);
	void update(float dt);
	Bullet* getBullet(){
		return &bullet;
};
	

protected:
	Animation idle;
	Animation back;
	Animation forward;
	Animation* currentAnimation;

private:
	Bullet bullet;




};

