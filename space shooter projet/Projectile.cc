#include "Projectile.h"

#include <iostream>
sf::Texture Projectile::Laser_texture_;

Projectile::Projectile(const sf::Vector2f& spawn_position)
{
	Laser_texture_.loadFromFile("assets\\laserRed01.png");
	Laser_Sprite_.setTexture(Laser_texture_);
	Laser_Sprite_.setScale(0.95f, 0.95f);
	Laser_Sprite_.setOrigin(-36, 0);
	Laser_Sprite_.setPosition(spawn_position);
	direction_ = { 0, -1300 };
}

void Projectile::Move(float dt, sf::Vector2u& window_size)
{
	Laser_Sprite_.move(direction_ * dt);

	sf::Vector2f position = getPosition();
	if (position.x < 0 || position.x > window_size.x || position.y < 0 || position.y > window_size.y)
	{
		IsDead_ = true;
	}
}

sf::FloatRect Projectile::get_hit_box() const
{
	return Laser_Sprite_.getGlobalBounds();
}


void Projectile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(Laser_Sprite_, states);
}
