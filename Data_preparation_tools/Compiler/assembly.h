//
// Created by YLW20 on 2022/5/22.
//

#ifndef CL_COMPILER_ASSEMBLY_H
#define CL_COMPILER_ASSEMBLY_H

#include <map>
#include <vector>
#include <string>
#include "num_magic.h"
#include "handler.h"
#include "bit_sequence.h"
#include "operation_code.h"

#define AAF(op, ...) assembly_format.insert(std::make_pair(op, std::vector<std::string>{__VA_ARGS__}))
extern std::map<std::string, std::vector<std::string>> assembly_format;
void assembly_format_init();

#endif //CL_COMPILER_ASSEMBLY_H
