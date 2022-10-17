#include "snn.h"
#include "snn-ref.h"

#define VINIT   20
#define STDPEN  1
#define VTH     40
#define VLEAK   20

int main(){
    int testTime = TESTLIM;
    srand(1651137040);

    printf("\033[35m===========================\n");
    printf("INSTR\tREF\n");
    printf("ands\t_ands\nrpop\t_rpop\n");
    printf("===========================\033[0m\n");
    for(int i = 0; i < testTime; i++){
        uint64_t    a = rand();
        uint64_t    b = rand();
        cont_print(ands(a, b), _ands(a, b),i, "ands", a, b);    // use snn module calculating a & b
        cont_print(rpop(ands(a, b)), _rpop(_ands(a, b)), i, "rpop", a, b); // calculate the population of "1" in the result of a & b
    }

    sinit(VINIT, STDPEN);
    printf("\033[35m===========================\n");
    printf("INSTR\tREF\n");
    printf("inf\t_inf\nsge\t_rsge\nsls\t_sls\nvleak\t_vleak\n");
    printf("===========================\033[0m\n");
    for (int i = 0; i < testTime; i++){
        uint64_t    a = rand();
        uint64_t    b = rand();
        cont_print(inf(a), _inf(a), i, "inf",a,b);
        cont_print(sge(a, b), _sge(a, b, VINIT), i, "sge", a, b);
        cont_print(sls(a), _sls(a, STDPEN, 0), i, "sls", a, b);
        cont_print(vleak(b), _vleak(b), i, "vleak", a, b);
    }
    
    PassMassage();
    return 0;
}