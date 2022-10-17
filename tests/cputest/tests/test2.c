#include "snn.h"
#include "snn-ref.h"

#define VINIT   20
#define STDPEN  1
#define VTH     40
#define VLEAK   20

int main(){
    sinit(VINIT, STDPEN);
    srand(1651133871);
    printf("\033[35m===========================\n");
    printf("INSTR\tREF\n");
    printf("nadd\t_nadd\n");
    printf("===========================\033[0m\n");
    int testTime = TESTLIM;
    vleak(VLEAK);
    for (int i = 0; i < testTime; i++){
        uint64_t a = rand();
        uint64_t b = rand();
        cont_print(nadd(a << 1, b), _nadd(a, b, VLEAK), i, "nadd", a, b);
    }
    PassMassage();
    return 0;
}