#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "Player.h"
#include "skeleton.h"
#include "Framerates.h"
#include "Map.h"
#include "Menu.h"
using namespace std;
using namespace sf;

int main()
{
    //----------------------------INITIALIZE-------------------
    ContextSettings settings;
    settings.antialiasingLevel = 8;
    RenderWindow window(VideoMode(1920, 1080), "RPG GAME", Style::Default, settings);

    window.setFramerateLimit(240);
    //----------------------------INITIALIZE-------------------
    FrameRate frameRate;
    Map map;
    Player player;
    Skeleton skeleton;
    Bullet bullet;

    //----------------------------INITIALIZE-------------------

    frameRate.Initialize();
    map.Initialize();
    player.Initialize();
    skeleton.Initialize();

    //----------------------------INITIALIZE-------------------

    //----------------------------LOAD--------------------
    bullet.Load();
    frameRate.Load();
    map.Load();
    player.Load();
    skeleton.Load();

    //----------------------------LOAD--------------------
    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Time deltaTimeTimer = clock.restart();
        double deltaTime = deltaTimeTimer.asMilliseconds();

        //-----------------------------UPDATE--------------------
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }

        sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));

        frameRate.Update(deltaTime);
        map.Update(deltaTime);
        skeleton.Update(deltaTime);
        player.Update(deltaTime, skeleton, mousePosition);
        bullet.Update(deltaTime);

        //------------------------------UPDATE------------------------------

        //-------------------------------DRAW------------------------------------
        window.clear(Color::Black);
        map.Draw(window);
        frameRate.Draw(window);
        skeleton.Draw(window);
        player.Draw(window);
        frameRate.Draw(window);
        window.display();
        bullet.Draw(window);
    }

    return 0;
}
