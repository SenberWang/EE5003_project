//
// Created by YLW20 on 2022/6/1.
//

#include <vector>
#include <string>
#include <map>

#include "assembly.h"
#include "machine_code.h"
#include "operation_code.h"

//add operation
#define AOP(op_name, op_code, ...)                                                               \
        operation_code.insert(std::make_pair(#op_name, op_code));                                \
        assembly_format.insert(std::make_pair(#op_name, std::vector<std::string>{__VA_ARGS__}))
//add machine code format
#define AIF(op_name, ...)                                                                        \
        _instruction_format op_name##fmt{__VA_ARGS__};                                           \
        instruction_format.insert(std::make_pair(#op_name, op_name##fmt))


int init(){
    AOP(none, 0b00000, "");
    AIF(none, opcode<0>, zero, zero, zero, zero, zero, zero, zero, zero_5, zero_5, zero_5, zero_5, zero_16, zero_16);

    AOP(mov , 0b00001, "rr", "rpi", "ri", "pri", "ppi", "pii");
    AIF(mov , opcode<0>, zero, is_PE<1>, is_PE<2>, is_imm<2>, zero, zero, zero, reg<1>, preg<2>, zero_5, zero_5, pimm<2> , pPE_mask<3>);
    AOP(movs, 0b00001, "rr", "rpi", "ri", "pri", "ppi", "pii");
    AIF(movs, opcode<0>, one , is_PE<1>, is_PE<2>, is_imm<2>, zero, zero, zero, reg<1>, preg<2>, zero_5, zero_5, pimms<2>, pPE_mask<3>);

    AOP(and0, 0b00010, "rrr", "rri", "pppi", "ppii");
    AIF(and0, opcode<0>, zero, is_PE<1>, zero, is_imm<3>, zero, zero, zero, reg<1>, reg<2>, preg<3>, zero_5, pimm<3>, pPE_mask<4>);
    AOP(and1, 0b00010, "rrr", "rri", "pppi", "ppii");
    AIF(and1, opcode<0>, zero, is_PE<1>, zero, is_imm<3>, zero, one , zero, reg<1>, reg<2>, preg<3>, zero_5, pimm<3>, pPE_mask<4>);
    AOP(and2, 0b00010, "rrr", "rri", "pppi", "ppii");
    AIF(and2, opcode<0>, zero, is_PE<1>, zero, is_imm<3>, one , zero, zero, reg<1>, reg<2>, preg<3>, zero_5, pimm<3>, pPE_mask<4>);
    AOP(and3, 0b00010, "rrr", "rri", "pppi", "ppii");
    AIF(and3, opcode<0>, zero, is_PE<1>, zero, is_imm<3>, one , one , zero, reg<1>, reg<2>, preg<3>, zero_5, pimm<3>, pPE_mask<4>);

    AOP(or0, 0b00011, "rrr", "rri", "pppi", "ppii");
    AIF(or0, opcode<0>, zero, is_PE<1>, zero, is_imm<3>, zero, zero, zero, reg<1>, reg<2>, preg<3>, zero_5, pimm<3>, pPE_mask<4>);
    AOP(or1, 0b00011, "rrr", "rri", "pppi", "ppii");
    AIF(or1, opcode<0>, zero, is_PE<1>, zero, is_imm<3>, zero, one , zero, reg<1>, reg<2>, preg<3>, zero_5, pimm<3>, pPE_mask<4>);
    AOP(or2, 0b00011, "rrr", "rri", "pppi", "ppii");
    AIF(or2, opcode<0>, zero, is_PE<1>, zero, is_imm<3>, one , zero, zero, reg<1>, reg<2>, preg<3>, zero_5, pimm<3>, pPE_mask<4>);
    AOP(or3, 0b00011, "rrr", "rri", "pppi", "ppii");
    AIF(or3, opcode<0>, zero, is_PE<1>, zero, is_imm<3>, one , one , zero, reg<1>, reg<2>, preg<3>, zero_5, pimm<3>, pPE_mask<4>);

    AOP(xor0, 0b00100, "rrr", "rri", "pppi", "ppii");
    AIF(xor0, opcode<0>, zero, is_PE<1>, zero, is_imm<3>, zero, zero, zero, reg<1>, reg<2>, preg<3>, zero_5, pimm<3>, pPE_mask<4>);
    AOP(xor1, 0b00100, "rrr", "rri", "pppi", "ppii");
    AIF(xor1, opcode<0>, zero, is_PE<1>, zero, is_imm<3>, zero, one , zero, reg<1>, reg<2>, preg<3>, zero_5, pimm<3>, pPE_mask<4>);
    AOP(xor2, 0b00100, "rrr", "rri", "pppi", "ppii");
    AIF(xor2, opcode<0>, zero, is_PE<1>, zero, is_imm<3>, one , zero, zero, reg<1>, reg<2>, preg<3>, zero_5, pimm<3>, pPE_mask<4>);
    AOP(xor3, 0b00100, "rrr", "rri", "pppi", "ppii");
    AIF(xor3, opcode<0>, zero, is_PE<1>, zero, is_imm<3>, one , one , zero, reg<1>, reg<2>, preg<3>, zero_5, pimm<3>, pPE_mask<4>);

    AOP(lft, 0b00101, "rrr", "rri", "pppi", "ppii");
    AIF(lft, opcode<0>, zero, is_PE<1>, zero, is_imm<3>, zero, zero, zero, reg<1>, reg<2>, preg<3>, zero_5, pimm<3>, pPE_mask<4>);

    AOP(rft , 0b00110, "rrr", "rri", "pppi", "ppii");
    AIF(rft , opcode<0>, zero, is_PE<1>, zero, is_imm<3>, zero, zero, zero, reg<1>, reg<2>, preg<3>, zero_5, pimm<3>, pPE_mask<4>);
    AOP(arft, 0b00110, "rrr", "rri", "pppi", "ppii");
    AIF(arft, opcode<0>, one , is_PE<1>, zero, is_imm<3>, zero, zero, zero, reg<1>, reg<2>, preg<3>, zero_5, pimm<3>, pPE_mask<4>);

    AOP(sgs , 0b00111, "rrii", "ppiii");
    AIF(sgs , opcode<0>, zero, is_PE<1>, zero, zero, reg<1>, reg<2>, zero_5, imm_idx<3>, imm_idx<4>, zero_6, zero_6, pPE_mask<5>);
    AOP(asgs, 0b00111, "rrii", "ppiii");
    AIF(asgs, opcode<0>, one , is_PE<1>, zero, zero, reg<1>, reg<2>, zero_5, imm_idx<3>, imm_idx<4>, zero_6, zero_6, pPE_mask<5>);

    AOP(cct, 0b01000, "rrriiii", "pppiiiii");
    AIF(cct , opcode<0>, zero, is_PE<1>, zero, zero, reg<1>, reg<2>, reg<3>, imm_idx<4>, imm_idx<5>, imm_idx<6>, imm_idx<7>, pPE_mask<8>);

    AOP(add , 0b01001, "rrr", "rri", "pppi", "ppii");
    AIF(add , opcode<0>, zero, is_PE<1>, zero, is_imm<3>, zero, zero, zero, reg<1>, reg<2>, preg<3>, zero_5, pimm<3> , pPE_mask<4>);
    AOP(adds, 0b01001, "rrr", "rri", "pppi", "ppii");
    AIF(adds, opcode<0>, one , is_PE<1>, zero, is_imm<3>, zero, zero, zero, reg<1>, reg<2>, preg<3>, zero_5, pimms<3>, pPE_mask<4>);

    AOP(sub , 0b01010, "rrr", "rri", "pppi", "ppii");
    AIF(sub , opcode<0>, zero, is_PE<1>, zero, is_imm<3>, zero, zero, zero, reg<1>, reg<2>, preg<3>, zero_5, pimm<3> , pPE_mask<4>);
    AOP(subs, 0b01010, "rrr", "rri", "pppi", "ppii");
    AIF(subs, opcode<0>, one , is_PE<1>, zero, is_imm<3>, zero, zero, zero, reg<1>, reg<2>, preg<3>, zero_5, pimms<3>, pPE_mask<4>);

    AOP(mul , 0b01011, "rrr", "rri", "pppi", "ppii");
    AIF(mul , opcode<0>, zero, is_PE<1>, zero, is_imm<3>, zero, zero, zero, reg<1>, reg<2>, preg<3>, zero_5, pimm<3> , pPE_mask<4>);
    AOP(muls, 0b01011, "rrr", "rri", "pppi", "ppii");
    AIF(muls, opcode<0>, one , is_PE<1>, zero, is_imm<3>, zero, zero, zero, reg<1>, reg<2>, preg<3>, zero_5, pimms<3>, pPE_mask<4>);

    AOP(dvd , 0b01100, "rrr", "rri", "pppi", "ppii");
    AIF(dvd , opcode<0>, zero, is_PE<1>, zero, is_imm<3>, zero, zero, zero, reg<1>, reg<2>, preg<3>, zero_5, pimm<3> , pPE_mask<4>);
    AOP(dvds, 0b01100, "rrr", "rri", "pppi", "ppii");
    AIF(dvds, opcode<0>, one , is_PE<1>, zero, is_imm<3>, zero, zero, zero, reg<1>, reg<2>, preg<3>, zero_5, pimms<3>, pPE_mask<4>);

    AOP(mod , 0b01101, "rrr", "rri", "pppi", "ppii");
    AIF(mod , opcode<0>, zero, is_PE<1>, zero, is_imm<3>, zero, zero, zero, reg<1>, reg<2>, preg<3>, zero_5, pimm<3> , pPE_mask<4>);
    AOP(mods, 0b10101, "rrr", "rri", "pppi", "ppii");
    AIF(mods, opcode<0>, one , is_PE<1>, zero, is_imm<3>, zero, zero, zero, reg<1>, reg<2>, preg<3>, zero_5, pimms<3>, pPE_mask<4>);

    AOP(je , 0b01110, "rri", "rrs", "rii", "ris");
    AIF(je , opcode<0>, zero, zero, zero, is_imm<2>, zero, zero, zero, reg<1>, preg<2>, zero_5, zero_5, pimm<2> , jmp_dest<3>);
    AOP(jes, 0b01110, "rri", "rrs", "rii", "ris");
    AIF(jes, opcode<0>, one , zero, zero, is_imm<2>, zero, zero, zero, reg<1>, preg<2>, zero_5, zero_5, pimms<2>, jmp_dest<3>);

    AOP(jn , 0b01110, "rri", "rrs", "rii", "ris");
    AIF(jn , opcode<0>, zero, zero, one , is_imm<2>, zero, zero, zero, reg<1>, preg<2>, zero_5, zero_5, pimm<2> , jmp_dest<3>);
    AOP(jns, 0b01110, "rri", "rrs", "rii", "ris");
    AIF(jns, opcode<0>, one , zero, one , is_imm<2>, zero, zero, zero, reg<1>, preg<2>, zero_5, zero_5, pimms<2>, jmp_dest<3>);

    AOP(jg , 0b01111, "rri", "rrs", "rii", "ris");
    AIF(jg , opcode<0>, zero, zero, zero, is_imm<2>, zero, zero, zero, reg<1>, preg<2>, zero_5, zero_5, pimm<2> , jmp_dest<3>);
    AOP(jgs, 0b01111, "rri", "rrs", "rii", "ris");
    AIF(jgs, opcode<0>, one , zero, zero, is_imm<2>, zero, zero, zero, reg<1>, preg<2>, zero_5, zero_5, pimms<2>, jmp_dest<3>);

    AOP(jng , 0b01111, "rri", "rrs", "rii", "ris");
    AIF(jng , opcode<0>, zero, zero, one , is_imm<2>, zero, zero, zero, reg<1>, preg<2>, zero_5, zero_5, pimm<2> , jmp_dest<3>);
    AOP(jngs, 0b01111, "rri", "rrs", "rii", "ris");
    AIF(jngs, opcode<0>, one , zero, one , is_imm<2>, zero, zero, zero, reg<1>, preg<2>, zero_5, zero_5, pimms<2>, jmp_dest<3>);

    AOP(jl , 0b10000, "rri", "rrs", "rii", "ris");
    AIF(jl , opcode<0>, zero, zero, zero, is_imm<2>, zero, zero, zero, reg<1>, preg<2>, zero_5, zero_5, pimm<2> , jmp_dest<3>);
    AOP(jls, 0b10000, "rri", "rrs", "rii", "ris");
    AIF(jls, opcode<0>, one , zero, zero, is_imm<2>, zero, zero, zero, reg<1>, preg<2>, zero_5, zero_5, pimms<2>, jmp_dest<3>);

    AOP(jnl , 0b10000, "rri", "rrs", "rii", "ris");
    AIF(jnl , opcode<0>, zero, zero, one , is_imm<2>, zero, zero, zero, reg<1>, preg<2>, zero_5, zero_5, pimm<2> , jmp_dest<3>);
    AOP(jnls, 0b10000, "rri", "rrs", "rii", "ris");
    AIF(jnls, opcode<0>, one , zero, one , is_imm<2>, zero, zero, zero, reg<1>, preg<2>, zero_5, zero_5, pimms<2>, jmp_dest<3>);

    AOP(jmp, 0b10001, "r", "i", "s");
    AIF(jmp, opcode<0>, zero, zero, zero, is_imm<1>, zero, zero, zero, preg<1>, zero_5, zero_5, zero_5, zero_16, jmp_dest<1>);

    AOP(rdi, 0b10010, "rr");
    AIF(rdi, opcode<0>, zero, zero, zero, zero, zero, zero, zero, reg<1>, reg<2>, zero_5, zero_5, zero_16, zero_16);

    AOP(ldw, 0b10011, "pppi", "ppii");
    AIF(ldw, opcode<0>, zero, zero, zero, is_imm<3>, zero, zero, zero, reg<1>, reg<2>, preg<3>, zero_5, pimm<3>, PE_mask<4>);

    AOP(wdw, 0b10100, "pppi", "ppii");
    AIF(wdw, opcode<0>, zero, zero, zero, is_imm<3>, zero, zero, zero, reg<1>, reg<2>, preg<3>, zero_5, pimm<3>, PE_mask<4>);

    AOP(rwm, 0b10101, "ppi");
    AIF(rwm, opcode<0>, zero, zero, zero, zero, zero, zero, zero, reg<1>, reg<2>, zero_5, zero_5, zero_16, PE_mask<3>);

    AOP(rpm, 0b10110, "ppi");
    AIF(rpm, opcode<0>, zero, zero, zero, zero, zero, zero, zero, reg<1>, reg<2>, zero_5, zero_5, zero_16, PE_mask<3>);

    AOP(wbw, 0b10111, "ppi");
    AIF(wbw, opcode<0>, zero, zero, zero, zero, zero, zero, zero, reg<1>, reg<2>, zero_5, zero_5, zero_16, PE_mask<3>);

    AOP(wbp, 0b11000, "ppi");
    AIF(wbp, opcode<0>, zero, zero, zero, zero, zero, zero, zero, reg<1>, reg<2>, zero_5, zero_5, zero_16, PE_mask<3>);

    AOP(opt, 0b11001, "pppii");
    AIF(opt, opcode<0>, zero, zero, zero, zero, zero, zero, zero, reg<1>, reg<2>, reg<3>, zero_5, cluster_mask<4>, PE_mask<5>);

    AOP(rom, 0b11010, "ppi");
    AIF(rom, opcode<0>, zero, zero, zero, zero, zero, zero, zero, reg<1>, reg<2>, zero_5, zero_5, zero_16, PE_mask<3>);

    AOP(syn , 0b11110, "");
    AIF(syn , opcode<0>, zero_59);
    AOP(done, 0b11111, "");
    AIF(done, opcode<0>, one_59);



    return 0;
}
