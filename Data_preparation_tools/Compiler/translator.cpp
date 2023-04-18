//
// Created by YLW20 on 2022/5/20.
//

#include "translator.h"

bool line_tokens_format_check(const std::vector<std::string> &line_tokens){
    std::string tokens_format;
    char token_type;
    for(std::string token: line_tokens) {
        token_type = get_token_type(token);
        if(token_type == -1){
            std::cout << "Find invalid token:  " << token << "." << std::endl;
            return false;
        }
        else tokens_format += token_type;
    }
    if(tokens_format.rfind('o', 0) != 0){
        std::cout << "First token in a line is not a valid operarion: " << line_tokens[0] << "." << std::endl;
        return false;
    }
    else {
        tokens_format = tokens_format.substr(1, tokens_format.length()-1);
    }
    if(!assembly_format.count(line_tokens[0])){
        std::cout << "Cannot find operation " << line_tokens[0] << "." << std::endl;
        return false;
    }
    std::vector<std::string> fmts = assembly_format.find(line_tokens[0])->second;
    for(std::string expected_fmt: fmts){
        if(tokens_format == expected_fmt.c_str())
            return true;
    }
    std::cout << "Find invalid line: " << std::endl;
    std::cout << "    Tokens in the line: " ;
    for(std::string token: line_tokens){
        std::cout << token << " ";
    }
    std::cout << ", format = " << tokens_format << std::endl;
    for(std::string fmt: fmts)
        std::cout << "    expected format : " << fmt << std::endl;
    return false;
}

int line_translator(std::vector<std::string> line_tokens, std::string &machine_code, const std::string separation){
    std::string temp_code;
    if(!line_tokens_format_check(line_tokens)){
        ERROR("invalid tokens in line.");
        return -1;
    }
    if(!instruction_format.count(line_tokens[0])){
        ERROR("no such operation %s.", line_tokens[0].c_str());
        return -1;
    }
    else{
        try {
            _instruction_format instr_fmt = instruction_format.find(line_tokens[0])->second;
            for (_field_translator field_translator: instr_fmt) {
                temp_code += (field_translator(line_tokens) + separation);
            }
            machine_code.swap(temp_code);
        }
        catch(bit_sequence_construct_exception e){
            ERROR("Failed to construct bit_sequence.");
            return -1;
        }
    }
    return 0;
}

int translate(const char *in_file_path, const char *out_file_path, const char *array_name){
    std::cout << std::endl << "Translating: " << std::endl;
    std::ifstream in(in_file_path);
    std::ofstream out(out_file_path);
    std::string line;
    if(!in){
        ERROR("file open failed");
        return -1;
    }
    unsigned int line_idx = 0;
    char machine_code[1024];
    while(getline_s(in, line)){
        std::vector<std::string> tokens;
        line_token_extract(line, tokens);
        if(!line_translator(tokens, line, "")) {
            std::sprintf(machine_code, "%s[%d] = 0b%s;", array_name, line_idx, line.c_str());
            out << machine_code << std::endl;
            line_translator(tokens, line, "");
            std::printf("%s[%d] = 0b%s;\n", array_name, line_idx, line.c_str());
            line_idx++;
        }
        else{
            std::cout << "Line " << line_idx << " in file \"" << out_file_path << "\" met translation failure." << std::endl;
            std::cout << "    " << line << std::endl << std::endl;
        }
    }
    in.close();
    out.close();
    std::cout << "DONE." << std::endl;
    return 0;
}

