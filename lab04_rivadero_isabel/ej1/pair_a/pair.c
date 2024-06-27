#include <stdlib.h>  
#include <assert.h>  
#include "pair.h" 

pair_t pair_new(int x, int y){
    pair_t new_pair;
    new_pair.fst= x;
    new_pair.snd= y;
    assert(new_pair.fst== x && new_pair.snd== y);
    return new_pair;
}

int pair_first(pair_t p){
    int first= p.fst;
    assert(p.fst== first);
    return first;
}

int pair_second(pair_t p){
    int second= p.snd;
    assert(p.snd== second);
    return second;
}

pair_t pair_swapped(pair_t p){
    int aux, first, second;
    first= p.fst;
    second= p.snd;
    aux= p.fst;
    p.fst= p.snd;
    p.snd= aux;
    assert(p.fst==second && p.snd== first);
    return p;
}

pair_t pair_destroy(pair_t p){
    //p.fst= NULL;
    //p.snd= NULL;
    
    return p;
}