#ifndef JEU_H
#define JEU_H


#include "heros.h"
#include "terrain.h"
#include "ennemi.h"
#include "balle.h"
#include "pickup.h"
#include "block.h"
#include "../sfml/menu.h"


#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

class Jeu
{
    /*private :

        Terrain ter;
        Heros heros;
        Ennemi ennemi;
        Balle balle;

    public :

        Jeu();

        Terrain & getTerrain();
        Heros & getHeros();
        Ennemi & getEnnemi();
        Balle & getBalle();


        const Terrain & getConstTerrain () const;
        const Heros & getConstHeros() const;
        const Ennemi & getConstEnnemi() const;

        // int getNombreEnnemis() const;

        void actionsAutomatiques();
        void input(const char touche);
        Heros personnage;*/

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------

    // execution du jeu
    public :
        Jeu();
        void run();

    // traitement du jeu
    private :
        bool event();
        void render();
        void update();

    // variables necessaires au jeu
    private :

    public :
        sf::RenderWindow window;
        sf::Font font;
        sf::Text scoreTexte;
        sf::Text hpTexte;
        sf::Text vieTexte;
        sf::View view1;



        // Objets
        Heros personnage;
        Ennemi ennemi;
        PickUp coin;
        PickUp heart;
        Balle projectile;
        Block wall;
        Block ground;

        //variables time
        sf::Clock clock1;
        sf::Clock clock2;
        sf::Clock clock3;


        // Compteurs
        int counter;
        int counter2;

        // Balle vector
        std::vector<Balle>::iterator iter;
        std::vector<Balle> balleArray;


        // Enemmi vector
        std::vector<Ennemi>::iterator iter4;
        std::vector<Ennemi> ennemiArray;

        // Pièces vector
        std::vector<PickUp>::iterator iter11;
        std::vector<PickUp> pickUpArray;

        // Murs vector
        std::vector<Block>::iterator iter14;
        std::vector<Block> wallArray;

        // Terrain vector
        std::vector<Block>::iterator iter16;
        std::vector<Block> groundArray;

        // Coeur vector
        std::vector<PickUp>::iterator iter20;
        std::vector<PickUp> heartArray;

        bool onMenu = true;
        bool en_jeu = false;
        bool pause = false;

        int niveau = 1;

};

#endif //! jeu.h
