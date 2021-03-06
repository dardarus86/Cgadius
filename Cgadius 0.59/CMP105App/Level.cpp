#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	player.setInput(input);
	view1.reset(sf::FloatRect(0.f, 0.f, 1200.f, 800.f));
	scoreview.setViewport(sf::FloatRect(0.0f, 0.0f, 0.9f, 0.9f));



	
	//boss.loadFromFile("sfx/boss.ogg");
	music.openFromFile("sfx/boss.ogg");
	music.setVolume(30);

	//sound.setBuffer(boss);
	//sound.setVolume(35);
	
	// initialise game objects
	backgroundtexture.loadFromFile("gfx/background.png");
	playertexture.loadFromFile("gfx/playersprite.png");

	background.setTexture(&backgroundtexture);
	background.setSize(sf::Vector2f(6000, 800));
	background.setPosition(0, 0);

	player.setTexture(&playertexture);
	player.setSize(sf::Vector2f(60, 60));
	player.setPosition(50, 350);

	//text
	if (!font.loadFromFile("font/andromeda.ttf"))
	{
		std::cout << "Error loading font\n";
	}

	score.setFont(font);
	score.setString("Score 0000");
	score.setCharacterSize(50);
	score.setFillColor(sf::Color::Red);
	score.setPosition(150, 20);

	lives.setFont(font);
	lives.setString("Lives 3");
	lives.setCharacterSize(50);
	lives.setFillColor(sf::Color::Red);
	lives.setPosition(500, 20);

	time.setFont(font);
	time.setString("T");
	time.setCharacterSize(50);
	time.setFillColor(sf::Color::Red);
	time.setPosition(800, 20);

	timer.setFont(font);
	timer.setCharacterSize(50);
	timer.setFillColor(sf::Color::Red);



	for (int i = 0; i < 99; i++)
	{
		enemyManager.spawn();

	}

	for (int i = 0; i < 14; i++)
	{
		wallManager.spawn();

	}

	for (int i = 0; i < 20; i++)
	{
		asteroidManager.spawn();

	}

	//asteroid manager pointers
	asteroidManager.setWallManager(&wallManager);
	//enemy manager pointers

	enemyManager.setWallManager(&wallManager);
	player.setPWallManager(&wallManager);


}

Level::~Level()
{
}

// handle user input
void Level::handleInput(float dt)
{

	player.handleInput(dt);

	if (input->isKeyDown(sf::Keyboard::M))
	{
		music.play();
	}
	if (input->isKeyDown(sf::Keyboard::N))
	{
		music.stop();
	}

	if (input->isKeyDown(sf::Keyboard::J))
	{
		music.setVolume(music.getVolume() - 10);
	}
	if (input->isKeyDown(sf::Keyboard::K))
	{
		music.setVolume(music.getVolume() + 10);
	}
	
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
	//class updates
	enemyManager.update(dt);
	asteroidManager.update(dt);
	player.update(dt);

	//view move
	view1.move(0.01f, 0);

//timer on top of screen
	time1 = clock.getElapsedTime();
	seconds = time1.asSeconds();
	std::string timerString = std::to_string(seconds);
	timer.setString(timerString);
	timer.setPosition(850, 20);

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
	window->setView(scoreview);
	window->draw(score);
	window->draw(lives);
	window->draw(time);
	window->draw(timer);

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