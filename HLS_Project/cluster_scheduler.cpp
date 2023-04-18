#include "cluster_scheduler.h"

void InitClstFlag(struct sClstInputPkg *ClstInputPkg)
{
    ap_uint<5> idxClstID;

    for (idxClstID=0; idxClstID<NUM_TOTAL_CLUSTER; idxClstID++)
    {
            (ClstInputPkg+idxClstID)->ClstID = idxClstID;
            *((ClstInputPkg+idxClstID)->IdxInstrMem) = 0;
            *((ClstInputPkg+idxClstID)->ClstDone) = 0;
            *((ClstInputPkg+idxClstID)->ClstSync) = 0;
            *((ClstInputPkg+idxClstID)->TimeStep) = 1;
    }
}