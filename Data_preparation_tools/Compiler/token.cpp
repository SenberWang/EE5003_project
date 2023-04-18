//
// Created by YLW20 on 2022/5/22.
//

#include "token.h"

char get_token_type(const std::string &token) {
    //if(token.empty()) std::cout << "empty token!" << std::endl;
    if (operation_code.count(token))
        return 'o'; //op_code
    else if (token[0] == '<' && token[token.length() - 1] == '>') {
//        std::cout << "token[token.length() - 2] == ']'  : " << (token[token.length() - 2] == ']') << std::endl;
//        std::cout << "(token.substr(1, 4) == \"REG[\")    : " << ((token.substr(1, 4) == "REG[")) << std::endl;
//        std::cout << "(token.substr(1, 7) == \"PE_REG[\") : " << ((token.substr(1, 7) == "PE_REG[")) << std::endl;
        if (token[token.length() - 2] == ']' && (token.substr(1, 4) == "REG[")) {
            std::string sub = token.substr(5, token.find(']') - 5);
            //std::cout << "substr " << sub << std::endl;
            if(is_valid_num(sub))
                return 'r'; //reg
        }
        else if (token[token.length() - 2] == ']' && (token.substr(1, 7) == "PE_REG[")) {
            std::string sub = token.substr(8, token.find(']') - 8);
            //std::cout << "substr " << sub << std::endl;
            if(is_valid_num(sub))
                return 'p';
        }
    } else if (token.rfind('#', 0) == 0) {
        if (is_all_num_bin(token.substr(1, token.length() - 1))) return 'i';
    } else if (token.rfind("0x", 0) == 0) {
        if (is_all_num_hex(token.substr(2, token.length() - 2))) return 'i';
    } else if (token.rfind('d', 0) == 0) {
        if (is_all_num(token.substr(1, token.length() - 1))) return 'i';
    } else if (token.rfind('!', 0) == 0) {
        return 's';
    }
    return -1;
}