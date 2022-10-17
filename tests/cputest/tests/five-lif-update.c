#include "snn.h"

// initial defination
#define VINIT   (20 << 1)   // initial voltage(VINIT[63:1],Spike[0] = 0)
#define VTH     40          // treshold voltage(20 << 1)
#define EN      0           // stdp enable flag
#define VLEAK   5           // leaky voltage

int vneuron[] = {
    VINIT, VINIT, VINIT, VINIT, VINIT
}; // initialize 5 neurons
int vin[] = {
    25, 10, 15, 20, 25
}; // set 5 input values for each neuron

int main(){
    sinit(VINIT, EN);       //initialize snn parameter
    vleak(VLEAK);
    uint64_t output = 0x0;  // declare output to record spike of 5 neuron
    for (int i = 0; i < 5; i++){
        vneuron[i] = sge(nadd(vneuron[i], vin[i]), VTH);
        output = sls(output);
    }
    // expect neuron 0 and neuron 4 to spike, output = [1 0 0 0 1]
    nemu_assert(output == 0x11);
    //printf("0x%x\n", output); 
    // use inf instruction to set inference output in stdp
    output = inf(0x80);
    nemu_assert(output == 0x80);
    //printf("0x%x\n", output);
    return 0;
}
