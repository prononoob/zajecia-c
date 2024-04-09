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
        printf("Lista jest pusta.\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    node_t* current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
}

void remove_by_index(node_t** head, int index) {
    if (*head == NULL || index < 0) {
        printf("Lista jest pusta lub indeks jest ujemny\n");
        return;
    }

    // Usuwanie jesli to pierwszy element
    if (index == 0) {
        node_t* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    node_t* current = *head;
    int i;
    for (i = 0; i < index - 1 && current != NULL; i++) {
        current = current->next;
    }

    // Jesli ten lub nastepny indeks jest null to znaczy ze szukanego indeksu nie ma na liscie
    if (current == NULL || current->next == NULL) {
        printf("Szukanego indeksu nie ma na liscie\n");
        return;
    }

    // Usuwanie jesli indeks istnieje
    node_t* temp = current->next;
    current->next = temp->next;
    free(temp);
}

void remove_value(node_t** head, int value) {
    // pusta lista
    if (*head == NULL) return;

    // sprawdzam czy wartosc jest pierwszym elementem
    node_t* temp;
    while (*head != NULL && (*head)->val == value) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    node_t* current = *head;
    while (current->next != NULL) {
        if (current->next->val == value) {
            temp = current->next;
            current->next = current->next->next;
            free(temp);
            return;
        }
        current = current->next;
    }
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
    remove_last(&head);
    print_list(head);
    remove_by_index(&head, 2); // Attempt to remove the element at index 2
    print_list(head); // Print list to verify removal
    return 0;
}