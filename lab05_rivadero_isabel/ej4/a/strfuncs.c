#include "strfuncs.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

size_t string_length(const char *str){
    unsigned int i=0u;
    while(str[i]!= '\0'){
      i++;
    }
    return i-1;
}

char *string_filter(const char *str, char c){
    char *new_str= NULL;
    unsigned int i=0u;
    unsigned int j=0u;

    size_t len = string_length(str);
    new_str = (char*) malloc(len + 1);
    
    while(str[i]!= '\0'){
      if(str[i]!= c){
        new_str[j]= str[i] ;
        j++;
      }
      i++;
    }
    new_str[j] = '\0'; 

    return new_str;
}



