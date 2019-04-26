#include "EnemyManager.h"

EnemyManager::EnemyManager()
{

	Enemygreytexture.loadFromFile("gfx/enemyship1.png");
	Enemygreentexture.loadFromFile("gfx/enemyship2.png");
	Enemypurpletexture.loadFromFile("gfx/enemyship3.png");
	audioManager.addSound("sfx/enemydeath.wav", "enemydeath");
	for (int i = 0; i < 47; i++)
	{
		Enemygrey.push_back(Enemy());
		Enemygrey[i].setAlive(false);
		Enemygrey[i].setTexture(&Enemygreytexture);
		Enemygrey[i].setSize(sf::Vector2f(60, 50));
		Enemygrey[i].setCollisionBox(0, 0, 60, 50);
		enemygreyhp = 1;

	}

	for (int i = 0; i < 30; i++)
	{
		Enemygreen.push_back(Enemy());
		Enemygreen[i].setAlive(false);
		Enemygreen[i].setTexture(&Enemygreentexture);
		Enemygreen[i].setSize(sf::Vector2f(60, 50));
		Enemygreen[i].setCollisionBox(0, 0, 60, 50);
		enemygreenhp = 2;

	}

	for (int i = 0; i < 19; i++)
	{
		Enemypurple.push_back(Enemy());
		Enemypurple[i].setAlive(false);
		Enemypurple[i].setTexture(&Enemypurpletexture);
		Enemypurple[i].setSize(sf::Vector2f(60, 50));
		Enemypurple[i].setCollisionBox(0, 0, 60, 50);
		enemypurplehp = 3;
	}
}

EnemyManager::~EnemyManager()
{}



void EnemyManager::update(float dt)
{
	std::vector<Wall> walls1 = wallManager->getWalls1();
	std::vector<Wall> walls2 = wallManager->getWalls2();
	std::vector<Bullet>* bullet1 = bulletManager->getBullets();
	/////// WALL COLLISION  /////////
	for (auto& wall : walls1)
	{
		for (auto& enemy : Enemygrey)
		{
			if (Collision::checkBoundingBox(&enemy, &wall))
			{

 				enemy.setVelocity(0, enemy.getVelocity().y * (-1));
				// AHH COLLISION!!!!
			}
		}
	}

	for (auto& wall2 : walls2)
	{
		for (auto& enemy : Enemygrey)
		{
			if (Collision::checkBoundingBox(&enemy, &wall2))
			{
				enemy.setVelocity(0, enemy.getVelocity().y * (-1));
				// AHH COLLISION!!!!
			}
		}
	}

	for (auto& wall2 : walls2)
	{
		for (auto& enemy : Enemygreen)
		{
			if (Collision::checkBoundingBox(&enemy, &wall2))
			{
				enemy.setVelocity(0, enemy.getVelocity().y * (-1));
				// AHH COLLISION!!!!
			}
		}
	}

	for (auto& wall2 : walls2)
	{
		for (auto& enemy : Enemypurple)
		{
			if (Collision::checkBoundingBox(&enemy, &wall2))
			{
				enemy.setVelocity(0, enemy.getVelocity().y * (-1));
				// AHH COLLISION!!!!
			}
		}
	}

	/////// BULLET COLLISION  /////////

	for (auto& bullet : *bullet1)
	{
		for (auto& enemy : Enemygrey)
		{
			if (Collision::checkBoundingBox(&enemy, &bullet))
			{
				if (enemy.isAlive())
				{
					
					enemy.setAlive(false);
					audioManager.playSoundbyName("enemydeath");
					bullet.setAlive(false);
				}
			}
		}
	}

	
	//call update on all ALIVE enemies
	for (int i = 0; i < Enemygrey.size(); i++)
	{
		Enemygrey[i].update(dt);
	}

	for (int i = 0; i < Enemygreen.size(); i++)
	{
		Enemygreen[i].update(dt);
	}
	

	for (int i = 0; i < Enemypurple.size(); i++)
	{
		Enemypurple[i].update(dt);
	}
	deathCheck();
	
}

//spawn new ball
//find a dead ball, make alive, move to spawn point, give random velocity
void EnemyManager::spawn()
{
//wave 1 top 4
	Enemygrey[0].setPosition(260, 300);
	Enemygrey[1].setPosition(310, 240);
	Enemygrey[2].setPosition(380, 215);
	Enemygrey[3].setPosition(460, 210);
//wave 1 bottom 8
	Enemygrey[5].setPosition(260, 420);
	Enemygrey[6].setPosition(310, 480);
	Enemygrey[7].setPosition(380, 520);
	Enemygrey[8].setPosition(460, 520);
//wave 2 top 12
	Enemygrey[10].setPosition(840, 240);
	Enemygrey[11].setPosition(910, 180);
	Enemygrey[12].setPosition(910, 240);
	Enemygrey[13].setPosition(910, 300);
//wave 2 bottom 16
	Enemygrey[14].setPosition(980,  480);
	Enemygrey[15].setPosition(1050, 420);
	Enemygrey[16].setPosition(1050, 480);
	Enemygrey[17].setPosition(1050, 540);
//wave 3 first grey 25
	Enemygrey[18].setPosition(2080, 300);
	Enemygrey[19].setPosition(2150, 300);
	Enemygrey[20].setPosition(2220, 300);
	Enemygrey[21].setPosition(2290, 300);
	Enemygrey[22].setPosition(2080, 360);
	Enemygrey[23].setPosition(2290, 360);
	Enemygrey[24].setPosition(2080, 420);
	Enemygrey[25].setPosition(2150, 420);
	Enemygrey[26].setPosition(2220, 420);
	Enemygrey[27].setPosition(2290, 420);
//wave 3 first green 27
	Enemygreen[0].setPosition(2150, 360);
	Enemygreen[1].setPosition(2220, 360);
//wave 3 second green 32
	Enemygreen[2].setPosition(2460, 360);
	Enemygreen[3].setPosition(2520, 300);
	Enemygreen[4].setPosition(2580, 240);
	Enemygreen[5].setPosition(2520, 420);
	Enemygreen[6].setPosition(2580, 480);
//wave 4 top 36
	Enemygreen[7].setPosition(3000, 240);
	Enemygreen[8].setPosition(3060, 180);
	Enemygreen[9].setPosition(3060, 300);
Enemypurple[0].setPosition(3120, 240);
//wave 4 bot 40
	Enemygreen[10].setPosition(3000, 420);
	Enemygreen[11].setPosition(3060, 360);
	Enemygreen[12].setPosition(3060, 480);
Enemypurple[1].setPosition(3120, 420);
//wave 5 49
	Enemypurple[2].setPosition(3570, 110);
	Enemypurple[3].setPosition(3570, 170);
	Enemypurple[4].setPosition(3570, 490);
	Enemypurple[5].setPosition(3750, 320);
	Enemypurple[6].setPosition(3750, 490);
	Enemypurple[7].setPosition(3750, 620);
	Enemypurple[8].setPosition(3970, 110);
	Enemypurple[9].setPosition(3970, 170);
	Enemypurple[10].setPosition(3890, 490);
//wave 6 19 68
Enemygrey[28].setPosition(4560, 130);
	Enemygrey[29].setPosition(4490, 185);
	Enemygrey[30].setPosition(4560, 245);
	Enemygrey[31].setPosition(4560, 305);
	Enemygrey[32].setPosition(4490, 365);
	Enemygrey[33].setPosition(4560, 420);
	Enemygrey[34].setPosition(4560, 480);
	Enemygrey[35].setPosition(4490, 540);
	Enemygrey[36].setPosition(4560, 600);
Enemygreen[13].setPosition(4550, 365);
	Enemygreen[14].setPosition(4620, 305);
	Enemygreen[15].setPosition(4620, 420);
	Enemygreen[16].setPosition(4680, 245);
	Enemygreen[17].setPosition(4680, 480);
Enemypurple[11].setPosition(4760, 180);
	Enemypurple[12].setPosition(4760, 240);
	Enemypurple[13].setPosition(4760, 300);
	Enemypurple[14].setPosition(4760, 360);
	Enemypurple[15].setPosition(4760, 420);
	Enemypurple[16].setPosition(4760, 480);
	Enemypurple[17].setPosition(4760, 540);
//wave 7 21
Enemygrey[37].setPosition(5160, 240);
	Enemygrey[38].setPosition(5220, 300);
	Enemygrey[39].setPosition(5280, 360);
	Enemygrey[40].setPosition(5280, 480);
	Enemygrey[41].setPosition(5220, 540);
	Enemygrey[42].setPosition(5160, 600);
	Enemygrey[43].setPosition(5400, 360);
	Enemygrey[44].setPosition(5460, 300);
	Enemygrey[45].setPosition(5400, 480);
	Enemygrey[46].setPosition(5460, 540);
Enemygreen[18].setPosition(5160, 420);
	Enemygreen[19].setPosition(5220, 420);
	Enemygreen[20].setPosition(5280, 420);
	Enemygreen[21].setPosition(5400, 420);
	Enemygreen[22].setPosition(5460, 420);
Enemygreen[23].setPosition(5340, 240);
	Enemygreen[24].setPosition(5340, 300);
	Enemygreen[25].setPosition(5340, 360);
	Enemygreen[26].setPosition(5340, 480);
	Enemygreen[27].setPosition(5340, 540);
	Enemygreen[28].setPosition(5340, 600);
	Enemypurple[18].setPosition(5340, 420);

	for (int i = 0; i < Enemygrey.size(); i++)
	{
		if (!Enemygrey[i].isAlive())
		{
			Enemygrey[i].setAlive(true);
			Enemygrey[i].setVelocity(0, 50);
			Enemygrey[i].setPosition(260, 300);
			return;
		}
	}

	for (int i = 0; i < Enemygreen.size(); i++)
	{
		if (!Enemygreen[i].isAlive())
		{
			Enemygreen[i].setAlive(true);
			Enemygreen[i].setVelocity(0, 50);
			Enemygreen[i].setPosition(0, -100);
			return;
		}
	}

	for (int i = 0; i < Enemypurple.size(); i++)
	{
		if (!Enemypurple[i].isAlive())
		{
			Enemypurple[i].setAlive(true);
			Enemypurple[i].setVelocity(0, 50);
			Enemypurple[i].setPosition(0, -100);
			return;
		}
	}

}


void EnemyManager::deathCheck(){}


//Render all alive asteroids
void EnemyManager::render(sf::RenderWindow* window)
{
	for (int i = 0; i < Enemygrey.size(); i++)
	{
		if (Enemygrey[i].isAlive())
		{
			window->draw(Enemygrey[i]);
		}
	}
	for (int i = 0; i < Enemygreen.size(); i++)
	{
		if (Enemygreen[i].isAlive())
		{			
			window->draw(Enemygreen[i]);
		}
	}
	for (int i = 0; i < Enemypurple.size(); i++)
	{
		if (Enemypurple[i].isAlive())
		{
			window->draw(Enemypurple[i]);
		}
	}


}
