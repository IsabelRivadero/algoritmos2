#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

struct Node{
    list_elem elem;
    list next;
};

list empty(){
    list l= NULL;
    return l;
}

list addl(list_elem e, list l){
    list p= malloc(sizeof(struct Node));
    p->elem= e;
    p->next= l;
    return p;
}


/* Destroy*/
list destroy(list l){
    if(!is_empty(l)){
        l-> next= destroy(l->next);
        free(l);
        l= NULL;
    }
    return l;
}


/* Operations*/
bool is_empty(list l){
    return (l== NULL);
}

list_elem head(list l){
    assert(!is_empty(l));
    return l->elem;
}

list tail(list l){
    assert(!is_empty(l));
    list p= l-> next;
    free(l);
    return p;
}

list addr(list l, list_elem e){
    list p= l;
    list q= malloc(sizeof(struct Node));
    q->elem=e;
    q->next=NULL;
    if(!is_empty(l)){
        while(p->next!=NULL){
            p=p->next;
        }
        p->next= q;
    }
    else{
        l= q;
    }
    return l;
}

unsigned int length(list l){
    unsigned int n=0u;
    list p= l;
    while(!is_empty(l)){
        n= n+1;
        p= p->next;
    }
    return n;
}

list concat(list l1, list l2){
    if(is_empty(l1)){
        return copy_list(l2);
    }else{
        list p= l1;
        while(!is_empty(p->next)){
            p=p->next;
        }
        p->next= l2;
    }
    return l1;
}

list_elem index(list l, unsigned int i){
    assert(length(l) > i);
    list p= l;
    for(unsigned int j=0u; j<i; j++){
        p= p->next;
    }
    return p->elem;

}

list take(list l,unsigned int n){
    unsigned j = 0u;
    if (n==0u){
        return destroy(l);
    }else{
        list p = l;
        while ((!is_empty(p)) && j<(n-1u)) {
            p = p->next;
            j = j+1u;
        }
        p->next= destroy(p->next);
        return l;
    }
}

list drop(list l, unsigned int n){
    unsigned j = 0u;
    while(!is_empty(l) && j<n) {
        l = tail(l);
        j = j+1u;
    }
    return l;
}

list copy_list(list l){
    if (is_empty(l)) {
        return empty();
    } else {
        list cop_l = malloc(sizeof(struct Node));
        cop_l->elem = l->elem;
        list p = l;
        list q = cop_l;
        while (!is_empty(p->next)) {
            q->next = malloc(sizeof(struct Node));
            q = q->next;
            p = p->next;
            q->elem = p->elem;
        }
        q->next = NULL;
        return cop_l;
    }
}