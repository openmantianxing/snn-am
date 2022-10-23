#include "snn.h"

uint64_t a[2] = {0xfff, 0x345};

int main(){
    // neuron state before nadd instruction
    for (int i = 0; i < 2; i ++){
        printf("%ld ", a[i]);
    }
    printf("\n");
    uint64_t b = nld(&a[0], 0);
    for (int i = 0; i < 2; i ++){
        printf("%ld ", a[i]);
    }
    printf("\n 0x%x \n", b);
    nst(&a[1], b, 0);
    for (int i = 0; i < 2; i ++){
        printf("%ld ", a[i]);
    }
    printf("\n");
    // neuron update input voltage
    return 0;
}

