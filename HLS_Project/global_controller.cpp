#include "global_vars.h"
#include "misc.h"
#include "decoder.h"
#include "register_file.h"
#include "spike_scheduler.h"
#include "output_mem.h"
#include "PE.h"
#include "ALU.h"
#include "cluster_scheduler.h"
#include "cluster_0.h"
#include "cluster_1.h"
#include "cluster_2.h"
#include "cluster_3.h"
#include "cluster_4.h"
#include "cluster_5.h"

int
SnnAcc(volatile ap_int<32> *ddr_0, int image_base_addr, int image_length, int weight_base_addr, int idx_img) {
#pragma HLS INTERFACE m_axi depth=1600 port=ddr_0
#pragma HLS INTERFACE s_axilite port=return register bundle=BUS_A
#pragma HLS INTERFACE s_axilite port=weight_base_addr register bundle=BUS_A
#pragma HLS INTERFACE s_axilite port=image_base_addr register bundle=BUS_A
#pragma HLS INTERFACE s_axilite port=image_length register bundle=BUS_A
#pragma HLS INTERFACE s_axilite port=idx_img register bundle=BUS_A

    struct sClstInputPkg ClstInputPkg[NUM_TOTAL_CLUSTER];
    struct sClstOutputPkg ClstOutputPkg[NUM_TOTAL_CLUSTER];
    struct sOutputMemPkg OutputMemPkg[NUM_TOTAL_CLUSTER];
    struct sSpikeMemPkg SpikeMem[1];
    _reg_timestep GlobalTimeStep;
    int result;
    int spike_id[10]={0};
    int spike_num,idx_spike_num,idx_spike_id;
    /********************* initialize instruction memory ********************/
    InitInstrMem(ClstInputPkg);

    /********************* reset input memory ********************/
    ResetSpikeMem(SpikeMem);
    ResetSpikeIdx(SpikeMem);

    /********************* reset output memory ********************/
    ResetOutputMem(OutputMemPkg, 5);

    /********************* initialize input memory ********************/
    InitSpikeMem(ddr_0, SpikeMem, image_base_addr, image_length, idx_img);

    /********************* run cluster *************************/
    InitClstFlag(ClstInputPkg);

    for (GlobalTimeStep = 1; GlobalTimeStep <= 15; GlobalTimeStep++) {
        /********************* cluster0 *************************/
        RunCluster_0(0, ddr_0, ClstInputPkg, SpikeMem, OutputMemPkg, GlobalTimeStep, ClstOutputPkg,
                     weight_base_addr);
//        printf("Timestep.%d, Clst.%d: %d spikes \n", int(GlobalTimeStep), 0, int(*(OutputMemPkg[0].IdxOutputMem)));
        ScheduleSpikeMem(SpikeMem, OutputMemPkg, 0, 1);

        /********************* cluster1 *************************/
        RunCluster_1(1, ddr_0, ClstInputPkg, SpikeMem, OutputMemPkg, GlobalTimeStep, ClstOutputPkg,
                     weight_base_addr);
//        printf("Timestep.%d, Clst.%d: %d spikes \n", int(GlobalTimeStep), 1, int(*(OutputMemPkg[1].IdxOutputMem)));
        ScheduleSpikeMem(SpikeMem, OutputMemPkg, 1, 1);

        /********************* cluster2 *************************/
        RunCluster_2(2, ddr_0, ClstInputPkg, SpikeMem, OutputMemPkg, GlobalTimeStep, ClstOutputPkg,
                     weight_base_addr);
//        printf("Timestep.%d, Clst.%d: %d spikes \n", int(GlobalTimeStep), 2, int(*(OutputMemPkg[2].IdxOutputMem)));
        ScheduleSpikeMem(SpikeMem, OutputMemPkg, 2, 1);

        /********************* cluster3 *************************/
        RunCluster_3(3, ddr_0, ClstInputPkg, SpikeMem, OutputMemPkg, GlobalTimeStep, ClstOutputPkg,
                     weight_base_addr);
//        printf("Timestep.%d, Clst.%d: %d spikes \n", int(GlobalTimeStep), 3, int(*(OutputMemPkg[3].IdxOutputMem)));
        ScheduleSpikeMem(SpikeMem, OutputMemPkg, 3, 0);

        /********************* cluster4 *************************/
        RunCluster_4(4, ddr_0, ClstInputPkg, SpikeMem, OutputMemPkg, GlobalTimeStep, ClstOutputPkg,
                     weight_base_addr);
//        printf("Timestep.%d, Clst.%d: %d spikes \n", int(GlobalTimeStep), 4, int(*(OutputMemPkg[4].IdxOutputMem)));
        ScheduleSpikeMem(SpikeMem, OutputMemPkg, 4, 1);

        /********************* cluster5 *************************/
        RunCluster_5(5, ddr_0, ClstInputPkg, SpikeMem, OutputMemPkg, GlobalTimeStep, ClstOutputPkg,
                     weight_base_addr);
//        printf("Timestep.%d, Clst.%d: %d spikes \n", int(GlobalTimeStep), 5, int(*(OutputMemPkg[5].IdxOutputMem)));
    }
    /********************* final result *************************/
    spike_num=*(OutputMemPkg[5].IdxOutputMem);

    for(idx_spike_num = 0; idx_spike_num < spike_num; idx_spike_num++) {
        spike_id[OutputMemPkg[5].OutputMem[idx_spike_num](3, 0)] += 1;
    }

    for(idx_spike_id = 0;idx_spike_id < 10; idx_spike_id++){
        if(spike_id[result] < spike_id[idx_spike_id]){
            result = idx_spike_id;
        }
    }
#ifdef TEST_FNL_PRINT
    printf("-------------------------------------------- Output C0 Print -------------------------------------- \n");

    int valNumOutput;
    valNumOutput = *(OutputMemPkg[0].IdxOutputMem);
    printf("Output spike of clst.0 number: %d. \n", valNumOutput);

    int PrintHigh;
    int PrintLow;

    int valRowOutput0;
    int valColOutput0;
    int valFeaOutput0;

    int idxOutputMem;
    for (idxOutputMem = 0; idxOutputMem < valNumOutput; idxOutputMem++) {
        PrintHigh = (OutputMemPkg[0].OutputMem[idxOutputMem])(63, 32);
        PrintLow = (OutputMemPkg[0].OutputMem[idxOutputMem])(31, 0);

        valColOutput0 = (OutputMemPkg[0].OutputMem[idxOutputMem])(4, 0);;
        valRowOutput0 = (OutputMemPkg[0].OutputMem[idxOutputMem])(9, 5);
        valFeaOutput0 = (OutputMemPkg[0].OutputMem[idxOutputMem])(13, 10);

        printf("OutputMem[%d] = 0x%x_%x. (%d,%d,%d). \n", idxOutputMem, PrintHigh, PrintLow, valFeaOutput0 + 1,
               valRowOutput0 + 1, valColOutput0 + 1);
    }
#endif


#ifdef TEST_FNL_PRINT
    printf("-------------------------------------------- Output C1 Print -------------------------------------- \n");

    int valNumOutput1;
    valNumOutput1 = *(OutputMemPkg[1].IdxOutputMem);
    printf("Output spike of clst.1 number: %d. \n", valNumOutput1);

    int PrintHigh1;
    int PrintLow1;

    int valRowOutput1;
    int valColOutput1;
    int valFeaOutput1;

    int idxOutputMem1;
    for (idxOutputMem1 = 0; idxOutputMem1 < valNumOutput1; idxOutputMem1++) {
        PrintHigh1 = (OutputMemPkg[1].OutputMem[idxOutputMem1])(63, 32);
        PrintLow1 = (OutputMemPkg[1].OutputMem[idxOutputMem1])(31, 0);

        valColOutput1 = (OutputMemPkg[1].OutputMem[idxOutputMem1])(4, 0);;
        valRowOutput1 = (OutputMemPkg[1].OutputMem[idxOutputMem1])(9, 5);
        valFeaOutput1 = (OutputMemPkg[1].OutputMem[idxOutputMem1])(13, 10);

        printf("OutputMem[%d] = 0x%x_%x. (%d,%d,%d). \n", idxOutputMem1, PrintHigh1, PrintLow1, valFeaOutput1 + 1,
               valRowOutput1 + 1, valColOutput1 + 1);
    }
#endif

#ifdef TEST_FNL_PRINT
    printf("-------------------------------------------- Output C2 Print -------------------------------------- \n");

    int valNumOutput2;
    valNumOutput2 = *(OutputMemPkg[2].IdxOutputMem);
    printf("Output spike of clst.2 number: %d. \n", valNumOutput2);

    int PrintHigh2;
    int PrintLow2;

    int valRowOutput2;
    int valColOutput2;
    int valFeaOutput2;

    int idxOutputMem2;
    for (idxOutputMem2 = 0; idxOutputMem2 < valNumOutput2; idxOutputMem2++) {
        PrintHigh2 = (OutputMemPkg[2].OutputMem[idxOutputMem2])(63, 32);
        PrintLow2 = (OutputMemPkg[2].OutputMem[idxOutputMem2])(31, 0);

        valColOutput2 = (OutputMemPkg[2].OutputMem[idxOutputMem2])(3, 0);;
        valRowOutput2 = (OutputMemPkg[2].OutputMem[idxOutputMem2])(7, 4);
        valFeaOutput2 = (OutputMemPkg[2].OutputMem[idxOutputMem2])(14, 8);

        printf("OutputMem[%d] = 0x%x_%x. (%d,%d,%d). \n", idxOutputMem2, PrintHigh2, PrintLow2, valFeaOutput2 + 1,
               valRowOutput2 + 1, valColOutput2 + 1);
    }
#endif


#ifdef TEST_FNL_PRINT
    printf("-------------------------------------------- Output C5 Print -------------------------------------- \n");

    int valNumOutput5;
    valNumOutput5 = *(OutputMemPkg[5].IdxOutputMem);
    printf("Output spike of clst.5 number: %d. \n", valNumOutput5);

    int PrintHigh5;
    int PrintLow5;

    int valRowOutput5;
    int valColOutput5;
    int valFeaOutput5;

    int idxOutputMem5;
    for (idxOutputMem5 = 0; idxOutputMem5 < valNumOutput5; idxOutputMem5++) {
        PrintHigh5 = (OutputMemPkg[5].OutputMem[idxOutputMem5])(63, 32);
        PrintLow5 = (OutputMemPkg[5].OutputMem[idxOutputMem5])(31, 0);

        valColOutput5 = (OutputMemPkg[5].OutputMem[idxOutputMem5])(3, 0);;
        valRowOutput5 = (OutputMemPkg[5].OutputMem[idxOutputMem5])(7, 4);
        valFeaOutput5 = (OutputMemPkg[5].OutputMem[idxOutputMem5])(14, 8);

        printf("OutputMem[%d] = 0x%x_%x. (%d,%d,%d). \n", idxOutputMem5, PrintHigh5, PrintLow5, valFeaOutput5 + 1,
               valRowOutput5 + 1, valColOutput5 + 1);
    }
#endif


#ifdef TEST_FNL_PRINT

    int valNumOutput4;
    int PrintHigh4;
    int PrintLow4;
    int valRowOutput4;
    int valColOutput4;
    int valFeaOutput4;
    int idxOutputMem4;
    int idx_clst_print_conv_output;

    for (idx_clst_print_conv_output = 4; idx_clst_print_conv_output < 8; idx_clst_print_conv_output++) {
        printf("-------------------------------------------- Output C%d Print -------------------------------------- \n",
               idx_clst_print_conv_output);

        valNumOutput4 = *(OutputMemPkg[idx_clst_print_conv_output].IdxOutputMem);
        printf("Output spike of clst.4 number: %d. \n", valNumOutput4);

        for (idxOutputMem4 = 0; idxOutputMem4 < valNumOutput4; idxOutputMem4++) {
            PrintHigh4 = (OutputMemPkg[idx_clst_print_conv_output].OutputMem[idxOutputMem4])(63, 32);
            PrintLow4 = (OutputMemPkg[idx_clst_print_conv_output].OutputMem[idxOutputMem4])(31, 0);

            valColOutput4 = (OutputMemPkg[idx_clst_print_conv_output].OutputMem[idxOutputMem4])(3, 0);;
            valRowOutput4 = (OutputMemPkg[idx_clst_print_conv_output].OutputMem[idxOutputMem4])(7, 4);
            valFeaOutput4 = (OutputMemPkg[idx_clst_print_conv_output].OutputMem[idxOutputMem4])(14, 8);

            printf("OutputMem[%d] = 0x%x_%x. (%d,%d,%d). \n", idxOutputMem4, PrintHigh4, PrintLow4, valFeaOutput4 + 1,
                   valRowOutput4 + 1, valColOutput4 + 1);
        }
    }

#endif

    /******************* output to the host **********************/
    return result;
}
