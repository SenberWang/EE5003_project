//
// Created by YLW20 on 2022/5/19.
//

#ifndef CL_COMPILER_NUM_MAGIC_H
#define CL_COMPILER_NUM_MAGIC_H

#include <string>
#include <bitset>
#include <cstddef>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include "bug_message.h"

#define MAX(x, y) ( ((x)>=(y)) ? (x) : (y) )
#define MIN(x, y) ( ((x)<=(y)) ? (x) : (y) )

typedef unsigned char uint_8 ;
typedef unsigned short uint_16;
typedef unsigned int uint_32 ;
typedef size_t uint_64 ;

typedef char int_8;
typedef short int_16;
typedef int int_32;
typedef long long int_64;

bool is_all_num(std::string str);
bool is_all_num_bin(std::string str);
bool is_all_num_hex(std::string str);
bool is_valid_num(std::string str);
int dec_string2num(std::string str, bool sign, uint_64 &num);
int bin_string2num(std::string str, bool sign, uint_64 &num);
int hex_string2num(std::string str, bool sign, uint_64 &num);
int hex_bit2num(char char_bit);
char num2hex_bit(uint_8 num);


#endif //CL_COMPILER_NUM_MAGIC_H
