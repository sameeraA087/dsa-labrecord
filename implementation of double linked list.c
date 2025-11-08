#include <stdio.h>
#include <stdlib.h>
// Node structure for doubly linked list
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;
// Insert at the beginning
void insertAtBeginning(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = *head;
    if (*head != NULL)
        (*head)->prev = newNode;
    *head = newNode;
}
// Insert at the end
void insertAtEnd(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}
// Display list forward
void displayForward(Node* head) {
    printf("List forward: ");
    Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
// Display list backward
void displayBackward(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    printf("List backward: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

// Delete node by value
void deleteNode(Node** head, int value) {
    Node* temp = *head;
    // Search for node to delete
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }
    // If node to be deleted is head
    if (*head == temp)
        *head = temp->next;
    // Update prev node next pointer
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    // Update next node prev pointer
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    free(temp);
    printf("Deleted %d from the list.\n", value);
}
int main() {
    Node* head = NULL;
    insertAtEnd(&head, 10);
    insertAtBeginning(&head, 5);
    insertAtEnd(&head, 15);
    insertAtEnd(&head, 20);
    displayForward(head);
    displayBackward(head);

    deleteNode(&head, 15);
    displayForward(head);
    displayBackward(head);
    deleteNode(&head, 100);  // Try deleting non-existent value
    return 0;
}

