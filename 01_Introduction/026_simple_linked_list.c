#include<stdio.h>
#include<stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

void print_ll(struct Node* head) {
    struct Node* current = head;
    while(current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;        
    }
    printf("NULL\n");
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

    struct Node* prime_numbers = (struct Node*) malloc(sizeof(struct Node));
    if (prime_numbers == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return(1);
    }
    prime_numbers->val = 2;
    prime_numbers->next = NULL;
    

    prime_numbers->next = (struct Node*) malloc(sizeof(struct Node));
    if (prime_numbers->next == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        free_ll(prime_numbers);
        return(1);
    }
    prime_numbers->next->val = 3;
    prime_numbers->next->next = NULL;

    prime_numbers->next->next = (struct Node*) malloc(sizeof(struct Node));
    if (prime_numbers->next->next == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        free_ll(prime_numbers);
        return(1);
    }
    prime_numbers->next->next->val = 5;
    prime_numbers->next->next->next = NULL;

    print_ll(prime_numbers);

    free_ll(prime_numbers);

    printf("\n\nEnd of Program");
    return(0);
}