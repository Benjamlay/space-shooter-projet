#include "ennemiShipManager.h"



std::vector<ennemi_space_ship>& ennemiShipManager::get_ennemi_ships()
{
	return ennemi_ships_;
}

void ennemiShipManager::Spawn(const sf::Vector2f& spawn_position)
{
	ennemi_ships_.emplace_back(spawn_position);
	//ennemi_ships_.back().setPosition(spawn_position);
}

bool remove_them(ennemi_space_ship& p)
{
	return p.is_dead();
}

void ennemiShipManager::Refresh(float dt, sf::Vector2u window_size)
{
	auto removed_elt = std::remove_if(ennemi_ships_.begin(), ennemi_ships_.end(), remove_them);

	for (ennemi_space_ship& p : ennemi_ships_)
	{
		p.Move(dt, window_size);
		//std::cout << "x: " << p.getPosition().x << "y: " << p.getPosition().y << '\n';
	}
	
}

void ennemiShipManager::fire_projectile(projectileManager ennemi_projectiles, const sf::Vector2u& windowSize)
{
	for(auto& enemy : ennemi_ships_)
	{
		if(Is_on_screen(enemy, windowSize) && enemy.CanShoot())
		{
			ennemi_projectiles.Spawn_enemy({50, 50});
		}
	}
}

bool ennemiShipManager::Is_on_screen(const ennemi_space_ship& enemy, const sf::Vector2u& windowSize)
{
	sf::Vector2f position = enemy.getPosition();
	return position.x >= 0 && position.x <= windowSize.x && position.y >= 0 && position.y <= windowSize.y;
}


void ennemiShipManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (const ennemi_space_ship& p : ennemi_ships_)
	{
		target.draw(p);
	}
}
