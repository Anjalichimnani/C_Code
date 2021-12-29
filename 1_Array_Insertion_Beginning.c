#include <stdio.h>
#define MAX 5

int main() {
    
    int LA[MAX] = {1, 3, 5, 7};
    int n = 4, item = 11, i = 0;
    
    printf("Original Array\n");
    
    //Print the Array elements
    for (int i = 0; i < n; i++)
        printf("LA[%d]=%d \n", i, LA[i]);
    
    //Move the elements one step downwards
    for (i = n; i > 0; i--)
        LA[i] = LA [i - 1];
    
    //insert at the beginning of the array and increment the size of array
    LA[0] = item;
    n++;
    
    printf("After Insertion\n");
    
    //Print the Array elements after the change
    for (int i = 0; i < n; i++)
        printf("LA[%d]=%d \n", i, LA[i]);
    
    return 0;
}
