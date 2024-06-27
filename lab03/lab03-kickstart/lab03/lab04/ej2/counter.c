#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#include "counter.h"

struct _counter {
    unsigned int count;
};

counter counter_init(void) {
/* Needs implementation. */
    counter c= malloc(sizeof(struct _counter));
    c->count= 0u;
    assert(counter_is_init(c));
    return c;
}

void counter_inc(counter c) {
/* Needs implementation. */
    c->count= c->count +1;
}

bool counter_is_init(counter c) {
/* Needs implementation. */
    return ((c->count)==0);
}

void counter_dec(counter c) {
/* Needs implementation. */
    assert(!counter_is_init(c));
    c->count= c->count -1;
}

counter counter_copy(counter c) {
/* Needs implementation. */
    counter copy= malloc(sizeof(struct _counter));
    copy->count= c->count;
    return copy; 
}

void counter_destroy(counter c) {
/*Needs implementation. */
    free(c);
    c= NULL;
}
