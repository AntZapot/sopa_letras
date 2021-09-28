//Librerias
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//Matriz filas y columnas
#define MAX_FILA 11
#define MAX_COLUMNA 13

//Colores
#define COLOR_CYAN "\x1b[36m"
#define COLOR_RESET "\x1b[0m"
#define COLOR_ROJO "\x1b[31m"

//Funciones
int imprimir_menu();
int scan_palabra(int mensaje);
int valor_palabra(int palabra);
int buscar_sopa(int arr[], int longitud);
int resultado_sopa(int arr_indices[][2], int longitud, int invertir);

//Comparar con arreglo ascii
//Solo buscara en las direcciones declaradas, ya que este ejemplo no necesita de mas direcciones de busqueda
int comparar_derecha(int arr[], int longitud, int i, int j);
int comparar_arriba(int arr[], int longitud, int i, int j);
int comparar_derecha_arriba(int arr[], int longitud, int i, int j);
int comparar_izquierda_arriba(int arr[], int longitud, int i, int j);
int comparar_izquierda_abajo(int arr[], int longitud, int i, int j);

//Matriz de caracteres
//Intercambio de (Ñ) a (?) debido a que genera errores al querer imprimir (Ñ) como caracter*
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


//Arreglo ascii 
int arr_ascii[MAX_FILA][MAX_COLUMNA];

int main(void)
{
    system("@cls||clear");

    //Conversion a ascii
    for (int i = 0; i < MAX_FILA; i++)
    {   
        for (int j = 0; j < MAX_COLUMNA; j++)
        {   
            arr_ascii[i][j] = (int)matriz[i][j];
        }
    }

    return imprimir_menu();
}

//Desplegar menu
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

//leer numero de palabra a buscar
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
    //Creacion de arreglo dinamico para almacenar valores ascii de las palabras
    int *arr, longitud;
    switch (palabra)
    {
    case 1:
        //DAÑA
        longitud = 4;
        arr = (int *)calloc(longitud, sizeof(int));
        arr[0] = 68;
        arr[1] = 65;
        arr[2] = 63;
        arr[3] = 65; 
        break;
    case 2:
        //EÑES
        longitud = 4;
        arr = (int *)calloc(longitud, sizeof(int));
        arr[0] = 69;
        arr[1] = 63;
        arr[2] = 69;
        arr[3] = 83; 
        break;
    case 3:
        //HELÉ
        longitud = 4;
        arr = (int *)calloc(longitud, sizeof(int));
        arr[0] = 72;
        arr[1] = 69;
        arr[2] = 76;
        arr[3] = 69; 
        break;
    case 4:
        //HEREDARAS
        longitud = 9;
        arr = (int *)calloc(longitud, sizeof(int));
        arr[0] = 72;
        arr[1] = 69;
        arr[2] = 82;
        arr[3] = 69; 
        arr[4] = 68; 
        arr[5] = 65; 
        arr[6] = 82; 
        arr[7] = 65; 
        arr[8] = 83; 
        break;
    case 5:
        //OPONES
        longitud = 6;
        arr = (int *)calloc(longitud, sizeof(int));
        arr[0] = 79;
        arr[1] = 80;
        arr[2] = 79;
        arr[3] = 78; 
        arr[4] = 69; 
        arr[5] = 83; 
        break;
    case 6:
        //ÓVALOS
        longitud = 6;
        arr = (int *)calloc(longitud, sizeof(int));
        arr[0] = 79;
        arr[1] = 86;
        arr[2] = 65;
        arr[3] = 76; 
        arr[4] = 79; 
        arr[5] = 83; 
        break;
    case 7:
        //PULCROS
        longitud = 7;
        arr = (int *)calloc(longitud, sizeof(int));
        arr[0] = 80;
        arr[1] = 85;
        arr[2] = 76;
        arr[3] = 67; 
        arr[4] = 82; 
        arr[5] = 79; 
        arr[6] = 83; 
        break;
    case 8:
        //RESEÑAR
        longitud = 7;
        arr = (int *)calloc(longitud, sizeof(int));
        arr[0] = 82;
        arr[1] = 69;
        arr[2] = 83;
        arr[3] = 69; 
        arr[4] = 63; 
        arr[5] = 65; 
        arr[6] = 82; 
        break;
    case 9:
        //RUANESA
        longitud = 7;
        arr = (int *)calloc(longitud, sizeof(int));
        arr[0] = 82;
        arr[1] = 85;
        arr[2] = 65;
        arr[3] = 78; 
        arr[4] = 69; 
        arr[5] = 83; 
        arr[6] = 65; 
        break;
    case 10:
        //TEORIZAS
        longitud = 8;
        arr = (int *) calloc(longitud, sizeof(int));
        arr[0] = 84;
        arr[1] = 69;
        arr[2] = 79;
        arr[3] = 82; 
        arr[4] = 73; 
        arr[5] = 90; 
        arr[6] = 65; 
        arr[7] = 83; 
        break;
    }
    
    return buscar_sopa(arr, longitud);
}

int buscar_sopa(int arr[], int longitud)
{
    //Recorrer el arreglo con valores ascii
    for (int i = 0; i < MAX_FILA; i++)
    {
        for (int j = 0; j < MAX_COLUMNA; j++)
        {
            //Encontrar la primera letra en el arreglo ascii 
            if(arr[0] == arr_ascii[i][j])
            {
                //Llamar funciones para determinar hacia donde se encuentran las demas coincidencias
                comparar_derecha(arr, longitud, i, j);
                comparar_derecha_arriba(arr, longitud, i, j);
                comparar_arriba(arr, longitud, i, j);
                comparar_izquierda_arriba(arr, longitud, i, j);
                comparar_izquierda_abajo(arr, longitud, i, j);
            }
        }
    }
    free(arr);
    return 0;
}

int comparar_arriba(int arr[], int longitud, int i, int j)
{
    int arr_temp[longitud];
    int arr_indices[longitud][2];
    
    for (int k = 0; k < longitud; k++)
    {
        arr_temp[0+k] = arr_ascii[i-k][j];
    }

    //Comprobar si son iguales
    for (int l = 0; l < longitud; l++)
    {
        if(arr[l] != arr_temp[l])
        {
            return 0;
        }
        else
        {
            arr_indices[l][0] = i-l;
            arr_indices[l][1] = j;
        }
    }
    
    return resultado_sopa(arr_indices, longitud, 1);
}

int comparar_derecha_arriba(int arr[], int longitud, int i, int j)
{
    int arr_temp[longitud];
    int arr_indices[longitud][2];
    for (int k = 0; k < longitud; k++)
    {
        arr_temp[0+k] = arr_ascii[i-k][j+k];
    }

    //Comprobar si son iguales
    for (int l = 0; l < longitud; l++)
    {
        if(arr[l] != arr_temp[l])
        {
            return 0;
        }
        else
        {
            arr_indices[l][0] = i-l;
            arr_indices[l][1] = j+l;
        }
    }
    
    return resultado_sopa(arr_indices, longitud, 1);
}

int comparar_derecha(int arr[], int longitud, int i, int j)
{
    int arr_temp[longitud];
    int arr_indices[longitud][2];
    for (int k = 0; k < longitud; k++)
    {
        arr_temp[0+k] = arr_ascii[i][j+k];
    }

    //Comprobar si son iguales
    for (int l = 0; l < longitud; l++)
    {
        if(arr[l] != arr_temp[l])
        {
            return 0;
        }
        else
        {
            arr_indices[l][0] = i;
            arr_indices[l][1] = j+l;
        }
    }
    return resultado_sopa(arr_indices, longitud, 0);
}

int comparar_izquierda_arriba(int arr[], int longitud, int i, int j)
{
    int arr_temp[longitud];
    int arr_indices[longitud][2];
    for (int k = 0; k < longitud; k++)
    {
        arr_temp[0+k] = arr_ascii[i-k][j-k];
    }

    //Comprobar si son iguales
    for (int l = 0; l < longitud; l++)
    {
        if(arr[l] != arr_temp[l])
        {
            return 0;
        }
        else
        {
            arr_indices[l][0] = i-l;
            arr_indices[l][1] = j-l;
        }
    }
    
    return resultado_sopa(arr_indices, longitud, 1);
}

int comparar_izquierda_abajo(int arr[], int longitud, int i, int j)
{
    int arr_temp[longitud];
    int arr_indices[longitud][2];
    for (int k = 0; k < longitud; k++)
    {
        arr_temp[0+k] = arr_ascii[i+k][j-k];
    }

    //Comprobar si son iguales
    for (int l = 0; l < longitud; l++)
    {
        if(arr[l] != arr_temp[l])
        {
            return 0;
        }
        else
        {
            arr_indices[l][0] = i+l;
            arr_indices[l][1] = j-l;
        }
    }
    
    return resultado_sopa(arr_indices, longitud, 0);
}

//Imprimr sopa de letras en tipo cadena y darle formato
int resultado_sopa(int arr_indices[][2], int longitud, int invertir)//invertir detecta en que orden aparecen los indices
{
    int contador = invertir ? longitud - 1 : 0;
    system("@cls||clear");

    char* matriz_cadena[MAX_FILA][MAX_COLUMNA] = 
    {
        { "O", "P", "O", "N", "E", "S", "A", "S", "R", "U", "S", "D", "E"},
        { "C", "S", "E", "Z", "L", "Ñ", "P", "U", "L", "C", "R", "O", "S"},
        { "R", "A", "N", "L", "R", "S", "A", "T", "O", "Z", "V", "A", "L"},
        { "V", "R", "V", "S", "E", "N", "L", "I", "I", "R", "Z", "Z", "Ñ"},
        { "O", "A", "U", "P", "E", "H", "R", "D", "Z", "I", "N", "D", "O"},
        { "V", "D", "I", "S", "R", "U", "A", "S", "R", "N", "O", "Ñ", "T"},
        { "S", "E", "A", "H", "Ñ", "U", "Ñ", "O", "O", "V", "Ñ", "R", "Z"},
        { "O", "R", "L", "Ñ", "A", "E", "E", "I", "O", "L", "D", "A", "O"},
        { "I", "E", "E", "Ñ", "Ñ", "T", "S", "Ñ", "V", "D", "A", "I", "U"},
        { "Ñ", "H", "A", "E", "Z", "S", "E", "O", "U", "R", "C", "V", "C"},
        { "T", "D", "S", "N", "Z", "H", "R", "A", "S", "L", "A", "A", "O"}
    };

    printf(COLOR_CYAN"¡Se ha encontrado la palabra con exito en los siguientes indices!\n"COLOR_RESET);

    for (int i = 0; i < longitud; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf(COLOR_CYAN" %d"COLOR_RESET, arr_indices[i][j]);
        }
        printf("\t");
    }

    printf("\n\n");
    for (int i = 0; i < MAX_FILA; i++)
    {
        for (int j = 0; j < MAX_COLUMNA; j++)
        {
            if(arr_indices[0+contador][0] == i && arr_indices[0+contador][1] == j)
            {
                printf(COLOR_CYAN"%s\t"COLOR_RESET, matriz_cadena[i][j]);
                contador = invertir ? contador - 1 : contador + 1;
            }
            else 
            {
                printf("%s\t", matriz_cadena[i][j]);
            }
        }
        printf("\n");
    }
    return main();
}