#ifndef _PE_HEADER_
#define _PE_HEADER_

#include "global_vars.h"
#include "ALU.h"
#include "register_file.h"
#include "output_mem.h"

void SchedulePE(volatile ap_int<32> *ddr_0,
                struct sPEInputPkg *PEInputPkg,
                struct sOutputMemPkg *OutputMemPkg,
                struct sMsgPkg *InputMsgPkg,
                struct sRegFileWidePkg *RegFilePkg,
                _reg_64b *RegFileWidePkg_0,
                _reg_64b *RegFileWidePkg_1,
                _reg_64b *RegFileWidePkg_2,
                _reg_64b *RegFileWidePkg_3,
                _weight_mem *WeightMemPE_0,
                _weight_mem *WeightMemPE_1,
                _weight_mem *WeightMemPE_2,
                _weight_mem *WeightMemPE_3,
                _potential_mem *PotenMemPE_0,
                _potential_mem *PotenMemPE_1,
                _potential_mem *PotenMemPE_2,
                _potential_mem *PotenMemPE_3
);


template<int n>
void PE(volatile ap_int<32> *ddr_0,
        struct sPEInputPkg *PEInputPkg,
        struct sOutputMemPkg *OutputMemPkg,
        struct sMsgPkg *InputMsgPkg,
        struct sRegFileWidePkg *RegFilePkg,
        _reg_64b *RegFileWidePkg,
        _weight_mem *WeightMemPE,
        _potential_mem *PotenMemPE)
{
#ifdef TEST_LDW_PSEUDO
    FILE *fp = NULL;
    int i;
#endif

    struct sMsgPkg MsgPkg = *InputMsgPkg;

    _reg_64b TempReg_1;
    _reg_64b TempReg_2;
    _reg_64b TempReg_3;
    _reg_64b TempReg_4;

    _reg_32b TempReg_1_32b;

    _reg_64b_s TempReg_1s;

    switch (InputMsgPkg->opcode)
    {
        case LDW:
            ReadRegFileWide(RegFileWidePkg, MsgPkg.rega, &TempReg_1);
            ReadRegFileWide(RegFileWidePkg, MsgPkg.regb, &TempReg_2);
            ReadRegFileWide(RegFileWidePkg, MsgPkg.regc, &TempReg_3);

#ifndef TEST_LDW_PSEUDO
            //memcpy(WeightMemPE + TempReg_1, (const ap_int<32> *)(ddr_0 + BASE_ADDR_DDR / 4 + TempReg_2), TempReg_3 * sizeof(ap_int<32>));
#endif

#ifdef TEST_LDW_PSEUDO
            //fp = fopen("C:\\Users\\wangy\\Workspace\\NNWeight\\v3\\nn_c0.bin", "rb");
            //fseek( fp, TempReg_2*4 + PEInputPkg->DDR_SEG_OFFSET, SEEK_SET );


            if((PEInputPkg->ClstID)==0)
            {
                fp = fopen("C:\\Users\\wangy\\Workspace\\NNWeight\\v3\\nn_c0.bin", "rb");
                fseek( fp, TempReg_2*4 + PEInputPkg->DDR_SEG_OFFSET, SEEK_SET );
            }
            else if((PEInputPkg->ClstID)==1)
            {
                fp = fopen("C:\\Users\\wangy\\Workspace\\NNWeight\\v3\\nn_c1.bin", "rb");
                fseek( fp, TempReg_2*4 + PEInputPkg->DDR_SEG_OFFSET_1, SEEK_SET );
            }
            else if((PEInputPkg->ClstID)==2)
            {
                fp = fopen("C:\\Users\\wangy\\Workspace\\NNWeight\\v3\\nn_c2.bin", "rb");
                fseek( fp, TempReg_2*4 + PEInputPkg->DDR_SEG_OFFSET_2, SEEK_SET );
            }


            for(i = 0;i < TempReg_3;i++)
            {
                //fscanf(fp, "%d", &weight_mem_PE1[reg_ldw_dest_addr+i]);
                fread((WeightMemPE + TempReg_1 + i), 1, 4, fp);
            }
            fclose(fp);
#endif

            break;

        case WDW:
            ReadRegFileWide(RegFileWidePkg, MsgPkg.rega, &TempReg_1);
            ReadRegFileWide(RegFileWidePkg, MsgPkg.regb, &TempReg_2);
            ReadRegFileWide(RegFileWidePkg, MsgPkg.regc, &TempReg_3);
            //memcpy((ap_int<32> *)(ddr_0 + BASE_ADDR_DDR / 4 + TempReg_1), WeightMemPE+ TempReg_2, TempReg_3 * sizeof(ap_int<32>));

            break;

        case MOV:
            if((MsgPkg.flagp == 0)&&(MsgPkg.flagc == 1))
            {
                ReadRegFileWide(RegFileWidePkg, MsgPkg.regb, &TempReg_1);
                InputMsgPkg->rcpvalue = 0;
                InputMsgPkg->rcpvalue = TempReg_1;
            }
            else if((MsgPkg.flagp == 1)&&(MsgPkg.flagc == 0))
            {
                if(MsgPkg.flagi == 0)
                {
                    TempReg_1 = 0;
                    TempReg_1 = MsgPkg.rcpvalue;

                    WriteRegFileWide(RegFileWidePkg, MsgPkg.rega, &TempReg_1);
                }
                else
                {
                    if((MsgPkg.flags == 1)&&(MsgPkg.imma[15]==1))
                    {TempReg_1 = ALL_HIGH_64B;}
                    else
                    {TempReg_1 = ALL_LOW_64B;}

                    TempReg_1(15,0)=MsgPkg.imma;
                }
                WriteRegFileWide(RegFileWidePkg, MsgPkg.rega, &TempReg_1);
            }
            else if((MsgPkg.flagp == 1)&&(MsgPkg.flagc == 1))
            {
                ReadRegFileWide(RegFileWidePkg, MsgPkg.regb, &TempReg_1);
                WriteRegFileWide(RegFileWidePkg, MsgPkg.rega, &TempReg_1);
            }

            break;

        case AND:
            ReadRegFileWide(RegFileWidePkg, MsgPkg.regb, &TempReg_1);
            if(MsgPkg.flagi == 0)
            {
                ReadRegFileWide(RegFileWidePkg, MsgPkg.regc, &TempReg_2);
            }
            else
            {
                if((MsgPkg.flagfh==0)&&(MsgPkg.flagfl==0))
                {
                    TempReg_2=ALL_HIGH_64B;
                    TempReg_2(15,0)=MsgPkg.imma(15,0);
                }

                if((MsgPkg.flagfh==0)&&(MsgPkg.flagfl==1))
                {
                    TempReg_2=ALL_HIGH_64B;
                    TempReg_2(31,16)=MsgPkg.imma(15,0);
                }

                if((MsgPkg.flagfh==1)&&(MsgPkg.flagfl==0))
                {
                    TempReg_2=ALL_HIGH_64B;
                    TempReg_2(47,32)=MsgPkg.imma(15,0);
                }

                if((MsgPkg.flagfh==1)&&(MsgPkg.flagfl==1))
                {
                    TempReg_2=ALL_HIGH_64B;
                    TempReg_2(63,48)=MsgPkg.imma(15,0);
                }
            }
            TempReg_3 = ALUPE(TempReg_1, TempReg_2, ALU_AND);
            WriteRegFileWide(RegFileWidePkg, MsgPkg.rega, &TempReg_3);

            break;
/*
        case OR:
            ReadRegFileWide(RegFileWidePkg, MsgPkg.regb, &TempReg_1);
            if(MsgPkg.flagi == 0)
            {
                ReadRegFileWide(RegFileWidePkg, MsgPkg.regc, &TempReg_2);
            }
            else
            {
                if((MsgPkg.flagfh==0)&&(MsgPkg.flagfl==0))
                {
                    TempReg_2=ALL_LOW_64B;
                    TempReg_2(15,0)=MsgPkg.imma(15,0);
                }

                if((MsgPkg.flagfh==0)&&(MsgPkg.flagfl==1))
                {
                    TempReg_2=ALL_LOW_64B;
                    TempReg_2(31,16)=MsgPkg.imma(15,0);
                }

                if((MsgPkg.flagfh==1)&&(MsgPkg.flagfl==0))
                {
                    TempReg_2=ALL_LOW_64B;
                    TempReg_2(47,32)=MsgPkg.imma(15,0);
                }

                if((MsgPkg.flagfh==1)&&(MsgPkg.flagfl==1))
                {
                    TempReg_2=ALL_LOW_64B;
                    TempReg_2(63,48)=MsgPkg.imma(15,0);
                }
            }
            TempReg_3 = ALUPE(TempReg_1, TempReg_2, ALU_OR);
            WriteRegFileWide(RegFileWidePkg, MsgPkg.rega, &TempReg_3);

            break;
*/
/*
        case XOR:
            ReadRegFileWide(RegFileWidePkg, MsgPkg.regb, &TempReg_1);
            if(MsgPkg.flagi == 0)
            {
                ReadRegFileWide(RegFileWidePkg, MsgPkg.regc, &TempReg_2);
            }
            else
            {
                if((MsgPkg.flagfh==0)&&(MsgPkg.flagfl==0))
                {
                    TempReg_2=ALL_HIGH_64B;
                    TempReg_2(15,0)=MsgPkg.imma(15,0);
                }

                if((MsgPkg.flagfh==0)&&(MsgPkg.flagfl==1))
                {
                    TempReg_2=ALL_HIGH_64B;
                    TempReg_2(31,16)=MsgPkg.imma(15,0);
                }

                if((MsgPkg.flagfh==1)&&(MsgPkg.flagfl==0))
                {
                    TempReg_2=ALL_HIGH_64B;
                    TempReg_2(47,32)=MsgPkg.imma(15,0);
                }

                if((MsgPkg.flagfh==1)&&(MsgPkg.flagfl==1))
                {
                    TempReg_2=ALL_HIGH_64B;
                    TempReg_2(63,48)=MsgPkg.imma(15,0);
                }
            }
            TempReg_3 = ALUPE(TempReg_1, TempReg_2, ALU_XOR);
            WriteRegFileWide(RegFileWidePkg, MsgPkg.rega, &TempReg_3);

            break;
*/
        case ADD:
            ReadRegFileWide(RegFileWidePkg, MsgPkg.regb, &TempReg_1);
            if(MsgPkg.flagi == 0)
            {
                ReadRegFileWide(RegFileWidePkg, MsgPkg.regc, &TempReg_2);
            }
            else
            {
                if((MsgPkg.flags == 1)&&(MsgPkg.imma[15]==1))
                {TempReg_2 = ALL_HIGH_64B;}
                else
                {TempReg_2 = ALL_LOW_64B;}
                TempReg_2(15,0)=MsgPkg.imma;
            }

            if(MsgPkg.flags == 1)
            {
                TempReg_1s = ALUPE(*(_reg_64b_s *)(&TempReg_1), *(_reg_64b_s *)(&TempReg_2), ALU_ADD);
                TempReg_3 = *(_reg_64b *)(&TempReg_1s);
            }
            else
            {
                TempReg_3 = ALUPE(TempReg_1, TempReg_2, ALU_ADD);
            }
            WriteRegFileWide(RegFileWidePkg, MsgPkg.rega, &TempReg_3);

            break;

        case SUB:
            ReadRegFileWide(RegFileWidePkg, MsgPkg.regb, &TempReg_1);
            if(MsgPkg.flagi == 0)
            {
                ReadRegFileWide(RegFileWidePkg, MsgPkg.regc, &TempReg_2);
            }
            else
            {
                if((MsgPkg.flags == 1)&&(MsgPkg.imma[15]==1))
                {TempReg_2 = ALL_HIGH_64B;}
                else
                {TempReg_2 = ALL_LOW_64B;}
                TempReg_2(15,0)=MsgPkg.imma;
            }

            if(MsgPkg.flags == 1)
            {
                TempReg_1s = ALUPE(*(_reg_64b_s *)(&TempReg_1), *(_reg_64b_s *)(&TempReg_2), ALU_SUB);
                TempReg_3 = *(_reg_64b *)(&TempReg_1s);
            }
            else
            {
                TempReg_3 = ALUPE(TempReg_1, TempReg_2, ALU_SUB);
            }
            WriteRegFileWide(RegFileWidePkg, MsgPkg.rega, &TempReg_3);

            break;

        case MUL:
            ReadRegFileWide(RegFileWidePkg, MsgPkg.regb, &TempReg_1);
            if(MsgPkg.flagi == 0)
            {
                ReadRegFileWide(RegFileWidePkg, MsgPkg.regc, &TempReg_2);
            }
            else
            {
                if((MsgPkg.flags == 1)&&(MsgPkg.imma[15]==1))
                {TempReg_2 = ALL_HIGH_64B;}
                else
                {TempReg_2 = ALL_LOW_64B;}
                TempReg_2(15,0)=MsgPkg.imma;
            }

            if(MsgPkg.flags == 1)
            {
                TempReg_1s = ALUPE(*(_reg_64b_s *)(&TempReg_1), *(_reg_64b_s *)(&TempReg_2), ALU_MUL);
                TempReg_3 = *(_reg_64b *)(&TempReg_1s);
            }
            else
            {
                TempReg_3 = ALUPE(TempReg_1, TempReg_2, ALU_MUL);
            }
            WriteRegFileWide(RegFileWidePkg, MsgPkg.rega, &TempReg_3);

            break;
/*
        case DVD:
            ReadRegFileWide(RegFileWidePkg, MsgPkg.regb, &TempReg_1);
            if(MsgPkg.flagi == 0)
            {
                ReadRegFileWide(RegFileWidePkg, MsgPkg.regc, &TempReg_2);
            }
            else
            {
                if((MsgPkg.flags == 1)&&(MsgPkg.imma[15]==1))
                {TempReg_2 = ALL_HIGH_64B;}
                else
                {TempReg_2 = ALL_LOW_64B;}
                TempReg_2(15,0)=MsgPkg.imma;
            }

            if(MsgPkg.flags == 1)
            {
                TempReg_1s = ALUPE(*(_reg_64b_s *)(&TempReg_1), *(_reg_64b_s *)(&TempReg_2), ALU_DVD);
                TempReg_3 = *(_reg_64b *)(&TempReg_1s);
            }
            else
            {
                TempReg_3 = ALUPE(TempReg_1, TempReg_2, ALU_DVD);
            }
            WriteRegFileWide(RegFileWidePkg, MsgPkg.rega, &TempReg_3);

            break;
*/
/*
        case MOD:
            ReadRegFileWide(RegFileWidePkg, MsgPkg.regb, &TempReg_1);
            if(MsgPkg.flagi == 0)
            {
                ReadRegFileWide(RegFileWidePkg, MsgPkg.regc, &TempReg_2);
            }
            else
            {
                if((MsgPkg.flags == 1)&&(MsgPkg.imma[15]==1))
                {TempReg_2 = ALL_HIGH_64B;}
                else
                {TempReg_2 = ALL_LOW_64B;}
                TempReg_2(15,0)=MsgPkg.imma;
            }

            if(MsgPkg.flags == 1)
            {
                TempReg_1s = ALUPE(*(_reg_64b_s *)(&TempReg_1), *(_reg_64b_s *)(&TempReg_2), ALU_MOD);
                TempReg_3 = *(_reg_64b *)(&TempReg_1s);
            }
            else
            {
                TempReg_3 = ALUPE(TempReg_1, TempReg_2, ALU_MOD);
            }
            WriteRegFileWide(RegFileWidePkg, MsgPkg.rega, &TempReg_3);

            break;
*/
        case LFT:
            ReadRegFileWide(RegFileWidePkg, MsgPkg.regb, &TempReg_1);
            if(MsgPkg.flagi == 0)
            {
                ReadRegFileWide(RegFileWidePkg, MsgPkg.regc, &TempReg_2);
            }
            else
            {
                TempReg_2 = ALL_LOW_64B;
                TempReg_2(15,0) = MsgPkg.imma;
            }
            TempReg_3 = ALUPE(TempReg_1, TempReg_2, ALU_LFT);
            WriteRegFileWide(RegFileWidePkg, MsgPkg.rega, &TempReg_3);

            break;

        case RFT:
            ReadRegFileWide(RegFileWidePkg, MsgPkg.regb, &TempReg_1);
            if(MsgPkg.flagi == 0)
            {
                ReadRegFileWide(RegFileWidePkg, MsgPkg.regc, &TempReg_2);
            }
            else
            {
                TempReg_2 = ALL_LOW_64B;
                TempReg_2(15,0) = MsgPkg.imma;
            }

            TempReg_3 = ALUPE(TempReg_1, TempReg_2, ALU_RFT);
            if((MsgPkg.flags==1)&&(TempReg_1[63]==1))
            {TempReg_3(63,63-TempReg_2) = ALL_HIGH_64B;}

            WriteRegFileWide(RegFileWidePkg, MsgPkg.rega, &TempReg_3);

            break;

        case SGS:
            /*
            ReadRegFileWide(RegFileWidePkg, MsgPkg.regb, &TempReg_1);
            if((MsgPkg.flags==1)&&(TempReg_1[MsgPkg.immbh]==1))
            {TempReg_2 = ALL_HIGH_64B;}
            else
            {TempReg_2 = ALL_LOW_64B;}

            TempReg_2(MsgPkg.immbh-MsgPkg.immbl, 0) = TempReg_1(MsgPkg.immbh, MsgPkg.immbl);
            WriteRegFileWide(RegFileWidePkg, MsgPkg.rega, &TempReg_2);
             */

            ReadRegFileWide(RegFileWidePkg, MsgPkg.regb, &TempReg_1);
            if(TempReg_1[31]==1)
            {TempReg_2 = ALL_HIGH_64B;}
            else
            {TempReg_2 = ALL_LOW_64B;}

            TempReg_2(31, 0) = TempReg_1(31, 0);
            WriteRegFileWide(RegFileWidePkg, MsgPkg.rega, &TempReg_2);

            break;
/*
        case CCT:
            ReadRegFileWide(RegFileWidePkg, MsgPkg.regb, &TempReg_1);
            ReadRegFileWide(RegFileWidePkg, MsgPkg.regc, &TempReg_2);
            TempReg_3 = ALL_LOW_64B;
            TempReg_3((MsgPkg.immch-MsgPkg.immcl), 0) = TempReg_2(MsgPkg.immch, MsgPkg.immcl);
            TempReg_3((MsgPkg.immbh-MsgPkg.immbl+MsgPkg.immch-MsgPkg.immcl+1), (MsgPkg.immch-MsgPkg.immcl+1)) = TempReg_1(MsgPkg.immbh, MsgPkg.immbl);
            WriteRegFileWide(RegFileWidePkg, MsgPkg.rega, &TempReg_3);

            break;
*/
        case RWM:
            ReadRegFileWide(RegFileWidePkg, MsgPkg.regb, &TempReg_1);

            TempReg_1_32b = WeightMemPE[TempReg_1];
            if(TempReg_1_32b[31]==1)
            {TempReg_2 = ALL_HIGH_64B;}
            else
            {TempReg_2 = ALL_LOW_64B;}
            TempReg_2(31,0)=TempReg_1_32b(31,0);

            WriteRegFileWide(RegFileWidePkg, MsgPkg.rega, &TempReg_2);

            break;

        case RPM:
            ReadRegFileWide(RegFileWidePkg, MsgPkg.regb, &TempReg_1);
            TempReg_2 = PotenMemPE[TempReg_1];
            WriteRegFileWide(RegFileWidePkg, MsgPkg.rega, &TempReg_2);

            #ifdef TEST_LOG_PRINT
                int PrintHighRPM;
                int PrintLowRPM;
                PrintHighRPM = TempReg_2(63,32);
                PrintLowRPM  = TempReg_2(31,0);

                printf("PE--read 0x%x_%x from PotenMem[%d]. \n", (unsigned int)PrintHighRPM, (unsigned int)PrintLowRPM, (int)TempReg_1);
            #endif

            break;

        case WBW:
            ReadRegFileWide(RegFileWidePkg, MsgPkg.rega, &TempReg_1);
            ReadRegFileWide(RegFileWidePkg, MsgPkg.regb, &TempReg_2);
            WeightMemPE[TempReg_1] = TempReg_2(31,0);

            break;

        case WBP:
            ReadRegFileWide(RegFileWidePkg, MsgPkg.rega, &TempReg_1);
            ReadRegFileWide(RegFileWidePkg, MsgPkg.regb, &TempReg_2);
            PotenMemPE[TempReg_1] = TempReg_2(63,0);

#ifdef TEST_LOG_PRINT
            int PrintHighWBP;
            int PrintLowWBP;
            PrintHighWBP = TempReg_2(63,32);
            PrintLowWBP  = TempReg_2(31,0);

            printf("PE--write 0x%x_%x to PotenMem[%d]. \n", (unsigned int)PrintHighWBP, (unsigned int)PrintLowWBP, (int)TempReg_1);
#endif

            break;

        case OPT:
            ReadRegFileWide(RegFileWidePkg, MsgPkg.rega, &TempReg_1);
            ReadRegFileWide(RegFileWidePkg, MsgPkg.regb, &TempReg_2);
            ReadRegFileWide(RegFileWidePkg, MsgPkg.regc, &TempReg_3);
            if (ALUPES(*(ap_int<64> *)(&TempReg_1), *(ap_int<64> *)(&TempReg_2), ALU_JNL))
            {
                //TempReg_1(31,0)=0;
                TempReg_1=0;
                WriteRegFileWide(RegFileWidePkg, MsgPkg.rega, &TempReg_1);
                TempReg_4=0;
                TempReg_4(47,32) = MsgPkg.imma; //mask_clst
                TempReg_4(31,0) = TempReg_3(31,0);
                //write TempReg_3 to output memory
                WriteOutputMem(OutputMemPkg, TempReg_4);

#ifdef TEST_LOG_PRINT
                int PrintHighOPT;
                int PrintLowOPT;
                PrintHighOPT = TempReg_4(63,32);
                PrintLowOPT  = TempReg_4(31,0);

                printf("PE--write 0x%x_%x to OutputMem. \n", (unsigned int)PrintHighOPT, (unsigned int)PrintLowOPT);
#endif
            }

            break;

        default:
            break;

    }
}

#endif
