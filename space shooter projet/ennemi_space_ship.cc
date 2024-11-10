#include "ennemi_space_ship.h"

sf::Texture ennemi_space_ship::ennemi_texture_;

ennemi_space_ship::ennemi_space_ship( const sf::Vector2f& spawn_position)
{
	ennemi_texture_.loadFromFile("assets\\playerShip2_blue.png");
	ship_sprite.setTexture(ennemi_texture_);
	ship_sprite.setScale(0.75f, 0.75f);
	ship_sprite.setRotation(180);
	ship_sprite.setPosition(spawn_position);
	isDamaged_ = false;
	direction_ = { 0, 150 };
	lastShotTime_ = 0.f;
}

void ennemi_space_ship::Move(float dt, sf::Vector2u& window_size)
{
	move(direction_ * dt);
	//ship_sprite.setPosition(getPosition());

	sf::Vector2f position = getPosition();
	if (position.x < 0 || position.x > window_size.x || position.y < 0 || position.y > window_size.y)
	{
		isDead = true;
	}
}

sf::FloatRect ennemi_space_ship::getHitBox()
{
	return ship_sprite.getGlobalBounds();
}

bool ennemi_space_ship::CanShoot()
{
	if (Clock_.getElapsedTime().asSeconds() - lastShotTime_ >= shootInterval_) {
		lastShotTime_ = Clock_.getElapsedTime().asSeconds();
		return true;
	}

	return false;
}


