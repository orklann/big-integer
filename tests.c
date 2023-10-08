#include <stdio.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include "big_integer.h"

int main() {
    // Test big_integer_add()
    // #1
    BigInt *a = big_integer_create("246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498");

    BigInt *b = big_integer_create("946346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498246346394683469942958349834839483948229498");

    char *add_result_test = "1192692789366939885916699669678967896458996492692789366939885916699669678967896458996492692789366939885916699669678967896458996492692789366939885916699669678967896458996492692789366939885916699669678967896458996492692789366939885916699669678967896458996492692789366939885916699669678967896458996492692789366939885916699669678967896458996492692789366939885916699669678967896458996492692789366939885916699669678967896458996492692789366939885916699669678967896458996492692789366939885916699669678967896458996492692789366939885916699669678967896458996492692789366939885916699669678967896458996492692789366939885916699669678967896458996492692789366939885916699669678967896458996492692789366939885916699669678967896458996";
    char *add_result = big_integer_display(big_integer_add(a, b));
    assert(strcmp(add_result, add_result_test) == 0);

    return 0;
}
