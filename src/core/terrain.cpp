#include <assert.h>
#include "terrain.h"
/*
using namespace std;

const char terrain[29][51] =
{
    "##################################################",
    "##################################################",
    "##                                              ##",
    "##                                              ##",
    "##                                              ##",
    "##                                              ##",
    "##                                              ##",
    "##                                              ##",
    "##                                              ##",
    "##                                              ##",
    "##                                              ##",
    "##                                              ##",
    "##                                              ##",
    "##                                              ##",
    "##                                              ##",
    "##                                              ##",
    "##                                              ##",
    "##                                              ##",
    "##                                              ##",
    "##                                              ##",
    "##                                              ##",
    "##                                              ##",
    "##                                              ##",
    "##                                              ##",
    "##                                              ##",
    "##################################################",
    "##################################################"
};

Terrain::Terrain()
{
    dimx = 50;
    dimy = 28;
    for (int i = 0 ; i < dimx ; ++i)
    {
        for(int j = 0 ; j < dimy ; ++j)
        {
            ter[i][j] = terrain[dimy-1-j][i];
        }
    }
}

bool Terrain::estPositionPersoValide(const int x, const int y) const
{
    return ( (x>=0) && (x<dimx) && (y>=0) && (y<dimy) && (ter[x][y] != '#'));
}

bool Terrain::estPositionEnnemiValide(const int x, const int y) const
{
    return ( (x>=0) && (x<dimx) && (y>=0) && (y<dimy) );
}

bool Terrain::estPositionBalleValide(const int x, const int y) const
{
    return ( (x>=0) && (x<dimx) && (y>=0) && (y<dimy) && (ter[x][y] != '#'));
}

char Terrain::getCharXY(const int x, const int y) const
{
    assert(x >= 0);
    assert(x < dimx);
    assert(y >= 0);
    assert(y < dimy);
    return ter[x][y];
}

int Terrain::getDimx() const
{
    return dimx;
}

int Terrain::getDimy() const
{
    return dimy;
}

void Terrain::initialisePerso(const int x, const int y)
{
    assert(x >= 0);
    assert(y >= 0);
    assert(x < dimx);
    assert(x < dimy);
    ter[x][y] = ' ';
}
*/
