#include <stdio.h>
#include <time.h>
#include "big_integer.h"


int main() {

    BigInt *a = big_integer_create("246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498");

    BigInt *b = big_integer_create("946346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498");

    clock_t start, end;
    double cpu_time_used;

    start = clock(); // Start the timer
    BigInt *c = big_integer_add(a, b);
    end = clock(); // Stop the timer
    
    printf("%s\n", big_integer_display(c));
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC; // Calculate the elapsed time
    printf("Time taken: %f seconds\n", cpu_time_used);

    BigInt *aa = big_integer_create("8208342849823490820948203840238402840238402834238084280480");
    start = clock(); // Start the timer
    BigInt *c_mul_const = big_integer_multiple_constant(aa, 9);
    end = clock(); // Stop the timer
    printf("%s\n", big_integer_display(c_mul_const));

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC; // Calculate the elapsed time
    printf("Time taken: %f seconds\n", cpu_time_used);

    BigInt *ma = big_integer_create("8823738938393930049483737383002172373893838383838383838383838376373737377812834712734712741241248124810248019248012840128401280412804824");
    BigInt *mb = big_integer_create("2823738938393930049483737383002172373893838383838383838383838376373737377812834712834712741241248124810248019248012840128401280412804824");
    start = clock(); // Start the timer
    BigInt *c_mul = big_integer_multiple(ma, mb);
    end = clock(); // Stop the timer
    printf("%s\n", big_integer_display(c_mul));

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC; // Calculate the elapsed time
    printf("Time taken: %f seconds\n", cpu_time_used);


    BigInt *sa = big_integer_create("946346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498");

    BigInt *sb = big_integer_create("546346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229499");

    start = clock(); // Start the timer
    BigInt *sc = big_integer_substract(sa, sb);
    end = clock(); // Stop the timer
    
    printf("%s\n", big_integer_display(sc));
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC; // Calculate the elapsed time
    printf("Time taken: %f seconds\n", cpu_time_used);

    big_integer_delete(a);
    big_integer_delete(b);
    big_integer_delete(c);
    big_integer_delete(aa);
    big_integer_delete(c_mul_const);
    big_integer_delete(ma);
    big_integer_delete(mb);
    big_integer_delete(c_mul);
    big_integer_delete(sa);
    big_integer_delete(sb);
    big_integer_delete(sc);
    return 0;
}
