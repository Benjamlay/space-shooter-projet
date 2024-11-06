#ifndef ENNEMISHIPMANAGER_H
#define ENNEMISHIPMANAGER_H

#include "ennemi_space_ship.h"
#include "space_ship.h"

class ennemiShipManager : public sf::Drawable
{
	std::vector<ennemi_space_ship> ennemi_ships_;

public:


	std::vector<ennemi_space_ship>& get_ennemi_ships();
	void Spawn(ennemi_space_ship spawn_position);
	void Refresh(float dt, sf::Vector2u window_size);

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif // ENNEMISHIPMANAGER_H
