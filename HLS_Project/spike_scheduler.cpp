#include "spike_scheduler.h"

void ReadSpikeMem(struct sSpikeMemPkg *SpikeMemPkg, ap_uint<4> ClstID, _idx_spike_mem IdxSpikeMem, _spike_mem *ReadOut)
{
	*ReadOut = SpikeMemPkg->SpikeMem[ClstID][IdxSpikeMem];
}


void WriteSpikeMem(struct sSpikeMemPkg *SpikeMemPkg, ap_uint<4> ClstID, _spike_mem WriteIn)
{
	_idx_spike_mem CurIdx;
	CurIdx = SpikeMemPkg->IdxSpikeMem[ClstID];
	SpikeMemPkg->SpikeMem[ClstID][CurIdx] = WriteIn;
	SpikeMemPkg->IdxSpikeMem[ClstID] = CurIdx+1;
}


void ResetSpikeMem(struct sSpikeMemPkg *SpikeMemPkg)
{
	ap_uint<4> idx_clst_id;
	_idx_spike_mem idx_spike_id;
	for(idx_clst_id=0; idx_clst_id<(NUM_TOTAL_CLUSTER); idx_clst_id++)
	{
		for(idx_spike_id=0; idx_spike_id<DEPTH_SPIKE_MEM; idx_spike_id++)
		{
			SpikeMemPkg->SpikeMem[idx_clst_id][idx_spike_id]=0;
		}
	}
}


void ResetPartialSpikeMem(struct sSpikeMemPkg *SpikeMemPkg, _mask_clst MaskClst)
{
    ap_uint<4> idx_clst_id;
    _idx_spike_mem idx_spike_id;
    for(idx_clst_id=0; idx_clst_id<(NUM_TOTAL_CLUSTER); idx_clst_id++)
    {
        if(MaskClst[idx_clst_id]==1)
        {
            for(idx_spike_id=0; idx_spike_id<DEPTH_SPIKE_MEM; idx_spike_id++)
            {
                SpikeMemPkg->SpikeMem[idx_clst_id][idx_spike_id]=0;
            }
        }
    }
}


void ResetSpikeIdx(struct sSpikeMemPkg *SpikeMemPkg)
{
	ap_uint<4> idx_clst_id;
	for(idx_clst_id=0; idx_clst_id<(NUM_TOTAL_CLUSTER); idx_clst_id++)
	{
		SpikeMemPkg->IdxSpikeMem[idx_clst_id]=0;
	}
}


void ResetPartialSpikeIdx(struct sSpikeMemPkg *SpikeMemPkg, _mask_clst MaskClst)
{
    ap_uint<4> idx_clst_id;
    for(idx_clst_id=0; idx_clst_id<(NUM_TOTAL_CLUSTER); idx_clst_id++)
    {
        if(MaskClst[idx_clst_id]==1)
        {
            SpikeMemPkg->IdxSpikeMem[idx_clst_id]=0;
        }
    }
}


void ScheduleSpikeMem(struct sSpikeMemPkg *SpikeMemPkg, struct sOutputMemPkg *OutputMemPkg, ap_uint<4> OutputMemID, _bool IsReset)
{
	ap_uint<4> idx_clst_id;
	ap_uint<12> idx_opt_mem;
	_output_mem TempReg1;
    _output_mem TempReg2;
    _mask_clst MaskClst;

    MaskClst = ((OutputMemPkg+OutputMemID)->OutputMem[0])(47,32);
    ap_uint<12> last_addr_opt_mem;
    ap_uint<12> cur_addr_opt_mem;

    last_addr_opt_mem = *((OutputMemPkg+OutputMemID)->IdxOutputMemLast);
    cur_addr_opt_mem = *((OutputMemPkg+OutputMemID)->IdxOutputMem);
    *((OutputMemPkg+OutputMemID)->IdxOutputMemLast) = *((OutputMemPkg+OutputMemID)->IdxOutputMem);

    /*************************/
    if (IsReset==1)
    {
        ResetPartialSpikeMem(SpikeMemPkg, MaskClst);
        ResetPartialSpikeIdx(SpikeMemPkg, MaskClst);
    }
    /*************************/

    for(idx_clst_id=0; idx_clst_id<NUM_TOTAL_CLUSTER; idx_clst_id++)
	{
		if(MaskClst[idx_clst_id]==1)
		{
			for(idx_opt_mem=last_addr_opt_mem; idx_opt_mem<cur_addr_opt_mem; idx_opt_mem++)
			{
				TempReg1 = (OutputMemPkg+OutputMemID)->OutputMem[idx_opt_mem];
                TempReg2(31,24) = TempReg1(31,24);
                TempReg2(23,0) = TempReg1(23,0);
				WriteSpikeMem(SpikeMemPkg, idx_clst_id, TempReg2);
            }
		}
	}

    /*************************/
    ResetOutputMem(OutputMemPkg, OutputMemID);
    /*************************/

#ifdef TEST_SPK_SCD
    printf("SPK.SCD-CLST.MASK: %d. \n", (int)MaskClst);
#endif
}
