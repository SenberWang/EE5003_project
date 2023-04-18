//
// Created by YLW20 on 2022/5/13.
//

#ifndef CL_COMPILER_OPCODE_H
#define CL_COMPILER_OPCODE_H

#define NONE  000000
#define MOV   000001
#define MOVS  000001
#define AND   000010
#define OR    000011
#define XOR   000100
#define ADD   000101
#define ADDS  000101
#define SUB   000110
#define SUBS  000110
#define MUL   000111
#define MULS  000111
#define DVD   001000
#define DVDS  001000
#define MOD   001001
#define MODS  001001
#define LFT   001010
#define RFT   001011
#define ARFT  001011
#define SGS   001100
#define ASGS  001100
#define CCT   001101
#define BEQ   001110
#define BNQ   001111
#define JMP   010000
#define RDI   010001
#define RDS   010010
#define LDW   100000
#define WRW   100001
#define RCP   100010
#define PMOV  100011
#define PMOVS 100011
#define PAND  100100
#define POR   100101
#define PXOR  100110
#define PADD  100111
#define PADDS 100111
#define PSUB  101000
#define PSUBS 101000
#define PMUL  101001
#define PMULS 101001
#define PDVD  101010
#define PDVDS 101010
#define PMOD  101011
#define PMODS 101011
#define PLFT  101100
#define PRFT  101101
#define PARFT 101101
#define PSGS  101110
#define PASGS 101110
#define PCCT  101111
#define RWM   110000
#define RPM   110001
#define RWP   110010
#define WBW   110011
#define WBP   110100
#define OPT   110101
#define SYN   110110
#define DONE  110111

#endif //CL_COMPILER_OPCODE_H
