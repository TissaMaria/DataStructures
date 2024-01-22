#include <stdio.h>
#include <string.h>

#define MAX 100

int top = -1;
char stack[MAX], infix[MAX], postfix[MAX];

void push(char symbol);
char pop();
int isEmpty();
int precedence(char symbol);
void print();
void inToPost();

int main() {
    printf("Enter an Infix Expression: ");
    
    gets(infix);
    inToPost();
    print();
    return 0;
}

void inToPost() {
    int i = 0, j = 0;
    char symbol, next;

    for (; i < strlen(infix); i++) {
        symbol = infix[i];

        switch (symbol) {
            case '(':
                push(symbol);
                break;
            case ')':
                while ((next = pop()) != '(') {
                    postfix[j++] = next;
                }
                break;
            case '^':
            case '/':
            case '*':
            case '+':
            case '-':
                while (!isEmpty() && precedence(stack[top]) >= precedence(symbol)) {
                    postfix[j++] = pop();
                }
                push(symbol);
                break;
            default:
                postfix[j++] = symbol;
        }
    }

    while (!isEmpty()) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

void print() {
    for (int i = 0; i < strlen(postfix); i++) {
        printf("%c", postfix[i]);
    }

}

void push(char symbol) {
    top++;
    stack[top] = symbol;
}

char pop() {
    char next = stack[top];
    top--;
    return next;
}

int isEmpty() {
    return top == -1;
}

int precedence(char symbol) {
    switch (symbol) {
        case '^':
            return 3;
        case '/':
        case '*':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}
