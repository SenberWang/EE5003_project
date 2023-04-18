#ifndef _SPIKE_SCHEDULER_HEADER_
#define _SPIKE_SCHEDULER_HEADER_

#include "global_vars.h"
#include "output_mem.h"

void ReadSpikeMem(struct sSpikeMemPkg *SpikeMemPkg, ap_uint<4> ClstID, _idx_spike_mem IdxSpikeMem, _spike_mem *ReadOut);
void WriteSpikeMem(struct sSpikeMemPkg *SpikeMemPkg, ap_uint<4> ClstID, _spike_mem WriteIn);
void ResetSpikeMem(struct sSpikeMemPkg *SpikeMemPkg);
void ResetPartialSpikeMem(struct sSpikeMemPkg *SpikeMemPkg, _mask_clst MaskClst);
void ResetSpikeIdx(struct sSpikeMemPkg *SpikeMemPkg);
void ResetPartialSpikeIdx(struct sSpikeMemPkg *SpikeMemPkg, _mask_clst MaskClst);
void ScheduleSpikeMem(struct sSpikeMemPkg *SpikeMemPkg, struct sOutputMemPkg *OutputMemPkg, ap_uint<4> OutputMemID, _bool IsReset);

#endif
