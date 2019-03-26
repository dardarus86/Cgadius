#include "Framework/GameObject.h"
#include "Framework/Input.h"
#include "Bullet.h"
#include "Framework/Animation.h"
#include "WallManager.h"

class Player : public GameObject
{
public:
	Player();
	~Player();

	void handleInput(float dt);
	void update(float dt);
	Bullet* getBullet(){return &bullet;};
	void setPWallManager(WallManager* wm)
	{
		this->wallManager = wm;
	}
	

protected:
	Animation idle;
	Animation back;
	Animation forward;
	Animation* currentAnimation;

private:

	Bullet bullet;
	WallManager* wallManager;
	sf::Vector2f playerCentre;
	sf::Vector2f wallCentre;






};

