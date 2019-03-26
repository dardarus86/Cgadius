#include "Framework/GameObject.h"
#include "Framework/Input.h"

class BulletManager : public GameObject
{
public:
	BulletManager();
	~BulletManager();


	void spawn();
	void update(float dt);
	void deathCheck();
	void render(sf::RenderWindow* window);

private:


};
