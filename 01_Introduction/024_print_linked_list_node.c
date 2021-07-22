/*
    Printing a linked list node with exact contents and address values.
*/
#include <stdio.h>
#include <stdlib.h>

// Linked list node
struct Node {
    int data;
    struct Node *next;
};

void print_node(struct Node **p2r_node) // by p2r_node we mean ptr_ptr_node
{
    printf("%15c----------------\n", ' ');
    printf("%p |%14d|\n", &((*p2r_node)->data), (*p2r_node)->data);
    printf("%15c|--------------|\n", ' ');
    printf("%p |%p|\n", &((*p2r_node)->next), (*p2r_node)->next);
    printf("%15c----------------\n", ' ');
    
}

int main()
{
    struct Node node1;
    struct Node node2;
    
    node1.data = 2;
    node1.next = &node2;
    
    struct Node *ptr_node1 = &node1;
    
    print_node(&ptr_node1);
    
	return 0;
}