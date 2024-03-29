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

void print_node(struct Node *ptr_node) 
{
    printf("%15c----------------\n", ' ');
    printf("%p |%14d|\n", ptr_node, (*ptr_node).data);
    printf("%15c|--------------|\n", ' ');
    printf("%p |%p|\n", &((*ptr_node).next), (*ptr_node).next);
    printf("%15c----------------\n", ' ');
    
}

int main()
{
    struct Node node1;
    struct Node node2;
    
    node1.data = 2;
    node1.next = &node2;
    
    struct Node *ptr_node1 = &node1;
    
    print_node(ptr_node1);
    
	return 0;
}