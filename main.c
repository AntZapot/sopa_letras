#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Matriz filas y columnas
#define MAX_FILA 11
#define MAX_COLUMNA 13
//Colores
#define COLOR_CYAN "\x1b[36m"
#define COLOR_RESET "\x1b[0m"
#define COLOR_ROJO "\x1b[31m"

int imprimir_menu();
int scan_palabra(int mensaje);
int valor_palabra(int palabra);

char matriz[MAX_FILA][MAX_COLUMNA] = 
{
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
    system("@cls||clear");
    int arr_ascii[MAX_FILA][MAX_COLUMNA];

    imprimir_menu();
    
    //Conversion a ascii
    for (int i = 0; i < MAX_FILA; i++)
    {
        for (int j = 0; j < MAX_COLUMNA; j++)
        { 
            arr_ascii[i][j] = (int)matriz[i][j];
        }
    }
    
    // //Comprobacion de arreglo arr_ascii <--TEMPORAL-->
    // for (int i = 0; i < MAX_FILA; i++)
    // {
    //     for (int j = 0; j < MAX_COLUMNA; j++)
    //     { 
    //         printf("%d\t", arr_ascii[i][j]);
    //     }
    //     printf("\n");
    // }
    

    return 0;
}

int imprimir_menu() 
{
    printf("Palabras a buscar:\n");
    printf("1.DAÑA\n");
    printf("2.EÑES\n");
    printf("3.HELÉ\n");
    printf("4.HEREDARAS\n");
    printf("5.OPONES\n");
    printf("6.ÓVALOS\n");
    printf("7.PULCROS\n");
    printf("8.RESEÑAR\n");
    printf("9.RUANESA\n");
    printf("10.TEORIZAS\n");
    printf(COLOR_CYAN"Ingresa el numero de la palabra a buscar\n"COLOR_RESET);
    
    return scan_palabra(0);
}

int scan_palabra(int mensaje) 
{
    int palabra;
    if(mensaje)
    {
        printf(COLOR_ROJO"Favor de insertar un dato valido\n"COLOR_RESET);
    }
    
    scanf("%d", &palabra);
    if(palabra > 0 && palabra <= 10)
    {
        return valor_palabra(palabra);
    }
    return scan_palabra(1);
}

//Asignacion de valos ascii a la palabra selecionada
int valor_palabra(int palabra)
{
    switch (palabra)
    {
    case 1:
        int palabra_uno[4] = {68, 65, 63, 65}; //DAÑA
        break;
    case 2:
        int palabra_dos[4] = {69, 63, 69, 83}; //EÑES
        break;
    case 3:
        int palabra_tres[4] = {72, 69, 76, 69}; //HELÉ
        break;
    case 4:
        int palabra_cuatro[9] = {72, 69, 82, 69, 68, 65, 82, 65, 83}; //HEREDARAS
        break;
    case 5:
        int palabra_cinco[6] = {79, 80, 79, 78, 69, 83}; //OPONES
        break;
    case 6:
        int palabra_seis[6] = {79, 86, 65, 76, 79, 83}; //ÓVALOS
        break;
    case 7:
        int palabra_siete[7] = {80, 85, 76, 67, 82, 79, 83};  //PULCROS
        break;
    case 8:
        int palabra_ocho[7] = {82, 69, 83, 69, 63, 65, 82}; //RESEÑAR
        break;
    case 9:
        int palabra_nueve[7] = {82, 85, 65, 78, 69, 83, 65}; //RUANESA
        break;
    case 10:
        int palabra_diez[8] = {84, 69, 79, 82, 73, 90, 65, 83}; //TEORIZAS
        break;
    }

    
    return 0;
}
