#include <stdio.h>
#include <stdlib.h>
// Define the node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;
// Insert at the beginning
void insertAtBeginning(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}
// Insert at the end
void insertAtEnd(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Display the linked list
void displayList(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    printf("Linked list: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
// Delete node by value
void deleteNode(Node** head, int value) {
    Node* temp = *head;
    Node* prev = NULL;
    // If head node itself holds the value
    if (temp != NULL && temp->data == value) {
        *head = temp->next;
        free(temp);
        printf("Deleted %d from the list.\n", value);
        return;
    }
    // Search for the value
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // If value not found
    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }
    // Unlink the node and free memory
    prev->next = temp->next;
    free(temp);
    printf("Deleted %d from the list.\n", value);
}
int main() {
    Node* head = NULL;
    insertAtEnd(&head, 10);
    insertAtBeginning(&head, 5);
    insertAtEnd(&head, 15);
    insertAtEnd(&head, 20);
    displayList(head);
    deleteNode(&head, 15);
    displayList(head);
    deleteNode(&head, 100);  // Try deleting a value not in list
    return 0;
}

