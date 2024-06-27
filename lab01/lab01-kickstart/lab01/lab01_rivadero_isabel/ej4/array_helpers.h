#ifndef _ARRAY_HELPERS_H
#define _ARRAY_HELPERS_H

#include <stdbool.h>

unsigned int array_from_file(int array[],
                             unsigned int max_size,
                             const char *filepath);
/* obtiene un arreglo de una archivo */

void array_dump(int a[], unsigned int length);
/* escribe la longitud y los elementos del arreglo*/

bool array_is_sorted(int a[], unsigned int length);
/* dado un array a[] y su tamaño length debe devolver true si y sólo si los
elementos del arreglo a[] están ordenados de manera ascendente */

#endif
