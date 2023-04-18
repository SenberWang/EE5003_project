//
// Created by YLW20 on 2022/5/20.
//

#ifndef CL_COMPILER_TRANSLATOR_H
#define CL_COMPILER_TRANSLATOR_H

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <map>
#include <cstdio>
#include "num_magic.h"
#include "handler.h"
#include "operation_code.h"
#include "assembly.h"
#include "machine_code.h"

char get_token_type(const std::string &token);
bool line_tokens_format_check(const std::vector<std::string> &line_tokens);
int line_translator(std::vector<std::string> line_tokens, std::string &machine_code, const std::string separation);
int translate(const char *in_file_path, const char *out_file_path, const char *array_name);


#endif //CL_COMPILER_TRANSLATOR_H
