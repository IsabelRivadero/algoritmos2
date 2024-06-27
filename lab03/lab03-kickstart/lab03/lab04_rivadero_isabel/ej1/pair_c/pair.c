#include <stdlib.h>  
#include <stdio.h> 
#include <assert.h>

#include "pair.h" 

struct s_pair_t {
    int fst;
    int snd;
};

pair_t pair_new(int x, int y){
    pair_t par= NULL;
    par= malloc(sizeof(struct s_pair_t));
    par->fst= x;
    par->snd= y;
    assert(par->fst==x && par->snd==y);
    return par;
}

int pair_first(pair_t p){
    //assert(p --> (x, y));
    int first= p->fst;
    assert(p->fst== first);
    return first;
}

int pair_second(pair_t p){
    //assert(p --> (x, y));
    int second= p->snd;
    assert(p->snd== second);
    return second;
}

pair_t pair_swapped(pair_t p){
    //assert(p --> (x, y));
    int first, second;
    first= p->fst;
    second= p->snd;
    pair_t q= pair_new(second, first);

    assert(q->fst==second && q->snd== first);
    return q;
}

pair_t pair_destroy(pair_t p){
    free(p);  
    return p;
}