/*
    Printing a linked list with exact contents and address values.
*/
#include <stdio.h>
#include <stdlib.h>

// Linked list node
struct Node {
    int data;
    struct Node *next;
};

void add_node(struct Node **ptr_head, int val);
void remove_node(struct Node **ptr_head, int val);
void print_node(struct Node *ptr_node) ;
void print_vertical_arrow();
void print_ll(struct Node **ptr_head);

int main()
{
    struct Node *head = NULL;
    print_ll(&head);
    
    printf("\n\nAdd node containing data 2 into the linked list.\n");
    add_node(&head, 2);
    print_ll(&head);
    
    printf("\n\nAdd node containing data 3 into the linked list.\n");
    add_node(&head, 3);
    print_ll(&head);
    
    printf("\n\nAdd node containing data 5 into the linked list.\n");
    add_node(&head, 5);
    print_ll(&head);
    
    printf("\n\nAdd node containing data 7 into the linked list.\n");
    add_node(&head, 7);
    print_ll(&head);
    
    printf("\nRemove node containing data 3 from the linked list.\n");
    remove_node(&head, 3);
    print_ll(&head);
    
    printf("\nRemove node containing data 7 from the linked list.\n");
    remove_node(&head, 7);
    print_ll(&head);
    
    printf("\nRemove node containing data 3 from the linked list.\n");
    remove_node(&head, 3);
    print_ll(&head);
    
	return 0;
}

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

void print_node(struct Node *ptr_node) 
{
    printf("%15c----------------\n", ' ');
    printf("%p |%14d|\n", ptr_node, (*ptr_node).data);
    printf("%15c|--------------|\n", ' ');
    printf("%p |%14p|\n", &((*ptr_node).next), (*ptr_node).next);
    printf("%15c----------------\n", ' ');
    
}

void print_vertical_arrow()
{
    printf("%15c        |\n", ' ');
    printf("%15c        |\n", ' ');
    printf("%15c        v\n", ' ');
}

void print_ll(struct Node **ptr_head)
{
    printf("\n****************************************************************************");
    printf("\n*                            Printing the linked list                      *");
    printf("\n****************************************************************************\n\n");

    printf("%15c/--------------\\\n", ' ');
    printf("%p |%14p|\n", ptr_head, *ptr_head);
    printf("%15c\\--------------/\n", ' ');
    *ptr_head ? print_vertical_arrow():printf(" ");;
    
    struct Node *head = *ptr_head;
    while(head) {
        print_node(head);
        head->next ? print_vertical_arrow():printf(" ");
        head = head->next;
    }
    
    printf("\n****************************************************************************\n\n");
}