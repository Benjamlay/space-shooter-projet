#ifndef ASTEROIDESMANAGER_H
#define ASTEROIDESMANAGER_H
#include <vector>

#include "asteroides.h"

class asteroidesManager : public sf::Drawable
{
	std::vector<asteroides> meteorField_;

public:

	std::vector<asteroides>& getAsteroides();
	void Spawn(const sf::Vector2f& spawn_position);
	void Refresh(float dt, sf::Vector2u window_size);
	size_t getSize();
	asteroides& getAsteroide(size_t idx);

protected:

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


#endif // ASTEROIDESMANAGER_H
