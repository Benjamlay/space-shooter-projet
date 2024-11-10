#ifndef ENNEMIPROJECTILES_H
#define ENNEMIPROJECTILES_H
#include "Projectile.h"

class ennemiProjectiles : public Projectile
{
	static sf::Texture Laser_texture_enemy_;
public:
	ennemiProjectiles(const sf::Vector2f& spawn_position);
	void Move(float dt, sf::Vector2u& window_size);
};
#endif // ENNEMIPROJECTILES_H
