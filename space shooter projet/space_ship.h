#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <iostream>
#include <SFML/Graphics.hpp>

class space_ship : public sf::Drawable, public sf::Transformable
{
protected:

	sf::Sprite ship_sprite;
	sf::Texture texture_sprite;
	//TODO float PV;
	float speed_ = 500.0f;
	float isDamaged_;
	float damage_cool_down_;
	bool isAlive;
	sf::Clock damage_clock;

public:

	space_ship();
	void MoveSpaceship(sf::Vector2f direction, float dt);
	sf::FloatRect get_hit_box();
	void GetDamage();
	void refresh(float dt);

protected:

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
#endif // SPACESHIP_H
