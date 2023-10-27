#pragma once
#include <SFML/Graphics.hpp>
class Map
{
	sf::Texture map;
	sf::Sprite sprite;
public:
	Map();
	~Map();


	void Initialize();  //<- called once
	void Load(); //<- called once
	void Update(float deltaTime); //<-update once per frame
	void Draw(sf::RenderWindow& window); //<- draw once per frame
};

