typedef struct _BigInt {
    int *rep;
    int n;
    int d;
} BigInt;


BigInt big_integer_create(char *s);
BigInt big_integer_add(BigInt a, BigInt b);
BigInt big_integer_substract(BigInt a, BigInt b);
