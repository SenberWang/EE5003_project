#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include "bit_sequence.h"
#include "handler.h"
#include "translator.h"


int init();

int main(){
    std::string input{"../input/instr_out_v5.txt"};
    std::string output{"../output/out_instr_out_v5.txt"};

    /** DO NOT CHANGE EASILY **/
    init();

    comments_hide(input.c_str(), "../temp/out_commentless.txt");
    reg_alias_extract("../temp/out_commentless.txt", "../temp/out_SETless.txt");
    segment_id_extract("../temp/out_SETless.txt", "../temp/out_segmentless.txt");
    alias_substitute("../temp/out_segmentless.txt", "../temp/out_aliasless.txt");
    segment_id_substitute("../temp/out_aliasless.txt", "../temp/out_segidless.txt");
    imm_separation_remove("../temp/out_segidless.txt", "../temp/out_sepaless.txt");
    translate("../temp/out_sepaless.txt", output.c_str(), "ClstInputPkg[5].InstrMem");
    return 0;
}


