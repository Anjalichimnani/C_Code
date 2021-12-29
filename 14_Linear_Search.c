#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAXSIZE  10

int array[MAXSIZE] = {1,2,3,4,5,6,7,8,9,10};

int linearSearch (int data) {
    
    for (int i = 0; i < MAXSIZE; i++) 
        if (array[i] == data)
            return i;
    return -1;
}

void main () {
    
    int value = 6, index = -1;
    
    printf ("Linear Search Implementation\n");
    
    printf ("Value to be searched %d\n", value);
    
    index = linearSearch(value);
    if (index != -1)
        printf ("Value found at location %d\n", index+1);
    else
        printf ("Value not found");
    
    value = 19;
    
    printf ("Value to be searched %d\n", value);
    
    index = linearSearch(value);
    if (index != -1)
        printf ("Value found at location %d\n", index+1);
    else
        printf ("Value not found");
    
}