#ifndef ASTEROIDES_H
#define ASTEROIDES_H
#include <SFML/Graphics.hpp>

class asteroides : public sf::Drawable, public sf::Transformable
{
	sf::Sprite asteroides_sprite_;
	static sf::Texture asteroides_texture_;
	sf::Vector2f direction_;

	bool IsDead_ = false;


public:

	asteroides(const sf::Vector2f& spawn_position);
	void move(float dt, sf::Vector2u& window_size);
	sf::Vector2f getYSize();
	bool IsDead() const { return IsDead_; }
	sf::FloatRect getHitBox();

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


#endif // ASTEROIDES_H
