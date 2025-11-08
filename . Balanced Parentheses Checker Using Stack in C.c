#include <stdio.h>
#include <string.h>
#define MAX 100
typedef struct {
    char arr[MAX];
    int top;
} Stack;
void init(Stack *s) {
    s->top = -1;
}
int isEmpty(Stack *s) {
    return s->top == -1;
}
int isFull(Stack *s) {
    return s->top == MAX - 1;
}
void push(Stack *s, char c) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++(s->top)] = c;
}
char pop(Stack *s) {
    if (isEmpty(s)) {
        return '\0'; // Empty stack
    }
    return s->arr[(s->top)--];
}
int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}
int areParenthesesBalanced(char *expr) {
    Stack s;
    init(&s);
    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];
        // If opening bracket, push it
        if (ch == '(' || ch == '{' || ch == '[') {
            push(&s, ch);
        }
        // If closing bracket, stack must not be empty and top must match
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty(&s)) {
                return 0;  // No matching opening bracket
            }
            char topChar = pop(&s);
            if (!isMatchingPair(topChar, ch)) {
                return 0;  // Mismatched pair
            }
        }
    }

    // At the end, stack should be empty if balanced
    return isEmpty(&s);
}

int main() {
    char expr[MAX];

    printf("Enter expression: ");
    fgets(expr, MAX, stdin);

    // Remove trailing newline if present
    expr[strcspn(expr, "\n")] = '\0';

    if (areParenthesesBalanced(expr)) {
        printf("Parentheses are balanced.\n");
    } else {
        printf("Parentheses are NOT balanced.\n");
    }

    return 0;
}

