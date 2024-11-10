#include "space_ship.h"

#include <SFML/Graphics/RenderStates.hpp>

sf::Texture space_ship::texture_sprite;

space_ship::space_ship(const sf::Vector2f& position)
{
	texture_sprite.loadFromFile("assets\\playerShip1_orange.png");
	ship_sprite.setTexture(texture_sprite);
	ship_sprite.setScale(0.75f, 0.75f);
	isDamaged_ = false;
	ship_sprite.setPosition(position);

}

void space_ship::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(ship_sprite, states);
}

sf::FloatRect space_ship::get_hit_box()
{
	sf::FloatRect hit_box = ship_sprite.getGlobalBounds();

	hit_box.left += getPosition().x;
	hit_box.top += getPosition().y;
	return hit_box;
}

bool space_ship::is_dead()
{
	return isDead;
}

void space_ship::GetDamage()
{
	isDamaged_ = true;
	damage_cool_down_ = 3.f;
}

void space_ship::refresh(float dt)
{
	if(isDamaged_)
	{
		damage_cool_down_ -= dt;

		int visibilitySwitch = static_cast<int>(damage_cool_down_ * 10) % 2;
		if (visibilitySwitch == 0) {
			ship_sprite.setColor(sf::Color(255, 255, 255, 50)); // Moins opaque
		}
		else {
			ship_sprite.setColor(sf::Color(255, 255, 255, 255));
			//ship_sprite.setColor(sf::Color(255, 255, 255, 50));
		}
	}

	if(damage_cool_down_ <= 0)
	{
		isDamaged_ = false;
		ship_sprite.setColor(sf::Color(255, 255, 255, 255));
	}
}

void space_ship::Move(sf::Vector2f direction, float dt)
{
	move(speed_ * direction * dt);
}


