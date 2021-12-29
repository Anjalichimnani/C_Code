#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAXSIZE  20

int array[MAXSIZE] = {1,2,3,4,5,6,7,8,9,10,16,18,25,28,39,40,53,65,71,89};

int binarySearch (int data) {
    
    int lower = 0, upper = MAXSIZE - 1, mid = -1;
    
    while (lower <= upper) {
        mid = lower + (upper - lower)/2;
        
        if (array[mid] == data)
            return mid;
        
        if (array[mid] < data)
            lower = mid + 1;
        else 
            upper = mid - 1;
    }
    
    return -1;
}

void main () {
    
    int value = 89, index = -1;
    
    printf ("Binary Search Implementation\n");
    
    printf ("Value to be searched %d\n", value);
    
    index = binarySearch(value);
    if (index != -1)
        printf ("Value found at location %d\n", index+1);
    else
        printf ("Value not found");
    
    value = 19;
    
    printf ("Value to be searched %d\n", value);
    
    index = binarySearch(value);
    if (index != -1)
        printf ("Value found at location %d\n", index+1);
    else
        printf ("Value not found");
    
}