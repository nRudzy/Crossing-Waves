/**
    @file struct terrain.h
    @brief Fichier d'en-tête du module Terrain
*/
#ifndef TERRAIN_H
#define TERRAIN_H
/**
   @struct Terrain
   @brief Cette classe est utilisée pour la conception du terrain
*/
class Terrain
{

private :

/**
    @brief Les composantes de la classe Terrain
*/
    int dimx;
    int dimy;
    char ter [100][100];

public :

/**
    @brief Constructeur par défaut de la classe Terrain
*/
     Terrain();

/**
    @brief Récupère le caractere dans la case (x,y)
    @param x : abscisse de la case de l'objet en caractère
    @param y : ordonnée de la case de l'objet en caractère

*/
     char getCharXY (const int x, const int y) const;

/**
    @brief Accesseur : récupère la dimension du terrain en abscisses X
*/
     int getDimx() const;

/**
    @brief Accesseur : récupère la dimension du terrain en ordonnées Y
*/
     int getDimy() const;

/**
    @brief Vérifie si la position du personnage est valide ou non
    @param x : abscisse de la case de l'objet en caractère
    @param y : ordonnée de la case de l'objet en caractère

*/
    bool estPositionPersoValide(const int x, const int y) const;

/**
    @brief Vérifie si la position de l'ennemi est valide ou non
    @param x : abscisse de la case de l'objet en caractère
    @param y : ordonnée de la case de l'objet en caractère

*/
    bool estPositionEnnemiValide(const int x, const int y) const;

    bool estPositionBalleValide(const int x, const int y) const;


    void initialisePerso(const int x, const int y);

};
#endif //! terrain.h
