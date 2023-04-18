#include <iostream>
#include "ap_int.h"
#include "global_vars.h"

int SnnAcc(volatile ap_int<32> *ddr_0, int image_base_addr, int image_length,int weight_base_addr,int idx_img);

int main() {
    int rev;
    ap_int<32> *ddr_0;
    int idx_img;

    printf("Test begin\n");

    for(idx_img=0;idx_img<5;idx_img++) {
        rev = SnnAcc(ddr_0, 0, 0, 0, idx_img);
        printf("Classify result of %d is %d\n", idx_img+1, rev);
    }
    return 0;
}
