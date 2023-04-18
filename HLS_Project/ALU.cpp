#include "ALU.h"

_reg_64b ALU(_reg_64b arg_1, _reg_64b arg_2, ap_uint<4> flag)
{
    _reg_64b retALU;
    switch (flag)
    {
        case ALU_AND:	retALU = arg_1 & arg_2;		break;
        //case ALU_OR:	retALU = arg_1 | arg_2;		break;
        //case ALU_XOR:	retALU = arg_1 ^ arg_2;		break;
        case ALU_ADD:	retALU = arg_1 + arg_2;		break;
        //case ALU_SUB:	retALU = arg_1 - arg_2;		break;
        //case ALU_MUL:	retALU = arg_1 * arg_2;		break;
        //case ALU_DVD:	retALU = arg_1 / arg_2;		break;
        //case ALU_MOD:	retALU = arg_1 % arg_2;		break;
        case ALU_LFT:	retALU = arg_1 << arg_2;	break;
        case ALU_RFT:	retALU = arg_1 >> arg_2;	break;
        case ALU_JE:	retALU = (arg_1 == arg_2);	break;
        case ALU_JN:	retALU = (arg_1 != arg_2);	break;
        case ALU_JG:	retALU = (arg_1 >  arg_2);	break;
        case ALU_JNG:	retALU = (arg_1 <= arg_2);	break;
        case ALU_JL:	retALU = (arg_1 < arg_2);	break;
        case ALU_JNL:	retALU = (arg_1 >= arg_2);	break;
    }

    #ifdef TEST_LOG_PRINT
    printf("ALU.CTRL.U--Param1: 0x%x; Param2: 0x%x; Result: 0x%x. \n", (unsigned int)arg_1, (unsigned int)arg_2, (unsigned int)retALU);
    #endif

    return retALU;
}


_reg_64b ALUPE(_reg_64b arg_1, _reg_64b arg_2, ap_uint<4> flag)
{
	_reg_64b retALU;
    switch (flag)
    {
    case ALU_AND:	retALU = arg_1 & arg_2;		break;
    //case ALU_OR:	retALU = arg_1 | arg_2;		break;
    //case ALU_XOR:	retALU = arg_1 ^ arg_2;		break;
    case ALU_ADD:	retALU = arg_1 + arg_2;		break;
    case ALU_SUB:	retALU = arg_1 - arg_2;		break;
    case ALU_MUL:	retALU = arg_1 * arg_2;		break;
    //case ALU_DVD:	retALU = arg_1 / arg_2;		break;
    //case ALU_MOD:	retALU = arg_1 % arg_2;		break;
    case ALU_LFT:	retALU = arg_1 << arg_2;	break;
    case ALU_RFT:	retALU = arg_1 >> arg_2;	break;
    /*
    case ALU_JE:	retALU = (arg_1 == arg_2);	break;
    case ALU_JN:	retALU = (arg_1 != arg_2);	break;
    case ALU_JG:	retALU = (arg_1 >  arg_2);	break;
    case ALU_JNG:	retALU = (arg_1 <= arg_2);	break;
    case ALU_JL:	retALU = (arg_1 < arg_2);	break;
    case ALU_JNL:	retALU = (arg_1 >= arg_2);	break;
    */
    }

    #ifdef TEST_LOG_PRINT
        printf("ALU.PE.U--Param1: 0x%x; Param2: 0x%x; Result: 0x%x. \n", (unsigned int)arg_1, (unsigned int)arg_2, (unsigned int)retALU);
    #endif

    return retALU;
}


_reg_64b_s ALUS(_reg_64b_s arg_1, _reg_64b_s arg_2, ap_uint<4> flag)
{
	_reg_64b_s retALU;
    switch (flag)
    {
    case ALU_ADD:	retALU = arg_1 + arg_2;		break;
    //case ALU_SUB:	retALU = arg_1 - arg_2;		break;
    //case ALU_MUL:	retALU = arg_1 * arg_2;		break;
    //case ALU_DVD:	retALU = arg_1 / arg_2;		break;
    //case ALU_MOD:	retALU = arg_1 % arg_2;		break;
    }

    #ifdef TEST_LOG_PRINT
        printf("ALU.CTRL.S--Param1: %d; Param2: %d; Result: %d. \n", (int)arg_1, (int)arg_2, (int)retALU);
    #endif

    return retALU;
}


_reg_64b_s ALUPES(_reg_64b_s arg_1, _reg_64b_s arg_2, ap_uint<4> flag)
{
	_reg_64b_s retALU;
    switch (flag)
    {
    case ALU_JNL:   retALU = (arg_1 >= arg_2);	break;
    case ALU_ADD:	retALU = arg_1 + arg_2;		break;
    case ALU_SUB:	retALU = arg_1 - arg_2;		break;
    case ALU_MUL:	retALU = arg_1 * arg_2;		break;
    //case ALU_DVD:	retALU = arg_1 / arg_2;		break;
    //case ALU_MOD:	retALU = arg_1 % arg_2;		break;
    }

    #ifdef TEST_LOG_PRINT
        printf("ALU.PE.S--Param1: %d; Param2: %d; Result: %d. \n", (int)arg_1, (int)arg_2, (int)retALU);
    #endif

    return retALU;
}

