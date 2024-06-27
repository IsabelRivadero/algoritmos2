#include <stdlib.h>
#include <assert.h>
#include "stack.h"

struct _s_stack {
    stack_elem *elems;      // Arreglo de elementos
    unsigned int size;      // Cantidad de elementos en la pila
    unsigned int capacity;  // Capacidad actual del arreglo elems
};

stack stack_empty(){
    stack s=calloc(1, sizeof(struct _s_stack));
    s->elems= NULL;
    s-> size= 0u;
    s-> capacity= 10u;
    return s;
}

stack stack_push(stack s, stack_elem e){
    if(stack_is_empty(s)){
        s->elems=calloc(s->capacity, sizeof(stack_elem));
    }
    if(s->size== s->capacity){
        s->elems= realloc(s->elems, (2*(s->capacity)*sizeof(stack_elem)));
        s->capacity= 2*(s->capacity);
    }
    s->elems[s->size]= e;
    s->size++;
    
    assert(!stack_is_empty(s));
    return s;
}

stack stack_pop(stack s){
    assert(!stack_is_empty(s));
    s->size= s->size -1;
    return s;
}

unsigned int stack_size(stack s){
     return s->size;
}

stack_elem stack_top(stack s){
    assert(!stack_is_empty(s));
    return s->elems[s->size-1];
}

bool stack_is_empty(stack s){
    return (s->size== 0);
}

stack_elem *stack_to_array(stack s){
    if(s->size==0u){
        return NULL;
    }
    unsigned int size= s->size;
    stack_elem *array= (stack_elem *) calloc(size, sizeof(stack_elem));
    for(unsigned int i=0; i<size; i++){
        array[size-1-i]=s->elems[i];
    }
    return array;
}

stack stack_destroy(stack s){
    free(s->elems);
    s->elems= NULL;
    free(s);
    s= NULL;
    return s;
}

