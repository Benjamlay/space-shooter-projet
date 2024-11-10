#ifndef PROJECTILE_MANAGER_H
#define PROJECTILE_MANAGER_H
#include "Projectile.h"
#include <vector>
#include <SFML/Audio.hpp>

#include "ennemiProjectiles.h"


class projectileManager : public sf::Drawable
{
private:

	std::vector<Projectile> projectiles_;
	std::vector<ennemiProjectiles> ennemi_projectiles_;
	sf::SoundBuffer LaserSound_;
	sf::Sound Laser_;

public:

	projectileManager();
	std::vector<Projectile>& getProjectiles();
	std::vector<ennemiProjectiles>& get_E_Projectiles();
	void Spawn(const sf::Vector2f& spawn_position);
	void Spawn_enemy(const sf::Vector2f& spawn_position);
	void Refresh(float dt, sf::Vector2u window_size);
	void Refresh_enemy(float dt, sf::Vector2u window_size);
	size_t getSize();
	//Projectile& getProjectile(size_t idx);


protected:

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;


};



#endif // PROJECTILE_MANAGER_H
