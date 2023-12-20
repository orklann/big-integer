typedef struct _BigInt {
    int *rep;
    int n;
    int d;
} BigInt;


BigInt* big_integer_create(char *s);
BigInt* big_integer_from_size(unsigned int n);
void big_integer_add(BigInt *a, BigInt *b, BigInt  *c);
BigInt* big_integer_multiple_constant(BigInt *a, int constant);
BigInt* big_integer_multiple(BigInt *a, BigInt *b);
BigInt* big_integer_substract(BigInt *a, BigInt *b);
char *big_integer_to_str(BigInt *a);
void big_integer_delete(BigInt *a);
int big_integer_compare(BigInt *a, BigInt *b);
