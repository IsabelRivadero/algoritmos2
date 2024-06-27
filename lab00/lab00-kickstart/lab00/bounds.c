#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 100

struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

struct bound_data check_bound(int value, int arr[], unsigned int length) {
    struct bound_data res;
    // TODO: COMPLETAR //
    res.is_upperbound= true;
    res.is_lowerbound= true;
    res.exists= false;
    res.where= 0u;

    for (unsigned int i=0u; i< length; i++){
        if(value< arr[i]){
            res.is_upperbound= false;
        }
        else if(value> arr[i]){
            res.is_lowerbound= false;
        }
        else if(value== arr[i]){
            res.exists= true;
            res.where= i;
        }
    }
    return res;
}

int main(void) {
    int a[ARRAY_SIZE];
    int value;
    // TODO: COMPLETAR - Pedir entrada al usuario//
    unsigned int length;
    
    printf("Ingrese la longitud del arreglo (hasta %d elementos): ", ARRAY_SIZE);
    scanf("%u", &length);
    printf("Ingrese %u elementos del arreglo:\n", length);
    for (unsigned int i = 0; i < length; i++) {
        scanf("%d", &a[i]);
    }
    printf("Los elementos del arreglo son:");
    for (unsigned int i = 0; i < length; i++) {
        printf(" %d", a[i]);
    }
    printf("\n");
    printf("Ingrese el value: ");
    scanf("%d", &value);
    printf("\n");

    struct bound_data result = check_bound(value, a, length);

    // TODO: REEMPLAZAR LO SIGUIENTE LUEGO POR LA SALIDA QUE PIDE EL ENUNCIADO
    if(result.is_upperbound){
        printf("Value es cota superior: %d", result.is_upperbound);
        printf("\n");
        if(result.exists){
            printf("Value es maximo: %d", result.is_upperbound);
            printf("\n");
            printf("Es posicion del maximo: %u", result.where); 
            printf("\n");
        }
    }
    else if(result.is_lowerbound){
        printf("Value es cota inferior: %d", result.is_lowerbound);
        printf("\n");
        if(result.exists){
            printf("Value es minimo: %d", result.is_lowerbound);
            printf("\n");
            printf("Es posicion del minimo: %u", result.where);
            printf("\n");
        }
    }

    return EXIT_SUCCESS;
}

