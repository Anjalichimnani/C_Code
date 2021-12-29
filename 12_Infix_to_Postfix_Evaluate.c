#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAXSIZE  25

char stack[MAXSIZE];
int top = -1;

int stack_int[25];
int top_int = -1;

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

void push(char data) {
    
    if(!isFull())
        stack[++top] = data;
}

char pop() {
    
    if(!isEmpty())
        return stack[top--];
    
    printf("Stack is Empty");
    return -1;
}

void push_int(int val) {
    stack_int [++top_int] = val;    
}

int pop_int() {
    return stack_int [top_int--];    
}

int isOperator(char symbol) {
    
    switch(symbol) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        case '(':
        case ')':
        case '#': return 1;
                  break;
        default: return 0;
    }
    
}

int precedence (char operator) {
    
    switch (operator) {
        case '+':
        case '-': return 2;
                  break;
        case '*':
        case '/': return 3;
                  break;
        case '^': return 4;
                  break;
        case '(': 
        case ')': 
        case '#': return 1;
                  break;
        
    }
    
}

void convert(char infix[], char postfix[]) {
    
    int i = 0, j = 0;
    char symbol;
    push('#');
    
    for (i=0; i<strlen(infix); i++) {
        symbol = infix[i];
        
        if(!isOperator(symbol)) 
            postfix[j++] = symbol;
        else {
            if (symbol == '(')
                push (symbol);
            else {
                if (symbol == ')') {
                    while (stack[top] != '(')
                        postfix[j++] = pop();
                    
                    pop();
                }
                else {
                    if(precedence(symbol)>precedence(stack[top]))
                        push(symbol);
                    else {
                        while(precedence(stack[top])>=precedence(symbol))
                            postfix[j++] = pop();
                        
                        push (symbol);
                    }
                }
            }
        }
    
    }
    
    while (stack[top] != '#')
            postfix[j++] = pop();
        
    postfix[j] = '\0';
}

int evaluate (char *postfix) {
    
    int operand1=0, operand2=0, j = 0;
    char symbol = postfix[0];
    
    while ( (symbol = postfix[j++]) != '\0') {
        
        if (isdigit(symbol))
            push_int ((int)symbol - '0');
        else {
            
            operand1 = pop_int();
            operand2 = pop_int();
            
            switch (symbol) {
                case '+': push_int (operand1 + operand2);
                          break;
                case '-': push_int (operand1 - operand2);
                          break;
                case '*': push_int (operand1 * operand2);
                          break;
                case '/': push_int (operand1 / operand2);
                          break;
            }
        }

    }
    
    return pop_int();
    
}

void main () {
    
    char infix[25] = "(1+2)*3";
    char postfix[25] = "";
    
    convert (infix, postfix);
    
    printf ("Infix Expression is:%s\n", infix);
    printf ("Postfix Expression is:%s\n", postfix);
    printf ("Postfix Expression Evaluation is:%d\n", evaluate(postfix));
}