#include "ennemi_space_ship.h"

ennemi_space_ship::ennemi_space_ship()
{
	texture_sprite.loadFromFile("assets\\playerShip2_blue.png");
	ship_sprite.setTexture(texture_sprite);
	ship_sprite.setScale(0.75f, 0.75f);
	isDamaged_ = false;
}

void ennemi_space_ship::fire_projectile()
{

}

