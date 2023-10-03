typedef struct _BigInt {
    int *rep;
    int n;
    int d;
} BigInt;


BigInt big_integer_create(char *s);
BigInt add(BigInt a, BigInt b);
