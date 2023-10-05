#include <string.h>
#include <stdlib.h>
#include "big_integer.h"

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

BigInt big_integer_add(BigInt a, BigInt b) {
    int n = a.n;
    if (n < b.n) {
        n = b.n;
        int *rep = (int*)malloc(sizeof(int)*n);
        for (int i = 0; i < n; i++) {
            if (i < a.n) {
                rep[i] = a.rep[i];
            } else {
                rep[i] = 0;
            }
        }
        free(a.rep);
        a.rep = rep;
    } else {
        int *rep = (int*)malloc(sizeof(int)*n);
        for (int i = 0; i < n; i++) {
            if (i < b.n) {
                rep[i] = b.rep[i];
            } else {
                rep[i] = 0;
            }
        }
        free(b.rep);
        b.rep = rep;
    }
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

BigInt big_integer_substract(BigInt a, BigInt b) {
    int n = a.n;
    if (n < b.n) {
        n = b.n;
        int *rep = (int*)malloc(sizeof(int)*n);
        for (int i = 0; i < n; i++) {
            if (i < a.n) {
                rep[i] = a.rep[i];
            } else {
                rep[i] = 0;
            }
        }
        free(a.rep);
        a.rep = rep;
    } else {
        int *rep = (int*)malloc(sizeof(int)*n);
        for (int i = 0; i < n; i++) {
            if (i < b.n) {
                rep[i] = b.rep[i];
            } else {
                rep[i] = 0;
            }
        }
        free(b.rep);
        b.rep = rep;
    }
    int d = 0;
    BigInt c;
    c.rep = (int*)malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++) {
        int sum = a.rep[i] - b.rep[i] + d;
        d = (int)(sum / 10);
        c.rep[i] = sum % 10;
    }
    c.n = n;
    c.d = d;
    return c;
}
