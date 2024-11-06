#include "ennemiShipManager.h"

std::vector<ennemi_space_ship>& ennemiShipManager::get_ennemi_ships()
{
	return ennemi_ships_;
}

void ennemiShipManager::Spawn(ennemi_space_ship spawn_position)
{
	ennemi_ships_.emplace_back(spawn_position);
}

void ennemiShipManager::Refresh(float dt, sf::Vector2u window_size)
{

}

void ennemiShipManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

}
