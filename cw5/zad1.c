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
    add_first(&head, 0);
    print_list(head);
    return 0;
}