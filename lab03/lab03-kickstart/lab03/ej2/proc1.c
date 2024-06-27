#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>

void absolute(int x, int y) {
    // Completar aquí //
    if(x>=0){
        y= x;
    }else{
        y=-x;
    }
}

int main(void) {
    int a=0, res=0;
    // Completar aquí //
    a= -10;
    absolute(a, res);
    fprintf(stdout, "a %d \n", a);
    fprintf(stdout, "res %d \n", res);
    
    return EXIT_SUCCESS;
}

/* muestra por pantalla:
a -10
res 0
No coincide con el lenguaje visto en el teorico
*/  
