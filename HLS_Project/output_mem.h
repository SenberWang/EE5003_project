#ifndef _OPT_MEM_HEADER_
#define _OPT_MEM_HEADER_

#include "global_vars.h"

void ReadOutputMem(struct sOutputMemPkg *OutputMemPkg, _idx_output_mem IdxOutputMem, _output_mem *ReadOut);
void WriteOutputMem(struct sOutputMemPkg *OutputMemPkg, _output_mem WriteIn);
void ResetOutputMem(struct sOutputMemPkg *OutputMemPkg, ap_uint<4> OutputMemID);

#endif
