#include "Player.h"
#include "skeleton.h"
#include "Math.h"
#include<iostream>
using namespace std;
using namespace sf;


Player::Player() : 
	playerSpeed(1.0f), maxFireRate(300), fireRateTimer(0)
{
}

Player::~Player()
{
}

void Player::Initialize()
{
	boundingRectangle.setFillColor(sf::Color::Transparent);
	boundingRectangle.setOutlineColor(sf::Color::Red);
	boundingRectangle.setOutlineThickness(1);
	boundingRectangle.setSize(sf::Vector2f(64,64));

	size = sf::Vector2i(64, 64);
	sprite.scale(sf::Vector2f(1, 1));

	
}

void Player::Load()
{
	if (texture.loadFromFile("assets/player/textures/spritesheet.png"))
	{
		std::cout << "Player Images Loaded!" << std::endl;
		sprite.setTexture(texture);

		int XIndex = 0;
		int YIndex = 0;

		sprite.setTextureRect(sf::IntRect(XIndex * size.x, YIndex * size.y, size.x, size.y));
		sprite.setPosition(sf::Vector2f(1600, 700));
		sprite.scale(sf::Vector2f(1, 1));
		boundingRectangle.setSize(
			sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
	}
	else
	{
		std::cout << "Player Image failed to loaded!" << std::endl;
	}

}

void Player::Update(float deltaTime,Skeleton& skeleton, sf::Vector2f& mousePosition)
{
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		Vector2f position = sprite.getPosition();
		sprite.setPosition(position + Vector2f(0.2, 0)*playerSpeed * deltaTime);	
	}

	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		Vector2f position = sprite.getPosition();
		sprite.setPosition(position + Vector2f(-0.2, 0) * playerSpeed * deltaTime);
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		Vector2f position = sprite.getPosition();
		sprite.setPosition(position + Vector2f(0, 0.2) * playerSpeed * deltaTime);
	}
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		Vector2f position = sprite.getPosition();
		sprite.setPosition(position + Vector2f(0, -0.2) * playerSpeed * deltaTime);
	}

	//-----------------------------------------------------------
	fireRateTimer += deltaTime;

	if (Mouse::isButtonPressed(Mouse::Left)&&fireRateTimer>=maxFireRate)
	{
		bullets.push_back(Bullet());
		int i = bullets.size() - 1;
		bullets[i].Initialize(sprite.getPosition(), mousePosition,0.5f);

		fireRateTimer = 0;
	}

	for (size_t i = 0; i < bullets.size(); i++)
	{

		//Vector2f bulletDirection = mousePosition - bullets[i].getPosition();
		//bulletDirection = Math::NormalizeVector(bulletDirection);
		//bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed * deltaTime);

		bullets[i].Update(deltaTime);
		if (skeleton.health > 0)
		{

			if (Math::DidRectCollide(bullets[i].GetGlobalBounds(), skeleton.sprite.getGlobalBounds()))
			{
				skeleton.ChangeHealth(-10); //dealing damage while collision
				bullets.erase(bullets.begin() + i); // deleting bullets at collision
			}
		}
	}

	boundingRectangle.setPosition(sprite.getPosition());

}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	window.draw(boundingRectangle);

	for (size_t i = 0; i < bullets.size(); i++)
	{
		bullets[i].Draw(window);
	}
}