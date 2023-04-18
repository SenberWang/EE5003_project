#ifndef _POTEN_INIT_HEADER_
#define _POTEN_INIT_HEADER_

#include "global_vars.h"

void InitPotenMem(_potential_mem *PotenMemPE_0,
                  _potential_mem *PotenMemPE_1,
                  _potential_mem *PotenMemPE_2,
                  _potential_mem *PotenMemPE_3,
                  ap_uint<CLST_ID_WIDTH> ClstID);

#endif
