#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAX_SIZE - 1;
}

void push(int item) {
    if (isFull()) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = item;
}

int pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

int evaluatePostfix(char *postfix) {
    int i, operand1, operand2, result;

    for (i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            push(postfix[i] - '0');
        } else {
            operand2 = pop();
            operand1 = pop();

            switch (postfix[i]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                case '%':
                    result = operand1 % operand2;
                    break;
                case '^':
                    result = operand1 ^ operand2;
                    break;
                default:
                    printf("Invalid operator\n");
                    exit(1);
            }

            push(result);
        }
    }

    return pop();
}

int main() {
    char postfix[MAX_SIZE];

    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    printf("Result: %d\n", evaluatePostfix(postfix));

    return 0;
}