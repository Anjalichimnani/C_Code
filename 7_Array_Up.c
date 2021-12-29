#include <stdio.h>
#define MAX 5

void main() {
    
    int LA[MAX] = {1, 3, 5, 7};
    int n = 4, item = 4, k = 3;
    
    printf("Original Array\n");
    
    //Print the Array elements
    for (int i = 0; i < n; i++)
        printf("LA[%d]=%d \n", i, LA[i]);
    
    //Update the value item in array LA at position k
    LA[k - 1] = item;
    
    printf("After Update\n");
    
    //Print the Array elements after the change
    for (int i = 0; i < n; i++)
        printf("LA[%d]=%d \n", i, LA[i]);

}