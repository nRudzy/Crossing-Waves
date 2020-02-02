#ifndef BLOCK_H
#define BLOCK_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class Block
{
    public :

            sf::RectangleShape wallBody;
            sf::Sprite wallSprite;
            sf::Texture wallTexture;
            sf::Vector2f walltaille;

            sf::SoundBuffer wall_hitBuffer;
            sf::Sound wallHit;

            sf::RectangleShape groundBody;
            sf::Sprite groundSprite;
            sf::Texture groundTexture;
            sf::Vector2f groundtaille;

            Block();

            void updateWall();
            void updateGround();

};

#endif
