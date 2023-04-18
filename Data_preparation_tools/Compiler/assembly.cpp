//
// Created by YLW20 on 2022/5/22.
//

#include "assembly.h"

void assembly_format_init(){
    //assembly_format.insert(std::make_pair("mov", std::vector<std::string>{"rr", "ri"}));
    AAF("none" , "");
    AAF("mov"  , "rr" , "ri"  ); //"r" stands for reg
    AAF("movs" , "rr" , "ri"  ); //"i" stands for imm
    AAF("and"  , "rrr", "rri" );
    AAF("or"   , "rrr", "rri" );
    AAF("xor"  , "rrr", "rri" );
    AAF("add"  , "rrr", "rri" );
    AAF("adds" , "rrr", "rri" );
    AAF("sub"  , "rrr", "rri" );
    AAF("subs" , "rrr", "rri" );
    AAF("mul"  , "rrr", "rri" );
    AAF("muls" , "rrr", "rri" );
    AAF("dvd"  , "rrr", "rri" );
    AAF("dvds" , "rrr", "rri" );
    AAF("mod"  , "rrr", "rri" );
    AAF("mods" , "rrr", "rri" );
    AAF("lft"  , "rrr", "rri" );
    AAF("rft"  , "rrr", "rri" );
    AAF("arft" , "rrr", "rri" );
    AAF("sgs"  , "rrii");
    AAF("asgs" , "rrii");
    AAF("cct"  , "rrriiii");
    AAF("je"   , "rri", "rrs", "rii", "ris");
    AAF("jes"  , "rri", "rrs", "rii", "ris");
    AAF("jn"   , "rri", "rrs", "rii", "ris");
    AAF("jns"  , "rri", "rrs", "rii", "ris");
    AAF("jg"   , "rri", "rrs", "rii", "ris");
    AAF("jgs"  , "rri", "rrs", "rii", "ris");
    AAF("jng"  , "rri", "rrs", "rii", "ris");
    AAF("jngs" , "rri", "rrs", "rii", "ris");
    AAF("jl"   , "rri", "rrs", "rii", "ris");
    AAF("jls"  , "rri", "rrs", "rii", "ris");
    AAF("jnl"  , "rri", "rrs", "rii", "ris");
    AAF("jnls" , "rri", "rrs", "rii", "ris");
    AAF("jmp"  , "r", "s", "i"); //"s" stands for segment id
    AAF("rdi"  , "rr");
    AAF("rds"  , "rr");
    AAF("ldw"  , "rrri");
    AAF("wdw"  , "rrri");
    AAF("rcp"  , "rpi", "pri"); //"p" stands for pe_reg
    AAF("rcps" , "rpi", "pri");
    AAF("pmov" , "ppi", "pii");
    AAF("pmovs", "ppi", "pii");
    AAF("pand0", "pppi", "ppii");
    AAF("pand1", "pppi", "ppii");
    AAF("pand2", "pppi", "ppii");
    AAF("pand3", "pppi", "ppii");
    AAF("por0" , "pppi", "ppii");
    AAF("por1" , "pppi", "ppii");
    AAF("por2" , "pppi", "ppii");
    AAF("por3" , "pppi", "ppii");
    AAF("pxor0", "pppi", "ppii");
    AAF("pxor1", "pppi", "ppii");
    AAF("pxor2", "pppi", "ppii");
    AAF("pxor3", "pppi", "ppii");
    AAF("padd" , "pppi", "ppii");
    AAF("padds", "pppi", "ppii");
    AAF("psub" , "pppi", "ppii");
    AAF("psubs", "pppi", "ppii");
    AAF("pmul" , "pppi", "ppii");
    AAF("pmuls", "pppi", "ppii");
    AAF("pdvd" , "pppi", "ppii");
    AAF("pdvds", "pppi", "ppii");
    AAF("pmod" , "pppi", "ppii");
    AAF("pmods", "pppi", "ppii");
    AAF("plft" , "pppi", "ppii");
    AAF("prft" , "pppi", "ppii");
    AAF("parft", "pppi", "ppii");
    AAF("psgs" , "ppiii");
    AAF("pasgs", "ppiii");
    AAF("pcct" , "pppiiiii");
    AAF("rwm"  , "pri");
    AAF("rpm"  , "pri");
    AAF("rwp"  , "pprri");
    AAF("wbw"  , "rpi");
    AAF("wbp"  , "rpi");
    AAF("opt"  , "pppii");
    AAF("syn"  , "");
    AAF("done" , "");
}
