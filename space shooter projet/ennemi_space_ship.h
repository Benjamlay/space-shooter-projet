#ifndef ENNEMI_SPACE_SHIP_H
#define ENNEMI_SPACE_SHIP_H
#include "space_ship.h"

class ennemi_space_ship : public space_ship
{

	static sf::Texture ennemi_texture_;
	sf::Vector2f direction_;
	sf::Clock Clock_;
	float lastShotTime_;
	float shootInterval_ = 1.5f;
public:

	ennemi_space_ship(const sf::Vector2f& spawn_position);
	void Move(float dt, sf::Vector2u& window_size);
	sf::FloatRect getHitBox();
	bool CanShoot();

protected:

	
};


#endif // ENNEMI_SPACE_SHIP_H
