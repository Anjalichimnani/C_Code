#include <stdio.h>
#include <stdbool.h>

#define MAX 7
int intArray[MAX] = {9, 3, 1, 0, 5, 6, 4};

void printline (int count) {

  for (int i = 1; i < count; i++)
    printf("=");

  printf("=\n");
}

void display () {

  printf("[");

  for (int i=0; i<MAX; i++)
    printf("%d ", intArray[i]);

  printf("]\n");
}

void selectionSort () {

  int indexMin, i, j;

  for (i=0; i<MAX-1; i++) {

    indexMin = i;

    for (j=i+1; j<MAX; j++)
      if (intArray[j]<intArray[indexMin])
        indexMin = j;

    if (indexMin != i) {
      printf ("Items Swapped: [%d, %d]\n", intArray[i], intArray[indexMin]);

      int temp = intArray[indexMin];
      intArray[indexMin] = intArray[i];
      intArray[i] = temp;
    }

    printf ("Iteration #%d\n", i+1);
    display ();
  }
}

int main(void) {

  printf("Input Array: \n");
  display ();
  printline(50);
  selectionSort();
  printline(50);
  printf("Output Array:\n");
  display ();

  return 0;
}
