#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "stack.h"

int main(){
    printf("------Testing stack struct-------");

    printf("\nStack: p -> (2, next) -> (3, NULL)\n");
	stack s = stack_empty();
	s = stack_push(s, 3);
	s = stack_push(s, 2);

    unsigned int size = stack_size(s);
	printf("Stack size : %u\n", size);
	printf("Stack is empty? %s\n", stack_is_empty(s) ? "true" : "false");
	printf("Stack to array: \n");
	int *array = stack_to_array(s);
	for(unsigned int i=0; i<size; i++)
		printf("array[%u] = %d\n", i, array[i]);
	free(array);
	printf("Stack top : %d\n", stack_top(s));

	printf("\nPop stack : \n");
	s = stack_pop(s);
	size = stack_size(s);
	printf("Stack size : %u\n", size);
	printf("Stack is empty? %s\n", stack_is_empty(s) ? "true" : "false");
	printf("Stack to array: \n");
	array = stack_to_array(s);
	for(unsigned int i=0; i<size; i++)
		printf("array[%u] = %d\n", i, array[i]);
	free(array);
	printf("Stack top : %d\n", stack_top(s));

	printf("\nPop stack : \n");
	s = stack_pop(s);
	size = stack_size(s);
	printf("Stack size : %u\n", size);
	printf("Stack is empty? %s\n", stack_is_empty(s) ? "true" : "false");
	
	stack_destroy(s);
	return 0;
}

