#ifndef _WEIGHT_INIT_HEADER_
#define _WEIGHT_INIT_HEADER_

#include "global_vars.h"

void InitWeightMem(volatile ap_int<32> *ddr_0,
                   _weight_mem *WeightMemPE_0,
                   _weight_mem *WeightMemPE_1,
                   _weight_mem *WeightMemPE_2,
                   _weight_mem *WeightMemPE_3,
                   ap_uint<CLST_ID_WIDTH> ClstID,
                   int weight_base_addr);

#endif
