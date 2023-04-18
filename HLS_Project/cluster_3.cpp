#include "cluster_3.h"

sClstOutputPkg Cluster_3(volatile ap_int<32> *ddr_0,
                         struct sClstInputPkg *ClstInputPkg,
                         struct sSpikeMemPkg *SpikeMemPkg,
                         struct sOutputMemPkg *OutputMemPkg,
                         int weight_base_addr)
{
    /*******************************************************************************/
    static struct sPEInputPkg PEInputPkg[NUM_PE_PER_CLUSTER];
    struct sClstOutputPkg ClstOutputPkg;
    struct sMsgPkg MsgPkg;
    static struct sRegFileWidePkg RegFilePkg;

    /**********************************************************/
    static _reg_64b RegFileWidePkg_0[DEPTH_REG_FILE];
    static _reg_64b RegFileWidePkg_1[DEPTH_REG_FILE];
    static _reg_64b RegFileWidePkg_2[DEPTH_REG_FILE];
    static _reg_64b RegFileWidePkg_3[DEPTH_REG_FILE];

    RegFileWidePkg_0[PEREG_ID_TIMESTEP]=*(ClstInputPkg->TimeStep);
    RegFileWidePkg_1[PEREG_ID_TIMESTEP]=*(ClstInputPkg->TimeStep);
    RegFileWidePkg_2[PEREG_ID_TIMESTEP]=*(ClstInputPkg->TimeStep);
    RegFileWidePkg_3[PEREG_ID_TIMESTEP]=*(ClstInputPkg->TimeStep);

    static _weight_mem WeightMemPE_0[DEPTH_WEIGHT_MEM];
    static _weight_mem WeightMemPE_1[DEPTH_WEIGHT_MEM];
    static _weight_mem WeightMemPE_2[DEPTH_WEIGHT_MEM];
    static _weight_mem WeightMemPE_3[DEPTH_WEIGHT_MEM];

    static _potential_mem PotenMemPE_0[DEPTH_POTENTIAL_MEM];
    static _potential_mem PotenMemPE_1[DEPTH_POTENTIAL_MEM];
    static _potential_mem PotenMemPE_2[DEPTH_POTENTIAL_MEM];
    static _potential_mem PotenMemPE_3[DEPTH_POTENTIAL_MEM];

    /**********************************************************/
    ap_uint<4> idx_PE;
    for (idx_PE=0; idx_PE<NUM_PE_PER_CLUSTER ; idx_PE++)
    {
        PEInputPkg[idx_PE].ClstID = ClstInputPkg->ClstID;
        PEInputPkg[idx_PE].PEID = idx_PE;
    }

    /**********************************************************/
    if (*(ClstInputPkg->TimeStep)==1)
    {
        InitWeightMem(ddr_0, WeightMemPE_0, WeightMemPE_1, WeightMemPE_2, WeightMemPE_3, ClstInputPkg->ClstID,weight_base_addr);
        InitPotenMem(PotenMemPE_0, PotenMemPE_1, PotenMemPE_2, PotenMemPE_3, ClstInputPkg->ClstID);
    }

    /*******************************************************************************/
    ap_uint<1> *ClusterDone;
    ClusterDone = ClstInputPkg->ClstDone;

    ap_uint<1> *ClusterSync;
    ClusterSync = ClstInputPkg->ClstSync;

    _idx_instr_mem *IdxInstr;
    IdxInstr = ClstInputPkg->IdxInstrMem;

    RegFilePkg.RegFile[REG_ID_TIMESTEP]=*(ClstInputPkg->TimeStep);

    /****************************************************************/
    while (!(*ClusterDone))
    {
        InstrDecode(&MsgPkg, ClstInputPkg->InstrMem[*IdxInstr]);

        *IdxInstr = executer(
                ddr_0,
                IdxInstr,
                ClusterDone,
                ClusterSync,
                ClstInputPkg,
                SpikeMemPkg,
                PEInputPkg,
                OutputMemPkg,
                &MsgPkg,
                &RegFilePkg,
                RegFileWidePkg_0,
                RegFileWidePkg_1,
                RegFileWidePkg_2,
                RegFileWidePkg_3,
                WeightMemPE_0,
                WeightMemPE_1,
                WeightMemPE_2,
                WeightMemPE_3,
                PotenMemPE_0,
                PotenMemPE_1,
                PotenMemPE_2,
                PotenMemPE_3
        );

    }     //end of while

/*
#ifdef TEST_FNL_PRINT
    int idxPotenC0;
    ap_int<32> valPotenValC0;
    int valPotenRowC0;
    int valPotenColC0;
    int valPotenFeaC0;
    float fltPotenValC0;
    int valPotenFeMapC0;
    int tempPrint;
    float scaling = 4194304;


    if(*(ClstInputPkg->TimeStep)==2)
    {
        printf("-------------------------------------------- Potential C3 Print -------------------------------------- \n");

        for (idxPotenC0 = 0; idxPotenC0 < 64 * 8; idxPotenC0++) {
            valPotenValC0 = PotenMemPE_0[idxPotenC0](31, 0);
            valPotenColC0 = PotenMemPE_0[idxPotenC0](35, 32);
            valPotenRowC0 = PotenMemPE_0[idxPotenC0](39, 36);
            valPotenFeaC0 = PotenMemPE_0[idxPotenC0](46, 40);
            tempPrint = valPotenValC0;

            fltPotenValC0 = (float) tempPrint / scaling;
            printf("CLST3.PE0(%d, %d, %d) = 0x%x|%g. \n", valPotenFeaC0, valPotenRowC0, valPotenColC0, tempPrint,
                   fltPotenValC0);
        }

        for (idxPotenC0 = 0; idxPotenC0 < 64 * 8; idxPotenC0++) {
            valPotenValC0 = PotenMemPE_1[idxPotenC0](31, 0);
            valPotenColC0 = PotenMemPE_1[idxPotenC0](35, 32);
            valPotenRowC0 = PotenMemPE_1[idxPotenC0](39, 36);
            valPotenFeaC0 = PotenMemPE_1[idxPotenC0](46, 40);
            tempPrint = valPotenValC0;

            fltPotenValC0 = (float) tempPrint / scaling;
            printf("CLST3.PE1(%d, %d, %d) = 0x%x|%g. \n", valPotenFeaC0, valPotenRowC0, valPotenColC0, tempPrint,
                   fltPotenValC0);
        }

        for (idxPotenC0 = 0; idxPotenC0 < 64 * 8; idxPotenC0++) {
            valPotenValC0 = PotenMemPE_2[idxPotenC0](31, 0);
            valPotenColC0 = PotenMemPE_2[idxPotenC0](35, 32);
            valPotenRowC0 = PotenMemPE_2[idxPotenC0](39, 36);
            valPotenFeaC0 = PotenMemPE_2[idxPotenC0](46, 40);
            tempPrint = valPotenValC0;

            fltPotenValC0 = (float) tempPrint / scaling;
            printf("CLST3.PE2(%d, %d, %d) = 0x%x|%g. \n", valPotenFeaC0, valPotenRowC0, valPotenColC0, tempPrint,
                   fltPotenValC0);
        }

        for (idxPotenC0 = 0; idxPotenC0 < 64 * 8; idxPotenC0++) {
            valPotenValC0 = PotenMemPE_3[idxPotenC0](31, 0);
            valPotenColC0 = PotenMemPE_3[idxPotenC0](35, 32);
            valPotenRowC0 = PotenMemPE_3[idxPotenC0](39, 36);
            valPotenFeaC0 = PotenMemPE_3[idxPotenC0](46, 40);
            tempPrint = valPotenValC0;

            fltPotenValC0 = (float) tempPrint / scaling;
            printf("CLST3.PE3(%d, %d, %d) = 0x%x|%g. \n", valPotenFeaC0, valPotenRowC0, valPotenColC0, tempPrint,
                   fltPotenValC0);
        }
    }
#endif
*/

    return ClstOutputPkg;

#ifdef TEST_LOG_PRINT
    printf("PE--CurStage: finish cluster. \n");
#endif

} //end of main function


void RunCluster_3(ap_uint<4> ClusterID, volatile ap_int<32> *ddr_0, struct sClstInputPkg *ClstInputPkg, struct sSpikeMemPkg *SpikeMemPkg, struct sOutputMemPkg *OutputMemPkg, _reg_timestep GlobalTimeStep, struct sClstOutputPkg *ClstOutputPkg,int weight_base_addr)
{
	*((ClstInputPkg+ClusterID)->ClstDone) = 0;
    *((ClstInputPkg+ClusterID)->ClstSync) = 0;
	*((ClstInputPkg+ClusterID)->TimeStep) = GlobalTimeStep;

	ClstOutputPkg[ClusterID] = Cluster_3(ddr_0, ClstInputPkg+ClusterID, SpikeMemPkg, OutputMemPkg+ClusterID,weight_base_addr);
}