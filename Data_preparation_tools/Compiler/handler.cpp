//
// Created by Kera Cai on 2022/5/14.
//

#include "handler.h"

int comments_hide(const char *in_file_path, const char *out_file_path){
    std::cout << std::endl << "HIDDING COMMENTS: " << std::endl;
    std::ifstream in(in_file_path);
    std::ofstream out(out_file_path);
    std::string line;
    if(!in){
        ERROR("file open failed");
        return -1;
    }
    while(getline_s(in, line)) { //read one line
        //delete all the content after '/' in a line
        int slash_pos = line.find('/');
        if(slash_pos != line.npos) {
            if(slash_pos!=0) {
                std::string sub_line = line.substr(0, slash_pos);
                line.swap(sub_line);
            }
            else
                line.clear();
        }
        //if all the chars are ' ', delete this line
        if(count(line.begin(), line.end(), ' ') == line.length())
            line.clear();
        if(!line.empty()) {
            std::cout << line << std::endl;
            out << line << std::endl;
        }
    }
    in.close();
    out.close();
    std::cout << "DONE." << std::endl;
    return 0;
}

int line_token_extract(std::string line, std::vector<std::string> &tokens){
    //std::vector<std::string> temp_tokens;
    bool token_start = false;
    int token_start_idx;
    if(line.empty()) return 0;
    for(int i=0; i<=line.length()-1; i++){
        //std::cout << " " << line[i] << " ";
        if(!token_start && line[i] != ' ' && line[i] != ',' && line[i] != ';'){
            token_start_idx = i;
            //std::cout << " token start idx " << token_start_idx;
            token_start = true;
        }
        else if(token_start){
            if(line[i]==' ' || line[i]==',' || line[i]==';' || i==line.length()-1){
                if(line[i]==' ' || line[i]==',' || line[i]==';')
                    tokens.push_back(line.substr(token_start_idx, i-token_start_idx));
                else
                    tokens.push_back(line.substr(token_start_idx, i-token_start_idx+1));
                token_start = false;
            }
        }
    }
    return 0;
}

int reg_alias_extract(const char *in_file_path, const char *out_file_path){
    std::cout << std::endl << "SETTING ALIAS: " << std::endl;
    std::ifstream in(in_file_path);
    std::ofstream out(out_file_path);
    if(!in){
        ERROR("file open failed");
        return -1;
    }
    std::string line;
    while(getline_s(in, line)){
        std::vector<std::string> tokens;
        line_token_extract(line, tokens);
        if(!tokens.size()) continue;
        if(tokens[0] == std::string("SET")){
            if(reg_alias.count(tokens[2])){
                ERROR("\"%s\" has already be used as the alias for %s, "
                      "cannot be used for %s again", tokens[2].c_str(),
                      reg_alias.find(tokens[2])->second.c_str(), tokens[1].c_str());
                return -1;
            }
            reg_alias.insert(std::pair<std::string, std::string>(tokens[2], tokens[1]));
            std::cout << "Set alias: \"" << tokens[2] << "\" for: " << tokens[1] << std::endl;
        }
        else{
            for_each(tokens.begin(), tokens.end(),
                     [&out](std::string token)->void { out << token << " ";});
            out << std::endl;
        }
    }
//    for(auto iter = reg_alias.begin(); iter != reg_alias.end(); ++iter) {
//        std::cout << iter->first << " " << iter->second << std::endl;
//    }
    in.close();
    out.close();
    std::cout << "DONE." << std::endl;
    return 0;
}

int segment_id_extract(const char *in_file_path, const char *out_file_path) {
    std::cout << std::endl << "EXTRACTING SEGMENT ID: " << std::endl;
    std::ifstream in(in_file_path);
    std::ofstream out(out_file_path);
    if (!in) {
        ERROR("file open failed");
        return -1;
    }
    std::string line;
    unsigned line_id = 0;
    while(getline_s(in, line)){
        std::vector<std::string> tokens;
        line_token_extract(line, tokens);
        if(tokens[0].back() == ':') {
            segment_id.insert(
                    std::pair<std::string, unsigned>
                            (tokens[0].substr(0, tokens[0].length() - 1), line_id)
            );
            for(int i=1; i<=tokens.size()-1; i++)
                out << tokens[i] << " ";
            out << std::endl;
        }
        else{
            for_each(tokens.begin(), tokens.end(),
                     [&out](std::string token)->void { out << token << " ";});
            out << std::endl;
        }
        line_id++;
    }
    for(auto iter = segment_id.begin(); iter != segment_id.end(); ++iter) {
        std::cout << iter->first << " " << iter->second << std::endl;
    }
    in.close();
    out.close();
    std::cout << "DONE." << std::endl;
    return 0;

}

int alias_substitute(const char *in_file_path, const char *out_file_path){
    std::cout << std::endl << "SUBSTITUTING ALIAS: " << std::endl;
    std::ifstream in(in_file_path);
    std::ofstream out(out_file_path);
    if(!in){
        ERROR("file open failed");
        return -1;
    }
    std::string line;
    while(getline_s(in, line)){
        std::vector<std::string> tokens;
        line_token_extract(line, tokens);
        for_each(tokens.begin(), tokens.end(),
                 [](std::string &token)->
                         void {
                     unsigned l = token.length();
                     if(token[0] == '<' && token[l-1] == '>') {
                         std::string sub = token.substr(1, l-2);
                         if(!(sub.rfind("REG[", 0) == 0 && sub.back() == ']' ||
                              sub.rfind("PE_REG[", 0) == 0 && sub.back() == ']')) {
                             if (sub.compare(0, 3, "") && token.compare(0, 6, "")) {
                                 std::cout << "Alias substitution: find alias:";
                                 if (reg_alias.count(sub) == 0) {
                                     ERROR("No such alias definition \"%s\".", sub.c_str());
                                     assert(0);
                                 } else {
                                     std::cout << " \"" << token << "\" -> \"";
                                     token = "<" + reg_alias.find(sub)->second + ">";
                                     std::cout << token << "\"." << std::endl;
                                 }
                             }
                         }
                     }
                 });
        for_each(tokens.begin(), tokens.end(),
                 [&out](std::string token)->void { out << token << " ";});
        out << std::endl;
    }
    in.close();
    out.close();
    std::cout << "DONE." << std::endl;
    return 0;
}

int imm_separation_remove(const char *in_file_path, const char *out_file_path){
    std::cout << std::endl << "REMOVING SEPARATION CHAR IN IMMDIATE NUMBER: " << std::endl;
    std::ifstream in(in_file_path);
    std::ofstream out(out_file_path);
    if(!in){
        ERROR("file open failed");
        return -1;
    }
    std::string line;
    while(getline_s(in, line)){
        std::vector<std::string> tokens;
        line_token_extract(line, tokens);
        for(std::string &token: tokens){
            if(token.rfind('#', 0) == 0 || token.rfind("0b", 0) == 0 ||
               token.rfind("0x", 0) == 0) {
                token.erase(std::remove(token.begin(), token.end(), '_'), token.end());
            }
        }
        for_each(tokens.begin(), tokens.end(),
                 [&out](std::string token)->void { out << token << " ";});
        out << std::endl;
    }
    in.close();
    out.close();
    std::cout << "DONE." << std::endl;
    return 0;
}

int segment_id_substitute(const char *in_file_path, const char *out_file_path){
    std::cout << std::endl << "SUBSTITUTING SEGMENT_ID: " << std::endl;
    std::ifstream in(in_file_path);
    std::ofstream out(out_file_path);
    if(!in){
        ERROR("file open failed");
        return -1;
    }
    std::string line;
    while(getline_s(in, line)){
        std::vector<std::string> tokens;
        line_token_extract(line, tokens);
        for_each(tokens.begin(), tokens.end(),
                 [](std::string &token)->
                         void {
                     unsigned l = token.length();
                     if( token.rfind("!", 0)==0 ){
                         std::string sub = token.substr(1, token.length()-1);
                         if(!segment_id.count(sub)){
                             ERROR("No such alias definition \"%s\".", sub.c_str());
                             assert(0);
                         }
                         else{
                             std::cout << " \"" << token << "\" -> \"";
                             token = "d" + std::to_string(segment_id.find(sub)->second);
                             std::cout << token << "\"." << std::endl;
                         }
                     }
                 });
        for_each(tokens.begin(), tokens.end(),
                 [&out](std::string token)->void { out << token << " ";});
        out << std::endl;
    }
    in.close();
    out.close();
    std::cout << "DONE." << std::endl;
    return 0;
}

std::string get_reg_id(std::string str){
    unsigned char pos_0 = str.find('[');
    unsigned char pos_1 = str.find(']');
    return str.substr(pos_0 + 1, pos_1 - pos_0 -1);
}
