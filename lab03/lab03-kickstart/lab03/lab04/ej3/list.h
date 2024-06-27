#ifndef _LIST_H
#define _LIST_H

#include <stdbool.h>

typedef int list_elem;
typedef struct Node * list;

/* Constructors */
list empty();
/*Crea una lista vacia */

list addl(list_elem e, list l);
/* agrega el elemento e al comienzo de la lista l */


/* Destroy*/
list destroy(list l);
/* Libera memoria en caso de que sea necesario */


/* Operations*/
bool is_empty(list l);
/* Devuelve True si la lista l es vacia */

list_elem head(list l);
/* Devuelve el primer elemento de la lista l
PRE: not_is_empty(l) */

list tail(list l);
/* Elimina el primer elemento de la lista l
PRE: not is_empty(l)*/

list addr(list l, list_elem e);
/* Agrega el elemento e al final de la lista l*/

unsigned int length(list l);
/* Devuelve la cantidad de elementos de la lista l */

list concat(list l1, list l2);
/* Agrega al final de l todos los elementos de l0 en el mismo orden */

list_elem index(list l, unsigned int i);
/* Devuelve el n-esimo elemento de la lista l
PRE: length(l) > n*/

list take(list l,unsigned int n);
/* Deja en l solo los primeros n elementos, eliminando el resto */

list drop(list l, unsigned int n);
/* Elimina los primeros n elementos de l */

list copy_list(list l);
/* Copia todos los elementos de l1 en una nueva lista l2 */

#endif
