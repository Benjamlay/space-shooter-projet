#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <iostream>
#include <SFML/Graphics.hpp>

class space_ship : public sf::Drawable, public sf::Transformable
{
protected:

	sf::Sprite ship_sprite;
	static sf::Texture texture_sprite;
	//TODO float PV;
	float speed_ = 500.0f;
	float isDamaged_;
	float damage_cool_down_;
	bool isDead;
	sf::Clock damage_clock;

public:

	space_ship(const sf::Vector2f& position = sf::Vector2f(0, 0));
	void Move(sf::Vector2f direction, float dt);
	sf::FloatRect get_hit_box();
	bool is_dead();
	void GetDamage();
	void refresh(float dt);

protected:

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
#endif // SPACESHIP_H
