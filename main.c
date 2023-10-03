#include <stdio.h>
#include <stdlib.h>

typedef struct _BigInt {
    int *rep;
    int n;
    int d;
} BigInt;

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
    BigInt a;
    int arep[] = {1, 1, 2, 1, 1, 9};
    a.rep = (int*)&arep;
    a.n = sizeof(arep) / sizeof(int);
    a.d = 0;

    BigInt b;
    int brep[] = {1, 1, 2, 1, 1, 2};
    b.rep = (int*)&brep;
    b.n = sizeof(brep) / sizeof(int);
    b.d = 0;

    BigInt c = add(a, b);
    printf("carry: %d-", c.d);
    for (int i = c.n - 1; i >= 0; i--) {
        printf("%d", (int)c.rep[i]);
    }
    printf("\n");

    return 0;
}
