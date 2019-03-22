#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Framework/Input.h"
#include "Framework/Collision.h"
#include "AsteroidManager.h"
#include "WallManager.h"
#include "EnemyManager.h"
#include "Asteroid.h"
#include "Enemy.h"
#include "Wall.h"
#include "Player.h"

#include <string>
#include <iostream>


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;
	//bullet	
	//View
	sf::View view1;
	//Sound+Music
	sf::SoundBuffer boss;
	sf::Sound sound;
	//background
	GameObject background;
	sf::Texture backgroundtexture;
	//player
	Player player;
	sf::Texture playertexture;
	//wall(white collidable wall objects in level)
	AsteroidManager asteroidManager;
	WallManager wallManager;
	EnemyManager enemyManager;
	
};