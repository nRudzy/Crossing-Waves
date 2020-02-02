#include "ennemi.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
/*
Ennemi::Ennemi()
{
    x = 5;
    y = 5;
    direction = 0;
    vivant = true;
}

void Ennemi::gauche(const Terrain &t)
{
    if(t.estPositionEnnemiValide(x-1,y)) x--;
}

void Ennemi::droite(const Terrain &t)
{
    if(t.estPositionEnnemiValide(x+1,y)) x++;
}

void Ennemi::haut(const Terrain &t)
{
    if(t.estPositionEnnemiValide(x,y-1)) y--;
}

void Ennemi::bas(const Terrain &t)
{
    if(t.estPositionEnnemiValide(x,y+1)) y++;
}

int Ennemi::getX() const
{
    return x;
}

int Ennemi::getY() const
{
    return y;
}

void Ennemi::goVersHeros(const Terrain & t, const Heros & h)
{
    int directionx = h.getX() - x;
    int directiony = h.getY() - y;

    if (directionx > 0) directionx = 1;
    if (directionx < 0) directionx = -1;
    if (directiony > 0) directiony = 1;
    if (directiony < 0) directiony = -1;

    if (t.estPositionEnnemiValide(x + directionx , y + directiony))
    {
        x = x + directionx;
        y = y + directiony;
    }
}
*/

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------

Ennemi::Ennemi()
{
    taille.x = 96;
    taille.y = 96;
    ennemiBody.setSize(taille);
    ennemiBody.setFillColor(sf::Color::White);
    ennemiTexture.loadFromFile("data/enemy.png");
    ennemiSprite.setTexture(ennemiTexture);
    ennemiSprite.setTextureRect(sf::IntRect(0, 0 , taille.x , taille.y));

    ennemi_hitBuffer.loadFromFile("data/cartoon015.wav");
    ennemiHit.setBuffer(ennemi_hitBuffer);
}


void Ennemi::goRight() // pour aller a droite
{
    ennemiSprite.setPosition(ennemiSprite.getPosition().x+vitesseMonster, ennemiSprite.getPosition().y); //(on fait - pour aller a gauche et + pour aller a droite)
}

void Ennemi::goLeft() // pour aller a gauche
{
    ennemiSprite.setPosition(ennemiSprite.getPosition().x-vitesseMonster, ennemiSprite.getPosition().y); //(on fait - pour aller a gauche et + pour aller a droite)
}

void Ennemi::goUp() // pour aller en haut
{
    ennemiSprite.setPosition(ennemiSprite.getPosition().x, ennemiSprite.getPosition().y-vitesseMonster); //(on fait - pour aller a gauche et + pour aller a droite)
}

void Ennemi::goDown() // pour aller en bas
{
    ennemiSprite.setPosition(ennemiSprite.getPosition().x, ennemiSprite.getPosition().y+vitesseMonster); //(on fait - pour aller a gauche et + pour aller a droite)
}

void Ennemi::update()
{
    ennemiText.setPosition(ennemiSprite.getPosition().x - ennemiBody.getSize().x+120 , ennemiSprite.getPosition().y - ennemiBody.getSize().y/2+20);
}

void Ennemi::updateMovement()
{
    srand(time(NULL));

    if (counterEnnemi >= 4)
    {
        counterEnnemi = 0;
    }

    if(direction == 2) // Quand on appuie sur Z
    {
        if (canMoveUp == true)
        {
            goUp();
            ennemiSprite.setTextureRect(sf::IntRect(taille.x*counterEnnemi, taille.y*3 , taille.x, taille.y));
            counterEnnemi++;

            canMoveUp = true;
            canMoveDown = true;
            canMoveLeft = true;
            canMoveRight = true;
        }

    }
    else if(direction == 4) // Quand on appuie sur S
    {
        if (canMoveDown == true)
        {
            goDown();
            ennemiSprite.setTextureRect(sf::IntRect(taille.x*counterEnnemi, taille.y*0 , taille.x, taille.y));
            counterEnnemi++;

            canMoveUp = true;
            canMoveDown = true;
            canMoveLeft = true;
            canMoveRight = true;
        }
    }
    else if(direction == 1) // Quand on appuie sur Q
    {

        if (canMoveLeft == true)
        {
            goLeft();
            ennemiSprite.setTextureRect(sf::IntRect(taille.x*counterEnnemi, taille.y , taille.x, taille.y));
            counterEnnemi++;

            canMoveUp = true;
            canMoveDown = true;
            canMoveLeft = true;
            canMoveRight = true;
        }
    }
    else if(direction == 3) // Quand on appuie sur D
    {

        if (canMoveRight == true)
        {
            goRight();
            ennemiSprite.setTextureRect(sf::IntRect(taille.x*counterEnnemi , taille.y*2 , taille.x, taille.y));
            counterEnnemi++;

            canMoveUp = true;
            canMoveDown = true;
            canMoveLeft = true;
            canMoveRight = true;
        }
    }
    else
    {
        // Pas de mouvements
    }

    counter++;
    if (counter >= porteeDeDeplacement)
    {
        direction = rand()%6+1; // rand entre 1 et 6
        counter = 0;
    } // pour appliquer une nouvelle direction
}
