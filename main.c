#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _BigInt {
    int *rep;
    int n;
    int d;
} BigInt;

BigInt big_integer_create(char *s) {
    BigInt result;
    result.rep = (int*)malloc(sizeof(int) * strlen(s));
    int index = 0;
    for (int i = strlen(s) - 1; i >= 0; i--) {
        result.rep[index] = s[i] - '0';
        index++;
    }
    result.n = strlen(s);
    result.d = 0;
    return result;
}

BigInt add(BigInt a, BigInt b) {
    int n = a.n;
    int d = 0;
    BigInt c;
    c.rep = (int*)malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++) {
        int sum = a.rep[i] + b.rep[i] + d;
        d = (int)(sum / 10);
        c.rep[i] = sum % 10;
    }
    c.n = n;
    c.d = d;
    return c;
}

int main() {
    BigInt a = big_integer_create("911211");

    BigInt b = big_integer_create("211211");

    BigInt c = add(a, b);
    printf("carry: %d-", c.d);
    for (int i = c.n - 1; i >= 0; i--) {
        printf("%d", (int)c.rep[i]);
    }
    printf("\n");

    return 0;
}
