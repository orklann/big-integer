#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "big_integer.h"

BigInt* big_integer_create(char *s) {
    BigInt *result = (BigInt*)malloc(sizeof(BigInt));
    result->rep = (int*)malloc(sizeof(int) * strlen(s));
    int index = 0;
    /*
     * layout of rep: 10^0, 10^1, 10^(n-1)
     * for index from 0 to n-1
     */
    for (int i = strlen(s) - 1; i >= 0; i--) {
        result->rep[index] = s[i] - '0';
        index++;
    }
    result->n = strlen(s);
    return result;
}

BigInt* big_integer_from_size(unsigned int n) {
    BigInt *result = (BigInt*)malloc(sizeof(BigInt));
    result->rep = (int*)malloc(sizeof(int)*n);
    result->n = n;
    return result;
}

BigInt* big_integer_add(BigInt *a, BigInt *b) {
    int n = a->n;
    if (n < b->n) {
        n = b->n;
        int *rep = (int*)malloc(sizeof(int)*n);
        for (int i = 0; i < n; i++) {
            if (i < a->n) {
                rep[i] = a->rep[i];
            } else {
                rep[i] = 0;
            }
        }
        free(a->rep);
        a->rep = rep;
    } else {
        int *rep = (int*)malloc(sizeof(int)*n);
        for (int i = 0; i < n; i++) {
            if (i < b->n) {
                rep[i] = b->rep[i];
            } else {
                rep[i] = 0;
            }
        }
        free(b->rep);
        b->rep = rep;
    }
    int d = 0;
    BigInt *c = big_integer_from_size(n);
    for (int i = 0; i < n; i++) {
        int sum = a->rep[i] + b->rep[i] + d;
        d = (int)(sum / 10);
        c->rep[i] = sum % 10;
    }
    c->n = n;
    // Carry occurs
    if (d >= 1) {
        BigInt * carry_int = big_integer_from_size(n+1);
        for (int i = 0; i < n + 1; i++) {
            if (i <= n - 1) {
                carry_int->rep[i] = c->rep[i];
            } else {
                carry_int->rep[i] =  d;
            }
        }
        carry_int->n = n + 1;
        big_integer_delete(c);
        return carry_int;
    }
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


char *big_integer_display(BigInt *a) {
    char *result = (char*)malloc(a->n * sizeof(char));
    int i;
    for (i = 0; i < a->n; i++) {
        int c = a->rep[i];
        if (c >= 0) {
            result[a->n - 1 - i] = c + '0';       
        } else {
            result[a->n - 1 - i] = c + 10 + '0';
            if (i + 1 <= a->n - 1) {
                a->rep[i + 1] -= 1;
            }
        }
    }
    result[a->n] = '\0';
    return result;
}

void big_integer_delete(BigInt *a) {
    free(a->rep);
    free(a);
}

