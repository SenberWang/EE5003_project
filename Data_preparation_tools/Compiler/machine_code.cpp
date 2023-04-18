//
// Created by YLW20 on 2022/5/19.
//

#include <map>
#include <string>
#include "machine_code.h"

#define AIF(op, ...) \
        _instruction_format op##fmt{__VA_ARGS__}; \
        instruction_format.insert(std::make_pair(#op, op##fmt))

void instruction_format_init() {
    AIF(none, opcode<0>, zero, zero, zero, zero_5, zero_5, zero_5, zero_5, zero_19, zero_16);

    AIF(mov , opcode<0>, zero, zero, imm_flag<2>, reg<1>, preg<2>, zero_5, zero_5, zero_19, immB<2> );
    AIF(movs, opcode<0>,  one, zero, imm_flag<2>, reg<1>, reg<2>,  zero_5, zero_5, zero_19, immBs<2>);
    //
    AIF(and, opcode<0>, zero, zero, imm_flag<3>, reg<1>, reg<2>, preg<3>, zero_5, zero_3, pimmL<3>);
    AIF(or , opcode<0>, zero, zero, imm_flag<3>, reg<1>, reg<2>, preg<3>, zero_5, zero_3, pimmL<3>);
    AIF(xor, opcode<0>, zero, zero, imm_flag<3>, reg<1>, reg<2>, preg<3>, zero_5, zero_3, pimmL<3>);

    AIF(add , opcode<0>, zero, zero, imm_flag<3>, reg<1>, reg<2>, preg<3>, zero_5, zero_19, pimmB<3> );
    AIF(adds, opcode<0>, one , zero, imm_flag<3>, reg<1>, reg<2>, preg<3>, zero_5, zero_19, pimmBs<3>);
    AIF(sub , opcode<0>, zero, zero, imm_flag<3>, reg<1>, reg<2>, preg<3>, zero_5, zero_19, pimmB<3> );
    AIF(subs, opcode<0>, one , zero, imm_flag<3>, reg<1>, reg<2>, preg<3>, zero_5, zero_19, pimmBs<3>);
    AIF(mul , opcode<0>, zero, zero, imm_flag<3>, reg<1>, reg<2>, preg<3>, zero_5, zero_19, pimmB<3> );
    AIF(muls, opcode<0>, one , zero, imm_flag<3>, reg<1>, reg<2>, preg<3>, zero_5, zero_19, pimmBs<3>);
    AIF(dvd , opcode<0>, zero, zero, imm_flag<3>, reg<1>, reg<2>, preg<3>, zero_5, zero_19, pimmB<3> );
    AIF(dvds, opcode<0>, one , zero, imm_flag<3>, reg<1>, reg<2>, preg<3>, zero_5, zero_19, pimmBs<3>);
    AIF(mod , opcode<0>, zero, zero, imm_flag<3>, reg<1>, reg<2>, preg<3>, zero_5, zero_19, pimmB<3> );
    AIF(mods, opcode<0>, one , zero, imm_flag<3>, reg<1>, reg<2>, preg<3>, zero_5, zero_19, pimmBs<3>);

    AIF(lft , opcode<0>, zero, zero, imm_flag<3>, reg<1>, reg<2>, preg<3>, zero_5, zero_19, pimmB<3>);
    AIF(rft , opcode<0>, zero, zero, imm_flag<3>, reg<1>, reg<2>, preg<3>, zero_5, zero_19, pimmB<3>);
    AIF(arft, opcode<0>, one , zero, imm_flag<3>, reg<1>, reg<2>, preg<3>, zero_5, zero_19, pimmB<3>);

    AIF(sgs , opcode<0>, zero, zero, zero, reg<1>, reg<2>, zero_5, imm_idx<3>, imm_idx<4>, zero_6, zero_6, zero_16);
    AIF(asgs, opcode<0>, one , zero, zero, reg<1>, reg<2>, zero_5, imm_idx<3>, imm_idx<4>, zero_6, zero_6, zero_16);
    AIF(cct , opcode<0>, zero, zero, zero, reg<1>, reg<2>, reg<3>, imm_idx<4>, imm_idx<5>, imm_idx<6>, imm_idx<7>, zero_16);

    AIF(je  , opcode<0>, zero, zero, imm_flag<2>, reg<1>, preg<2>, zero_5, zero_5, pimmA<2> , jmp_dest<3>);
    AIF(jes , opcode<0>, one , zero, imm_flag<2>, reg<1>, preg<2>, zero_5, zero_5, pimmAs<2>, jmp_dest<3>);
    AIF(jn  , opcode<0>, zero, zero, imm_flag<2>, reg<1>, preg<2>, zero_5, zero_5, pimmA<2> , jmp_dest<3>);
    AIF(jns , opcode<0>, one , zero, imm_flag<2>, reg<1>, preg<2>, zero_5, zero_5, pimmAs<2>, jmp_dest<3>);
    AIF(jg  , opcode<0>, zero, zero, imm_flag<2>, reg<1>, preg<2>, zero_5, zero_5, pimmA<2> , jmp_dest<3>);
    AIF(jgs , opcode<0>, one , zero, imm_flag<2>, reg<1>, preg<2>, zero_5, zero_5, pimmAs<2>, jmp_dest<3>);
    AIF(jng , opcode<0>, zero, zero, imm_flag<2>, reg<1>, preg<2>, zero_5, zero_5, pimmA<2> , jmp_dest<3>);
    AIF(jngs, opcode<0>, one , zero, imm_flag<2>, reg<1>, preg<2>, zero_5, zero_5, pimmAs<2>, jmp_dest<3>);
    AIF(jl  , opcode<0>, zero, zero, imm_flag<2>, reg<1>, preg<2>, zero_5, zero_5, pimmA<2> , jmp_dest<3>);
    AIF(jls , opcode<0>, one , zero, imm_flag<2>, reg<1>, preg<2>, zero_5, zero_5, pimmAs<2>, jmp_dest<3>);
    AIF(jnl , opcode<0>, zero, zero, imm_flag<2>, reg<1>, preg<2>, zero_5, zero_5, pimmA<2> , jmp_dest<3>);
    AIF(jnls, opcode<0>, one , zero, imm_flag<2>, reg<1>, preg<2>, zero_5, zero_5, pimmAs<2>, jmp_dest<3>);
    AIF(jmp , opcode<0>, zero, zero, zero, zero_5, zero_5, preg<1>, zero_5, zero_19, pimmB<1>);

    AIF(rdi, opcode<0>, zero, zero, zero, reg<1>, reg<2>, zero_5, zero_5, zero_19, zero_16);
    AIF(rds, opcode<0>, zero, zero, zero, reg<1>, reg<2>, zero_5, zero_5, zero_19, zero_16);

    AIF(ldw, opcode<0>, zero, zero, zero, reg<1>, reg<2>, reg<3>, zero_5, zero_19, PE_mask<4>);
    AIF(wdw, opcode<0>, zero, zero, zero, reg<1>, reg<2>, reg<3>, zero_5, zero_19, PE_mask<4>);

    AIF(rcp, opcode<0>, zero, drx_flag<1>, zero, reg<1>, reg<2>, zero_5, zero_5, zero_19, PE_mask<4>);

    AIF(pmov , opcode<0>, zero, zero, imm_flag<2>, reg<1>, preg<2>, zero_5, zero_5, pimmA<2> , PE_mask<3>);
    AIF(pmovs, opcode<0>, one , zero, imm_flag<2>, reg<1>, preg<2>, zero_5, zero_5, pimmAs<2>, PE_mask<3>);
    
    AIF(pand0, opcode<0>, zero, zero, imm_flag<3>, reg<1>, reg<2>, preg<3>, zero_5, pimmA<3>, PE_mask<4>);
    AIF(pand1, opcode<0>, zero, one , imm_flag<3>, reg<1>, reg<2>, preg<3>, zero_5, pimmA<3>, PE_mask<4>);
    AIF(pand2, opcode<0>, one , zero, imm_flag<3>, reg<1>, reg<2>, preg<3>, zero_5, pimmA<3>, PE_mask<4>);
    AIF(pand3, opcode<0>, one , one , imm_flag<3>, reg<1>, reg<2>, preg<3>, zero_5, pimmA<3>, PE_mask<4>);
    AIF(por0 , opcode<0>, zero, zero, imm_flag<3>, reg<1>, reg<2>, preg<3>, zero_5, pimmA<3>, PE_mask<4>);
    AIF(por1 , opcode<0>, zero, one , imm_flag<3>, reg<1>, reg<2>, preg<3>, zero_5, pimmA<3>, PE_mask<4>);
    AIF(por2 , opcode<0>, one , zero, imm_flag<3>, reg<1>, reg<2>, preg<3>, zero_5, pimmA<3>, PE_mask<4>);
    AIF(por3 , opcode<0>, one , one , imm_flag<3>, reg<1>, reg<2>, preg<3>, zero_5, pimmA<3>, PE_mask<4>);
    AIF(pxor0, opcode<0>, zero, zero, imm_flag<3>, reg<1>, reg<2>, preg<3>, zero_5, pimmA<3>, PE_mask<4>);
    AIF(pxor1, opcode<0>, zero, one , imm_flag<3>, reg<1>, reg<2>, preg<3>, zero_5, pimmA<3>, PE_mask<4>);
    AIF(pxor2, opcode<0>, one , zero, imm_flag<3>, reg<1>, reg<2>, preg<3>, zero_5, pimmA<3>, PE_mask<4>);
    AIF(pxor3, opcode<0>, one , one , imm_flag<3>, reg<1>, reg<2>, preg<3>, zero_5, pimmA<3>, PE_mask<4>);

    AIF(padd , opcode<0>, zero, zero, imm_flag<3>, reg<1>, reg<2>, preg<3>, zero_5, pimmA<3> , PE_mask<4>);
    AIF(padds, opcode<0>, one , zero, imm_flag<3>, reg<1>, reg<2>, preg<3>, zero_5, pimmAs<3>, PE_mask<4>);
    AIF(psub , opcode<0>, zero, zero, imm_flag<3>, reg<1>, reg<2>, preg<3>, zero_5, pimmA<3> , PE_mask<4>);
    AIF(psubs, opcode<0>, one , zero, imm_flag<3>, reg<1>, reg<2>, preg<3>, zero_5, pimmAs<3>, PE_mask<4>);
    AIF(pmul , opcode<0>, zero, zero, imm_flag<3>, reg<1>, reg<2>, preg<3>, zero_5, pimmA<3> , PE_mask<4>);
    AIF(pmuls, opcode<0>, one , zero, imm_flag<3>, reg<1>, reg<2>, preg<3>, zero_5, pimmAs<3>, PE_mask<4>);
    AIF(pdvd , opcode<0>, zero, zero, imm_flag<3>, reg<1>, reg<2>, preg<3>, zero_5, pimmA<3> , PE_mask<4>);
    AIF(pdvds, opcode<0>, one , zero, imm_flag<3>, reg<1>, reg<2>, preg<3>, zero_5, pimmAs<3>, PE_mask<4>);
    AIF(pmod , opcode<0>, zero, zero, imm_flag<3>, reg<1>, reg<2>, preg<3>, zero_5, pimmA<3> , PE_mask<4>);
    AIF(pmods, opcode<0>, one , zero, imm_flag<3>, reg<1>, reg<2>, preg<3>, zero_5, pimmAs<3>, PE_mask<4>);

    AIF(plft , opcode<0>, zero, zero, imm_flag<3>, reg<1>, reg<2>, preg<3>, zero_5, pimmA<3>, PE_mask<4>);
    AIF(prft , opcode<0>, zero, zero, imm_flag<3>, reg<1>, reg<2>, preg<3>, zero_5, pimmA<3>, PE_mask<4>);
    AIF(parft, opcode<0>, one , zero, imm_flag<3>, reg<1>, reg<2>, preg<3>, zero_5, pimmA<3>, PE_mask<4>);

    AIF(psgs , opcode<0>, zero, zero, zero, reg<1>, reg<2>, zero_5, imm_idx<3>, imm_idx<4>, zero_6, zero_6, PE_mask<5>);
    AIF(pasgs, opcode<0>, one , zero, zero, reg<1>, reg<2>, zero_5, imm_idx<3>, imm_idx<4>, zero_6, zero_6, PE_mask<5>);
    AIF(pcct , opcode<0>, zero, zero, zero, reg<1>, reg<2>, reg<3>, imm_idx<4>, imm_idx<5>, imm_idx<6>, imm_idx<7>, PE_mask<8>);

    AIF(rwm, opcode<0>, zero, zero, zero, reg<1>, reg<2>, zero_5, zero_5, zero_19, PE_mask<3>);
    AIF(rpm, opcode<0>, zero, zero, zero, reg<1>, reg<2>, zero_5, zero_5, zero_19, PE_mask<3>);
    AIF(rwp, opcode<0>, zero, zero, zero, reg<1>, reg<2>, reg<3>, reg<4>, zero_19, PE_mask<5>);
    AIF(wbw, opcode<0>, zero, zero, zero, reg<1>, reg<2>, zero_5, zero_5, zero_19, PE_mask<3>);
    AIF(wbp, opcode<0>, zero, zero, zero, reg<1>, reg<2>, zero_5, zero_5, zero_19, PE_mask<3>);

    AIF(opt, opcode<0>, zero, zero, zero, reg<1>, reg<2>, reg<3>, zero_5, cluster_mask<4>, PE_mask<5>);

    AIF(syn , opcode<0>, zero, zero, zero, zero_5, zero_5, zero_5, zero_5, zero_19, zero_16);
    AIF(done, opcode<0>, zero, zero, zero, zero_5, zero_5, zero_5, zero_5, zero_19, zero_16);
}

