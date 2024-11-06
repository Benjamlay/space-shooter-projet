#include "ennemiProjectiles.h"


ennemiProjectiles::ennemiProjectiles()
{
	Laser_texture_.loadFromFile("assets\\laserBlue01.png");
	Laser_Sprite_.setTexture(Laser_texture_);
	direction_ = { 0, 1300 };
}
