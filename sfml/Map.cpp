#include "Map.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Map::Map()
{
}

Map::~Map()
{
}

void Map::Initialize()
{
}

void Map::Load()
{
	if (map.loadFromFile("assets/map/textures/map.png"))
	{
		std::cout << "Map has been loaded!" << std::endl;
		sprite.setTexture(map);
	}
	else
	{
		std::cout << "Failed to load the world" << std::endl;
	}
}

void Map::Update(float deltaTime)
{
}

void Map::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}
