
#include "Background.h"

Background::Background()
{
	texture_background_.loadFromFile("assets\\blueBigger.png");
	sprite_background_.setTexture(texture_background_);
	
}

void Background::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(sprite_background_, states);
}

void Background::MoveBackground(sf::Vector2f direction, float dt)
{
	{
		float speed = speed_;

		setPosition(getPosition() + speed * direction * dt);
	}
}

float Background::GetImageHeight()
{
	return imageHeight;
}

