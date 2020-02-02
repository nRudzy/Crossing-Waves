#ifndef PICKUP_H
#define PICKUP_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class PickUp
{
    public :

            bool isCoin = true;
            bool isHeart = true;
            bool destroy = false;

            PickUp();
            void updateCoin();
            void updateHeart();
            int valeurCoin = 25;
            int valeurHeart = 1;

            // coin
            sf::RectangleShape coinBody;
            sf::Sprite coinSprite;
            sf::Texture coinTexture;
            sf::Vector2f taille;

            // coeur
            sf::RectangleShape heartBody;
            sf::Sprite heartSprite;
            sf::Texture heartTexture;
            sf::Vector2f taille2;

            sf::SoundBuffer coin_dropBuffer;
            sf::Sound coinDrop;

            sf::SoundBuffer coin_pickBuffer;
            sf::Sound coinPick;

            sf::SoundBuffer heart_pickBuffer;
            sf::Sound heartPick;
};

#endif
