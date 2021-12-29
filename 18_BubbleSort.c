#include <stdio.h>
#include <stdbool.h>

#define MAX 10
//int list[MAX] = {9, 3, 4, 0, 1, 2, 5, 6, 8, 7};
//int list[MAX] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int list[MAX] = {0, 1, 2, 3, 4, 9, 8, 7, 6, 5};

void bubbleSort () {

  int temp;
  bool swapped = false;

  for (int i = 0; i < MAX - 1; i++) {
    swapped = false;
    printf("\nIteration #%d\n", i+1);

    for (int j = 0; j < MAX-1-i; j++) {

      printf("   Items Compared: [%d, %d]: ", list[j], list[j+1]);

      if (list[j] > list[j+1]) {
        temp = list[j];
        list[j] = list[j+1];
        list[j+1] = temp;

        swapped = true;
        printf("[%d, %d] => Swapped\n", list[j], list[j+1]);
      }
      else
        printf("[%d, %d] => Not Swapped\n", list[j], list[j+1]);
    }

    if (!swapped)
      break;
  }
}

void display() {

  printf ("[");
  for (int i = 0; i < MAX; i++)
    printf("%d ", list[i]);
  printf("]\n");
}

int main(void) {

  printf("Input Array: ");
  display();
  bubbleSort();
  printf("\nOutput Array: ");
  display();

  return 0;
}
