#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	player.setInput(input);
	view1.reset(sf::FloatRect(0.f, 0.f, 1200.f, 800.f));
	boss.loadFromFile("sfx/boss.ogg");
	sound.setBuffer(boss);
	sound.setVolume(35);

	// initialise game objects
	backgroundtexture.loadFromFile("gfx/background.png");
	playertexture.loadFromFile("gfx/playersprite.png");

	background.setTexture(&backgroundtexture);
	background.setSize(sf::Vector2f(6000, 800));
	background.setPosition(0, 0);

	player.setTexture(&playertexture);
	player.setSize(sf::Vector2f(60, 60));
	player.setPosition(50, 350);

	for (int i = 0; i < 99; i++)
	{
		enemyManager.spawn();

	}

	for (int i = 0; i < 14; i++)
	{
		wallManager.spawn();

	}

	for (int i = 0; i < 15; i++)
	{
		asteroidManager.spawn();

	}

	//asteroid manager pointers
	asteroidManager.setWallManager(&wallManager);
	//enemy manager pointers

	enemyManager.setWallManager(&wallManager);


}

Level::~Level()
{
}

// handle user input
void Level::handleInput(float dt)
{
	player.handleInput(dt);



	if (input->isKeyDown(sf::Keyboard::Right) && input->isKeyDown(sf::Keyboard::Space))
	{
		view1.move(dt + 6.0f, 0);
	}

	else  if (input->isKeyDown(sf::Keyboard::Left) && input->isKeyDown(sf::Keyboard::Space))
	{
		view1.move(dt - 5.f, 0);
	}
	if (player.getPosition().x >= 5200)
	{
		view1.reset(sf::FloatRect(4800.f, 0.f, 1200.f, 800.f));
	}

}

// Update game objects
void Level::update(float dt)
{

	enemyManager.update(dt);
	asteroidManager.update(dt);
	player.update(dt);


	view1.move(0.02f, 0);


	/*
	if (player.getPosition().x + player.getSize().x >= 5000)
	{
	view1.move(0.f, 0.f);
	}
	else if (player.getPosition().x + player.getSize().x >= 5000))
	{
	view1.move(0.002f, 0);
	}
	*/

}

// Render level
void Level::render()
{
	beginDraw();
	window->setView(view1);
	window->draw(background);
	wallManager.render(window);
	asteroidManager.render(window);
	enemyManager.render(window);
	window->draw(*player.getBullet());
	window->draw(player);
	endDraw();

}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}