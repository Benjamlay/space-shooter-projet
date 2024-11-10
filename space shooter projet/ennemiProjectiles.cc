#include "ennemiProjectiles.h"

#include <iostream>

sf::Texture ennemiProjectiles::Laser_texture_enemy_;

ennemiProjectiles::ennemiProjectiles(const sf::Vector2f& spawn_position)
{
	Laser_texture_enemy_.loadFromFile("assets\\laserBlue01.png");
	Laser_Sprite_.setTexture(Laser_texture_enemy_);
	Laser_Sprite_.setScale(0.95f, 0.95f);
	Laser_Sprite_.setPosition(spawn_position);
	direction_ = { 0, 1300 };
}

void ennemiProjectiles::Move(float dt, sf::Vector2u& window_size)
{
	move(direction_ * dt);
	Laser_Sprite_.setPosition(getPosition());
	sf::Vector2f position = getPosition();
	if (position.x < 0 || position.x > window_size.x || position.y < 0 || position.y > window_size.y)
	{
		IsDead_ = true;
	}
}
