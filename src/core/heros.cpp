#include "heros.h"
#include "../var/variables.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
using namespace std;

/*--------------------------------------------------------------- Mode console ---------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*Heros::Heros()
{
    x = 25;
    y = 15;
}

void Heros::gauche(const Terrain &t)
{
    if(t.estPositionPersoValide(x-1,y)) x--;
}

void Heros::droite(const Terrain &t)
{
    if(t.estPositionPersoValide(x+1,y)) x++;
}

void Heros::haut(const Terrain &t)
{
    if(t.estPositionPersoValide(x,y-1)) y--;
}

void Heros::bas(const Terrain &t)
{
    if(t.estPositionPersoValide(x,y+1)) y++;
}

int Heros::getX() const
{
    return x;
}

int Heros::getY() const
{
    return y;
}*/
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------

/*--------------------------------------------------------------- Mode Graphique ---------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

Heros::Heros()
{   taille.x = 150; // Composante du vecteur taille pour la largeur du personnage
    taille.y = 117; // Composante du vecteur taille pour la hauteur du personnage

    body.setFillColor(sf::Color::White); // Définition du rectangle body en couleur blanche
    bodyTexture.loadFromFile("data/sprite.png"); // Texture appliquée a bodyTexture
    body.setTexture(&bodyTexture); // appliquer la texture à body
    body.setTextureRect(sf::IntRect(0, 0 , taille.x, taille.y)); // appliquer la texture suivant les zones dans l'ordre (x du début de l'image , y du début de l'image , taille de l'image , taille de l'image)
    body.setSize(taille); // on lui applique sa taille
    body.setPosition(window_width / 2, window_height / 2); // position du départ ( ici au milieu de la fenetre car c'est ce qu'on veut au debut de chaque manche)

    counterHeros = 0;

    body.setOrigin(75,58);
    playerHP = 2;
    playerVies = 3;

    player_getsHitBuffer.loadFromFile("data/man_gets_hit.wav");
    playerGetsHit.setBuffer(player_getsHitBuffer);
    playerGetsHit.setVolume(50);
}

void Heros::goRight() // pour aller a droitewindow_width + 520
{
    body.setPosition(body.getPosition().x+vitessePlayer, body.getPosition().y); //(on fait - pour aller a gauche et + pour aller a droite)
}

void Heros::goLeft() // pour aller a gauche
{
    body.setPosition(body.getPosition().x-vitessePlayer, body.getPosition().y); //(on fait - pour aller a gauche et + pour aller a droite)
}

void Heros::goUp() // pour aller en haut
{
    body.setPosition(body.getPosition().x, body.getPosition().y-vitessePlayer); //(on fait - pour aller a gauche et + pour aller a droite)
}

void Heros::goDown() // pour aller en bas
{
    body.setPosition(body.getPosition().x, body.getPosition().y+vitessePlayer); //(on fait - pour aller a gauche et + pour aller a droite)
}


void Heros::input()
{
    if (counterHeros >= 7)
    {
        counterHeros = 0;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) // Quand on appuie sur Z
    {
        if (canMoveUp == true)
        {
            goUp();
            direction = 2;
            body.setTextureRect(sf::IntRect(taille.x*counterHeros, taille.y , taille.x, taille.y));
            counterHeros++;

            canMoveUp = true;
            canMoveDown = true;
            canMoveLeft = true;
            canMoveRight = true;
        }

    }

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) // Quand on appuie sur S
    {
        if (canMoveDown == true)
        {
            goDown();
            direction = 4;
            body.setTextureRect(sf::IntRect(taille.x*counterHeros, taille.y*0 , taille.x, taille.y));
            counterHeros++;

            canMoveUp = true;
            canMoveDown = true;
            canMoveLeft = true;
            canMoveRight = true;
        }

    }

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) // Quand on appuie sur Q
    {
        if (canMoveLeft == true)
        {
            goLeft();
            direction = 1;
            body.setTextureRect(sf::IntRect(taille.x*counterHeros, taille.y*2 , taille.x, taille.y));
            counterHeros++;

            canMoveUp = true;
            canMoveDown = true;
            canMoveLeft = true;
            canMoveRight = true;
        }
    }

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) // Quand on appuie sur D
    {
        if (canMoveRight == true)
        {
            goRight();
            direction = 3;
            body.setTextureRect(sf::IntRect(taille.x*counterHeros , taille.y*3 , taille.x, taille.y));
            counterHeros++;

            canMoveUp = true;
            canMoveDown = true;
            canMoveLeft = true;
            canMoveRight = true;
        }

    }

}
