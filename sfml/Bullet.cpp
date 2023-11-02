#include "Bullet.h"
#include "Skeleton.h"
#include "Math.h"
#include <SFML/Graphics.hpp>
class MAT {
public:
	static const double PI;
};

const double MAT::PI = 3.14159265358979323846;

Bullet::Bullet() :
	m_speed(0),
	rotation(0)
{
	rectangleShape.setSize(sf::Vector2f(70, 70));
}

Bullet::~Bullet()
{
}

void Bullet::Initialize(const sf::Vector2f& position, const sf::Vector2f& target, float speed)
{
	m_speed = speed;

	rectangleShape.setPosition(position);
	direction = Math::NormalizeVector(target - position);
	Load();

}


void Bullet::Update(float deltaTime)
{
	sf::Vector2f newPosition = rectangleShape.getPosition() + direction * m_speed * deltaTime;

	// Sprawdzamy, czy obiekt przekroczył połowę drogi
	if (newPosition.x > (rectangleShape.getPosition().x + direction.x * rectangleShape.getSize().x / 2)) {
		rectangleShape.setSize(sf::Vector2f(70, 70)); // Możesz dostosować rozmiar kwadratu według potrzeb
		rotation += 0.1f * deltaTime; // Prędkość obrotu 45 stopni na sekundę (półtora obrotu na sekundę)
		rectangleShape.setRotation(rotation);
		rectangleShape.setOrigin(rectangleShape.getSize() / 2.0f); // Ustaw punkt obrotu na środek
	}

	rectangleShape.setPosition(newPosition);
}

void Bullet::Draw(sf::RenderWindow& window)
{
	window.draw(rectangleShape);

}

void Bullet::Load()
{
	if (texture.loadFromFile("assets/bullet/bullet.png"))
	{
		rectangleShape.setTexture(&texture);

	}
	else
	{
		std::cout << "Failed to load the bone" << std::endl;
	}
}
