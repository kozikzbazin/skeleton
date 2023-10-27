#include "Framerates.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "skeleton.h"
using namespace std;
using namespace sf;



FrameRate::FrameRate():
	timer(0)
{
}
 FrameRate::~FrameRate()
{
}

void FrameRate::Initialize()
{
}

void FrameRate::Load()
{
	if (font.loadFromFile("assets/Fonts/arial.ttf"))
	{
		std::cout << "Arial.tff font in assets has been loaded successfully!" << std::endl;
		frameRateText.setFont(font);
	}
	else
	{
		std::cout << "Failed to load Arial.tff font in assets!" << std::endl;
	}
}

void FrameRate::Update(double deltaTime)
{
	timer += deltaTime;
	if (timer >= 100.0f)
	{
		double fps = 1000.0f / deltaTime;
		frameRateText.setString("FPS: " + std::to_string((int)fps) + " frameTime: " +
			std::to_string((int)deltaTime));
		timer = 0;
	}
}

void FrameRate::Draw(sf::RenderWindow& window)
{
	window.draw(frameRateText);
}
