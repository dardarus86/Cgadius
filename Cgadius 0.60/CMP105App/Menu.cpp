#include "Menu.h"



Menu::Menu(sf::RenderWindow* hwnd, Input* in, GameState *state)
{

	window = hwnd;
	input = in;
	gameState = state;
	audioManager.addMusic("sfx/menu.ogg", "menu");
	audioManager.addMusic("sfx/level.ogg", "level");
	audioManager.addMusic("sfx/boss.ogg", "boss");

	// render text
	if (!font.loadFromFile("font/galactic.ttf"))
	{
		std::cout << "Error loading font/n";
	}
	backgroundtexture.loadFromFile("gfx/menu.png");

	backgroundobj.setTexture(&backgroundtexture);
	backgroundobj.setPosition(0, 0);
	backgroundobj.setSize(sf::Vector2f(1200, 800));

	background.addFrame(sf::IntRect(0, 0, 500, 333));
	background.addFrame(sf::IntRect(500,0 , 500, 333));
	background.addFrame(sf::IntRect(1000,0 , 500, 333));
	background.addFrame(sf::IntRect(1500,0, 500, 333));
	background.addFrame(sf::IntRect(2000, 0, 500, 333));
	background.addFrame(sf::IntRect(2500,0, 500, 333));
	background.addFrame(sf::IntRect(3000,0 , 500, 333));
	background.addFrame(sf::IntRect(3500, 0, 500, 333));
	background.addFrame(sf::IntRect(4000,0 , 500, 333));
	background.addFrame(sf::IntRect(4500, 0, 500, 333));
	background.addFrame(sf::IntRect(5000, 0, 500, 333));
	background.addFrame(sf::IntRect(5500,0 , 500, 333));
	background.addFrame(sf::IntRect(6000,0 , 500, 333));
	background.setFrameSpeed(0.1f);

	background.getCurrentFrame();

	text.setFont(font);
	text.setString("CGADIUS");
	text.setCharacterSize(80);
	text.setFillColor(sf::Color::Red);
	text.setPosition(400, 50);

	text2.setFont(font);
	text2.setString("Press Enter to play");
	text2.setCharacterSize(50);
	text2.setFillColor(sf::Color::Red);
	text2.setPosition(350, 150);
}


Menu::~Menu()
{

}


// handle user input
void Menu::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Enter))
	{
		input->setKeyUp(sf::Keyboard::Enter);
		audioManager.stopAllMusic();
		gameState->setCurrentState(State::LEVEL);
	}
}

// Update game objects
void Menu::update(float dt)
{
	if (audioManager.getMusic()->getStatus() == sf::SoundSource::Stopped)
	{
		audioManager.playMusicbyName("menu");
	}
	backgroundobj.setTextureRect(background.getCurrentFrame());
	background.animate(dt);


}

// Render level
void Menu::render()
{
	beginDraw();
	window->draw(backgroundobj);
	window->draw(text);
	window->draw(text2);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Menu::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Menu::endDraw()
{
	window->display();
}