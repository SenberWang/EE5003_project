#include "output_mem.h"

void ReadOutputMem(struct sOutputMemPkg *OutputMemPkg, _idx_output_mem IdxOutputMem, _output_mem *ReadOut)
{
	*ReadOut = OutputMemPkg->OutputMem[IdxOutputMem];
}


void WriteOutputMem(struct sOutputMemPkg *OutputMemPkg, _output_mem WriteIn)
{
	_idx_output_mem CurIdx;
	CurIdx = *(OutputMemPkg->IdxOutputMem);
	OutputMemPkg->OutputMem[CurIdx] = WriteIn;
	*(OutputMemPkg->IdxOutputMem) = CurIdx+1;
}


void ResetOutputMem(struct sOutputMemPkg *OutputMemPkg, ap_uint<4> OutputMemID)
{
	_idx_output_mem CurIdx;
	CurIdx = *((OutputMemPkg+OutputMemID)->IdxOutputMem);

	_idx_output_mem idx_output_id;
	for(idx_output_id=0; idx_output_id < CurIdx; idx_output_id++)
	{
		(OutputMemPkg+OutputMemID)->OutputMem[idx_output_id] = 0;
	}

	*((OutputMemPkg+OutputMemID)->IdxOutputMem) = 0;
    *((OutputMemPkg+OutputMemID)->IdxOutputMemLast) = 0;
}


