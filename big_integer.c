#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
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

/*
 * 0 <= constant <= 10
 */
BigInt* big_integer_multiple_constant(BigInt *a, int constant) {
    BigInt *c = big_integer_from_size(a->n);
    int carry = 0;
    for (int i = 0; i < a->n; i++) {
        int value = (a->rep[i] * constant) + carry;
        c->rep[i] =  value % 10;
        carry = (int)(value / 10);
    }
    if (carry >= 1) {
        BigInt *carry_result = big_integer_from_size(c->n + 1);
        for (int i = 0; i < c->n; i++) {
            carry_result->rep[i] = c->rep[i];
        }
        carry_result->rep[c->n] = carry;
        big_integer_delete(c);
        return carry_result;
    }
    return c;
}

BigInt* big_integer_multiple(BigInt *a, BigInt *b) {
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
    BigInt *c = big_integer_multiple_constant(a, b->rep[0]);
    for (int j = 1; j < n; j++) {
        BigInt *mul = big_integer_multiple_constant(a, b->rep[j]);
        for (int i = 0; i < j; i++) {
            BigInt *temp = big_integer_multiple_constant(mul, 10);
            big_integer_delete(mul);
            mul = temp;
        }
        BigInt *temp = big_integer_add(c, mul);
        big_integer_delete(mul);
        c = temp;
    }
    return c;
}

BigInt* big_integer_substract(BigInt *a, BigInt *b) {
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
        int sum = a->rep[i] - b->rep[i] + d;
        d = (int)(sum / 10);
        c->rep[i] = sum % 10;
    }
    c->n = n;
    // Carry occurs
    if (d < 0) {
        BigInt * carry_int = big_integer_from_size(n+1);
        for (int i = 0; i < n + 1; i++) {
            if (i <= n - 1) {
                carry_int->rep[i] = c->rep[i];
            } else {
                carry_int->rep[i] = -1;
            }
        }
        carry_int->n = n + 1;
        big_integer_delete(c);
        return carry_int;
    }
    return c;
}


char *big_integer_display(BigInt *a) {
    char *result = (char*)malloc(a->n * sizeof(char));
    int i;
    int sign = 0;
    if (a->rep[a->n - 1] < 0) {
        sign = 1;
    }
    for (i = 0; i < a->n; i++) {
        int c = a->rep[i];
        if (!sign) {
            if (c >= 0) {
                result[a->n - 1 - i] = c + '0';       
            } else {
                result[a->n - 1 - i] = c + 10 + '0';
                if (i + 1 <= a->n - 1) {
                    a->rep[i + 1] -= 1;
                }
            }
        } else {
            if (c <= 0) {
                result[a->n - 1 - i] = (c * -1) + '0';  
            } else {
                result[a->n - 1 - i] = 10 - c + '0';
                if (i + 1 <= a->n - 1) {
                    a->rep[i + 1] += 1;
                }
            }
        }
    }
    result[a->n] = '\0';
    if (sign) {
        char *sign_result = (char*)malloc((a->n + 1) * sizeof(char));
        sign_result[0] = '-';
        bool leading_zeros = true;
        int index = 1;
        for (int i = 0; i < a->n + 1; i++) {
            if (result[i] != '0' && leading_zeros) {
                leading_zeros = false;
            }
            if (!leading_zeros) {
                sign_result[index] = result[i];
                index++;
            }
        }
        sign_result[index] = '\0';
        return sign_result;
    }
    return result;
}

void big_integer_delete(BigInt *a) {
    free(a->rep);
    free(a);
}

