#include <stdlib.h>
#include <assert.h>
#include "stack.h"
 
struct _s_stack{
    stack_elem elem;
    stack next;
};

stack stack_empty(){
    stack s= NULL;
    return s;
}

stack stack_push(stack s, stack_elem e){
    stack s2= NULL;
    s2= (stack)calloc(1, sizeof(struct _s_stack));
    s2->elem= e;
    s2->next= NULL;
    if(s== NULL){
        return s2;
    }
    s2->next= s;
    s= s2;
    assert(!stack_empty(s));
    return s;
}

stack stack_pop(stack s){
    assert(!stack_is_empty(s));
    stack s2= s->next;
    free(s);
    s=s2;
    return s;
}

unsigned int stack_size(stack s){
    unsigned int n=0u;
    while(!stack_is_empty(s)){
        s= s->next;
        n++;
    }
    return n;
}

stack_elem stack_top(stack s){
    assert(!stack_is_empty(s));
    stack_elem e= s->elem;
    return e;
}

bool stack_is_empty(stack s){
    return (s== NULL);
}

stack_elem *stack_to_array(stack s){
    if(s==NULL){
        return NULL;
    }
    unsigned int size= stack_size(s);
    stack_elem *array= (stack_elem *) calloc(size, sizeof(stack_elem));

    for(unsigned int i=0; i<size; i++){
        array[size-1-i]=s->elem;
        s=s->next;
    }
    return array;
}

stack stack_destroy(stack s){
    while(!stack_is_empty(s)){
        stack p= s;
        s= s->next;
        free(p);
    }
    s= NULL;
    return s;
}