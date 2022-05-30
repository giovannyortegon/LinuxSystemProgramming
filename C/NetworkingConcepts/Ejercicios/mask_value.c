#include<stdio.h>
#include <arpa/inet.h>


#define UNSET_BIT(n, pos)   (n = n & ((1 << pos) ^ 0xFFFFFFFF))
#define MAX_MASK_LEN 32

static unsigned int get_mask_value_in_integer_format(char mask_value);

int main() {
    char mask = 24;
    unsigned int mask_integer_format = get_mask_value_in_integer_format(mask);
    printf("%x\n", htonl(mask_integer_format));


}

static unsigned int get_mask_value_in_integer_format(char mask_value) {

    unsigned int mask = 0xFFFFFFFF;
    char n_trail_bits = MAX_MASK_LEN - mask_value;
    int i = 0;
    for(; i < n_trail_bits; i++) {
        // printf("%d\n", i);
        UNSET_BIT(mask, i);
        // printf("%x\n", mask);
    }
    return mask;
}
