#include <stdlib.h>
#include <stdio.h>

int main() {

    char entrada[5];
    scanf("%c", entrada);
    int num1, num2, result;
    char op;
    num1 = atoi(&entrada[0]);
    num2 = atoi(&entrada[4]);
    op = entrada[2];
    printf("%c", op);
    if (&op == "+") {
        printf("%c", op);
        result = num1 + num2;
    } else if (&op == "-") {
        result = num1 - num2;
    } else if (&op == "*") {
        result = num1 * num2;
    } else {
        printf("Nenhum dos anteriores\n");
    }
    printf("%d", result);

    return 0;
}