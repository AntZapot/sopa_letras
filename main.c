//Librerias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Matriz filas y columnas
#define MAX_FILA 11
#define MAX_COLUMNA 13

//Colores
#define COLOR_CYAN "\x1b[36m"
#define COLOR_RESET "\x1b[0m"
#define COLOR_ROJO "\x1b[31m"

//Funciones
int convertir_ascii(void);
int imprimir_menu(void);
int scan_palabra(void);
int valor_palabra(int palabra);
int buscar_sopa(int arr[], int longitud);
int resultado_sopa(int arr_indices[][2], int longitud, int invertir);
int operacion(int indice1, int indice2, int operacion);

//Comparar con arreglo ascii
/*
    Parametros:
    arr[] = arreglo con los valores ASCII de la palabra a buscar,
    int i, int j = indices donde se encontro una coicidencia del primer valor de (arr[0]),
    int op1, int op2 = Operadores que se pasaran a funcion operacion, para determinar si suma, resta o se queda igual,
    int invertir = orden en que apareceran los indices, descendente: 1, ascendente: 0
*/
int encontrar_indices(int arr[], int longitud, int i, int j, int op1, int op2, int invertir);

/*
    Si se desea cambia la sopa de letras se debe cambiar los datos en ambas matrices
    Tanto la de caracteres como la de cadenas
*/

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

//Matriz que se imprimira al encontrar los indices de la palabra a buscar
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


//Arreglo ascii 
int arr_ascii[MAX_FILA][MAX_COLUMNA];

int main(int mensaje)
{
    char num;
    if(mensaje)
    {
        system("@cls||clear");
    }
    else 
    {
        printf(COLOR_CYAN"\nPresione 0 para volver al menú ó ingresa otra palabra a buscar\n"COLOR_RESET);
        printf(COLOR_CYAN"Para salir presione Ctrl + C\n"COLOR_RESET);
        do
        {
            scanf("%d", &num);
        } while (num != 0);
        system("@cls||clear");
    }

    //Conversion a ascii
    convertir_ascii();

    return imprimir_menu();
}

int convertir_ascii(void)
{
    for (int i = 0; i < MAX_FILA; i++)
    {   
        for (int j = 0; j < MAX_COLUMNA; j++)
        {   
            if((int)matriz[i][j] == 63 )
            {
                arr_ascii[i][j] = 165;
            }
            else 
            {
                arr_ascii[i][j] = (int)matriz[i][j];
            }
        }
    }
}

//Desplegar menu
int imprimir_menu(void) 
{
    printf(COLOR_CYAN"Palabras a disponibles:\n"COLOR_RESET);
    printf("DAÑA\n");
    printf("EÑES\n");
    printf("HELÉ\n");
    printf("HEREDARAS\n");
    printf("OPONES\n");
    printf("ÓVALOS\n");
    printf("PULCROS\n");
    printf("RESEÑAR\n");
    printf("RUANESA\n");
    printf("TEORIZAS\n");
    printf(COLOR_CYAN"Teclea la palabra a buscar\n"COLOR_RESET);
    printf(COLOR_CYAN"¡Si tecleas otra palabra fuera de la lista y existe se te marcará!\n"COLOR_RESET);
    
    return scan_palabra();
}

//leer numero de palabra a buscar
int scan_palabra(void) 
{
    //Lectura de variable palabra
    char palabra[10];
    scanf("%s", palabra);
    //declaracion de arreglo dinamico y longitud
    int *arr, longitud;
    //Tranformar a mayus
    for (int i = 0; palabra[i] != '\0'; i++)
    {   
        palabra[i] = toupper(palabra[i]);
    }
    //Asignacion de longitud y quitar espacios de mas
    longitud = strlen(palabra);
    for (int i = 0; palabra[i] != '\0'; i++)
    {
        //Manejo de caracteres especiales ñ, Ñ, ó, Ó, 
        longitud = (int)palabra[i] < -61 ? longitud-- : longitud;
        if((int)palabra[i] == -111 || (int)palabra[i] == -79)
        {
            longitud--;
        }
        else if((int)palabra[i] == -119 || (int)palabra[i] == -87)
        {
            longitud--;
        }
        else if((int)palabra[i] == -109 || (int)palabra[i] == -77)
        {
            longitud--;
        }
    }

    //Creacion de arreglo dinamico en base a lo longitud obtenida
    arr = (int *)calloc(longitud, sizeof(int));
    //Llenar el arreglo dinamico con los valores ASCII
    int j = 0;
    for (int i = 0; palabra[i] != '\0'; i++)
    {   
        if((int)palabra[i] == -111 || (int)palabra[i] == -79)
        {
            arr[j] = 165;
            j++;
        }
        else if((int)palabra[i] == -119 || (int)palabra[i] == -87)
        {
            arr[j] = 69;
            j++;
        }
        else if((int)palabra[i] == -109 || (int)palabra[i] == -77)
        {
            arr[j] = 79;
            j++;
        }
        else if((int)palabra[i] > 0)
        {
            arr[j] = (int)palabra[i];
            j++;
        }
    }

    return buscar_sopa(arr, longitud);
}

int buscar_sopa(int arr[], int longitud)
{   
    int contador = 0, multiplicador = 0;
    //Recorrer el arreglo con valores ascii
    for (int i = 0; i < MAX_FILA; i++)
    {
        for (int j = 0; j < MAX_COLUMNA; j++)
        {
            //Encontrar la primera letra en el arreglo ascii 
            if(arr[0] == arr_ascii[i][j])
            {
                //Busqueda en las 8 direcciones posibles 
                // 1: Sumar 0: Dejar Igual -1: Restar
                multiplicador++;
                encontrar_indices(arr, longitud, i, j, -1, 0, 1) ? contador++ : contador; //arriba
                encontrar_indices(arr, longitud, i, j, -1, 1, 1) ? contador++ : contador; //derecha arriba
                encontrar_indices(arr, longitud, i, j, 0, 1, 0) ? contador++ : contador; //derecha
                encontrar_indices(arr, longitud, i, j, 1, 1, 0) ? contador++ : contador; //derecha abajo
                encontrar_indices(arr, longitud, i, j, 1, 0, 0) ? contador++ : contador;//abajo
                encontrar_indices(arr, longitud, i, j, 1, -1, 0) ? contador++ : contador; //izquierda abajo
                encontrar_indices(arr, longitud, i, j, 0, -1, 1) ? contador++ : contador; //izquierda
                encontrar_indices(arr, longitud, i, j, -1, -1, 1) ? contador++ : contador; //izquierda arriba
            }
        }
    }
    if(contador == multiplicador * 8)
    {
        printf(COLOR_ROJO"\nNo se encontró la palabra deseada, prueba con alguna de las palabras listadas\n"COLOR_RESET);
        return main(0);
    }
    //liberacion de memoria
    free(arr);
    return 0;
}

//Seleccion de operacion
int operacion(int indice1, int indice2, int operacion)
{
    switch (operacion)
    {
    case -1:
        return indice1 - indice2;
        break;
    case 0:
        return indice1;
        break;
    case 1:
        return indice1 + indice2;
        break;
    }
}

int encontrar_indices(int arr[], int longitud, int i, int j, int op1, int op2, int invertir)
{
    int arr_temp[longitud];
    int arr_indices[longitud][2];

    //LLenado de arreglo temporal
    for (int k = 0; k < longitud; k++)
    {
        arr_temp[0+k] = arr_ascii[operacion(i, k, op1)][operacion(j, k, op2)];
    }

    //Comprobar si son iguales el arreglo con los valores ASCII de la palabra y el arreglo temporal
    for (int l = 0; l < longitud; l++)
    {
        if(arr[l] != arr_temp[l])
        {
            return 1;
        }
        else
        {
            arr_indices[l][0] = operacion(i, l, op1);
            arr_indices[l][1] = operacion(j, l, op2);
        }
    }
    
    return resultado_sopa(arr_indices, longitud, invertir);
}

//Imprimr sopa de letras en tipo cadena y darle formato
int resultado_sopa(int arr_indices[][2], int longitud, int invertir)//invertir detecta en que orden aparecen los indices
{
    int contador = invertir ? longitud - 1 : 0;
    system("@cls||clear");

    printf(COLOR_CYAN"¡Se ha encontrado la palabra con exito en los siguientes indices!\n"COLOR_RESET);

    //Imprimir indices donde se encontró la palabra
    for (int i = 0; i < longitud; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf(COLOR_CYAN" %d"COLOR_RESET, arr_indices[i][j]);
        }
        printf("\t");
    }
    printf("\n\n");

    //Imprimir la sopa de letras con los indices de las coincidencias en color
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
    return main(0);
}