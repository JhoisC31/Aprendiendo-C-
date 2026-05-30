#include "constantes.h"
#include "solucion.h"
#include "logica.h"

#include <iostream>
using namespace std;

char winer = '_';

int GetEstado()
{
    char** t = GetTablero();

    /* Diagonales */
    if(t[1][1] != '_')
    {
        if(t[0][0] == t[1][1] && t[1][1] == t[2][2])
        {
            winer = t[1][1];
            return winer == 'X' ? GANO_X : GANO_O;
        }
        if(t[0][2] == t[1][1] && t[1][1] == t[2][0])
        {
            winer = t[1][1];
            return winer == 'X' ? GANO_X : GANO_O;
        }
    }

    /* Columnas y filas */
    for(int i = 0; i < 3; i++)
    {
        if(t[i][0] != '_' && t[i][0] == t[i][1] && t[i][0] == t[i][2])
        {
            winer = t[i][0];
            return winer == 'X' ? GANO_X : GANO_O;
        }

        if(t[0][i] != '_' && t[0][i] == t[1][i] && t[0][i] == t[2][i])
        {
            winer = t[0][i];
            return winer == 'X' ? GANO_X : GANO_O;
        }
    }

    /* juego en Curso empate */
    int vacias = 0;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(t[i][j] == '_') vacias++;

    return vacias > 0 ? JUEGO_EN_CURSO : EMPATE;
}