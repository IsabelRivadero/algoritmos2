#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "queue.h"

struct s_queue {
    /* COMPLETAR */
    struct s_node *first;
    struct s_node * lst;
    unsigned int size;
};

struct s_node {
    queue_elem elem;
    struct s_node *next;
};

static struct s_node *
create_node(queue_elem e) {
    struct s_node *new_node=malloc(sizeof(struct s_node));
    assert(new_node!=NULL);
    new_node->elem = e;
    new_node->next = NULL;
    return new_node;
}

static struct s_node *
destroy_node(struct s_node *node) {
    node->next=NULL;
    free(node);
    node=NULL;
    return node;
}

static bool
invrep(queue q) {
    return q != NULL;
}

queue queue_empty(void) {
    queue q= NULL;
    /* COMPLETAR */
    q= malloc(sizeof(struct s_queue));
    if (q == NULL) {
        fprintf(stderr, "Error: no se pudo asignar memoria para la cola.\n");
        exit(EXIT_FAILURE);
    }
    q->first= NULL;
    q->lst= NULL;
    q->size= 0u;
    assert(invrep(q) && queue_is_empty(q));
    return q;
}

queue queue_enqueue(queue q, queue_elem e) {
    assert(invrep(q));
    struct s_node *new_node = create_node(e);
    if (q->first==NULL) {
        q->first = new_node;
        q->lst= new_node;
        q->size= 1;
    } else {
        /* COMPLETAR */
        q->lst->next= new_node;
        q->lst= new_node;
        q->size = q->size+1;
    }
    assert(invrep(q) && !queue_is_empty(q)/* && queue_first(q) == e*/);
    return q;
}

bool queue_is_empty(queue q) {
    assert(invrep(q));
    return q->first == NULL;
}

queue_elem queue_first(queue q) {
    assert(invrep(q) && !queue_is_empty(q));
    return q->first->elem;
}
unsigned int queue_size(queue q) {
    assert(invrep(q));
    //unsigned int size=0;
    /* COMPLETAR */
    return q->size;
}

queue queue_dequeue(queue q) {
    assert(invrep(q) && !queue_is_empty(q));
    struct s_node * killme=q->first;
    q->first = q->first->next;
    killme = destroy_node(killme);
    q->size =q->size-1;
    assert(invrep(q));
    return q;

}

void queue_dump(queue q, FILE *file) {
    file = file==NULL ? stdout: file;
    struct s_node *node=q->first;
    fprintf(file, "[ ");
    while(node!=NULL) {
        fprintf(file, "%d", node->elem);
        node = node->next;
        if (node != NULL) {
            fprintf(file, ", ");
        }
    }
    fprintf(file, "]\n");
}

queue queue_disscard(queue q, unsigned int n) {
    if (queue_is_empty(q) || n >= queue_size(q)) {
        return q;
    }
    if (n == 0) {
        return queue_dequeue(q);
    }
    struct s_node* prev = NULL;
    struct s_node* curr = q->first;
    for (unsigned int i = 0; i < n; i++) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    free(curr);
    q->size--;
    return q;
}

queue queue_destroy(queue q) {
    assert(invrep(q));
    struct s_node *node=q->first;
    while (node != NULL) {
        struct s_node *killme=node;
        node = node->next;
        killme = destroy_node(killme);
    }
    free(q);
    q = NULL;
    assert(q == NULL);
    return q;
}

