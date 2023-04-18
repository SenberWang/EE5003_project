#include "PE.h"

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
)
{
    struct sMsgPkg MsgPkg = *InputMsgPkg;

    _mask_pe MaskPE;
    MaskPE = MsgPkg.immb;

    if(MaskPE[0]==1)
    {
        PE<0>(ddr_0, PEInputPkg+0, OutputMemPkg, InputMsgPkg, RegFilePkg, RegFileWidePkg_0, WeightMemPE_0, PotenMemPE_0);
    }

    if(MaskPE[1]==1)
    {
        PE<1>(ddr_0, PEInputPkg+1, OutputMemPkg, InputMsgPkg, RegFilePkg, RegFileWidePkg_1, WeightMemPE_1, PotenMemPE_1);
    }

    if(MaskPE[2]==1)
    {
        PE<2>(ddr_0, PEInputPkg+2, OutputMemPkg, InputMsgPkg, RegFilePkg, RegFileWidePkg_2, WeightMemPE_2, PotenMemPE_2);
    }

    if(MaskPE[3]==1)
    {
        PE<3>(ddr_0, PEInputPkg+3, OutputMemPkg, InputMsgPkg, RegFilePkg, RegFileWidePkg_3, WeightMemPE_3, PotenMemPE_3);
    }
}
