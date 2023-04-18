//
// Created by YLW20 on 2022/5/22.
//

#ifndef CL_COMPILER_OPERATION_CODE_H
#define CL_COMPILER_OPERATION_CODE_H

#include <vector>
#include <string>
#include <map>

extern std::map<std::string, unsigned> operation_code;

//add operation code
//#define AOP(op, op_code) operation_code.insert(std::make_pair(op, op_code))
//add instruction format
//_instruction_format mov_fmt{
//opcode, flagS, _1_bit_0, flagI, regA, regB, _5_bits_0, _5_bits_0, _19_bits_0, immB_token2
//};
//instruction_format.insert(std::make_pair("mov", mov_fmt));


void operation_code_init();

#define NONE  0b000000
#define MOV   0b000001
#define MOVS  0b000001
#define AND   0b000010
#define OR    0b000011
#define XOR   0b000100
#define ADD   0b000101
#define ADDS  0b000101
#define SUB   0b000110
#define SUBS  0b000110
#define MUL   0b000111
#define MULS  0b000111
#define DVD   0b001000
#define DVDS  0b001000
#define MOD   0b001001
#define MODS  0b001001
#define LFT   0b001010
#define RFT   0b001011
#define ARFT  0b001011
#define SGS   0b001100
#define ASGS  0b001100
#define CCT   0b001101
#define JE    0b001110
#define JES   0b001110
#define JN    0b001111
#define JNS   0b001111
#define JG    0b010000
#define JGS   0b010000
#define JNG   0b010001
#define JNGS  0b010001
#define JL    0b010010
#define JLS   0b010010
#define JNL   0b010011
#define JNLS  0b010011
#define JMP   0b010100
#define RDI   0b010001
#define RDS   0b010010
#define LDW   0b100000
#define WDW   0b100001
#define RCP   0b100010
#define RCPS  0b100010
#define PMOV  0b100011
#define PMOVS 0b100011
#define PAND0 0b100100
#define PAND1 0b100100
#define PAND2 0b100100
#define PAND3 0b100100
#define POR0  0b100101
#define POR1  0b100101
#define POR2  0b100101
#define POR3  0b100101
#define PXOR0 0b100110
#define PXOR1 0b100110
#define PXOR2 0b100110
#define PXOR3 0b100110
#define PADD  0b100111
#define PADDS 0b100111
#define PSUB  0b101000
#define PSUBS 0b101000
#define PMUL  0b101001
#define PMULS 0b101001
#define PDVD  0b101010
#define PDVDS 0b101010
#define PMOD  0b101011
#define PMODS 0b101011
#define PLFT  0b101100
#define PRFT  0b101101
#define PARFT 0b101101
#define PSGS  0b101110
#define PASGS 0b101110
#define PCCT  0b101111
#define RWM   0b110000
#define RPM   0b110001
#define RWP   0b110010
#define WBW   0b110011
#define WBP   0b110100
#define OPT   0b110101
#define SYN   0b110110
#define DONE  0b110111

#endif //CL_COMPILER_OPERATION_CODE_H
