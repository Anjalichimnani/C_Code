#include <stdio.h>
#include <stdbool.h>

#define MAX 7
int intArray[MAX] = {1, 9, 0, 4, 3, 2, 5};

void printline (int count) {

  for (int i = 1; i<count; i++)
    printf ("=");

  printf ("=\n");
}

void display () {
  printf("[");

  for (int i = 0; i < MAX; i++)
    printf ("%d ", intArray[i]);

  printf("]\n");
}

void insertionSort () {

  int valueToInsert;
  int holePosition;

  for (int i = 1; i < MAX; i++) {

    valueToInsert = intArray[i];
    holePosition = i;

    while (holePosition > 0 && intArray[holePosition - 1] > valueToInsert) {
      intArray[holePosition] = intArray[holePosition - 1];
      holePosition--;
      printf (" Item Moved: %d\n", intArray[holePosition]);
    }

    if (holePosition != i) {
      printf (" Item Inserted: %d\n", valueToInsert);
      intArray[holePosition] = valueToInsert;
    }

    printf ("Iteration #%d\n", i);
  }
}

int main (void) {

  printf ("Input Array: ");
  display();
  printline(50);
  insertionSort();
  printline(50);
  printf("Output Array: ");
  display();
  return 0;
}
