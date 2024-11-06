#include "projectileManager.h"

#include <iostream>


projectileManager::projectileManager()
{
	LaserSound_.loadFromFile("assets\\sound\\laserSound.wav");
	Laser_.setBuffer(LaserSound_);
}

std::vector<Projectile>& projectileManager::getProjectiles()
{
	return projectiles_;
}

void projectileManager::Spawn(const sf::Vector2f& spawn_position)
{
	projectiles_.emplace_back(spawn_position);
	//projectiles_.back().setPosition(spawn_position);
	Laser_.play();
}


bool remove_them(const Projectile& p)
{
	return p.IsDead();
}

void projectileManager::Refresh(float dt, sf::Vector2u window_size)
{
	
	auto removed_elt = std::remove_if(projectiles_.begin(), projectiles_.end(), remove_them);

	for (Projectile& p : projectiles_)
	{
		p.Move(dt, window_size);
	}
	//note : les projectiles disparaissent en sortant de l'écran ! update : en fait je suis pas sur :(
}

size_t projectileManager::getSize()
{
	return projectiles_.size();
}

//Projectile& projectileManager::getProjectile(size_t idx)
//{
//	return projectiles_[idx];
//}

void projectileManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for(const Projectile& p : projectiles_)
	{
		target.draw(p);
	}
}
