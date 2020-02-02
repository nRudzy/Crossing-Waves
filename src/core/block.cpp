#include "block.h"

Block::Block()
{
    walltaille.x = 128;
    walltaille.y = 128;
    wallBody.setSize(walltaille);
    wallBody.setFillColor(sf::Color::White);
    wallTexture.loadFromFile("data/block4.png");
    wallSprite.setTexture(wallTexture);
    wallSprite.setTextureRect(sf::IntRect(0, 0 , walltaille.x , walltaille.y));

    wall_hitBuffer.loadFromFile("data/hit_wall.wav");
    wallHit.setBuffer(wall_hitBuffer);
    wallHit.setVolume(40);

    groundtaille.x = 516;
    groundtaille.y = 516;
    groundBody.setSize(groundtaille);
    groundBody.setFillColor(sf::Color::White);
    groundTexture.loadFromFile("data/ground4.jpg");
    groundSprite.setTexture(groundTexture);
    groundSprite.setTextureRect(sf::IntRect(0, 0 , groundtaille.x , groundtaille.y));
}

void Block::updateWall()
{
    wallSprite.setPosition(wallBody.getPosition());
}

void Block::updateGround()
{
    groundSprite.setPosition(groundBody.getPosition());
}
