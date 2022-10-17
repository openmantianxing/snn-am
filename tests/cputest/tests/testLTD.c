#include "snn.h"
#include "snn-ref.h"
#define VINIT   20
#define STDPEN  1

int main(void){
    sinit(VINIT, STDPEN);
    srand(20221013);
    uint64_t dw = 0;
    int testTime = TESTLIM;
    uint64_t possible = 0;
    int wsum = 0;
    printf("\033[35m===========================\n");
    printf("INSTR\tREF\n");
    printf("ltd\n");
    printf("===========================\033[0m\n");
    for (int i = 0; i < testTime; i++){
        uint64_t w = rand() % 64 + 1;
        uint64_t syn = rand64bits();
        uint64_t syn_new = 0;
        wsum = rpop(syn);
        dw = wsum > w ? wsum - w : 0;
        possible = dw * 1024 / wsum;
        syn_new = ltd(possible, syn);
        int n = rpop(syn_new);
        if(possible == 0){
            if(syn_new == syn){
                cont_print(syn_new, syn, i, "ltd", syn, w);
            }else{
                printf("\033[31m failed \033[0m\n");
                printf("[   %06d] %s failed, dut_result is 0x%lx, ref_result is 0x%lx\n", i, "ltd", syn_new, syn);
                nemu_assert(0);
            }
        }else{
            if(abs(n - w) <= 19){
                cont_print(n, w, i, "ltd", syn, w);
            }else{
                printf("\033[31m failed \033[0m\n");
                printf("[   %06d] %s failed, dut valid syn number is %d, expected syn number is %d\n", i, "ltd", n, w);
                nemu_assert(0);                
            }
        }
    }
    PassMassage();
    return 0;
}
