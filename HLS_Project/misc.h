#ifndef _MISC_HEADER_
#define _MISC_HEADER_

#include "global_vars.h"

void InitInstrMem(struct sClstInputPkg *ClstInputPkg);

void InitSpikeMem(volatile ap_int<32> *ddr_0, struct sSpikeMemPkg *SpikeMemPkg, int image_base_addr, int image_length,int idx_img);

#endif
