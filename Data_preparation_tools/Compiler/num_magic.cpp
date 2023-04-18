//
// Created by YLW20 on 2022/5/19.
//

#include "num_magic.h"

int dec_string2num(std::string str, bool sign, uint_64 &num){
    num = 0;
    if(! (is_all_num(str) || is_all_num(str.substr(1)) && str[0] == '-') ){
        ERROR("The input string does not represent a valid decimal number.\n    String: \"%s\".\n", str.c_str());
        return -1;
    }
    char *end;
    if(sign)
        num = std::strtoll(str.c_str(), &end, 10);
    else {
        if(str[0] == '-'){
            ERROR("Unsigned decimal number cannot start with '-'.\n    String: \"%s\".\n", str.c_str());
            return -1;
        }
        num = std::strtoull(str.c_str(), &end, 10);
    }
    return 0;
}


int bin_string2num(std::string str, bool sign, size_t &num){
    num = 0;
    if(str[0]!='0' || str[1]!='b' || !is_all_num(str.substr(2, str.length()-2+1))){
        ERROR("The input string does not represent a valid binary number.\n    String: \"%s\".\n", str.c_str());
        return -1;
    }
    for(int i=2; i<=str.length()-1; i++) {
        num += (str[i] - 48) << (str.length()-i-1);
    }
    size_t one = 1;
    if(sign && str[2]=='1')
        for(int i=str.length()-2; i<=63; i++) {
            num += one << i;
        }
    return 0;
}

int hex_string2num(std::string str, bool sign, size_t &num){
    num = 0;
    if(str[0]!='0' || str[1]!='x' || !is_all_num_hex(str.substr(2, str.length()-2+1))){
        ERROR("The input string does not represent a valid hexadecimal number.\n    String: \"%s\".\n", str.c_str());
        return -1;
    }
    for(int i=2; i<=str.length()-1; i++) {
        num += hex_bit2num(str[i]) << 4*(str.length()-i-1);
    }
    size_t temp = num;
    size_t one = 1;
    if(sign && hex_bit2num(str[2])>=8 )
        for(int i=4*(str.length()-2); i<=63; i++) {
            num += one << i;
        }
    return 0;
}

int hex_bit2num(const char char_bit){
    int num;
    switch (char_bit) {
        case '0': num = 0; break;
        case '1': num = 1; break;
        case '2': num = 2; break;
        case '3': num = 3; break;
        case '4': num = 4; break;
        case '5': num = 5; break;
        case '6': num = 6; break;
        case '7': num = 7; break;
        case '8': num = 8; break;
        case '9': num = 9; break;
        case 'A': num = 10; break;
        case 'B': num = 11; break;
        case 'C': num = 12; break;
        case 'D': num = 13; break;
        case 'E': num = 14; break;
        case 'F': num = 15; break;
        default: num = -1; break;
    }
    return num;
}

bool is_all_num(std::string str){
    for(int i=0; i<=str.length()-1; i++){
        char char_bit = (char) str[i];
        if( char_bit<48 || char_bit>57 )
            return false;
    }
    return true;
}

bool is_all_num_bin(std::string str){
    for(int i=0; i<=str.length()-1; i++){
        char char_bit = (char) str[i];
        if( char_bit!='0' && char_bit!='1' )
            return false;
    }
    return true;
}

bool is_all_num_hex(std::string str){
    for(int i=0; i<=str.length()-1; i++){
        char char_bit = (char) str[i];
        if(hex_bit2num(char_bit)==-1)
            return false;
    }
    return true;
}

bool is_valid_num(std::string str){
    if(is_all_num(str)) return true;
    else if(str[0] == '0' &&str[1] == 'b')
        return is_all_num_bin(str.substr(2, str.length()-2));
    else if(str[0] == '0' &&str[1] == 'x')
        return is_all_num_hex(str.substr(2, str.length()-2));
    else return false;
}

char num2hex_bit(uint_8 num){
    switch(num){
        case 0: return '0';
        case 1: return '1';
        case 2: return '2';
        case 3: return '3';
        case 4: return '4';
        case 5: return '5';
        case 6: return '6';
        case 7: return '7';
        case 8: return '8';
        case 9: return '9';
        case 10: return 'A';
        case 11: return 'B';
        case 12: return 'C';
        case 13: return 'D';
        case 14: return 'E';
        case 15: return 'F';
        default: return -1;
    }
}