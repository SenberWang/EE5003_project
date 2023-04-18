#include "register_file.h"

void ReadRegFile(struct sRegFileWidePkg *RegFilePkg, _idx_reg_file idRegA, _reg_64b *retRegA)
{
	*retRegA = RegFilePkg->RegFile[idRegA];

    #ifdef TEST_LOG_PRINT
        printf("REG.CTRL--read 0x%x from Reg.%d. \n", (unsigned int)*retRegA, (int)idRegA);
    #endif
}

void WriteRegFile(struct sRegFileWidePkg *RegFilePkg, _idx_reg_file idRegA, _reg_64b *retRegA)
{
	RegFilePkg->RegFile[idRegA] = *retRegA;

    #ifdef TEST_LOG_PRINT
        printf("REG.CTRL--write 0x%x to Reg.%d. \n", (unsigned int)*retRegA, (int)idRegA);
    #endif
}

void ReadRegFileWide(ap_uint<64> *RegFilePkg, _idx_reg_file idRegA, _reg_64b *retRegA)
{
	*retRegA = RegFilePkg[idRegA];

    #ifdef TEST_LOG_PRINT
        int printout_high = (*retRegA)(63,32);
        int printout_low = (*retRegA)(31,0);
        printf("REG.PE--read 0x%lx_%lx from Reg.%d. \n", printout_high, printout_low, (int)idRegA);
    #endif
}

void WriteRegFileWide(ap_uint<64> *RegFilePkg, _idx_reg_file idRegA, _reg_64b *retRegA)
{
	RegFilePkg[idRegA] = *retRegA;

    #ifdef TEST_LOG_PRINT
        int printout_high = (*retRegA)(63,32);
        int printout_low = (*retRegA)(31,0);
        printf("REG.PE--write 0x%lx_%lx to Reg.%d. \n", printout_high, printout_low, (int)idRegA);
    #endif
}
