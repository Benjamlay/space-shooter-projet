#include "asteroides.h"


sf::Texture asteroides::asteroides_texture_;


asteroides::asteroides(const sf::Vector2f& spawn_position)
{
	asteroides_texture_.loadFromFile("assets\\BrownMeteor.png");
	asteroides_sprite_.setTexture(asteroides_texture_);
	asteroides_sprite_.setScale(0.75f, 0.75f);
	asteroides_sprite_.setPosition(spawn_position);
	direction_ = { 70, 300};
}

void asteroides::Move(float dt, sf::Vector2u& window_size)
{
	asteroides_sprite_.move(direction_ * dt);

	sf::Vector2f position = getPosition();
	if (position.x < 0 || position.x > window_size.x || position.y < 0 || position.y > window_size.y);
	{
		IsDead_ = true;
	}
}



sf::Vector2f asteroides::getYSize()
{
	return sf::Vector2f(asteroides_texture_.getSize());
}


sf::FloatRect asteroides::getHitBox()
{
	return asteroides_sprite_.getGlobalBounds();
}

void asteroides::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
	states.transform *= getTransform();
	target.draw(asteroides_sprite_, states);
}
