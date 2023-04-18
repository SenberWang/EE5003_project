#ifndef _REG_FILE_HEADER_
#define _REG_FILE_HEADER_

#include "global_vars.h"

void ReadRegFile(struct sRegFileWidePkg *RegFilePkg, _idx_reg_file idRegA, _reg_64b *retRegA);
void WriteRegFile(struct sRegFileWidePkg *RegFilePkg, _idx_reg_file idRegA, _reg_64b *retRegA);
void ReadRegFileWide(ap_uint<64> *RegFilePkg, _idx_reg_file idRegA, _reg_64b *retRegA);
void WriteRegFileWide(ap_uint<64> *RegFilePkg, _idx_reg_file idRegA, _reg_64b *retRegA);

#endif
