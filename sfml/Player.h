#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "skeleton.h"
#include"Bullet.h"
using namespace std;
using namespace sf;

class Player
{
private:
		sf::Texture texture;

		vector<Bullet>bullets;
		float bulletSpeed = 0.5f;

		sf::RectangleShape boundingRectangle;
		sf::Vector2i size;
		float maxFireRate;
		float fireRateTimer;
		float playerSpeed = 5.0f;

public:
		sf::Sprite sprite;
public:
	
	Player();
	~Player();

	void Initialize();  //<- called once
	void Load(); //<- called once
	void Update(float deltaTime, Skeleton&skeleton, sf::Vector2f& mousePosition); //<-update once per frame
	void Draw(sf::RenderWindow& window); //<- draw once per frame


};
