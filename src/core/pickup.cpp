#include "pickup.h"

PickUp::PickUp()
{
    taille.x = 32;
    taille.y = 32;
    coinBody.setSize(taille);
    coinBody.setFillColor(sf::Color::White);
    coinTexture.loadFromFile("data/coin.png");
    coinSprite.setTexture(coinTexture);
    coinSprite.setTextureRect(sf::IntRect(0, 0 , taille.x , taille.y));

    coin_dropBuffer.loadFromFile("data/coin-drop-4.wav");
    coinDrop.setBuffer(coin_dropBuffer);
    coinDrop.setVolume(50);


    coin_pickBuffer.loadFromFile("data/coin-pick.wav");
    coinPick.setBuffer(coin_pickBuffer);
    coinPick.setVolume(15);

    taille2.x = 24;
    taille2.y = 24;
    heartBody.setSize(taille);
    heartBody.setFillColor(sf::Color::White);
    heartTexture.loadFromFile("data/heart.png");
    heartSprite.setTexture(heartTexture);
    heartSprite.setTextureRect(sf::IntRect(0, 0 , taille2.x , taille2.y));

    heart_pickBuffer.loadFromFile("data/heart.wav");
    heartPick.setBuffer(heart_pickBuffer);
    heartPick.setVolume(50);

}

void PickUp::updateCoin()
{
    coinSprite.setPosition(coinBody.getPosition());
}

void PickUp::updateHeart()
{
    heartSprite.setPosition(heartBody.getPosition());
}

