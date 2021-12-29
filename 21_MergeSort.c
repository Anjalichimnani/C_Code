#include <stdio.h>

#define MAX 10
int array[MAX] = {9, 4, 5, 0, 1, 6, 7, 2, 3, 8};
int b[MAX];

void merging(int low, int mid, int high) {

  int l1, l2, i;

  for (l1=low, l2=mid+1, i=low; l1<=mid && l2<=high; i++) {
    if (array[l1] <= array[l2])
      b[i] = array[l1++];
    else
      b[i] = array[l2++];
  }

  while (l1<=mid)
    b[i++]= array[l1++];

  while (l2<=high)
    b[i++]= array[l2++];

  for(i=low; i<=high; i++)
    array[i] = b[i];
}

void sort (int low, int high) {
  printf("Low:%d, High:%d\n", low, high);
  int mid;

  if (low < high) {
    mid = (low + high)/2;

    sort(low, mid);
    sort(mid+1, high);

    printf("Low:%d , Mid:%d , High:%d\n", low, mid, high);
    merging(low, mid, high);
  }
  else {
    return;
  }

}



void display () {

  printf("[");

  for (int i=0; i<MAX; i++)
    printf("%d ", array[i]);

  printf("]\n");
}

int main (void) {

  printf("Input Array: ");
  display ();
  sort(0, MAX-1);

  printf("Output Array: ");
  display ();

  return 0;
}
