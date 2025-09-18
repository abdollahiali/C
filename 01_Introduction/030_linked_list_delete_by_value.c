#include<stdio.h>
#include<stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

void print_ll(struct Node* head) {
    struct Node* current = head;
    while (current) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL");
    return;
}

struct Node* create_node(int val) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    if (node == NULL) {
        fprintf(stderr, "Memory allocaiton failed.\n");
        return(NULL);
    }
    node->val = val;
    node->next = NULL;
    return(node);

}
struct Node* insert_node_at_specific_place(struct Node* head, int target_val, int val) {
    if(head == NULL)
        return NULL;
    struct Node* current  = head;
    while(current->next && current->val != target_val)
        current = current->next;
    if(current && current->val == target_val) {
        struct Node* node = create_node(val);
        node->next = current->next;
        current->next = node;
    }
    return(head);
}

struct Node* delete_by_value(struct Node* head, int target_val) {
    if(head == NULL)
        return(NULL);
    
    struct Node* current = head;
    struct Node* prev = NULL;
    while(current && (current->val != target_val)) {
        prev = current;
        current = current->next;
    }

    if(current && (current->val == target_val)) {
        prev->next = current->next;
        free(current);

    }
    return(head);
}

int main(void) {
    struct Node* prime_numbers = create_node(2);
    prime_numbers = insert_node_at_specific_place(prime_numbers, 2, 3);
    prime_numbers = insert_node_at_specific_place(prime_numbers, 3, 5);
    prime_numbers = insert_node_at_specific_place(prime_numbers, 5, 7);
    prime_numbers = insert_node_at_specific_place(prime_numbers, 7, 11);
    prime_numbers = insert_node_at_specific_place(prime_numbers, 11, 9);
    prime_numbers = insert_node_at_specific_place(prime_numbers, 9, 13);
    prime_numbers = insert_node_at_specific_place(prime_numbers, 13, 17);
    prime_numbers = insert_node_at_specific_place(prime_numbers, 17, 19);

    printf("The prime numbers contains the number 9:\n");
    print_ll(prime_numbers);

    prime_numbers = delete_by_value(prime_numbers, 9);
    printf("\n\nDeleting #9:\n");
    print_ll(prime_numbers);
    return(0);
}