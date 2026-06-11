#include <stdio.h>

int main() {
    int numero = 42;
    int *puntero1 = &numero; // puntero1 apunta a la dirección de 'numero'
    int *puntero2;           // Creamos un segundo puntero sin inicializar

    // COPIA DEL PUNTERO: Copiamos la dirección de memoria
    puntero2 = puntero1; 

    printf("Dirección de puntero1: %p, Valor: %d\n", (void*)puntero1, *puntero1);
    printf("Dirección de puntero2: %p, Valor: %d\n", (void*)puntero2, *puntero2);

    // Modificar el valor usando el segundo puntero
    *puntero2 = 99;

    printf("\nDespués de modificar *puntero2:\n");
    printf("Valor de la variable 'numero': %d\n", numero);
    printf("Valor a través de puntero1: %d\n", *puntero1);

    return 0;
}

////////////////////

char *spointer = &str;
str++;

////////////////////

char str[] = "hola mundo";

char strp[][] = {"hola" , "mundo"};

*str++;
ox34FA0 = "0"

1000 += 1;
1000 ++;