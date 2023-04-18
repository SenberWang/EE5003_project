//
// Created by Kera Cai on 2022/5/22.
//

#include <vector>
#include <string>
#include <map>
#include "machine_code.h"

std::map<std::string, std::string> reg_alias;
std::map<std::string, unsigned> segment_id;
std::map<std::string, unsigned> operation_code;
std::map<std::string, std::vector<std::string>> assembly_format;
std::map<std::string, _field_translator> field_translator;
std::map<std::string, _instruction_format> instruction_format;
