//
// Created by YLW20 on 2022/5/19.
//

#ifndef CL_COMPILER_MACHINE_CODE_H
#define CL_COMPILER_MACHINE_CODE_H

#include <map>
#include <utility>
#include <vector>
#include <string>
#include <functional>
#include "num_magic.h"
#include "handler.h"
#include "token.h"
#include "assembly.h"
#include "bit_sequence.h"
#include "operation_code.h"

typedef std::vector<std::string> _tokens;
typedef std::function<std::string(_tokens)> _field_translator;
typedef std::vector<_field_translator> _instruction_format;

extern std::map<std::string, std::string> reg_alias;
extern std::map<std::string, unsigned> segment_id;
extern std::map<std::string, _instruction_format> instruction_format;

//add instruction format


template<unsigned idx>
std::string opcode(const _tokens &tokens){
    return bit_sequence<5>{operation_code.find(tokens[idx])->second}.to_bin_string(5);
};

template<unsigned idx> // token idx
std::string reg(const _tokens &tokens){//token[idx] is determined to be a register
    return bit_sequence<5>{get_reg_id(tokens[idx])}.to_bin_string(5);
}

template<unsigned idx> // token idx
std::string preg(const _tokens &tokens){//token[idx] might be register or imm ...
    if(get_token_type(tokens[idx]) == 'r' || get_token_type(tokens[idx]) == 'p' )
        return bit_sequence<5>{get_reg_id(tokens[idx])}.to_bin_string(5);
    else
        return "00000";
}

template<unsigned idx> // token idx
std::string immA(const _tokens &tokens){ //token[idx] must be immA (unsigned)
    return bit_sequence<19>{tokens[idx]}.to_bin_string(19);
}

template<unsigned idx>
std::string immAs(const _tokens &tokens){ //token[idx] must be immA (signed)
    return bit_sequence<19>{tokens[idx], true}.to_bin_string(19);
}

template<unsigned idx>
std::string pimmA(const _tokens &tokens){ //token[idx] might be immA (unsigned) or register
    if(get_token_type(tokens[idx]) == 'i')
        return bit_sequence<19>{tokens[idx]}.to_bin_string(19);
    else
        return "000""0000""0000""0000""0000";
}

template<unsigned idx>
std::string pimmAs(const _tokens &tokens){ //token[idx] might be immA (unsigned) or register
    if(get_token_type(tokens[idx]) == 'i')
        return bit_sequence<19>{tokens[idx], true}.to_bin_string(19);
    else
        return "000""0000""0000""0000""0000";
}

template<unsigned idx>
std::string cluster_mask(const _tokens &tokens){ //token[idx] must be cluster mask
    return bit_sequence<16>{tokens[idx]}.to_bin_string(16);
}

template<unsigned idx>
std::string immB(const _tokens &tokens){ //token[idx] must be immB (unsigned)
    return bit_sequence<16>{tokens[idx]}.to_bin_string(16);
}

template<unsigned idx>
std::string immBs(const _tokens &tokens){ //token[idx] must immB (signed)
    return bit_sequence<16>{tokens[idx], true}.to_bin_string(16);
}

template<unsigned idx>
std::string pimmB(const _tokens &tokens){ //token[idx] might be immB (unsigned) or register
    if(get_token_type(tokens[idx]) == 'i')
        return bit_sequence<16>{tokens[idx]}.to_bin_string(16);
    else
        return "0000""0000""0000""0000";
}

template<unsigned idx>
std::string imm(const _tokens &tokens){ //token[idx] must be immB (unsigned)
    return bit_sequence<16>{tokens[idx]}.to_bin_string(16);
}

template<unsigned idx>
std::string imms(const _tokens &tokens){ //token[idx] must immB (signed)
    return bit_sequence<16>{tokens[idx], true}.to_bin_string(16);
}

template<unsigned idx>
std::string pimm(const _tokens &tokens){ //token[idx] might be immB (unsigned) or register
    if(get_token_type(tokens[idx]) == 'i')
        return bit_sequence<16>{tokens[idx]}.to_bin_string(16);
    else
        return "0000""0000""0000""0000";
}

template<unsigned idx>
std::string pimms(const _tokens &tokens){ //token[idx] might be immB (unsigned) or register
    if(get_token_type(tokens[idx]) == 'i')
        return bit_sequence<16>{tokens[idx], true}.to_bin_string(16);
    else
        return "0000""0000""0000""0000";
}

template<unsigned idx>
std::string jmp_dest(const _tokens &tokens){ //token[idx] might be the destination for jumping
    if(get_token_type(tokens[idx]) == 'i')
        return bit_sequence<16>{tokens[idx]}.to_bin_string(16);
    else if(get_token_type(tokens[idx]) == 's')
        return bit_sequence<16>{segment_id.find(tokens[idx].substr(1, tokens[idx].length()-1))->second}.to_bin_string(16);
    else
        return "0000""0000""0000""0000";
}

template<unsigned idx>
std::string pimmBs(const _tokens &tokens){ //token[idx] might be immB (signed) or register
    if(get_token_type(tokens[idx]) == 'i')
        return bit_sequence<16>{tokens[idx], true}.to_bin_string(16);
    else
        return "0000""0000""0000""0000";
}

template<unsigned idx>
std::string PE_mask(const _tokens &tokens){ //token[idx] must be PE_mask
    return bit_sequence<16>{tokens[idx]}.to_bin_string(16);
}

template<unsigned idx>
std::string pPE_mask(const _tokens &tokens){ //token[idx] must be PE_mask
    if(tokens.size() < idx + 1)
        return "0000""0000""0000""0000";
    else
        return bit_sequence<16>{tokens[idx]}.to_bin_string(16);
}

template<unsigned idx>
std::string pimmL(const _tokens &tokens){ //token[idx] might be immB (unsigned) or register
    if(get_token_type(tokens[idx]) == 'i')
        return bit_sequence<32>{tokens[idx]}.to_bin_string(32);
    else
        return "0000""0000""0000""0000""0000""0000""0000""0000";
}

template<unsigned idx>
std::string imm_idx(const _tokens &tokens){
    return bit_sequence<6>{tokens[idx]}.to_bin_string(6);
}


inline std::string one(const _tokens &tokens){
    return "1";
}

inline std::string zero(const _tokens &tokens){
    return "0";
}

inline std::string zero_2(const _tokens &tokens){
    return "00";
}

inline std::string zero_3(const _tokens &tokens){
    return "000";
}

inline std::string zero_5(const _tokens &tokens){
    return "0""0000";
}

inline std::string zero_6(const _tokens &tokens){
    return "00""0000";
}

inline std::string zero_16(const _tokens &tokens){
    return "0000""0000""0000""0000";
}

inline std::string zero_19(const _tokens &tokens){
    return "000""0000""0000""0000""0000";
}

inline std::string zero_59(const _tokens &tokens){
    return "00000000000""000000000000""000000000000""000000000000""000000000000";
}

inline std::string one_59(const _tokens &tokens){
    return "11111111111""111111111111""111111111111""111111111111""111111111111";
}

template<unsigned idx>
std::string imm_flag(const _tokens &tokens){ // imm or reg
    if (get_token_type(tokens[idx]) == 'i')
        return "1";
    else
        return "0";
}

template<unsigned idx>
std::string is_imm(const _tokens &tokens){ // imm or reg
    if (get_token_type(tokens[idx]) == 'i')
        return "1";
    else
        return "0";
}

template<unsigned idx>
std::string is_PE(const _tokens &tokens){ // direction flag
    if (get_token_type(tokens[idx]) == 'p') // 'r' <= 'p'
        return "1";
    else                                    // 'p' <= 'r'
        return "0";
}

template<unsigned idx>
std::string drx_flag(const _tokens &tokens){ // direction flag
    if (get_token_type(tokens[idx]) == 'p') // 'r' <= 'p'
        return "0";
    else                                    // 'p' <= 'r'
        return "1";
}

void instruction_format_init();

#endif //CL_COMPILER_MACHINE_CODE_H
