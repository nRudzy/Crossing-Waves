#include "balle.h"
#include "heros.h"
/*
Balle::Balle()
{
    Heros heros;
    setX(heros.getX());
    setY(heros.getY());
}


int Balle::getX() const
{
    return x;
}

int Balle::getY() const
{
    return y;
}

void Balle::setX(int a)
{
    x = a;
}

void Balle::setY(int b)
{
    y = b;
}

void Balle::gauche(const Terrain &t)
{
    if(t.estPositionBalleValide(x-1,y)) x--;
}

void Balle::droite(const Terrain &t)
{
    if(t.estPositionBalleValide(x+1,y)) x++;
}

void Balle::haut(const Terrain &t)
{
    if(t.estPositionBalleValide(x,y-1)) y--;
}

void Balle::bas(const Terrain &t)
{
    if(t.estPositionBalleValide(x,y+1)) y++;
}*/

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------

Balle::Balle()
{
    bullet.setSize(sf::Vector2f(10,10));
    bullet.setPosition(personnage.body.getPosition().x+5500, personnage.body.getPosition().y+3330);
    bullet.setFillColor(sf::Color::White);
    bulletTexture.loadFromFile("data/bullet.png");
    bullet.setTexture(&bulletTexture);

    shot_soundBuffer.loadFromFile("data/9mm.wav");
    shotSound.setBuffer(shot_soundBuffer);
    shotSound.setVolume(10);

}

void Balle::update()
{
    if (direction == 1 ) // Gauche
    {
        bullet.move( -vitesseBalle , 0);
    }

    if (direction == 2 ) // Haut
    {
        bullet.move( 0 , -vitesseBalle);
    }

    if (direction == 3 ) // Droite
    {
        bullet.move( vitesseBalle , 0);
    }

    if (direction == 4 ) // Bas
    {
        bullet.move( 0 , vitesseBalle);
    }

    counterLifeTime++; // Pour que le tir ait une portée
    if (counterLifeTime >= lifeTime) // Si on attein la portée max
    destroyOnEnnemi = true; // On s'en fiche que ce soit ennemi ou pas, tant que ça delete
}
