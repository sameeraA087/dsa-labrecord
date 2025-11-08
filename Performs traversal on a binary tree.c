#include <stdio.h>
#include <stdlib.h>
// Define the structure for a tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;
// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// Inorder Traversal: Left, Root, Right
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
// Preorder Traversal: Root, Left, Right
void preorder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
// Postorder Traversal: Left, Right, Root
void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
// Level-order Traversal (using a simple queue)
#define MAX_QUEUE 100
typedef struct {
    Node* items[MAX_QUEUE];
    int front, rear;
} Queue;
void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
}
int isEmpty(Queue* q) {
    return q->rear < q->front;
}
void enqueue(Queue* q, Node* node) {
    if (q->rear < MAX_QUEUE - 1) {
        q->items[++q->rear] = node;
    }
}
Node* dequeue(Queue* q) {
    if (!isEmpty(q)) {
        return q->items[q->front++];
    }
    return NULL;
}
void levelOrder(Node* root) {
    if (root == NULL) return;
    Queue q;
    initQueue(&q);
    enqueue(&q, root);
    while (!isEmpty(&q)) {
        Node* current = dequeue(&q);
        printf("%d ", current->data);
        if (current->left != NULL) enqueue(&q, current->left);
        if (current->right != NULL) enqueue(&q, current->right);
    }
}
int main() {
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
    */
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");
    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");
    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");
    printf("Level-order traversal: ");
    levelOrder(root);
    printf("\n");
    return 0;
}

