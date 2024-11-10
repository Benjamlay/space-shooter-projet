#ifndef ENNEMISHIPMANAGER_H
#define ENNEMISHIPMANAGER_H

#include "ennemi_space_ship.h"
#include "projectileManager.h"

class projectileManager;

class ennemiShipManager : public sf::Drawable
{
	std::vector<ennemi_space_ship> ennemi_ships_;

public:

	std::vector<ennemi_space_ship>& get_ennemi_ships();
	void Spawn(const sf::Vector2f& spawn_position);
	void Refresh(float dt, sf::Vector2u window_size);
	void fire_projectile(projectileManager ennemi_projectiles, const sf::Vector2u& windowSize);
	bool Is_on_screen(const ennemi_space_ship& enemy, const sf::Vector2u& windowSize);

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif // ENNEMISHIPMANAGER_H
