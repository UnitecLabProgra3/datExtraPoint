#include <iostream>

using namespace std;

bool puedoLlegar(char tablero[5][5], int x_actual, int y_actual, int pasos, bool encontrada)
{
    if(pasos<0)
        return false;
    if(x_actual>=5
       ||y_actual>=5
       ||x_actual<0
       ||y_actual<0)
        return false;
    if(tablero[y_actual][x_actual] == 'L')
        encontrada = true;
    if(tablero[y_actual][x_actual] == '#')
        return false;
    if(tablero[y_actual][x_actual] == 'S' && encontrada)
        return true;
    pasos--;
    return puedoLlegar(tablero, x_actual+1, y_actual, pasos, encontrada)
            ||puedoLlegar(tablero, x_actual-1, y_actual, pasos, encontrada)
            ||puedoLlegar(tablero, x_actual, y_actual+1, pasos, encontrada)
            ||puedoLlegar(tablero, x_actual, y_actual-1, pasos, encontrada);
}

int main()
{
    char tablero[5][5]={{' ', '#', ' ', ' ', ' '},
                        {'E', '#', ' ', '#', 'S'},
                        {' ', '#', ' ', '#', ' '},
                        {' ', '#', ' ', '#', '#'},
                        {' ', ' ', ' ', ' ', 'L'}};
    cout<<puedoLlegar(tablero, 0, 1, 17, false);
}
