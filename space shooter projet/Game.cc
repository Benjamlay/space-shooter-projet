#include "Game.h"


Game::Game()
{
	window_.create(sf::VideoMode(1280, 680), "Space Shooter");
}

void Game::Loop()
{
    float cooldown = 1.f;
    int pv = 0;
    background2.setPosition(0, -680);

    sf::Clock clock2;
    float meteor_spawn_interval = 0.5f;


    while (window_.isOpen())
    {
        cooldown += dt;

        // commandes du vaisseau ______________________________________________________________________________________________________

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
            ship1.MoveSpaceship(sf::Vector2f(0, -1), dt);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            ship1.MoveSpaceship(sf::Vector2f(0, 1), dt);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
            ship1.MoveSpaceship(sf::Vector2f(-1, 0), dt);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            ship1.MoveSpaceship(sf::Vector2f(1, 0), dt);
        }

        //background defilant :________________________________________________________________________________________________________

        background1.MoveBackground(sf::Vector2f(0, 1), dt);
        if (background1.getPosition().y >= 680){
            background1.setPosition(0, background2.getPosition().y - 680);
        }
        background2.MoveBackground(sf::Vector2f(0, 1), dt);
        if (background2.getPosition().y >= 680){
            background2.setPosition(0, background1.getPosition().y - 680);
        }

        // Tirer des lasers ____________________________________________________________________________________________________________


        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            if(cooldown > 0.15f)
            {
                projectiles_.Spawn(ship1.getPosition());
                cooldown = 0;
            }
        }
        // faire apparaitre des asteroides ____________________________________________________________________________________________

        if(clock2.getElapsedTime().asSeconds() >= meteor_spawn_interval)
        {
            asteroides_.Spawn(sf::Vector2f(rand() % window_.getSize().x, -50.f));
            clock2.restart();
        }

        if (clock2.getElapsedTime().asSeconds() >= meteor_spawn_interval)
        {
	        
        }
        //faire apparaitre des vaisseaux ______________________________________________________________________________________________





        // projectiles et asteroids se rencontrent t-ils ? ____________________________________________________________________________

        for(auto projectileIt = projectiles_.getProjectiles().begin(); projectileIt != projectiles_.getProjectiles().end();){
            bool asteroidDestroyed = false;
            for (auto asteroidesIt = asteroides_.getAsteroides().begin(); asteroidesIt != asteroides_.getAsteroides().end();){
                if (projectileIt->get_hit_box().intersects(asteroidesIt->getHitBox())) {
                    asteroidesIt = asteroides_.getAsteroides().erase(asteroidesIt);
                    projectileIt = projectiles_.getProjectiles().erase(projectileIt);
                    asteroidDestroyed = true;
                    break;
                }else{
                    ++asteroidesIt;
                }
            }if(!asteroidDestroyed){
                ++projectileIt;
            }
        }

        // ship1 rencontre-t-il des asteroids ? ______________________________________________________________________________________

        bool touchedAnAsteroid = false;

        for (auto asteroidesIt = asteroides_.getAsteroides().begin(); asteroidesIt != asteroides_.getAsteroides().end();) {
           if(ship1.get_hit_box().intersects(asteroidesIt->getHitBox())){
               asteroidesIt = asteroides_.getAsteroides().erase(asteroidesIt);
               touchedAnAsteroid = true;
               pv++ * dt;
               std::cout << pv << std::endl;
               break;
           }else{
               ++asteroidesIt;
           }
        }
    	if(touchedAnAsteroid)
    	{
    		ship1.GetDamage();
    	}

        if(pv > 3-1){
            break;
        }
        //_____________________________________________________________________________________________________________________________

    	ship1.refresh(dt);
        projectiles_.Refresh(dt, window_.getSize());
        asteroides_.Refresh(dt, window_.getSize());

        // clear draw display _______________________________________________________________________________________________________________________

    	window_.clear();

        window_.draw(background1);
        window_.draw(background2);
        window_.draw(ship1);
        window_.draw(projectiles_);
        window_.draw(asteroides_);

        window_.display();

        // fermer la fenetre __________________________________________________________________________________________________________

        sf::Event event;
        while (window_.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window_.close();
            }
        }


        dt = clock.restart().asSeconds();
    }
}