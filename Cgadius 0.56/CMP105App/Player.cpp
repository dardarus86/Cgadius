#include "Player.h"

Player::Player()
{

	idle.addFrame(sf::IntRect(0, 139, 160, 135));
	idle.addFrame(sf::IntRect(159, 139, 160, 135));
	idle.addFrame(sf::IntRect(319, 139, 160, 135));
	idle.addFrame(sf::IntRect(479, 139, 160, 135));
	idle.addFrame(sf::IntRect(639, 139, 160, 135));
	idle.addFrame(sf::IntRect(799, 139, 160, 135));
	idle.addFrame(sf::IntRect(959, 139, 160, 135));
	idle.addFrame(sf::IntRect(1119, 139, 160, 135));
	idle.addFrame(sf::IntRect(1279, 139, 160, 135));
	idle.addFrame(sf::IntRect(1439, 139, 160, 135));
	idle.addFrame(sf::IntRect(1599, 139, 160, 135));
	idle.setFrameSpeed(0.1f);


	forward.addFrame(sf::IntRect(479, 0, 160, 139));
	forward.addFrame(sf::IntRect(639, 0, 160, 139));

	forward.setFrameSpeed(0.1f);

	back.addFrame(sf::IntRect(0, 0, 160, 139));
	back.addFrame(sf::IntRect(159, 0, 160, 139));
	back.addFrame(sf::IntRect(319, 0, 160, 139));
	back.setFrameSpeed(0.1f);

	currentAnimation = &idle;
	setTextureRect(currentAnimation->getCurrentFrame());


}

Player::~Player()
{
}

void Player::handleInput(float dt)
{

	if (input->isKeyDown(sf::Keyboard::Right))
	{
		currentAnimation = &forward;
		setTextureRect(currentAnimation->getCurrentFrame());
		velocity.x = 400;
		velocity.y = 0;
		move(velocity*dt);
	}

	if (input->isKeyDown(sf::Keyboard::Left))
	{
		currentAnimation = &back;
		setTextureRect(currentAnimation->getCurrentFrame());
		velocity.x = -400;
		velocity.y = 0;
		move(velocity*dt);
	}

	if (input->isKeyDown(sf::Keyboard::Up))
	{
		currentAnimation = &idle;
		setTextureRect(currentAnimation->getCurrentFrame());
		velocity.x = 0;
		velocity.y = -400;
		move(velocity*dt);
	}

	if (input->isKeyDown(sf::Keyboard::Down))
	{
		currentAnimation = &idle;
		setTextureRect(currentAnimation->getCurrentFrame());
		velocity.x = 0;
		velocity.y = 400;
		move(velocity*dt);
	}

	if (input->isKeyDown(sf::Keyboard::Right) && input->isKeyDown(sf::Keyboard::Space))
	{
		currentAnimation = &forward;
		setTextureRect(currentAnimation->getCurrentFrame());
		velocity.x = 2000;
		velocity.y = 0;
		move(velocity*dt);
	}

	if (input->isKeyDown(sf::Keyboard::Left) && input->isKeyDown(sf::Keyboard::Space))
	{
		currentAnimation = &back;
		setTextureRect(currentAnimation->getCurrentFrame());
		velocity.x = -2100;
		velocity.y = 0;
		move(velocity*dt);
	}

	if (input->isKeyDown(sf::Keyboard::Numpad0))
	{
		
		bullet.setPosition(getPosition().x + 50, getPosition().y + 26);
		}

}

void Player::update(float dt)
{
	bullet.update(dt);
	currentAnimation->animate(dt);
	setTextureRect(currentAnimation->getCurrentFrame());
	// Check for collision with Left of window
	if (getPosition().y <= 100)
	{
		setPosition(getPosition().x, 100);
	}

	if (getPosition().y >= 700)
	{
		setPosition(getPosition().x, 700);
	}

}
