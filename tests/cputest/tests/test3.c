#include "snn.h"
#include "snn-ref.h"

#define VINIT   20
#define STDPEN  1

int main(){
    sinit(VINIT, STDPEN);
    srand(1651133871);
    int testTime = TESTLIM;
    uint64_t output = 0;
    printf("\033[35m===========================\n");
    printf("INSTR\tREF\n");
    printf("sup\t_sup\n");
    printf("===========================\033[0m\n");
    for (int i = 0; i < testTime; i++){
        uint64_t a = rand();
        uint64_t b = rand();
        output = rand() % 2;
        inf(output);
        cont_print(sup(a, b), _sup(a, b, output == 1 ? 0xffffffffffffffff: 0), i, "sup", a, b);
        printf("%d\n", output);

    }
    PassMassage();
    return 0;
}