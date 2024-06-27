#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

//#include "array_helpers.h"

unsigned int array_from_file(int array[],
                             unsigned int max_size,
                             const char *filepath) {
    FILE *file = NULL;
    file = fopen(filepath, "r");
    if (file == NULL) {
        fprintf(stderr, "The file doesn't exist. \n");
        exit(EXIT_FAILURE);
    }

    unsigned int i=0u;
    unsigned int size= 0u;
    int res=0;
    res= fscanf(file, " %u ", &size);
    if(res!=1){
        fprintf(stderr, "Invalid array. \n");
        exit(EXIT_FAILURE);
    }
    if(size> max_size){
        fprintf(stderr, "Invalid array. \n");
        exit(EXIT_FAILURE);
    }
    while(i<size){
        res= fscanf(file, "%d ", &(array[i]));
        if (res!= 1){
            fprintf(stderr, "Invalid array. \n");
            exit(EXIT_FAILURE);
        }
        i++;
    }
    fclose(file);
    return (size);
}

void array_dump(int a[], unsigned int length) {
    fprintf(stdout, "%u\n", length);
    for (unsigned int i=0u; i<length; i++){
        fprintf(stdout, "%i", a[i]);
        if (i<length -1){
            fprintf(stdout, " ");
        }else{
            fprintf(stdout, "\n");
        }
    }
}

bool array_is_sorted(int a[], unsigned int length){
    bool is_sorted= true;
    for (unsigned int i=0u; i<length -1; i++){
        if(a[i]> a[i +1]){
            is_sorted= false;
            break;
        }
    }
    return is_sorted;
}
