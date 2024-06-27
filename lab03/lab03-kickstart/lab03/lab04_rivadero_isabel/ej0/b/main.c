#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "data.h"

void
print_data(data_t d) {
    printf("NOMBRE: %s\n"
           "EDAD  : %d años\n"
           "ALTURA: %d cm\n\n",
           d.name, d.age, d.height);
}

void set_name(name_t new_name, data_t *d) {
    /* COMPLETAR */
    strcpy(d->name, new_name);
}

int main(void) {

    data_t messi = {"Leo Messi", 35, 169};
    print_data(messi);
    name_t messi_full_name = "Lionel Messi";
    /* COMPLETAR */
    data_t *d=NULL;
    d= &messi;
    set_name(messi_full_name,d);
    print_data(messi);

    return EXIT_SUCCESS;
}

