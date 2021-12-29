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

//display the List
void printList(struct node *HEAD) {
    CURRENT = HEAD;
    
    printf ("[ ");
    
    while (CURRENT != NULL) {
        printf("(%d, %d) ", CURRENT->key, CURRENT->data);
        CURRENT = CURRENT->next;
    }
    
printf ("]\n");
}

//insert link at First Location
void insertFirst(int key, int data) {
    
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->key = key;
    newNode->data = data;
    newNode->next = HEAD;
    
    HEAD = newNode;
}

bool isEmpty (struct node *HEAD) {
    return HEAD == NULL;
}

struct node* deleteFirst() {
    
    CURRENT=HEAD;
    
    if (isEmpty(CURRENT))
        return NULL;
    else {
        HEAD = CURRENT->next;
        CURRENT->next = NULL;
        
        return CURRENT;
    }
    
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
struct node* deleteLink (int key) {
    
    CURRENT = HEAD;
    struct node* previous = NULL;
        
    while(CURRENT != NULL) {
        if (CURRENT->key == key) {
            if (previous !=NULL)
                previous->next = CURRENT->next;
            else
                HEAD = HEAD->next;
            CURRENT->next = NULL;
            return CURRENT;
        }
        previous = CURRENT;
        CURRENT = CURRENT->next;
    }
    
    return NULL;
}

//sort the list based on the data
void sort(struct node *HEAD) {
    int i, j, k, tempdata, size;
    struct node* next = NULL;
    
    size = length(HEAD);
    k = size;
    
    for (i=0; i < k - 1; i++, k--) {
        CURRENT = HEAD;
        next = CURRENT-> next;
        
        for (j = 1; j < k; j++) {
            if (CURRENT->data > next->data) {
                tempdata = CURRENT->data;
                CURRENT->data = next->data;
                next->data = tempdata;
                
                tempdata = CURRENT->key;
                CURRENT->key = next->key;
                next->key = tempdata;
            }
            CURRENT = next;
            next=next->next;
        }
    }
}

//reverse the Linked List
void reverse() {
    
    struct node* previous = NULL;
    struct node* next;
    CURRENT = HEAD;
    next = CURRENT->next;
    
    while (CURRENT->next != NULL) {
        
        CURRENT->next = previous;
        previous = CURRENT;
        CURRENT = next;
        next = next->next;
        
    } 
    
    CURRENT->next = previous;
    HEAD = CURRENT;
}

void main() {
    
    printf("Linked List Implementation:\n\n");
    
    printf("Linked List is: \n");
    printList(HEAD);
    
    printf("List is Empty: %s\n", isEmpty(HEAD) ? "true" : "false");
    
    insertFirst(1, 10);
    insertFirst(2, 5);
    insertFirst(3, 30);
    
    printf("Linked List is: \n");
    printList(HEAD);
    
    //delete the First Node
    struct node *tempLink = deleteFirst();
    if(tempLink == NULL)
        printf("List is Empty");
    else 
        printf ("Deleted Node is: (%d, %d)\n", tempLink->key, tempLink->data);
    
    printf("Linked List is: \n");
    printList(HEAD);
    
    printf("Length of the List is %d\n", length(HEAD));
    insertFirst(3, 30); 
    printf("Length of the List is %d\n", length(HEAD));  

    struct node *foundLink = find(2);
    if (foundLink == NULL)
        printf("The key is not found in the list");
    else
        printf("The key is found in the list with data %d %d\n", foundLink->key, foundLink->data);
    
    //delete the Node with key 2
    tempLink = deleteLink(2);
    if(tempLink == NULL)
        printf("List is Empty");
    else 
        printf ("Deleted Node is: (%d, %d)\n", tempLink->key, tempLink->data);

    printf("Linked List is: \n");
    printList(HEAD);

    insertFirst(2, 5);
    
    sort(HEAD);
    printf("Linked List is: \n");
    printList(HEAD);
    
    reverse(HEAD);
    printf("Linked List is: \n");
    printList(HEAD);
}