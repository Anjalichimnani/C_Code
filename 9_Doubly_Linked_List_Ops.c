#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int key;
    int data;
    
    struct node *next;
    struct node *prev;
};

struct node *HEAD = NULL;
struct node *LAST = NULL;
struct node *CURRENT = NULL;

bool isEmpty (struct node *HEAD) {
    return HEAD == NULL;
}

int length(struct node *HEAD) {
    
    int count = 0;
    CURRENT = HEAD;
    
    while (CURRENT != NULL) {
        count++;
        CURRENT = CURRENT->next;
    }
    
    return count;
}

//display the List from first to last
void printForward(struct node *HEAD) {
    CURRENT = HEAD;
    
    printf ("[ ");
    
    while (CURRENT != NULL) {
        printf("(%d, %d) ", CURRENT->key, CURRENT->data);
        CURRENT = CURRENT->next;
    }
    
printf ("]\n");
}

//display the List from last to first
void printBackward(struct node *LAST) {
    CURRENT = LAST;
    
    printf ("[ ");
    
    while (CURRENT != NULL) {
        printf("(%d, %d) ", CURRENT->key, CURRENT->data);
        CURRENT = CURRENT->prev;
    }
    
printf ("]\n");
}

//insert link at First Location
void insertFirst(int key, int data) {
    
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->key = key;
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    
    if(isEmpty(HEAD))
        LAST = newNode;
    else
        HEAD->prev = newNode;
    
    newNode->next = HEAD;
    
    HEAD = newNode;
}

//insert link at Last Location
void insertLast(int key, int data) {
    
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->key = key;
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    
    if(isEmpty(HEAD))
        HEAD = newNode;
    else
        LAST->next = newNode;
    
    newNode->prev = LAST;
    
    LAST = newNode;
}

//Delete the first item
struct node* deleteFirst() {
    
    CURRENT=HEAD;
    
    if (isEmpty(CURRENT))
        return NULL;
    else {
        if(HEAD->next == NULL)
            LAST = NULL;
        else 
            CURRENT->next->prev = NULL;
        
        HEAD = CURRENT->next;
        CURRENT->next = NULL;
        
        return CURRENT;
    }
    
}

//Delete the last item
struct node* deleteLast() {
    
    CURRENT=LAST;
    
    if (isEmpty(CURRENT))
        return NULL;
    else {
        if(LAST->prev == NULL)
            HEAD = NULL;
        else 
            CURRENT->prev->next = NULL;
        
        LAST = CURRENT->prev;
        CURRENT->prev = NULL;
        
        return CURRENT;
    }
    
}

//find a link with a given key
struct node* find(int key) {
    
    CURRENT = HEAD;
    
    while (CURRENT != NULL) {
        if (CURRENT->key == key) 
            return CURRENT;
        CURRENT=CURRENT->next;
    }
    
    return NULL;
}

//delete a Link with a given key
struct node* delete (int key) {
    
    CURRENT = HEAD;
        
    while(CURRENT != NULL) {
        if (CURRENT->key == key) {
            if (CURRENT->prev !=NULL)
                CURRENT->prev->next = CURRENT->next;
            else
                HEAD = HEAD->next;
            
            if (CURRENT->next != NULL)
                CURRENT->next->prev = CURRENT->prev;
            else
                LAST = CURRENT->prev;
            
            CURRENT->next = NULL;
            CURRENT->prev = NULL;
            return CURRENT;
        }
        
        CURRENT = CURRENT->next;
    }
    
    return NULL;
}

//insert after a given key
bool insertAfter (int key, int newKey, int newData) {
    
    CURRENT = HEAD;
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->key = newKey;
    newNode->data = newData;
    newNode->next = NULL;
    newNode->prev = NULL;
    
    while (CURRENT !=NULL) {
        
        if (CURRENT->key == key) {
            if(CURRENT->next == NULL)
                LAST = newNode;
            else
                CURRENT->next->prev = newNode;
            
            newNode->next = CURRENT->next;
            CURRENT->next = newNode;
            newNode->prev = CURRENT;
            
            return true;
        }
        
        CURRENT = CURRENT-> next;
    }
    
    return false;
}


void main() {
    
    printf("Doubly Linked List Implementation:\n\n");
    
    printf("Doubly Linked List is: \n");
    printForward(HEAD);
    
    printf("List is Empty: %s\n", isEmpty(HEAD) ? "true" : "false");
    
    insertFirst(1, 10);
    insertFirst(2, 5);
    insertFirst(3, 30);
    insertFirst(4, 6);
    insertFirst(5, 50);
    insertFirst(6, 60);
    insertLast(0, -1);
    insertLast(0, -2);
    
    printf("Doubly Linked List from first to last is: \n");
    printForward(HEAD);
    
    printf("Doubly Linked List from last to first is: \n");
    printBackward(LAST);
    
    printBackward(HEAD);
    
    //delete the First Node
    struct node *tempLink = deleteFirst();
    if(tempLink == NULL)
        printf("List is Empty");
    else 
        printf ("Deleted First Node is: (%d, %d)\n", tempLink->key, tempLink->data);
    
    printf("Linked List is: \n");
    printForward(HEAD);
    
    tempLink = deleteLast();
    if(tempLink == NULL)
        printf("List is Empty");
    else 
        printf ("Deleted last Node is: (%d, %d)\n", tempLink->key, tempLink->data);
    
    printf("Linked List is: \n");
    printForward(HEAD);
    
    printf("Length of the List is %d\n", length(HEAD));
    insertFirst(3, 30); 
    printf("Length of the List is %d\n", length(HEAD));

    printf("Linked List is: \n");
    printForward(HEAD);
    
    //delete the Node with key 2
    tempLink = delete(2);
    if(tempLink == NULL)
        printf("List is Empty");
    else 
        printf ("Deleted Node is: (%d, %d)\n", tempLink-> key, tempLink->data);

    printf("Linked List is: \n");
    printForward(HEAD);
    
    //insert after node with key 4
    bool inserted = insertAfter(0, 100, 100);
    if (inserted)
        printf ("Node is inserted after key 4\n");
    else
        printf ("Node with key 4 not found\n");
    
    printf("Linked List is: \n");
    printBackward(LAST);

}