#include <stdio.h>
#define MAX 5

int main() {
    
    int LA[MAX] = {1, 3, 5, 7};
    int n = 4, item = 5, i = -1;
    
    //Search the value item in array LA
    for (i = 0; i < n; i++)
        if(LA[i] == item)
            break;
        
    if (i < n)
        printf("The value %d is found at %d location", item, i+1);
    else
        printf("The value %d is not found at %d location", item, i+1);
    
    
    return 0;
}