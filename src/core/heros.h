/**
    @file struct heros.h
    @brief Fichier d'en-tête du module Heros
*/
#ifndef HEROS_H
#define HEROS_H
#include "terrain.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


/**
   @struct Heros
   @brief Cette classe est utilisée pour la conception du heros
*/

class Heros
{
/**
    @ Paramètres de la classe Heros
*/
    /*private :

        int x, y;

    public :

        Heros();

        void gauche (const Terrain & t);
        void droite (const Terrain & t);
        void haut (const Terrain & t);
        void bas (const Terrain & t);

        int getX() const;
        int getY() const;*/

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
    public :
/**
    @brief Constructeur par défaut de la classe Heros
*/
        Heros();
    public :
/**
    @brief Paramètres privés de la classe Heros qui permettre de le définir ainsi que ses mouvements
*/
    sf::RectangleShape body;
    sf::Sprite bodySprite;
    sf::Texture bodyTexture;
    sf::Vector2f taille;

    sf::SoundBuffer player_getsHitBuffer;
    sf::Sound playerGetsHit;

    int playerHP;
    bool canMoveUp = true;
    bool canMoveDown = true;
    bool canMoveLeft = true;
    bool canMoveRight = true;

    //int playerMAXHP = 10;
    int playerVies;
    int counterHeros;
    int direction = 0; // On va prendre 1 pour gauche, 2 pour haut, 3 pour droite et 4 pour bas
    int score = 0;

    public :
/**
    @brief Fonction publique qui permet de gérer les déplacements du personnage
*/
    void input();


    private :
/**
    @ Procédures privée qui permet de déplacer le personnage vers la droite
*/
    void goRight();

/**
    @ Procédures privée qui permet de déplacer le personnage vers la gauche
*/
    void goLeft();

/**
    @ Procédures privée qui permet de déplacer le personnage vers le haut
*/
    void goUp();

/**
    @ Procédures privée qui permet de déplacer le personnage vers le bas
*/
    void goDown();


};
#endif //! heros.h
