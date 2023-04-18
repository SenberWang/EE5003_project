//
// Created by YLW20 on 2022/5/19.
//

#ifndef CL_COMPILER_HANDLER_H
#define CL_COMPILER_HANDLER_H

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cassert>
#include <cstdio>
#include <cstring>
#include "bug_message.h"

extern std::map<std::string, std::string> reg_alias;
extern std::map<std::string, unsigned> segment_id;

inline bool getline_s(std::istream &in, std::string &line){
    bool isnt_end = std::getline(in, line) ? true : false;
    if(line.back() == '\r')
        line.pop_back();
    return isnt_end;
}

std::string get_reg_id(std::string str);
int comments_hide(const char *in_file_path, const char *out_file_path);
int line_token_extract(std::string line, std::vector<std::string> &tokens);
int reg_alias_extract(const char *in_file_path, const char *out_file_path);
int segment_id_extract(const char *in_file_path, const char *out_file_path);
int alias_substitute(const char *in_file_path, const char *out_file_path);
int segment_id_substitute(const char *in_file_path, const char *out_file_path);
int imm_separation_remove(const char *in_file_path, const char *out_file_path);

#endif //CL_COMPILER_HANDLER_H
