#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXSIZE  20

int array[MAXSIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 20, 21};

int interpolationSearch (int data) {
    
    int lower = 0, upper = MAXSIZE - 1, mid = 0;
    
    while (lower <= upper) {
        mid = lower + abs(((upper - lower)*(data - array[lower]))/(array[upper] - array[lower]));
        
        if (array[mid] == data)
            return mid;
        
        if (array[mid] < data) {
            lower = mid + 1;
        }
        else 
            upper = mid - 1;
        
        printf("Mid: %d, Lower: %d, Upper: %d", mid, lower, upper);
    }
    
    return -1;
}

void main () {
    
    int value = 19, index = -1;
    
    printf ("Interpolation Search Implementation\n");
    
    printf ("Value to be searched %d\n", value);
    
    index = interpolationSearch(value);
    if (index != -1)
        printf ("Value found at location %d\n", index+1);
    else
        printf ("Value not found\n");
    
    value = 15;
    
    printf ("Value to be searched %d\n", value);
    
    index = interpolationSearch(value);
    if (index != -1)
        printf ("Value found at location %d\n", index+1);
    else
        printf ("Value not found\n");
    
}