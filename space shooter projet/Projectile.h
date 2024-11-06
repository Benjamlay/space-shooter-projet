#ifndef PROJECTILES_H
#define PROJECTILES_H
#include <SFML/Graphics.hpp>

class Projectile : public sf::Drawable, public sf::Transformable
{
protected:
	static sf::Texture Laser_texture_;
	sf::Vector2f direction_;
	sf::Sprite Laser_Sprite_;

	bool IsDead_ = false;
	sf::Time lifetime_;

public:
	Projectile() = default;
	Projectile(const sf::Vector2f& spawn_position);
	void Move(float dt, sf::Vector2u& window_size);
	bool IsDead() const { return IsDead_; }
	sf::FloatRect get_hit_box() const;



protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
#endif // PROJECTILES_H



//potentiellement faire une hiérarchie de class pour les Projectile du player et des ennemis par exemple