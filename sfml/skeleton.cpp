#include "skeleton.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

Skeleton::Skeleton() :
	health(100)
{

}
Skeleton::~Skeleton()
{

}
void Skeleton::ChangeHealth(int hp)
{
	health += hp;
	healthText.setString(std::to_string(health));

}

void Skeleton::Initialize()
{
	boundingRectangle.setFillColor(sf::Color::Transparent);
	boundingRectangle.setOutlineColor(sf::Color::Blue);
	boundingRectangle.setOutlineThickness(1);
	boundingRectangle.setSize(sf::Vector2f(64, 64));

	size = sf::Vector2i(64, 64);
}

void Skeleton::Load()
{
	if (font.loadFromFile("assets/Fonts/arial.ttf"))
	{
		std::cout << "Arial.tff font in assets has been loaded successfully!" << std::endl;
		healthText.setFont(font);
		healthText.setString(std::to_string(health));
		
	}
	else
	{
		std::cout << "Failed to load Arial.tff font in assets!" << std::endl;
	}

	if (texture.loadFromFile("assets/skeleton/textures/spritesheet.png"))
	{
		cout << "Player Images Loaded!" << endl;
		sprite.setTexture(texture);
		sprite.setPosition(Vector2f(200, 200));
		healthText.setScale(sf::Vector2f(0.5, 0.5));


		int XIndex = 0;
		int YIndex = 2;


		sprite.setTextureRect(IntRect(XIndex * size.x, YIndex * size.y, size.x, size.y));
		sprite.scale(Vector2f(1, 1));

		sprite.scale(sf::Vector2f(1, 1));
		boundingRectangle.setSize(
			sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));


	}
	else
	{
		cout << "Skeleton Image failed to loaded!" << endl;
	}
}

void Skeleton::Update(float deltaTime)
{
	if (health > 0)
	{
		boundingRectangle.setPosition(sprite.getPosition());
		healthText.setPosition(sprite.getPosition());
	}
}

void Skeleton::Draw(sf::RenderWindow& window)
{
	if (health > 0)
	{
		window.draw(sprite);
		window.draw(boundingRectangle);
		window.draw(healthText);

	}
}
