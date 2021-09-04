#include <stdio.h>
#include <string.h>

#define MAX_FILA 11
#define MAX_COLUMNA 13

    char matriz[MAX_FILA][MAX_COLUMNA] = {
        { 'O', 'P', 'O', 'N', 'E', 'S', 'A', 'S', 'R', 'U', 'S', 'D', 'E'},
        { 'C', 'S', 'E', 'Z', 'L', '?', 'P', 'U', 'L', 'C', 'R', 'O', 'S'},
        { 'R', 'A', 'N', 'L', 'R', 'S', 'A', 'T', 'O', 'Z', 'V', 'A', 'L'},
        { 'V', 'R', 'V', 'S', 'E', 'N', 'L', 'I', 'I', 'R', 'Z', 'Z', '?'},
        { 'O', 'A', 'U', 'P', 'E', 'H', 'R', 'D', 'Z', 'I', 'N', 'D', 'O'},
        { 'V', 'D', 'I', 'S', 'R', 'U', 'A', 'S', 'R', 'N', 'O', '?', 'T'},
        { 'S', 'E', 'A', 'H', '?', 'U', '?', 'O', 'O', 'V', '?', 'R', 'Z'},
        { 'O', 'R', 'L', '?', 'A', 'E', 'E', 'I', 'O', 'L', 'D', 'A', 'O'},
        { 'I', 'E', 'E', '?', '?', 'T', 'S', '?', 'V', 'D', 'A', 'I', 'U'},
        { '?', 'H', 'A', 'E', 'Z', 'S', 'E', 'O', 'U', 'R', 'C', 'V', 'C'},
        { 'T', 'D', 'S', 'N', 'Z', 'H', 'R', 'A', 'S', 'L', 'A', 'A', 'O'}
    }; 

int main(int argc, char const *argv[])
{
    int arr_ascii[MAX_FILA][MAX_COLUMNA];

    for (int i = 0; i < MAX_FILA; i++)
    {
        for (int j = 0; j < MAX_COLUMNA; j++)
        { 
            arr_ascii[i][j] = (int)matriz[i][j];
        }
    }
    
    //Comprobacion de arreglo arr_ascii <--TEMPORAL-->
    for (int i = 0; i < MAX_FILA; i++)
    {
        for (int j = 0; j < MAX_COLUMNA; j++)
        { 
            printf("%d\t", arr_ascii[i][j]);
        }
        printf("\n");
    }
    

    return 0;
}

