#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
class Skeleton
{
private:
	sf::Texture texture;

	sf::Text healthText;
	sf::Font font;

	
public:
	sf::Sprite sprite;
	sf::RectangleShape boundingRectangle;
	sf::Vector2i size;

	
public:
	int health;

	Skeleton();
	~Skeleton();

	void ChangeHealth(int hp);

	void Initialize();  //<- called once
	void Load(); //<- called once
	void Update(float deltaTime); //<-update once per frame
	void Draw(sf::RenderWindow& window); //<- draw once per frame


};

