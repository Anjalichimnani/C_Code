#include <stdio.h>
#define MAX 5

int main() {
    
    int LA[MAX] = {1, 3, 5, 7};
    int n = 4, item = 4, i = 0, k = 3;
    
    printf("Original Array\n");
    
    //Print the Array elements
    for (int i = 0; i < n; i++)
        printf("LA[%d]=%d \n", i, LA[i]);
    
    //Move the elements one step upwards till the deletion position
    for (int i = k; i < n; i++)
        LA[i - 1] = LA[i];
        
    //Reduce the size of array
    n--;
    
    printf("After Insertion\n");
    
    //Print the Array elements after the change
    for (int i = 0; i < n; i++)
        printf("LA[%d]=%d \n", i, LA[i]);
    
    return 0;
}