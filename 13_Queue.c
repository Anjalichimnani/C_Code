#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAXSIZE  6

int queue[MAXSIZE];
int front = 0, rear = -1, itemcount = 0;

int peek() {
    return queue[front];
}

bool isEmpty() {
    return itemcount == 0;
}

bool isFull () {
    return itemcount == MAXSIZE;
}

bool enqueue (int data) {
    
    if (isFull())
        return false;
    
    if (rear == MAXSIZE - 1)
        rear = -1;
    queue[++rear] = data;
    itemcount++;
    
    return true;
}

int dequeue () {
    
    int data = 0;
    
    if (isEmpty()) 
        return -1;
    
    data = queue[front++];
    itemcount--;
    
    if(front == MAXSIZE)
        front = 0;
    
    return data;
}

void main () {
    
    printf ("Queue Implementation\n");
    
    printf ("Queue is Empty :%s\n", isEmpty()? "true" : "false");
    
    enqueue (1);
    enqueue (2);
    enqueue (3);
    enqueue (4);
    enqueue (5);
    enqueue (6);
    
    printf ("Queue is Full :%s\n", isFull()? "true" : "false");
    
    printf ("First Element is: %d\n", peek());
    
    printf ("First Element Dequeued is: %d\n", dequeue());
    
    printf ("All Elements dequeued are: \n");
    while (!isEmpty())
        printf("%d\n",dequeue());
    
}