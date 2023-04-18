#ifndef _CLS4_HEADER_
#define _CLS4_HEADER_

#include "global_vars.h"
#include "PE.h"
#include "ALU.h"
#include "spike_scheduler.h"
#include "decoder.h"
#include "register_file.h"
#include "output_mem.h"
#include "weight_init.h"
#include "potential_init.h"
#include "executer.h"

sClstOutputPkg Cluster_4(volatile ap_int<32> *ddr_0, struct sClstInputPkg *ClstInputPkg, struct sSpikeMemPkg *SpikeMemPkg, struct sOutputMemPkg OutputMemPkg,int weight_base_addr);
void RunCluster_4(ap_uint<4> ClusterID, volatile ap_int<32> *ddr_0, struct sClstInputPkg *ClstInputPkg, struct sSpikeMemPkg *SpikeMemPkg, struct sOutputMemPkg *OutputMemPkg, _reg_timestep GlobalTimeStep, struct sClstOutputPkg *ClstOutputPkg,int weight_base_addr);

#endif
