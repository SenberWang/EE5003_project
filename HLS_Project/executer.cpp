#include "executer.h"

_idx_instr_mem executer(
        volatile ap_int<32> *ddr_0,
        _idx_instr_mem *IdxInstr,
        ap_uint<1> *ClusterDone,
        ap_uint<1> *ClusterSync,
        struct sClstInputPkg *ClstInputPkg,
        struct sSpikeMemPkg *SpikeMemPkg,
        struct sPEInputPkg *PEInputPkg,
        struct sOutputMemPkg *OutputMemPkg,
        struct sMsgPkg *MsgPkg,
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
        )
{
    _idx_instr_mem next_pc = *IdxInstr;

    _reg_64b TempReg_1;
    _reg_64b TempReg_2;
    _reg_64b TempReg_3;

    _reg_32b TempReg_1_32b;

    _reg_64b_s TempReg_1s;

    switch (MsgPkg->opcode)
    {
        case MOV:
#ifdef TEST_LOG_PRINT
            printf("CLS-----------------------------PC=%d: enter MOV case-----------------------------\n", (int)*IdxInstr);
#endif

            if((MsgPkg->flagp == 0)&&(MsgPkg->flagc == 0))
            {
                if(MsgPkg->flagi == 0)
                {
                    ReadRegFile(RegFilePkg, MsgPkg->regb, &TempReg_1);
                }
                else
                {
                    if((MsgPkg->flags == 1)&&(MsgPkg->imma[15]==1))
                    {TempReg_1 = ALL_HIGH_64B;}
                    else
                    {TempReg_1 = ALL_LOW_64B;}

                    TempReg_1(15,0)=MsgPkg->imma;
                }

                WriteRegFile(RegFilePkg, MsgPkg->rega, &TempReg_1);
            }
            else if((MsgPkg->flagp == 0)&&(MsgPkg->flagc == 1))
            {
                SchedulePE(ddr_0, PEInputPkg, OutputMemPkg, MsgPkg, RegFilePkg, RegFileWidePkg_0, RegFileWidePkg_1, RegFileWidePkg_2, RegFileWidePkg_3, WeightMemPE_0, WeightMemPE_1, WeightMemPE_2, WeightMemPE_3, PotenMemPE_0, PotenMemPE_1, PotenMemPE_2, PotenMemPE_3);
                TempReg_1 = 0;
                TempReg_1 = MsgPkg->rcpvalue;
                WriteRegFile(RegFilePkg, MsgPkg->rega, &TempReg_1);
            }
            else if((MsgPkg->flagp == 1)&&(MsgPkg->flagc == 0))
            {
                if(MsgPkg->flagi == 0)
                {
                    ReadRegFile(RegFilePkg, MsgPkg->regb, &TempReg_1);
                    MsgPkg->rcpvalue = 0;
                    MsgPkg->rcpvalue = TempReg_1;

                    SchedulePE(ddr_0, PEInputPkg, OutputMemPkg, MsgPkg, RegFilePkg, RegFileWidePkg_0, RegFileWidePkg_1, RegFileWidePkg_2, RegFileWidePkg_3, WeightMemPE_0, WeightMemPE_1, WeightMemPE_2, WeightMemPE_3, PotenMemPE_0, PotenMemPE_1, PotenMemPE_2, PotenMemPE_3);
                }
                else
                {
                    SchedulePE(ddr_0, PEInputPkg, OutputMemPkg, MsgPkg, RegFilePkg, RegFileWidePkg_0, RegFileWidePkg_1, RegFileWidePkg_2, RegFileWidePkg_3, WeightMemPE_0, WeightMemPE_1, WeightMemPE_2, WeightMemPE_3, PotenMemPE_0, PotenMemPE_1, PotenMemPE_2, PotenMemPE_3);
                }

            }
            else if((MsgPkg->flagp == 1)&&(MsgPkg->flagc == 1))
            {
                SchedulePE(ddr_0, PEInputPkg, OutputMemPkg, MsgPkg, RegFilePkg, RegFileWidePkg_0, RegFileWidePkg_1, RegFileWidePkg_2, RegFileWidePkg_3, WeightMemPE_0, WeightMemPE_1, WeightMemPE_2, WeightMemPE_3, PotenMemPE_0, PotenMemPE_1, PotenMemPE_2, PotenMemPE_3);
            }

            next_pc++;

#ifdef TEST_LOG_PRINT
            printf("CLS-----------------------------PC=%d: exit MOV case-----------------------------\n", (int)*IdxInstr);
#endif
            break;

        case AND:
#ifdef TEST_LOG_PRINT
            printf("CLS-----------------------------PC=%d: enter AND case-----------------------------\n", (int)*IdxInstr);
#endif

            if(MsgPkg->flagp == 0)
            {
                ReadRegFile(RegFilePkg, MsgPkg->regb, &TempReg_1);
                if(MsgPkg->flagi == 0)
                {
                    ReadRegFile(RegFilePkg, MsgPkg->regc, &TempReg_2);
                }
                else
                {
                    if((MsgPkg->flagfh==0)&&(MsgPkg->flagfl==0))
                    {
                        TempReg_2=ALL_HIGH_64B;
                        TempReg_2(15,0)=MsgPkg->imma(15,0);
                    }

                    if((MsgPkg->flagfh==0)&&(MsgPkg->flagfl==1))
                    {
                        TempReg_2=ALL_HIGH_64B;
                        TempReg_2(31,16)=MsgPkg->imma(15,0);
                    }

                    if((MsgPkg->flagfh==1)&&(MsgPkg->flagfl==0))
                    {
                        TempReg_2=ALL_HIGH_64B;
                        TempReg_2(47,32)=MsgPkg->imma(15,0);
                    }

                    if((MsgPkg->flagfh==1)&&(MsgPkg->flagfl==1))
                    {
                        TempReg_2=ALL_HIGH_64B;
                        TempReg_2(63,48)=MsgPkg->imma(15,0);
                    }
                }
                TempReg_3 = ALU(TempReg_1, TempReg_2, ALU_AND);
                WriteRegFile(RegFilePkg, MsgPkg->rega, &TempReg_3);
            }
            else
            {
                SchedulePE(ddr_0, PEInputPkg, OutputMemPkg, MsgPkg, RegFilePkg, RegFileWidePkg_0, RegFileWidePkg_1, RegFileWidePkg_2, RegFileWidePkg_3, WeightMemPE_0, WeightMemPE_1, WeightMemPE_2, WeightMemPE_3, PotenMemPE_0, PotenMemPE_1, PotenMemPE_2, PotenMemPE_3);
            }

            next_pc++;

#ifdef TEST_LOG_PRINT
            printf("CLS-----------------------------PC=%d: exit AND case-----------------------------\n", (int)*IdxInstr);
#endif
            break;
/*
        case OR:
#ifdef TEST_LOG_PRINT
            printf("CLS-----------------------------PC=%d: enter OR case-----------------------------\n", (int)*IdxInstr);
#endif

            if(MsgPkg->flagp == 0)
            {
                ReadRegFile(RegFilePkg, MsgPkg->regb, &TempReg_1);
                if(MsgPkg->flagi == 0)
                {
                    ReadRegFile(RegFilePkg, MsgPkg->regc, &TempReg_2);
                }
                else
                {
                    if((MsgPkg->flagfh==0)&&(MsgPkg->flagfl==0))
                    {
                        TempReg_2=ALL_LOW_64B;
                        TempReg_2(15,0)=MsgPkg->imma(15,0);
                    }

                    if((MsgPkg->flagfh==0)&&(MsgPkg->flagfl==1))
                    {
                        TempReg_2=ALL_LOW_64B;
                        TempReg_2(31,16)=MsgPkg->imma(15,0);
                    }

                    if((MsgPkg->flagfh==1)&&(MsgPkg->flagfl==0))
                    {
                        TempReg_2=ALL_LOW_64B;
                        TempReg_2(47,32)=MsgPkg->imma(15,0);
                    }

                    if((MsgPkg->flagfh==1)&&(MsgPkg->flagfl==1))
                    {
                        TempReg_2=ALL_LOW_64B;
                        TempReg_2(63,48)=MsgPkg->imma(15,0);
                    }
                }
                TempReg_3 = ALU(TempReg_1, TempReg_2, ALU_OR);
                WriteRegFile(RegFilePkg, MsgPkg->rega, &TempReg_3);
            }
            else
            {
                SchedulePE(ddr_0, PEInputPkg, OutputMemPkg, MsgPkg, RegFilePkg, RegFileWidePkg_0, RegFileWidePkg_1, RegFileWidePkg_2, RegFileWidePkg_3, WeightMemPE_0, WeightMemPE_1, WeightMemPE_2, WeightMemPE_3, PotenMemPE_0, PotenMemPE_1, PotenMemPE_2, PotenMemPE_3);
            }

            next_pc++;

#ifdef TEST_LOG_PRINT
            printf("CLS-----------------------------PC=%d: exit OR case-----------------------------\n", (int)*IdxInstr);
#endif
            break;
*/
/*
        case XOR:
            #ifdef TEST_LOG_PRINT
                printf("CLS-----------------------------PC=%d: enter XOR case-----------------------------\n", (int)*IdxInstr);
            #endif

            if(MsgPkg->flagp == 0)
            {
                ReadRegFile(RegFilePkg, MsgPkg->regb, &TempReg_1);
                if(MsgPkg->flagi == 0)
                {
                    ReadRegFile(RegFilePkg, MsgPkg->regc, &TempReg_2);
                }
                else
                {
                    if((MsgPkg->flagfh==0)&&(MsgPkg->flagfl==0))
                    {
                        TempReg_2=ALL_HIGH_64B;
                        TempReg_2(15,0)=MsgPkg->imma(15,0);
                    }

                    if((MsgPkg->flagfh==0)&&(MsgPkg->flagfl==1))
                    {
                        TempReg_2=ALL_HIGH_64B;
                        TempReg_2(31,16)=MsgPkg->imma(15,0);
                    }

                    if((MsgPkg->flagfh==1)&&(MsgPkg->flagfl==0))
                    {
                        TempReg_2=ALL_HIGH_64B;
                        TempReg_2(47,32)=MsgPkg->imma(15,0);
                    }

                    if((MsgPkg->flagfh==1)&&(MsgPkg->flagfl==1))
                    {
                        TempReg_2=ALL_HIGH_64B;
                        TempReg_2(63,48)=MsgPkg->imma(15,0);
                    }
                }
                TempReg_3 = ALU(TempReg_1, TempReg_2, ALU_XOR);
                WriteRegFile(RegFilePkg, MsgPkg->rega, &TempReg_3);
            }
            else
            {
                SchedulePE(ddr_0, PEInputPkg, OutputMemPkg, MsgPkg, RegFilePkg, RegFileWidePkg_0, RegFileWidePkg_1, RegFileWidePkg_2, RegFileWidePkg_3, WeightMemPE_0, WeightMemPE_1, WeightMemPE_2, WeightMemPE_3, PotenMemPE_0, PotenMemPE_1, PotenMemPE_2, PotenMemPE_3);
            }

            next_pc++;

            #ifdef TEST_LOG_PRINT
                printf("CLS-----------------------------PC=%d: exit XOR case-----------------------------\n", (int)*IdxInstr);
            #endif
			break;
*/
        case ADD:
#ifdef TEST_LOG_PRINT
            printf("CLS-----------------------------PC=%d: enter ADD case-----------------------------\n", (int)*IdxInstr);
#endif

            if(MsgPkg->flagp == 0)
            {
                ReadRegFile(RegFilePkg, MsgPkg->regb, &TempReg_1);
                if(MsgPkg->flagi == 0)
                {
                    ReadRegFile(RegFilePkg, MsgPkg->regc, &TempReg_2);
                }
                else
                {
                    if((MsgPkg->flags == 1)&&(MsgPkg->imma[15]==1))
                    {TempReg_2 = ALL_HIGH_64B;}
                    else
                    {TempReg_2 = ALL_LOW_64B;}
                    TempReg_2(15,0) = MsgPkg->imma(15,0);
                }

                if(MsgPkg->flags == 1)
                {
                    TempReg_1s = ALUS(*(_reg_64b_s *)(&TempReg_1), *(_reg_64b_s *)(&TempReg_2), ALU_ADD);
                    TempReg_3 = *(_reg_64b *)(&TempReg_1s);
                }
                else
                {
                    TempReg_3 = ALU(TempReg_1, TempReg_2, ALU_ADD);
                }
                WriteRegFile(RegFilePkg, MsgPkg->rega, &TempReg_3);
            }
            else
            {
                SchedulePE(ddr_0, PEInputPkg, OutputMemPkg, MsgPkg, RegFilePkg, RegFileWidePkg_0, RegFileWidePkg_1, RegFileWidePkg_2, RegFileWidePkg_3, WeightMemPE_0, WeightMemPE_1, WeightMemPE_2, WeightMemPE_3, PotenMemPE_0, PotenMemPE_1, PotenMemPE_2, PotenMemPE_3);
            }

            next_pc++;

#ifdef TEST_LOG_PRINT
            printf("CLS-----------------------------PC=%d: exit ADD case-----------------------------\n", (int)*IdxInstr);
#endif
            break;

        case SUB:
#ifdef TEST_LOG_PRINT
            printf("CLS-----------------------------PC=%d: enter SUB case-----------------------------\n", (int)*IdxInstr);
#endif
/*
            if(MsgPkg->flagp == 0)
            {
                ReadRegFile(RegFilePkg, MsgPkg->regb, &TempReg_1);
                if(MsgPkg->flagi == 0)
                {
                    ReadRegFile(RegFilePkg, MsgPkg->regc, &TempReg_2);
                }
                else
                {
                    if((MsgPkg->flags == 1)&&(MsgPkg->imma[15]==1))
                    {TempReg_2 = ALL_HIGH_64B;}
                    else
                    {TempReg_2 = ALL_LOW_64B;}
                    TempReg_2(15,0) = MsgPkg->imma(15,0);
                }

                if(MsgPkg->flags == 1)
                {
                    TempReg_1s = ALUS(*(_reg_64b_s *)(&TempReg_1), *(_reg_64b_s *)(&TempReg_2), ALU_SUB);
                    TempReg_3 = *(_reg_64b *)(&TempReg_1s);
                }
                else
                {
                    TempReg_3 = ALU(TempReg_1, TempReg_2, ALU_SUB);
                }
                WriteRegFile(RegFilePkg, MsgPkg->rega, &TempReg_3);
            }
            else
            {
                SchedulePE(ddr_0, PEInputPkg, OutputMemPkg, MsgPkg, RegFilePkg, RegFileWidePkg_0, RegFileWidePkg_1, RegFileWidePkg_2, RegFileWidePkg_3, WeightMemPE_0, WeightMemPE_1, WeightMemPE_2, WeightMemPE_3, PotenMemPE_0, PotenMemPE_1, PotenMemPE_2, PotenMemPE_3);
            }
*/
            SchedulePE(ddr_0, PEInputPkg, OutputMemPkg, MsgPkg, RegFilePkg, RegFileWidePkg_0, RegFileWidePkg_1, RegFileWidePkg_2, RegFileWidePkg_3, WeightMemPE_0, WeightMemPE_1, WeightMemPE_2, WeightMemPE_3, PotenMemPE_0, PotenMemPE_1, PotenMemPE_2, PotenMemPE_3);

            next_pc++;

#ifdef TEST_LOG_PRINT
            printf("CLS-----------------------------PC=%d: exit SUB case-----------------------------\n", (int)*IdxInstr);
#endif
            break;

        case MUL:
#ifdef TEST_LOG_PRINT
            printf("CLS-----------------------------PC=%d: enter MUL case-----------------------------\n", (int)*IdxInstr);
#endif
/*
            if(MsgPkg->flagp == 0)
            {
                ReadRegFile(RegFilePkg, MsgPkg->regb, &TempReg_1);
                if(MsgPkg->flagi == 0)
                {
                    ReadRegFile(RegFilePkg, MsgPkg->regc, &TempReg_2);
                }
                else
                {
                    if((MsgPkg->flags == 1)&&(MsgPkg->imma[15]==1))
                    {TempReg_2 = ALL_HIGH_64B;}
                    else
                    {TempReg_2 = ALL_LOW_64B;}
                    TempReg_2(15,0) = MsgPkg->imma(15,0);
                }

                if(MsgPkg->flags == 1)
                {
                    TempReg_1s = ALUS(*(_reg_64b_s *)(&TempReg_1), *(_reg_64b_s *)(&TempReg_2), ALU_MUL);
                    TempReg_3 = *(_reg_64b *)(&TempReg_1s);
                }
                else
                {
                    TempReg_3 = ALU(TempReg_1, TempReg_2, ALU_MUL);
                }
                WriteRegFile(RegFilePkg, MsgPkg->rega, &TempReg_3);
            }
            else
            {
                SchedulePE(ddr_0, PEInputPkg, OutputMemPkg, MsgPkg, RegFilePkg, RegFileWidePkg_0, RegFileWidePkg_1, RegFileWidePkg_2, RegFileWidePkg_3, WeightMemPE_0, WeightMemPE_1, WeightMemPE_2, WeightMemPE_3, PotenMemPE_0, PotenMemPE_1, PotenMemPE_2, PotenMemPE_3);
            }
*/
            SchedulePE(ddr_0, PEInputPkg, OutputMemPkg, MsgPkg, RegFilePkg, RegFileWidePkg_0, RegFileWidePkg_1, RegFileWidePkg_2, RegFileWidePkg_3, WeightMemPE_0, WeightMemPE_1, WeightMemPE_2, WeightMemPE_3, PotenMemPE_0, PotenMemPE_1, PotenMemPE_2, PotenMemPE_3);

            next_pc++;

#ifdef TEST_LOG_PRINT
            printf("CLS-----------------------------PC=%d: exit MUL case-----------------------------\n", (int)*IdxInstr);
#endif
            break;
/*
        case DVD:
#ifdef TEST_LOG_PRINT
            printf("CLS-----------------------------PC=%d: enter DVD case-----------------------------\n", (int)*IdxInstr);
#endif

            if(MsgPkg->flagp == 0)
            {
                ReadRegFile(RegFilePkg, MsgPkg->regb, &TempReg_1);
                if(MsgPkg->flagi == 0)
                {
                    ReadRegFile(RegFilePkg, MsgPkg->regc, &TempReg_2);
                }
                else
                {
                    if((MsgPkg->flags == 1)&&(MsgPkg->imma[15]==1))
                    {TempReg_2 = ALL_HIGH_64B;}
                    else
                    {TempReg_2 = ALL_LOW_64B;}
                    TempReg_2(15,0) = MsgPkg->imma(15,0);
                }

                if(MsgPkg->flags == 1)
                {
                    TempReg_1s = ALUS(*(_reg_64b_s *)(&TempReg_1), *(_reg_64b_s *)(&TempReg_2), ALU_DVD);
                    TempReg_3 = *(_reg_64b *)(&TempReg_1s);
                }
                else
                {
                    TempReg_3 = ALU(TempReg_1, TempReg_2, ALU_DVD);
                }
                WriteRegFile(RegFilePkg, MsgPkg->rega, &TempReg_3);
            }
            else
            {
                SchedulePE(ddr_0, PEInputPkg, OutputMemPkg, MsgPkg, RegFilePkg, RegFileWidePkg_0, RegFileWidePkg_1, RegFileWidePkg_2, RegFileWidePkg_3, WeightMemPE_0, WeightMemPE_1, WeightMemPE_2, WeightMemPE_3, PotenMemPE_0, PotenMemPE_1, PotenMemPE_2, PotenMemPE_3);
            }

            next_pc++;

#ifdef TEST_LOG_PRINT
            printf("CLS-----------------------------PC=%d: exit DVD case-----------------------------\n", (int)*IdxInstr);
#endif
            break;
*/
/*
        case MOD:
            #ifdef TEST_LOG_PRINT
                printf("CLS-----------------------------PC=%d: enter MOD case-----------------------------\n", (int)*IdxInstr);
            #endif

            if(MsgPkg->flagp == 0)
            {
                ReadRegFile(RegFilePkg, MsgPkg->regb, &TempReg_1);
                if(MsgPkg->flagi == 0)
                {
                    ReadRegFile(RegFilePkg, MsgPkg->regc, &TempReg_2);
                }
                else
                {
                    if((MsgPkg->flags == 1)&&(MsgPkg->imma[15]==1))
                    {TempReg_2 = ALL_HIGH_64B;}
                    else
                    {TempReg_2 = ALL_LOW_64B;}
                    TempReg_2(15,0) = MsgPkg->imma(15,0);
                }

                if(MsgPkg->flags == 1)
                {
                    TempReg_1s = ALUS(*(_reg_64b_s *)(&TempReg_1), *(_reg_64b_s *)(&TempReg_2), ALU_MOD);
                    TempReg_3 = *(_reg_64b *)(&TempReg_1s);
                }
                else
                {
                    TempReg_3 = ALU(TempReg_1, TempReg_2, ALU_MOD);
                }
                WriteRegFile(RegFilePkg, MsgPkg->rega, &TempReg_3);
            }
            else
            {
                SchedulePE(ddr_0, PEInputPkg, OutputMemPkg, MsgPkg, RegFilePkg, RegFileWidePkg_0, RegFileWidePkg_1, RegFileWidePkg_2, RegFileWidePkg_3, WeightMemPE_0, WeightMemPE_1, WeightMemPE_2, WeightMemPE_3, PotenMemPE_0, PotenMemPE_1, PotenMemPE_2, PotenMemPE_3);
            }

            next_pc++;

            #ifdef TEST_LOG_PRINT
                printf("CLS-----------------------------PC=%d: exit MOD case-----------------------------\n", (int)*IdxInstr);
            #endif
        	break;
*/
        case LFT:
#ifdef TEST_LOG_PRINT
            printf("CLS-----------------------------PC=%d: enter LFT case-----------------------------\n", (int)*IdxInstr);
#endif

            if(MsgPkg->flagp == 0)
            {
                ReadRegFile(RegFilePkg, MsgPkg->regb, &TempReg_1);
                if(MsgPkg->flagi == 0)
                {
                    ReadRegFile(RegFilePkg, MsgPkg->regc, &TempReg_2);
                }
                else
                {
                    TempReg_2 = ALL_LOW_64B;
                    TempReg_2(15,0) = MsgPkg->imma;
                }
                TempReg_3 = ALU(TempReg_1, TempReg_2, ALU_LFT);
                WriteRegFile(RegFilePkg, MsgPkg->rega, &TempReg_3);
            }
            else
            {
                SchedulePE(ddr_0, PEInputPkg, OutputMemPkg, MsgPkg, RegFilePkg, RegFileWidePkg_0, RegFileWidePkg_1, RegFileWidePkg_2, RegFileWidePkg_3, WeightMemPE_0, WeightMemPE_1, WeightMemPE_2, WeightMemPE_3, PotenMemPE_0, PotenMemPE_1, PotenMemPE_2, PotenMemPE_3);
            }

            next_pc++;

#ifdef TEST_LOG_PRINT
            printf("CLS-----------------------------PC=%d: exit LFT case-----------------------------\n", (int)*IdxInstr);
#endif
            break;

        case RFT:
#ifdef TEST_LOG_PRINT
            printf("CLS-----------------------------PC=%d: enter RFT case-----------------------------\n", (int)*IdxInstr);
#endif

            if(MsgPkg->flagp == 0)
            {
                ReadRegFile(RegFilePkg, MsgPkg->regb, &TempReg_1);
                if(MsgPkg->flagi == 0)
                {
                    ReadRegFile(RegFilePkg, MsgPkg->regc, &TempReg_2);
                }
                else
                {
                    TempReg_2 = ALL_LOW_64B;
                    TempReg_2(15,0) = MsgPkg->imma;
                }

                TempReg_3 = ALU(TempReg_1, TempReg_2, ALU_RFT);
                if((MsgPkg->flags==1)&&(TempReg_1[63]==1))
                {TempReg_3(63,31-TempReg_2) = ALL_HIGH_64B;}

                WriteRegFile(RegFilePkg, MsgPkg->rega, &TempReg_3);
            }
            else
            {
                SchedulePE(ddr_0, PEInputPkg, OutputMemPkg, MsgPkg, RegFilePkg, RegFileWidePkg_0, RegFileWidePkg_1, RegFileWidePkg_2, RegFileWidePkg_3, WeightMemPE_0, WeightMemPE_1, WeightMemPE_2, WeightMemPE_3, PotenMemPE_0, PotenMemPE_1, PotenMemPE_2, PotenMemPE_3);
            }

            next_pc++;

#ifdef TEST_LOG_PRINT
            printf("CLS-----------------------------PC=%d: exit RFT case-----------------------------\n", (int)*IdxInstr);
#endif
            break;

        case SGS:
#ifdef TEST_LOG_PRINT
            printf("CLS-----------------------------PC=%d: enter SGS case-----------------------------\n", (int)*IdxInstr);
#endif
/*
            if(MsgPkg->flagp == 0)
            {
                ReadRegFile(RegFilePkg, MsgPkg->regb, &TempReg_1);
                if((MsgPkg->flags==1)&&(TempReg_1[MsgPkg->immbh]==1))
                {TempReg_2 = ALL_HIGH_64B;}
                else
                {TempReg_2 = ALL_LOW_64B;}

                TempReg_2(MsgPkg->immbh-MsgPkg->immbl, 0) = TempReg_1(MsgPkg->immbh, MsgPkg->immbl);
                WriteRegFile(RegFilePkg, MsgPkg->rega, &TempReg_2);
            }
            else
            {
                SchedulePE(ddr_0, PEInputPkg, OutputMemPkg, MsgPkg, RegFilePkg, RegFileWidePkg_0, RegFileWidePkg_1, RegFileWidePkg_2, RegFileWidePkg_3, WeightMemPE_0, WeightMemPE_1, WeightMemPE_2, WeightMemPE_3, PotenMemPE_0, PotenMemPE_1, PotenMemPE_2, PotenMemPE_3);
            }
*/
            SchedulePE(ddr_0, PEInputPkg, OutputMemPkg, MsgPkg, RegFilePkg, RegFileWidePkg_0, RegFileWidePkg_1, RegFileWidePkg_2, RegFileWidePkg_3, WeightMemPE_0, WeightMemPE_1, WeightMemPE_2, WeightMemPE_3, PotenMemPE_0, PotenMemPE_1, PotenMemPE_2, PotenMemPE_3);

            next_pc++;

#ifdef TEST_LOG_PRINT
            printf("CLS-----------------------------PC=%d: exit SGS case-----------------------------\n", (int)*IdxInstr);
#endif
            break;
/*
        case CCT:
            #ifdef TEST_LOG_PRINT
                printf("CLS-----------------------------PC=%d: enter CCT case-----------------------------\n", (int)*IdxInstr);
            #endif

            if(MsgPkg->flagp == 0)
            {
                ReadRegFile(RegFilePkg, MsgPkg->regb, &TempReg_1);
                ReadRegFile(RegFilePkg, MsgPkg->regc, &TempReg_2);
                TempReg_3 = ALL_LOW_64B;
                TempReg_3((MsgPkg->immch-MsgPkg->immcl), 0) = TempReg_2(MsgPkg->immch, MsgPkg->immcl);
                TempReg_3((MsgPkg->immbh-MsgPkg->immbl+MsgPkg->immch-MsgPkg->immcl+1), (MsgPkg->immch-MsgPkg->immcl+1)) = TempReg_1(MsgPkg->immbh, MsgPkg->immbl);
                WriteRegFile(RegFilePkg, MsgPkg->rega, &TempReg_3);
            }
            else
            {
                SchedulePE(ddr_0, PEInputPkg, OutputMemPkg, MsgPkg, RegFilePkg, RegFileWidePkg_0, RegFileWidePkg_1, RegFileWidePkg_2, RegFileWidePkg_3, WeightMemPE_0, WeightMemPE_1, WeightMemPE_2, WeightMemPE_3, PotenMemPE_0, PotenMemPE_1, PotenMemPE_2, PotenMemPE_3);
            }

            next_pc++;

            #ifdef TEST_LOG_PRINT
                printf("CLS-----------------------------PC=%d: exit CCT case-----------------------------\n", (int)*IdxInstr);
            #endif
        	break;
*/
        case JE:
#ifdef TEST_LOG_PRINT
            printf("CLS-----------------------------PC=%d: enter JE case-----------------------------\n", (int)*IdxInstr);
#endif

            ReadRegFile(RegFilePkg, MsgPkg->rega, &TempReg_1);
            if(MsgPkg->flagi == 0)
            {	ReadRegFile(RegFilePkg, MsgPkg->regb, &TempReg_2); }
            else
            {
                if((MsgPkg->flags == 1)&&(MsgPkg->imma[15]==1))
                {TempReg_2 = ALL_HIGH_64B;}
                else
                {TempReg_2 = ALL_LOW_64B;}
                TempReg_2(15,0) = MsgPkg->imma;
            }

            if(MsgPkg->flagc == 0)
            {
                if(ALU(TempReg_1, TempReg_2, ALU_JE))
                { next_pc = MsgPkg->immb; }
                else
                { next_pc++; }
            }
            else
            {
                if(ALU(TempReg_1, TempReg_2, ALU_JN))
                { next_pc = MsgPkg->immb; }
                else
                { next_pc++; }
            }

#ifdef TEST_LOG_PRINT
            printf("CLS-----------------------------PC=%d: exit JE case-----------------------------\n", (int)*IdxInstr);
#endif
            break;

        case JG:
#ifdef TEST_LOG_PRINT
            printf("CLS-----------------------------PC=%d: enter JG case-----------------------------\n", (int)*IdxInstr);
#endif

            ReadRegFile(RegFilePkg, MsgPkg->rega, &TempReg_1);
            if(MsgPkg->flagi == 0)
            {	ReadRegFile(RegFilePkg, MsgPkg->regb, &TempReg_2); }
            else
            {
                if((MsgPkg->flags == 1)&&(MsgPkg->imma[15]==1))
                {TempReg_2 = ALL_HIGH_64B;}
                else
                {TempReg_2 = ALL_LOW_64B;}
                TempReg_2(15,0) = MsgPkg->imma;
            }

            if(MsgPkg->flagc == 0)
            {
                if(ALU(TempReg_1, TempReg_2, ALU_JG))
                { next_pc = MsgPkg->immb; }
                else
                { next_pc++; }
            }
            else
            {
                if(ALU(TempReg_1, TempReg_2, ALU_JNG))
                { next_pc = MsgPkg->immb; }
                else
                { next_pc++; }
            }

#ifdef TEST_LOG_PRINT
            printf("CLS-----------------------------PC=%d: exit JG case-----------------------------\n", (int)*IdxInstr);
#endif
            break;

        case JL:
#ifdef TEST_LOG_PRINT
            printf("CLS-----------------------------PC=%d: enter JL case-----------------------------\n", (int)*IdxInstr);
#endif

            ReadRegFile(RegFilePkg, MsgPkg->rega, &TempReg_1);
            if(MsgPkg->flagi == 0)
            {	ReadRegFile(RegFilePkg, MsgPkg->regb, &TempReg_2); }
            else
            {
                if((MsgPkg->flags == 1)&&(MsgPkg->imma[15]==1))
                {TempReg_2 = ALL_HIGH_64B;}
                else
                {TempReg_2 = ALL_LOW_64B;}
                TempReg_2(15,0) = MsgPkg->imma;
            }

            if(MsgPkg->flagc == 0)
            {
                if(ALU(TempReg_1, TempReg_2, ALU_JL))
                { next_pc = MsgPkg->immb; }
                else
                { next_pc++; }
            }
            else
            {
                if(ALU(TempReg_1, TempReg_2, ALU_JNL))
                { next_pc = MsgPkg->immb; }
                else
                { next_pc++; }
            }

#ifdef TEST_LOG_PRINT
            printf("CLS-----------------------------PC=%d: exit JL case-----------------------------\n", (int)*IdxInstr);
#endif
            break;

        case JMP:
#ifdef TEST_LOG_PRINT
            printf("CLS-----------------------------PC=%d: enter JMP case-----------------------------\n", (int)*IdxInstr);
#endif

            if(MsgPkg->flagi == 0)
            {
                ReadRegFile(RegFilePkg, MsgPkg->regc, &TempReg_1);
                next_pc = TempReg_1;
            }
            else
            {
                next_pc = MsgPkg->immb;
            }

#ifdef TEST_LOG_PRINT
            printf("CLS-----------------------------PC=%d: exit JMP case-----------------------------\n", (int)*IdxInstr);
#endif
            break;

        case RDI:
#ifdef TEST_LOG_PRINT
            printf("CLS-----------------------------PC=%d: enter RDI case-----------------------------\n", (int)*IdxInstr);
#endif

            ReadRegFile(RegFilePkg, MsgPkg->regb, &TempReg_1);
            ReadSpikeMem(SpikeMemPkg, ClstInputPkg->ClstID, TempReg_1(WIDTH_SPIKE_MEM_IDX-1,0), &TempReg_1_32b);
            TempReg_2 = 0;
            TempReg_2(31,0) = TempReg_1_32b(31,0);
            WriteRegFile(RegFilePkg, MsgPkg->rega, &TempReg_2);

            next_pc++;

#ifdef TEST_LOG_PRINT
            printf("CLS-----------------------------PC=%d: exit RDI case-----------------------------\n", (int)*IdxInstr);
#endif
            break;


        case LDW:
#ifdef TEST_LOG_PRINT
            printf("CLS-----------------------------PC=%d: enter LDW case-----------------------------\n", (int)*IdxInstr);
#endif

            SchedulePE(ddr_0, PEInputPkg, OutputMemPkg, MsgPkg, RegFilePkg, RegFileWidePkg_0, RegFileWidePkg_1, RegFileWidePkg_2, RegFileWidePkg_3, WeightMemPE_0, WeightMemPE_1, WeightMemPE_2, WeightMemPE_3, PotenMemPE_0, PotenMemPE_1, PotenMemPE_2, PotenMemPE_3);

            next_pc++;

#ifdef TEST_LOG_PRINT
            printf("CLS-----------------------------PC=%d: exit LDW case-----------------------------\n", (int)*IdxInstr);
#endif
            break;

        case WDW:
#ifdef TEST_LOG_PRINT
            printf("CLS-----------------------------PC=%d: enter WDW case-----------------------------\n", (int)*IdxInstr);
#endif

            SchedulePE(ddr_0, PEInputPkg, OutputMemPkg, MsgPkg, RegFilePkg, RegFileWidePkg_0, RegFileWidePkg_1, RegFileWidePkg_2, RegFileWidePkg_3, WeightMemPE_0, WeightMemPE_1, WeightMemPE_2, WeightMemPE_3, PotenMemPE_0, PotenMemPE_1, PotenMemPE_2, PotenMemPE_3);

            next_pc++;

#ifdef TEST_LOG_PRINT
            printf("CLS-----------------------------PC=%d: exit WDW case-----------------------------\n", (int)*IdxInstr);
#endif
            break;

        case RWM:
#ifdef TEST_LOG_PRINT
            printf("CLS-----------------------------PC=%d: enter RWM case-----------------------------\n", (int)*IdxInstr);
#endif

            SchedulePE(ddr_0, PEInputPkg, OutputMemPkg, MsgPkg, RegFilePkg, RegFileWidePkg_0, RegFileWidePkg_1, RegFileWidePkg_2, RegFileWidePkg_3, WeightMemPE_0, WeightMemPE_1, WeightMemPE_2, WeightMemPE_3, PotenMemPE_0, PotenMemPE_1, PotenMemPE_2, PotenMemPE_3);

            next_pc++;

#ifdef TEST_LOG_PRINT
            printf("CLS-----------------------------PC=%d: exit RWM case-----------------------------\n", (int)*IdxInstr);
#endif
            break;

        case RPM:
#ifdef TEST_LOG_PRINT
            printf("CLS-----------------------------PC=%d: enter RPM case-----------------------------\n", (int)*IdxInstr);
#endif

            SchedulePE(ddr_0, PEInputPkg, OutputMemPkg, MsgPkg, RegFilePkg, RegFileWidePkg_0, RegFileWidePkg_1, RegFileWidePkg_2, RegFileWidePkg_3, WeightMemPE_0, WeightMemPE_1, WeightMemPE_2, WeightMemPE_3, PotenMemPE_0, PotenMemPE_1, PotenMemPE_2, PotenMemPE_3);

            next_pc++;

#ifdef TEST_LOG_PRINT
            printf("CLS-----------------------------PC=%d: exit RPM case-----------------------------\n", (int)*IdxInstr);
#endif
            break;

        case WBW:
#ifdef TEST_LOG_PRINT
            printf("CLS-----------------------------PC=%d: enter WBW case-----------------------------\n", (int)*IdxInstr);
#endif

            SchedulePE(ddr_0, PEInputPkg, OutputMemPkg, MsgPkg, RegFilePkg, RegFileWidePkg_0, RegFileWidePkg_1, RegFileWidePkg_2, RegFileWidePkg_3, WeightMemPE_0, WeightMemPE_1, WeightMemPE_2, WeightMemPE_3, PotenMemPE_0, PotenMemPE_1, PotenMemPE_2, PotenMemPE_3);

            next_pc++;

#ifdef TEST_LOG_PRINT
            printf("CLS-----------------------------PC=%d: exit WBW case-----------------------------\n", (int)*IdxInstr);
#endif
            break;

        case WBP:
#ifdef TEST_LOG_PRINT
            printf("CLS-----------------------------PC=%d: enter WBP case-----------------------------\n", (int)*IdxInstr);
#endif

            SchedulePE(ddr_0, PEInputPkg, OutputMemPkg, MsgPkg, RegFilePkg, RegFileWidePkg_0, RegFileWidePkg_1, RegFileWidePkg_2, RegFileWidePkg_3, WeightMemPE_0, WeightMemPE_1, WeightMemPE_2, WeightMemPE_3, PotenMemPE_0, PotenMemPE_1, PotenMemPE_2, PotenMemPE_3);

            next_pc++;

#ifdef TEST_LOG_PRINT
            printf("CLS-----------------------------PC=%d: exit WBP case-----------------------------\n", (int)*IdxInstr);
#endif
            break;

        case OPT:
#ifdef TEST_LOG_PRINT
            printf("CLS-----------------------------PC=%d: enter OPT case-----------------------------\n", (int)*IdxInstr);
#endif

            SchedulePE(ddr_0, PEInputPkg, OutputMemPkg, MsgPkg, RegFilePkg, RegFileWidePkg_0, RegFileWidePkg_1, RegFileWidePkg_2, RegFileWidePkg_3, WeightMemPE_0, WeightMemPE_1, WeightMemPE_2, WeightMemPE_3, PotenMemPE_0, PotenMemPE_1, PotenMemPE_2, PotenMemPE_3);

            next_pc++;

#ifdef TEST_LOG_PRINT
            printf("CLS-----------------------------PC=%d: exit OPT case-----------------------------\n", (int)*IdxInstr);
#endif
            break;

        case SYN:
#ifdef TEST_LOG_PRINT
            printf("CLS-----------------------------PC=%d: enter SYN case-----------------------------\n", (int)*IdxInstr);
#endif

            *ClusterDone = 1;
            *ClusterSync = 1;

            next_pc++;

#ifdef TEST_LOG_PRINT
            printf("CLS-----------------------------PC=%d: exit SYN case-----------------------------\n", (int)*IdxInstr);
#endif
            break;

        case DONE:
#ifdef TEST_LOG_PRINT
            printf("CLS-----------------------------PC=%d: enter DONE case-----------------------------\n", (int)*IdxInstr);
#endif

            *ClusterDone = 1;

            next_pc++;

#ifdef TEST_LOG_PRINT
            printf("CLS-----------------------------PC=%d: exit DONE case-----------------------------\n", (int)*IdxInstr);
#endif
            break;

        default:
            break;

    } //end of switch

    return next_pc;
}