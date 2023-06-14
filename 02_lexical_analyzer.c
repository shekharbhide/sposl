#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


int main() {
    int i, id = 0, no = 0, op = 0;
    char s[30];

    printf("Enter Equation:");
    fflush(stdout);
    scanf("%s", s);

    for (i = 0; s[i] != '\0'; i++) {
        char ch = s[i];

        if (isalpha(ch)) {
            printf("%c is an identifier\n", ch);
            id++;
        } else if (isdigit(ch)) {
            printf("%c is a number\n", ch);
            no++;
        } else {
            printf("%c is an operator\n", ch);
            op++;
        }
    }

    printf("Total identifiers: %d\n", id);
    printf("Total numbers: %d\n", no);
    printf("Total operators: %d\n", op);
    printf("Total tokens: %d\n", (id + no + op));

    return 0;
}
