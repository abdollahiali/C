#include<stdio.h>
#include<stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

struct Node* create_node(int val) {
    struct Node* head = (struct Node*) malloc(sizeof(struct Node));
    if (head == NULL) {
        fprintf(stderr, "Memory allocaiton failed.\n");
        return(NULL);
    }
    head->val = val;
    head->next = NULL;
    return(head);
}

struct Node* insert_node_at_end(struct Node* head, int val) {
    struct Node* current = head;
    struct Node* node = create_node(val);
    if(current == NULL)
        return(node);
    while(current->next != NULL)
        current = current->next;
    current->next = node;
    return(head);
}

void print_ll(struct Node* head) {
    struct Node* current = head;
    while(current) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL");
}

void free_ll(struct Node* head) {
    struct Node* current = head;
    struct Node* next;
    while(current) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main(void) {

    struct Node* prime_numbers = create_node(2);
    prime_numbers = insert_node_at_end(prime_numbers, 3);
    prime_numbers = insert_node_at_end(prime_numbers, 5);
    prime_numbers = insert_node_at_end(prime_numbers, 7);
    prime_numbers = insert_node_at_end(prime_numbers, 11);
    prime_numbers = insert_node_at_end(prime_numbers, 13);
    prime_numbers = insert_node_at_end(prime_numbers, 17);
    prime_numbers = insert_node_at_end(prime_numbers, 19);

    print_ll(prime_numbers);
    free_ll(prime_numbers);

    return(0);

}