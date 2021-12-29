#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 5

struct DataItem {
  int key;
  int data;
};

struct DataItem* hashArray[SIZE];
struct DataItem* dummyItem;
struct DataItem* item;

int hashCode (int key) {
  return key % SIZE;
}

struct DataItem* search(int key) {

  //get the Hash Index
  int hashIndex = hashCode(key);
  int count = 0;

  //move in the Array until an empty location is found
  while (hashArray[hashIndex] != NULL && count < SIZE) {

    if (hashArray[hashIndex]->key == key)
      return hashArray[hashIndex];

    ++hashIndex;

    hashIndex %= SIZE;
    ++count;
  }

  return NULL;
}

void insert (int key, int data) {
  item = (struct DataItem*) malloc (sizeof(struct DataItem));
  item->data = data;
  item->key = key;

  int hashIndex = hashCode(key);
  int count = 0;

  while (hashArray[hashIndex] != NULL && hashArray[hashIndex]->key !=-1 && count++ < SIZE) {
    ++hashIndex;

    hashIndex %= SIZE;
  }

  if (count<SIZE)
    hashArray[hashIndex]=item;
  else
    printf("Not Inserted\n");
}

struct DataItem* delete (int key) {

  int hashIndex = hashCode(key);
  int count = 0;

  while (hashArray[hashIndex] != NULL && count < SIZE) {

    if (hashArray[hashIndex]->key == key) {
      struct DataItem* temp = hashArray[hashIndex];

      hashArray[hashIndex] = dummyItem;
      return temp;
    }

    ++hashIndex;

    hashIndex %= SIZE;
    ++count;
  }

  return NULL;
}

void display() {

  for (int i=0; i<SIZE; i++) {

    if (hashArray[i] != NULL && hashArray[i]->key != -1)
      printf (" Key: %d, Value: %d ", hashArray[i]->key, hashArray[i]->data);
    else
      printf (" ~~ ");
  }

  printf("\n");
}

int main(void) {

  dummyItem = (struct DataItem*) malloc (sizeof(struct DataItem));
  dummyItem->key = -1;
  dummyItem->data = -1;

  insert(1, 20);
  insert(2, 70);
  insert(42, 80);
  insert(4,25);
  insert(12,44);
  insert(14,32);
  //insert(17,11);
  //insert(13,78);
  //insert(37,97);

  display();

  item = search(37);

  if (item != NULL)
    printf("Element Found: %d %d\n", item->key, item->data);
  else
    printf("Element Not Found\n");

  item = search(97);

  if (item != NULL)
    printf("Element Found: %d %d\n", item->key, item->data);
  else
    printf("Element Not Found\n");

  delete(37);

  display();

  return 0;
}
