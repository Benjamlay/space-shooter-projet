#include "asteroidesManager.h"

std::vector<asteroides>& asteroidesManager::getAsteroides()
{
	return meteorField_;
}

void asteroidesManager::Spawn(const sf::Vector2f& spawn_position)
{
	meteorField_.emplace_back(spawn_position);
	//meteorField_.back().setPosition(spawn_position);
}

bool remove_them(const asteroides& p)
{
	return p.IsDead();
}

void asteroidesManager::Refresh(float dt, sf::Vector2u window_size)
{
	auto removed_elt = std::remove_if(meteorField_.begin(), meteorField_.end(), remove_them);

	for (asteroides& p : meteorField_)
	{
		p.Move(dt, window_size);
	}
}

void asteroidesManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (const asteroides& p : meteorField_)
	{
		target.draw(p);
	}
}
