#include<stdio.h>
#include<stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

void print_ll(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL");
}

struct Node* insert_node_at_beginning(struct Node* head, int val) {
    struct Node* current = (struct Node*) malloc(sizeof(struct Node));
    if (current == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return(NULL);
    }
    current->val = val;
    current->next = head;
    return current;
}

void free_ll(struct Node* head) {
    struct Node* current = head;
    struct Node* next = current;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main(void) {

    struct Node* prime_numbers;
    prime_numbers = insert_node_at_beginning(NULL, 2);
    prime_numbers = insert_node_at_beginning(prime_numbers, 3);
    prime_numbers = insert_node_at_beginning(prime_numbers, 5);
    prime_numbers = insert_node_at_beginning(prime_numbers, 7);
    prime_numbers = insert_node_at_beginning(prime_numbers, 11);
    prime_numbers = insert_node_at_beginning(prime_numbers, 13);

    print_ll(prime_numbers);
    free_ll(prime_numbers);

    printf("\nEnd of program.");
    return(0);
}