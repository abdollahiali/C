/*
    Given a linked list and a value, finds (if any) the first entry containing that value, and removes that entry from the linked list
*/
#include <stdio.h>
#include <stdlib.h>

// Linked list node
struct Node {
    int data;
    struct Node *next;
};

void add_node(struct Node **ptr_head, int val)
{
    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
    if(!new_node) {
        printf("Heap is full. Cannot insert new node.");
        return;
    }
    
    new_node->data = val;
    new_node->next = *ptr_head;
    *ptr_head = new_node;
}

void remove_node(struct Node **ptr_head, int val)
{
    struct Node *removed_node;
    
    while(*ptr_head && ((*ptr_head)->data!=val))
        ptr_head = &((*ptr_head)->next);
    
    if(!*ptr_head) {
        printf("Node containing data %d not found.\n", val);
        return;
    }
    
    removed_node = *ptr_head;
    *ptr_head = (*ptr_head)->next;
    free(removed_node);
    printf("The first node containing data %d was removed.\n", val);
    return;
}

void print(struct Node *head)
{
    printf("\n-------------------------------------------------------------------\n");
    printf("The contents of the linked list:\n");
    while(head) {
        printf("%d%s", head->data, (head->next ? " -> ": "\n"));
        head = head->next;
    }
    printf("-------------------------------------------------------------------\n");
}

int main()
{
    struct Node *linkedlist = NULL;
    print(linkedlist);
    
    printf("\nAdd node containing data 2 into the linked list.\n");
    add_node(&linkedlist, 2);
    print(linkedlist);
    
    printf("\nAdd node containing data 3 into the linked list.\n");
    add_node(&linkedlist, 3);
    print(linkedlist);
    
    printf("\nAdd node containing data 5 into the linked list.\n");
    add_node(&linkedlist, 5);
    print(linkedlist);
    
    printf("\nAdd node containing data 7 into the linked list.\n");
    add_node(&linkedlist, 7);
    print(linkedlist);

    printf("\nRemove node containing data 3 from the linked list.\n");
    remove_node(&linkedlist, 3);
    print(linkedlist);
    
    printf("\nRemove node containing data 7 from the linked list.\n");
    remove_node(&linkedlist, 7);
    print(linkedlist);
    
    printf("\nRemove node containing data 3 from the linked list.\n");
    remove_node(&linkedlist, 3);
    print(linkedlist);
    
	return 0;
}