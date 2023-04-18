#include "decoder.h"

void InstrDecode(struct sMsgPkg *MsgPkg, _instr_mem Instr)
{
	MsgPkg->opcode = Instr(OPCODE_MSB, OPCODE_LSB);
	MsgPkg->flags = Instr(FLAG_S_MSB, FLAG_S_LSB);
    MsgPkg->flagp = Instr(FLAG_P_MSB, FLAG_P_LSB);
    MsgPkg->flagc = Instr(FLAG_C_MSB, FLAG_C_LSB);
    MsgPkg->flagi = Instr(FLAG_I_MSB, FLAG_I_LSB);
    MsgPkg->flagfh = Instr(FLAG_FH_MSB, FLAG_FH_LSB);
    MsgPkg->flagfl = Instr(FLAG_FL_MSB, FLAG_FL_LSB);

    if((MsgPkg->opcode == SGS)||(MsgPkg->opcode == CCT))
    {
        MsgPkg->rega = Instr(REG_A_SC_MSB, REG_A_SC_LSB);
        MsgPkg->regb = Instr(REG_B_SC_MSB, REG_B_SC_LSB);
        MsgPkg->regc = Instr(REG_C_SC_MSB, REG_C_SC_LSB);
        MsgPkg->immbl = Instr(IMM_BL_MSB, IMM_BL_LSB);
        MsgPkg->immbh = Instr(IMM_BH_MSB, IMM_BH_LSB);
        MsgPkg->immcl = Instr(IMM_CL_MSB, IMM_CL_LSB);
        MsgPkg->immch = Instr(IMM_CH_MSB, IMM_CH_LSB);
        MsgPkg->imma = Instr(IMM_A_MSB, IMM_A_LSB);
        MsgPkg->immb = Instr(IMM_B_MSB, IMM_B_LSB);
    }
    else
    {
        MsgPkg->rega = Instr(REG_A_MSB, REG_A_LSB);
        MsgPkg->regb = Instr(REG_B_MSB, REG_B_LSB);
        MsgPkg->regc = Instr(REG_C_MSB, REG_C_LSB);
        MsgPkg->regd = Instr(REG_D_MSB, REG_D_LSB);
        MsgPkg->imma = Instr(IMM_A_MSB, IMM_A_LSB);
        MsgPkg->immb = Instr(IMM_B_MSB, IMM_B_LSB);
    }


#ifdef TEST_LOG_PRINT
    printf("DEC--CurOpcode: %d. \n", (int)MsgPkg->opcode);
    printf("DEC--CurFlagS: %d. ", (int)MsgPkg->flags);
    printf("DEC--CurFlagP: %d. ", (int)MsgPkg->flagp);
    printf("DEC--CurFlagC: %d. \n", (int)MsgPkg->flagc);
    printf("DEC--CurFlagI: %d. ", (int)MsgPkg->flagi);
    printf("DEC--CurFlagFH: %d. ", (int)MsgPkg->flagfh);
    printf("DEC--CurFlagFL: %d. \n", (int)MsgPkg->flagfl);
    printf("DEC--CurRegA: %d. ", (int)MsgPkg->rega);
    printf("DEC--CurRegB: %d. ", (int)MsgPkg->regb);
    printf("DEC--CurRegC: %d. ", (int)MsgPkg->regc);
    printf("DEC--CurRegD: %d. \n", (int)MsgPkg->regd);
    printf("DEC--CurImmA: 0x%x. ", (unsigned int)MsgPkg->imma);
    printf("DEC--CurImmB: 0x%x. \n", (unsigned int)MsgPkg->immb);

    if(MsgPkg->opcode == CCT)
    {
        printf("DEC--CurImmBH: 0x%x. \n", (unsigned int)MsgPkg->immbh);
        printf("DEC--CurImmBL: 0x%x. \n", (unsigned int)MsgPkg->immbl);
        printf("DEC--CurImmCH: 0x%x. \n", (unsigned int)MsgPkg->immch);
        printf("DEC--CurImmCL: 0x%x. \n", (unsigned int)MsgPkg->immcl);
    }

    if(MsgPkg->opcode == SGS)
    {
        printf("DEC--CurImmBH: 0x%x. \n", (unsigned int)MsgPkg->immbh);
        printf("DEC--CurImmBL: 0x%x. \n", (unsigned int)MsgPkg->immbl);
    }
#endif
}
