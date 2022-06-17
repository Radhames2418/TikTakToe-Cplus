#include "constantes.h"
#include "solucion.h"
#include "logica.h"

#include <iostream>
using namespace std;

/*
* Implementar esta función.
* Dependiendo el estado del juego esta debe retornar:

GANO_X: Si Ha ganado el jugador X
GANO_O: Si Ha ganado el jugador O
EMPATE: Si ya se llenaron todas las casillas y no hay ganador
JUEGO_EN_CURSO: Si el juego aún no se ha terminado.
*/

int GetEstado()
{

    char **tablero = GetTablero();

    // Horizontal
    for (int i = 0; i < 3; i++)
    {
        if (tablero[i][0] != '_' && tablero[i][0] == tablero[i][1] && tablero[i][0] == tablero[i][2])
        {

            for (int j = 0; j < 3; j++)
            {
                if (tablero[j][0] == 'X' && tablero[j][0] == tablero[j][1] && tablero[j][1] == tablero[j][2])
                {
                    return GANO_X;
                }
                else if (tablero[j][0] == 'O' && tablero[j][0] == tablero[j][1] && tablero[j][1] == tablero[j][2])
                {
                    return GANO_O;
                }
            }
        }
    }

    // Vertical
    for (int i = 0; i < 3; i++)
    {
        if (tablero[0][i] != '_' && tablero[0][i] == tablero[1][i] && tablero[0][i] == tablero[2][i])
        {

            for (int j = 0; j < 3; j++)
            {
                if (tablero[0][j] == 'O' && tablero[0][j] == tablero[1][j] && tablero[1][j] == tablero[2][j])
                {
                    return GANO_O;
                }
                else if (tablero[0][j] == 'X' && tablero[0][j] == tablero[1][j] && tablero[1][j] == tablero[2][j])
                {
                    return GANO_X;
                }
            }
        }
    }

    // Validacion Diagonal de izquierda a derecha
    if (tablero[0][0] != '_' && tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2])
    {

        if (tablero[0][0] == 'X' && tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2])
        {
            return GANO_X;
        }
        else if (tablero[0][0] == 'O' && tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2])
        {
            return GANO_O;
        }
    }

    // Validacion Diagonal de Derecha a Izquierda
    if (tablero[0][2] != '_' && tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0])
    {

        if (tablero[0][2] != 'X' && tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0])
        {
            return GANO_O;
        }
        else if (tablero[0][2] != 'O' && tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0])
        {
            return GANO_X;
        }
    }

    return JUEGO_EN_CURSO;
}
