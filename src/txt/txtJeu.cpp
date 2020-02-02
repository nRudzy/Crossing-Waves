#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include "winTxt.h"

#include "../core/jeu.h"

/*void txtAff(WinTXT & win, Jeu & jeu)
{
    const Terrain & ter = jeu.getConstTerrain();
    const Heros & heros = jeu.getConstHeros();
    const Ennemi & enne = jeu.getConstEnnemi();
    Balle & balle = jeu.getBalle();

    int * positionBalleX;
    positionBalleX = new int;
    *positionBalleX = heros.getX();

    int * positionBalleY;
    positionBalleY = new int;
    *positionBalleY = heros.getY();

    balle.setX(*positionBalleX);
    balle.setY(*positionBalleY);


    win.clear();

    //Affichage du terrain
    for (int i=0 ; i<ter.getDimx() ; ++i)
    {
        for (int j=0 ; j<ter.getDimy() ; ++j)
        {
            win.print(i,j,ter.getCharXY(i,j));
        }
    }


    //Affichage de l'ennemi
    win.print(enne.getX(), enne.getY(), 'E');

    //Affichage de la balle
    win.print(balle.getX(), balle.getY() , '*');

    //Affichage du personnage
    win.print(heros.getX(), heros.getY(), 'H');


    // TESTS
    char buffer [8];
    char buffer2 [8];
    char buffer3 [8];
    char buffer4 [8];


    win.print(4,24,"Position X : ");
    win.print(4,25,"Position Y : ");

    win.print(30,24,"Position X : ");
    win.print(30,25,"Position Y : ");

    sprintf(buffer, "%d", heros.getX());
    win.print(17,24, buffer);

    sprintf(buffer2, "%d", heros.getY());
    win.print(17,25, buffer2);

    sprintf(buffer3, "%d", balle.getX());
    win.print(43,24, buffer3);

    sprintf(buffer4, "%d", balle.getY());
    win.print(43,25, buffer4);
    win.draw();
}

void txtBoucle (Jeu & jeu)
{
    WinTXT win ( jeu.getConstTerrain().getDimx() , jeu.getConstTerrain().getDimy() );
    Balle & balle = jeu.getBalle();


    bool ok = true;
    int caractere;

    do
    {
        txtAff(win,jeu);

        #ifdef _WIN32
        Sleep(100)
        #else
        usleep(100000);
        #endif // WIN32

        //jeu.actionsAutomatiques();
        int * positionY;

        int * positionX;

        caractere = win.getCh();
        switch(caractere)
        {
            case 'z':
            case 'Z':
                        jeu.input('h');
                        break;
            case 's':
            case 'S':
                        jeu.input('b');
                        break;
            case 'q':
            case 'Q':
                        jeu.input('g');
                        break;
            case 'd':
            case 'D':
                        jeu.input('d');
                        break;



            case 'o' :
            case 'O' :
                                positionY = new int;
                                *positionY = balle.getY();
                        for(int i = *positionY ; i > *positionY - 8 ; --i)
                        jeu.input('u');
                        delete positionY;
                        break;
            case 'l' :
            case 'L' :
                                positionY = new int;
                                *positionY = balle.getY();
                        for(int j = *positionY ; j < *positionY + 8 ; ++j)
                        jeu.input('n');
                        delete positionY;
                        break;

            case 'k' :
            case 'K' :
                                positionX = new int;
                                *positionX = balle.getX();
                        for(int k = *positionX ; k > *positionX - 8 ; --k)
                        jeu.input('l');
                        delete positionX;
                        break;

            case 'm' :
            case 'M' :
                                positionX = new int;
                                *positionX = balle.getX();
                        for(int l = *positionX ; l < *positionX + 8 ; ++l)
                        jeu.input('r');
                        delete positionX;
                        break;


            case 'w':
            case 'W':

                        ok = false;
                        break;

        }
    }   while (ok);
}*/
