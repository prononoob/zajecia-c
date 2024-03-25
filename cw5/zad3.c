#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int val;
    struct node* next;
} node_t;

void add_first(node_t** head, int value) {
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    newNode->val = value;
    newNode->next = *head;
    *head = newNode;
}

void pop(node_t** head) {
    if (*head == NULL) {
        printf("\nLista jest pusta");
        return;
    }

    node_t* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void remove_last(node_t** head) {
    if (*head == NULL) {
        printf("\nLista jest pusta");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    // tu reszta ***** nie teraz juz blagam
}

void print_list(node_t* head) {
    node_t* cur = head;
    printf("\n");
    while (cur != NULL) {
        printf("%d ", cur->val);
        cur = cur->next;
    }
}

int main() {
    node_t* head = NULL;
    head = (node_t*)malloc(sizeof(node_t));
    if (head == NULL) {
        return 1;
    }
    head->val = 1;
    head->next = NULL;
    add_first(&head, 6);
    add_first(&head, 7);
    add_first(&head, 8);
    add_first(&head, 9);
    add_first(&head, 0);
    print_list(head);
    pop(&head);
    pop(&head);
    print_list(head);
    return 0;
}