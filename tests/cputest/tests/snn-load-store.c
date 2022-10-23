#include "snn.h"

uint64_t mem[] = {
	0x0, 0x0258, 0x4abc, 0x7fff, 0x8000, 0x8100, 0xabcd, 0xffff
};

uint64_t nld_ans[] = {
	0x00000000, 0x00000258, 0x00004abc, 0x00007fff, 0x00008000, 0x00008100, 0x0000abcd, 0x0000ffff
};

uint64_t nst_in[] = {
    0x2, 0x4, 0xcafe, 0xffffffff
};

int main(){
    for (int i = 0 ; i < LENGTH(mem); i++){
        printf("%ld ", mem[i]);
    }
    printf("\n");
    for (int i = 0; i < LENGTH(mem); i++) {
        nemu_assert(nld(&mem[i],0) == nld_ans[i]);
        printf("%ld ", mem[i]);
    }
    printf("\n");
    for(int i = 0; i < LENGTH(nst_in); i++) {
        nst(&mem[i], nst_in[i], 0);
        nemu_assert(mem[i] == nst_in[i]);
        printf("0x%x ", mem[i]);
    }
    printf("\n");
    return 0;
}