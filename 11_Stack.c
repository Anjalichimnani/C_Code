#include <stdio.h>
#include <stdbool.h>

int MAXSIZE = 5;
int stack[5];
int top = -1;

bool isEmpty () {
    
    if (top == -1)
        return true;
    return false;
}

bool isFull() {
    
    if(top == MAXSIZE - 1)
        return true;
    return false;
}

int peek() {
    if (!isEmpty())
        return stack[top];
    
    printf("Stack is Empty");
    return -1;
}

bool push(int data) {
    
    if(!isFull()) {
        stack[++top] = data;
        return true;
    }
    return false;
}

int pop() {
    
    if(!isEmpty())
        return stack[top--];
    
    printf("Stack is Empty");
    return -1;
}

void main () {
    
    printf ("Stack Implementation in Array:\n\n");
    
    push (10);
    push (20);
    push (30);
    push (40);
    push (50);
    
    printf("Element at the top of the Stack is:%d\n", peek());
    
    printf("The Stack is Full:%s\n",isFull()?"True":"False");
    
    printf("Stack Elements are:\n");
    while(!isEmpty())
        printf("%d\n",pop());
    
    printf("The Stack is Empty:%s\n",isEmpty()?"True":"False");
    printf("The Stack is Full:%s\n",isFull()?"True":"False");
}