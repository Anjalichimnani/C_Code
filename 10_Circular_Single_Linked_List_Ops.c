#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int key;
    int data;
    
    struct node *next;
};

struct node *HEAD = NULL;
struct node *CURRENT = NULL;
struct node *ptr = NULL;

bool isEmpty (struct node *HEAD) {
    return HEAD == NULL;
}

int length(struct node *HEAD) {
    
    int count = 0;
    CURRENT = HEAD;
    
    if (isEmpty(HEAD))
        return 0;
    
    while (CURRENT->next != HEAD) {
        count++;
        CURRENT = CURRENT->next;
    }
    
    //Counting the last node
    return ++count;
}

//display the List from first to last
void printList(struct node *HEAD) {
    CURRENT = HEAD;
    
    printf ("[ ");
    
    if (!isEmpty(HEAD)) {
    
        while (CURRENT->next != HEAD) {
            printf("(%d, %d) ", CURRENT->key, CURRENT->data);
            CURRENT = CURRENT->next;
        }
        printf("(%d, %d) ", CURRENT->key, CURRENT->data);
    }
    printf ("]\n");
}

//insert link at First Location
void insertFirst(int key, int data) {
    
    ptr = HEAD;
    
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->key = key;
    newNode->data = data;
    newNode->next = NULL;
    
    if(isEmpty(HEAD)) {
        HEAD = newNode;
        HEAD->next = HEAD;
    }
    else {
        while (ptr->next != HEAD)
            ptr = ptr->next;
        
        newNode->next = HEAD;
        HEAD = newNode;
        ptr->next = HEAD;
    }
}

//insert link at Last Location
void insertLast(int key, int data) {
    
    ptr = HEAD;
    
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->key = key;
    newNode->data = data;
    newNode->next = NULL;
    
    if(isEmpty(HEAD)) {
        HEAD = newNode;
        newNode->next = HEAD;
    }
    else {
        while (ptr->next != HEAD)
            ptr = ptr->next;
        
        newNode->next = HEAD;
        ptr->next = newNode;
    }
    
}

//Delete the first item
struct node* deleteFirst() {
    
    ptr = HEAD;
    
    CURRENT=HEAD;
    
    if (isEmpty(CURRENT))
        return NULL;
    else {
        while (ptr->next != HEAD)
            ptr = ptr->next;
        
        HEAD = HEAD->next;
        ptr->next = HEAD;
        CURRENT->next = NULL;
        
        return CURRENT;
    }
    
}

//Delete the last item
struct node* deleteLast() {
    
    struct node *previous = NULL;
    
    CURRENT=HEAD;
    ptr = HEAD;
    
    if (isEmpty(CURRENT))
        return NULL;
    
    if (CURRENT->next == HEAD) {
            HEAD = NULL;            
            CURRENT->next = NULL;
            return CURRENT;
    }
    
    while(ptr->next != HEAD) {
        previous = ptr;
        ptr = ptr->next;
    }

    previous->next = HEAD;
    CURRENT = ptr;
    CURRENT->next = NULL;
    
    return CURRENT;
    
}

//find a link with a given key
struct node* find(int key) {
    
    CURRENT = HEAD;
    
    if(isEmpty(HEAD))
        return NULL;
    
    while (CURRENT->next != HEAD) {
        if (CURRENT->key == key) 
            return CURRENT;
        CURRENT=CURRENT->next;
    }
    if (CURRENT->key == key) 
        return CURRENT;
    
    return NULL;
}

//delete a Link with a given key
struct node* delete (int key) {
    
    struct node *previous = NULL;
    CURRENT = HEAD;
    
    if(isEmpty(HEAD))
        return NULL;
        
    while(CURRENT->next != NULL) {
        if (CURRENT->key == key) {
            if (CURRENT == HEAD) 
                return deleteFirst();
            
            previous->next = CURRENT->next;
            CURRENT->next = NULL;
            
            return CURRENT;
        }
        
        previous = CURRENT;
        CURRENT = CURRENT->next;
    }
    if(CURRENT->key == key)
        return deleteLast();
    
    return NULL;
}

//insert after a given key
bool insertAfter (int key, int newKey, int newData) {
    
    CURRENT = HEAD;
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->key = newKey;
    newNode->data = newData;
    newNode->next = NULL;
    
    while (CURRENT->next != HEAD) {
        
        if (CURRENT->key == key) {
            newNode->next = CURRENT->next;
            CURRENT->next = newNode;
            
            return true;
        }
        
        CURRENT = CURRENT-> next;
    }
    
    if (CURRENT->key == key) {
        newNode->next = CURRENT->next;
        CURRENT->next = newNode;
            
        return true;
    }
    
    return false;
}

void main() {
    
    printf("Circular Single Linked List Implementation:\n\n");
    
    printf("Circular Single Linked List is: \n");
    printList(HEAD);
    
    printf("List is Empty: %s\n", isEmpty(HEAD) ? "true" : "false");
    printf("Length of the List is %d\n", length(HEAD));
    
    insertFirst(1, 10);
    insertFirst(2, 5);
    insertFirst(3, 30);
    insertFirst(4, 6);
    insertFirst(5, 50);
    insertFirst(6, 60);
    insertLast(0, -1);
    insertLast(0, -2);
    
    printf("Length of the List is %d\n", length(HEAD));
    
    printf("Circular Single Linked List from first to last is: \n");
    printList(HEAD);
    
    //delete the First Node
    struct node *tempLink = deleteFirst();
    if(tempLink == NULL)
        printf("List is Empty");
    else 
        printf ("Deleted First Node is: (%d, %d)\n", tempLink->key, tempLink->data);
    
    printf("Circular Single Linked List is: \n");
    printList(HEAD);
    
    tempLink = deleteLast();
    if(tempLink == NULL)
        printf("List is Empty");
    else 
        printf ("Deleted last Node is: (%d, %d)\n", tempLink->key, tempLink->data);
    
    printf("Circular Single Linked List is: \n");
    printList(HEAD);
    
    printf("Length of the List is %d\n", length(HEAD));
    
    //delete the Node with key 5
    tempLink = delete(5);
    if(tempLink == NULL)
        printf("List is Empty");
    else 
        printf ("Deleted Node is: (%d, %d)\n", tempLink-> key, tempLink->data);

    printf("Linked List is: \n");
    printList(HEAD);
    
    //delete the Node with key 0
    tempLink = delete(0);
    if(tempLink == NULL)
        printf("List is Empty");
    else 
        printf ("Deleted Node is: (%d, %d)\n", tempLink-> key, tempLink->data);

    printf("Linked List is: \n");
    printList(HEAD);

    //insert after node with key 4
    bool inserted = insertAfter(1, 100, 100);
    if (inserted)
        printf ("Node is inserted after key 4\n");
    else
        printf ("Node with key 4 not found\n");
    
    printf("Linked List is: \n");
    printList(HEAD);

}