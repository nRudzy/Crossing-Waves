#include "jeu.h"
#include "../var/variables.h"
#include "heros.h"
#include "balle.h"
#include "ennemi.h"
#include "pickup.h"
#include "../sfml/menu.h"

#include <vector>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;

/*Jeu::Jeu() : ter(), heros(), ennemi(), balle()
{
    ter.initialisePerso(heros.getX() , heros.getY());
}

Terrain & Jeu::getTerrain()
{
    return ter;
}

Heros & Jeu::getHeros()
{
    return heros;
}

Ennemi & Jeu::getEnnemi()
{
    return ennemi;
}

Balle & Jeu::getBalle()
{
    return balle;
}

const Terrain & Jeu::getConstTerrain() const
{
    return ter;
}

const Heros & Jeu::getConstHeros() const
{
    return heros;
}

const Ennemi & Jeu::getConstEnnemi() const
{
    return ennemi;
}

//const Balle & Jeu::getConstBalle() const
//{
//    return balle;
//}

void Jeu::input(const char touche)
{
    switch(touche)
    {
        case 'g' :
                    heros.gauche(ter);
                    break;
        case 'd' :
                    heros.droite(ter);
                    break;
        case 'h' :
                    heros.haut(ter);
                    break;
        case 'b' :
                    heros.bas(ter);
                    break;



        case 'u' :
                    balle.haut(ter);
                    break;

        case 'n' :
                    balle.bas(ter);
                    break;

        case 'l' :
                    balle.gauche(ter);
                    break;

        case 'r' :
                    balle.droite(ter);
                    break;

    }
}

void Jeu::actionsAutomatiques()
{
    ennemi.goVersHeros(ter,heros);
}*/

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------

Jeu::Jeu():window(sf::VideoMode(window_width, window_height), "Crossing Waves")
{
    sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width/2) - 350, (sf::VideoMode::getDesktopMode().height/2) - 350);
    window.setFramerateLimit(FRAMERATE);


    view1.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
    view1.setCenter(sf::Vector2f(view1.getSize().x/2, view1.getSize().y/2));
    //view1.zoom(1.5f);

}




bool Jeu::event()
{

    sf::Event event;
    Menu menu(window.getSize().x,window.getSize().y);

    while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                return true;

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                return true;

            switch (event.type)
           {    case sf::Event::KeyReleased:

                switch(event.key.code)
                {
                    case sf::Keyboard::Up:
                        menu.MoveUp();
                        break;

                    case sf::Keyboard::Down:
                        menu.MoveDown();
                        break;

                    case sf::Keyboard::Return:

                        switch(menu.GetPressedItem())
                        {
                            case 0:
                                std::cout<<"Bienvenue sur Crossing Waves ! "<<std::endl;
                                onMenu = false;
                                en_jeu = true;
                                break;

                            case 1:
                                std::cout<<"Consultez vos statistiques maintenant ! "<<std::endl;
                                break;

                            case 2:
                                window.close();
                                break;
                        }

                }

                break;
                case sf::Event::Closed: window.close();
                break;
           }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
        {
            if(onMenu)
            {

            }
            else if (en_jeu)
            {
                pause = true;
            }
            else if (pause)
            {
                pause = false;
            }
        }

        }

    return false;
}

void Jeu::update()
{

        srand(time(NULL));
        sf::Time elapsed1 = clock1.getElapsedTime();
        sf::Time elapsed2 = clock2.getElapsedTime();
        sf::Time elapsed3 = clock3.getElapsedTime();

        personnage.input();


        if(sf::Keyboard::isKeyPressed(sf::Keyboard::X))
        {   if(elapsed3.asSeconds() >= 0.5)
            {
                clock3.restart();

                ennemi.ennemiSprite.setPosition(rand()%900+100,rand()%900+100);
                ennemiArray.push_back(ennemi);
            }
        }

        // ON GENERE LES MURS EXTERIEURS
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::N))
        {
            if(elapsed3.asSeconds() >= 0.1)
            {
                clock3.restart();

                for(int i = 0 ; i < 20 ; i++) // MURS HORIZONTAUX DU HAUT
                {
                    wall.wallBody.setPosition((-80 * 10) + (i * 128) , 0);
                    wallArray.push_back(wall);
                }

                for(int j = 0 ; j < 21 ; j++) // MURS VERTICAUX DE GAUCHE
                {
                    wall.wallBody.setPosition((-80 * 10) , 0  + (j * 128) );
                    wallArray.push_back(wall);
                }

                for(int k = 0 ; k < 20 ; k++) // MURS HORIZONTAUX DU BAS
                {
                    wall.wallBody.setPosition((-80 * 10) + (k * 128) , (20 * 128));
                    wallArray.push_back(wall);
                }

                for(int l = 0 ; l < 21 ; l++) // MURS VERTICAUX DE DROITE
                {
                    wall.wallBody.setPosition((80 * 22),(l * 128));
                    wallArray.push_back(wall);
                }

            }
        }

        // ON GENERE LE TERRAIN
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::B))
        {
            if(elapsed3.asSeconds() >= 0.5)
            {
                clock3.restart();

                for(int i = 0 ; i < 5 ; i++)
                {
                    for(int j = 0 ; j < 5 ; j++)
                    {
                        ground.groundBody.setPosition(-770 + (i * 516), 30 + (j * 516));
                        groundArray.push_back(ground);
                    }
                }

            }
        }


        // On genere la position de départ de la balle

        if(elapsed1.asSeconds() >= 0.2)
        {
            clock1.restart();

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                projectile.shotSound.play();
                if(projectile.direction == 1)
                {
                    projectile.bullet.setPosition((personnage.body.getPosition().x-15),(personnage.body.getPosition().y+30));
                }
                else if(projectile.direction == 3)
                {
                    projectile.bullet.setPosition((personnage.body.getPosition().x-15),(personnage.body.getPosition().y+30));
                }
                else if(projectile.direction == 2)
                {
                    projectile.bullet.setPosition((personnage.body.getPosition().x-15),(personnage.body.getPosition().y+20));
                }
                else if(projectile.direction == 4)
                {
                    projectile.bullet.setPosition((personnage.body.getPosition().x-20),(personnage.body.getPosition().y+30));
                }
                projectile.direction = personnage.direction;
                balleArray.push_back(projectile);
            }
        }

        // Si la balle touche un ennemi + position de la balle
        counter = 0;
        for(iter = balleArray.begin() ; iter != balleArray.end() ; iter++)
        {
            counter2 = 0;
            for(iter4 = ennemiArray.begin() ; iter4 != ennemiArray.end() ; iter4++)
            {
                if( balleArray[counter].bullet.getGlobalBounds().intersects(ennemiArray[counter2].ennemiSprite.getGlobalBounds()) )
                {
                    ennemiArray[counter2].ennemiHP--;
                    if(ennemiArray[counter2].ennemiHP <= 0)
                    {
                        ennemiArray[counter2].vivant = false;
                        if(elapsed3.asSeconds() >= 0.5)
                        {
                        clock3.restart();

                        coin.coinDrop.play();

                        coin.coinBody.setPosition(ennemiArray[counter2].ennemiSprite.getPosition().x+15 , ennemiArray[counter2].ennemiSprite.getPosition().y+25); // Piece de gauche haut
                        pickUpArray.push_back(coin);

                        coin.coinBody.setPosition(ennemiArray[counter2].ennemiSprite.getPosition().x+30 , ennemiArray[counter2].ennemiSprite.getPosition().y+25); // Piece de droite haut
                        pickUpArray.push_back(coin);

                        coin.coinBody.setPosition(ennemiArray[counter2].ennemiSprite.getPosition().x+15 , ennemiArray[counter2].ennemiSprite.getPosition().y+45); // Piece de gauche bas
                        pickUpArray.push_back(coin);

                        coin.coinBody.setPosition(ennemiArray[counter2].ennemiSprite.getPosition().x+30 , ennemiArray[counter2].ennemiSprite.getPosition().y+45); // Piece de droite bas
                        pickUpArray.push_back(coin);

                        coin.coinBody.setPosition(ennemiArray[counter2].ennemiSprite.getPosition().x+22 , ennemiArray[counter2].ennemiSprite.getPosition().y+35); // Piece du milieu
                        pickUpArray.push_back(coin);

                        heart.heartBody.setPosition(ennemiArray[counter2].ennemiSprite.getPosition().x , ennemiArray[counter2].ennemiSprite.getPosition().y); // pop de coeur
                        heartArray.push_back(heart);
                        }
                    }
                    balleArray[counter].destroyOnEnnemi = true;
                    ennemiArray[counter2].ennemiHit.play();

                }
                counter2++;
            }

        counter++;
        }

         // Si la balle touche un ennemi + position de la balle
        counter = 0;
        for(iter = balleArray.begin() ; iter != balleArray.end() ; iter++)
        {
            counter2 = 0;
            for(iter14 = wallArray.begin() ; iter14 != wallArray.end() ; iter14++)
            {
                if( balleArray[counter].bullet.getGlobalBounds().intersects(wallArray[counter2].wallBody.getGlobalBounds()) )
                {
                    balleArray[counter].destroyOnWall = true;
                }
                counter2++;
            }

        counter++;
        }

        // On efface la balle lors du contact d'un ennemi
        counter = 0;
        for (iter = balleArray.begin() ; iter != balleArray.end() ; iter++)
        {
            if(balleArray[counter].destroyOnEnnemi)
            {
                balleArray.erase(iter);
                break;
            }

            counter++;

        }

        // On efface la balle lors du contact d'un mur
        counter = 0;
        for (iter = balleArray.begin() ; iter != balleArray.end() ; iter++)
        {

            if(balleArray[counter].destroyOnWall)
            {
                wall.wallHit.play();
                balleArray.erase(iter);
                break;
            }


            counter++;

        }

        // SI LE HEROS TOUCHE UNE PIECE
        counter = 0;
        for(iter11 = pickUpArray.begin() ; iter11 != pickUpArray.end() ; iter11++)
        {
                if( personnage.body.getGlobalBounds().intersects(pickUpArray[counter].coinBody.getGlobalBounds()) )
                {
                        pickUpArray[counter].destroy = true;

                    if(pickUpArray[counter].isCoin)
                    {
                        personnage.score += pickUpArray[counter].valeurCoin;
                    }
                }

        counter++;
        }

        // SI LE HEROS TOUCHE UN COEUR
        counter = 0;
        for(iter20 = heartArray.begin() ; iter20 != heartArray.end() ; iter20++)
        {
                if( personnage.body.getGlobalBounds().intersects(heartArray[counter].heartBody.getGlobalBounds()) )
                {
                    heartArray[counter].destroy = true;

                    if(heartArray[counter].isHeart) // coeur
                    {
                        if (personnage.playerHP >= 2)
                        {
                            personnage.playerHP += 0;
                        }
                        else
                        {
                            personnage.playerHP += heartArray[counter].valeurHeart;

                        }
                    }

                }

        counter++;
        }

        // SI HEROS TOUCHE UN MUR
        counter = 0;
        for(iter14 = wallArray.begin() ; iter14 != wallArray.end() ; iter14++)
        {
                if( personnage.body.getGlobalBounds().intersects(wallArray[counter].wallBody.getGlobalBounds()) )
                {
                    // Hit Wall
                    if (personnage.direction == 2) // Up
                    {
                        personnage.canMoveUp = false;
                        personnage.body.move(0,1);
                    }
                    else if (personnage.direction == 4) // Down
                    {
                        personnage.canMoveDown = false;
                        personnage.body.move(0,-1);
                    }
                    else if (personnage.direction == 1) // Left
                    {
                        personnage.canMoveLeft = false;
                        personnage.body.move(1,0);
                    }
                    else if (personnage.direction == 3) // Right
                    {
                        personnage.canMoveRight = false;
                        personnage.body.move(-1,0);
                    }
                    else
                    {

                    }

                }
        counter++;
        }

        // SI UN ENNEMI TOUCHE UN MUR
        counter = 0;
        for (iter4 = ennemiArray.begin(); iter4 != ennemiArray.end(); iter4++)
        {
            counter2 = 0;
            for (iter14 = wallArray.begin(); iter14 != wallArray.end(); iter14++)
            {

                if (ennemiArray[counter].ennemiSprite.getGlobalBounds().intersects(wallArray[counter2].wallBody.getGlobalBounds()))
                {
                    // Hit Wall
                    if (ennemiArray[counter].direction == 2) // Up
                    {
                        ennemiArray[counter].canMoveUp = false;
                        ennemiArray[counter].ennemiSprite.move(0,1);
                    }
                    else if (ennemiArray[counter].direction == 4) // Down
                    {
                        ennemiArray[counter].canMoveDown = false;
                        ennemiArray[counter].ennemiSprite.move(0,-1);
                    }
                    else if (ennemiArray[counter].direction == 1) // Left
                    {
                        ennemiArray[counter].canMoveLeft = false;
                        ennemiArray[counter].ennemiSprite.move(1,0);
                    }
                    else if (ennemiArray[counter].direction == 3) // Right
                    {
                        ennemiArray[counter].canMoveRight = false;
                        ennemiArray[counter].ennemiSprite.move(-1,0);
                    }
                    else
                    {

                    }
                }

                counter2++;
            }


            counter++;
        }

        // DETRUIRE LA PIECE
        counter = 0;
        for (iter11 = pickUpArray.begin() ; iter11 != pickUpArray.end() ; iter11++)
        {
            if(pickUpArray[counter].destroy)
            {
                coin.coinPick.play();
                pickUpArray.erase(iter11);
                break;
            }
            counter++;

        }
        // DETRUIRE UN COEUR
        counter = 0;
        for (iter20 = heartArray.begin() ; iter20 != heartArray.end() ; iter20++)
        {
            if(heartArray[counter].destroy)
            {
                heart.heartPick.play();
                heartArray.erase(iter20);
                break;
            }
            counter++;
        }

        //DETRUIRE UN MONSTRE
        counter = 0;
        for (iter4 = ennemiArray.begin() ; iter4 != ennemiArray.end() ; iter4++)
        {
            if (!ennemiArray[counter].vivant)
            {
                ennemiArray.erase(iter4);
                break;
            }
            counter++;
        }


        // SI HEROS TOUCHE UN ENNEMI
        if(elapsed2.asSeconds() >= 1.3)
        {
            clock2.restart();

            counter = 0;
            for(iter4 = ennemiArray.begin() ; iter4 != ennemiArray.end() ; iter4++)
            {
                    if( personnage.body.getGlobalBounds().intersects(ennemiArray[counter].ennemiSprite.getGlobalBounds()) )
                    {
                        personnage.playerGetsHit.play();
                        personnage.playerHP--;
                    }
            counter++;
            }
        }

        // SI LE HEROS MEURT
        if(personnage.playerHP <= 0)
        {
            personnage.playerHP = 2;
            personnage.playerVies--;
        }

        if(personnage.playerVies <= 0)
        {
            en_jeu = false;
        }


    //}

        // Partie ici pour mettre a jour les types sf::Text
        // choix de la chaîne de caractères à afficher
        scoreTexte.setString("Score : " + to_string(personnage.score));
        scoreTexte.setPosition(personnage.body.getPosition().x - window.getSize().x / 2, personnage.body.getPosition().y - (window.getSize().y / 2) +25);

        hpTexte.setString("HP : " + to_string(personnage.playerHP));
        hpTexte.setPosition(personnage.body.getPosition().x - window.getSize().x / 2, personnage.body.getPosition().y - window.getSize().y / 2);

        vieTexte.setString("HP : " + to_string(personnage.playerVies));
        vieTexte.setPosition(personnage.body.getPosition().x - window.getSize().x / 2, personnage.body.getPosition().y - window.getSize().y / 2 + 50);




        // SI HEROS TOUCHE UN ENNEMI


}

void Jeu::render()
{
    Menu menu(window.getSize().x,window.getSize().y);

    window.clear();

    if(onMenu)
    {
        menu.draw(window);
    }
    else
    {
        // On bouge ici la caméra en fonction de la position du personnage
        window.setView(view1);
        view1.setCenter(personnage.body.getPosition());

        // ON DESINNE ICI LE TERRAIN
        counter = 0;
        for (iter16 = groundArray.begin() ; iter16 != groundArray.end() ; iter16++)
        {
            groundArray[counter].updateGround(); // On met a jour la piece
            window.draw(groundArray[counter].groundSprite);

            counter++;
        }

        // ON DESINNE ICI LA BALLE
        counter = 0;
        for (iter = balleArray.begin() ; iter != balleArray.end() ; iter++)
        {
            balleArray[counter].update(); // On met a jour la balle
            window.draw(balleArray[counter].bullet);

            counter++;
        }

        //On dessine la piece
        counter = 0;
        for (iter11 = pickUpArray.begin() ; iter11 != pickUpArray.end() ; iter11++)
        {
            pickUpArray[counter].updateCoin(); // On met a jour la piece
            window.draw(pickUpArray[counter].coinSprite);

            counter++;
        }

        //On dessine le coeur
        counter = 0;
        for (iter20 = heartArray.begin() ; iter20 != heartArray.end() ; iter20++)
        {
            heartArray[counter].updateHeart(); // On met a jour le coeur
            window.draw(heartArray[counter].heartSprite);

            counter++;
        }

        // ON DESSINE ICI L'HEROS
        window.draw(personnage.body);

        // ON DESINNE ICI L'ENNEMI
        counter = 0;
        for (iter4 = ennemiArray.begin() ; iter4 != ennemiArray.end() ; iter4++)
        {
            ennemiArray[counter].updateMovement(); // On met a jour la l'ennemi
            window.draw(ennemiArray[counter].ennemiSprite);

            counter++;
        }
        // ON DESINNE ICI LE TEXTE DE L'ENNEMI
        counter = 0;
        for (iter4 = ennemiArray.begin() ; iter4 != ennemiArray.end() ; iter4++)
        {
            ennemiArray[counter].update();
            ennemiArray[counter].ennemiText.setString("HP " + to_string(ennemiArray[counter].ennemiHP) + "/ 3");
            window.draw(ennemiArray[counter].ennemiText);

            counter++;
        }

        // ON DESINNE ICI UN MUR
        counter = 0;
        for (iter14 = wallArray.begin() ; iter14 != wallArray.end() ; iter14++)
        {
            wallArray[counter].updateWall(); // On met a jour la piece
            window.draw(wallArray[counter].wallSprite);

            counter++;
        }


        // DESSINE LE SCORE
        window.draw(scoreTexte);
        window.draw(hpTexte);
        window.draw(vieTexte);
    }



    window.display();
}


void Jeu::run()
{
    sf::Music music1;

        if (!music1.openFromFile("data/music.ogg"))
        {
            //return EXIT_FAILURE;
        }
        music1.setLoop(true);
        music1.setVolume(10);
        music1.play();


            font.loadFromFile("arial.ttf");
            // choix de la police à utiliser
            scoreTexte.setFont(font); // font est un sf::Font
            // choix de la taille des caractères
            scoreTexte.setCharacterSize(24); // exprimée en pixels, pas en points !
            // choix de la couleur du texte
            scoreTexte.setColor(sf::Color::Yellow);

            hpTexte.setFont(font);
            hpTexte.setCharacterSize(24);
            hpTexte.setColor(sf::Color::Green);

            ennemi.font.loadFromFile("arial.ttf");
            ennemi.ennemiText.setFont(ennemi.font);
            ennemi.ennemiText.setCharacterSize(15);
            ennemi.ennemiText.setStyle(sf::Text::Bold);
            ennemi.ennemiText.setColor(sf::Color::Red);

            vieTexte.setFont(font);
            vieTexte.setCharacterSize(24);
            vieTexte.setColor(sf::Color::Red);


        while (!event())
        {
            window.clear(sf::Color::Black);
            if(event())
            break;

            if (!pause && !onMenu && en_jeu)
            update();

            render();
        }


}

