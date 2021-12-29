#include <stdio.h>

int main() {
    
    int LA[] = {1, 3, 5, 7, 8};
    int n = 5, item = 10;
    
    printf("Original Array\n");
    
    //Print the Array elements
    for (int i = 0; i < n; i++)
        printf("LA[%d]=%d \n", i, LA[i]);
    
    //insert at the end of the array and increment the size of array
    LA[n++] = item;
    
    printf("After Insertion\n");
    
    //Print the Array elements after the change
    for (int i = 0; i < n; i++)
        printf("LA[%d]=%d \n", i, LA[i]);
    
    return 0;
}
