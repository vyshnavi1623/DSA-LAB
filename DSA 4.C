#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MAX 100
 
double stack[MAX];
int top = -1;
 
void push(double val) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = val;
}
 
double pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return 0;
    }
    return stack[top--];
}
 
double evaluatePostfix(char postfix[]) {
    int i;
    double op1, op2, result;
 
    for (i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];
        if (isspace(c)) continue;
 
        if (isdigit(c)) {
            push(c - '0');
        } else {
            op2 = pop();
            op1 = pop();
            switch (c) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '^': result = pow(op1, op2); break;
                default:
                    printf("Invalid operator: %c\n", c);
                    result = 0;
            }
            push(result);
        }
    }
    return pop();
}
 
int main() {
    char postfix[MAX];
 
    printf("Enter postfix expression (single-digit operands, e.g. 23+4*): ");
    fgets(postfix, MAX, stdin);
    postfix[strcspn(postfix, "\n")] = '\0';
 
    double result = evaluatePostfix(postfix);
    printf("Result = %.2f\n", result);
    return 0;
}
