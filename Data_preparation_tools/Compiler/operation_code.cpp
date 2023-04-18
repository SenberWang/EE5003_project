//
// Created by YLW20 on 2022/5/22.
//

#include "operation_code.h"

//add operation code
#define AOP(op, op_code) operation_code.insert(std::make_pair(op, op_code))

void operation_code_init(){
    AOP("none" , NONE );
    AOP("mov"  , MOV  );
    AOP("movs" , MOVS );
    AOP("and"  , AND  );
    AOP("or"   , OR   );
    AOP("xor"  , XOR  );
    AOP("add"  , ADD  );
    AOP("adds" , ADDS );
    AOP("sub"  , SUB  );
    AOP("subs" , SUBS );
    AOP("mul"  , MUL  );
    AOP("muls" , MULS );
    AOP("dvd"  , DVD  );
    AOP("dvds" , DVDS );
    AOP("mod"  , MOD  );
    AOP("mods" , MODS );
    AOP("lft"  , LFT  );
    AOP("rft"  , RFT  );
    AOP("arft" , ARFT );
    AOP("sgs"  , SGS  );
    AOP("asgs" , ASGS );
    AOP("cct"  , CCT  );
    AOP("je"   , JE   );
    AOP("jes"  , JES  );
    AOP("jn"   , JN   );
    AOP("jns"  , JNS  );
    AOP("jg"   , JG   );
    AOP("jgs"  , JGS  );
    AOP("jng"  , JNG  );
    AOP("jngs" , JNGS );
    AOP("jl"   , JL   );
    AOP("jls"  , JLS  );
    AOP("jnl"  , JNL  );
    AOP("jnls" , JNLS );
    AOP("jmp"  , JMP  );
    AOP("rdi"  , RDI  );
    AOP("rds"  , RDS  );
    AOP("ldw"  , LDW  );
    AOP("wdw"  , WDW  );
    AOP("rcp"  , RCP  );
    AOP("rcps" , RCPS );
    AOP("pmov" , PMOV );
    AOP("pmovs", PMOVS);
    AOP("pand0", PAND0);
    AOP("pand1", PAND1);
    AOP("pand2", PAND2);
    AOP("pand3", PAND3);
    AOP("por0" , POR0 );
    AOP("por1" , POR1 );
    AOP("por2" , POR2 );
    AOP("por3" , POR3 );
    AOP("pxor0", PXOR0);
    AOP("pxor1", PXOR1);
    AOP("pxor2", PXOR2);
    AOP("pxor3", PXOR3);
    AOP("padd" , PADD );
    AOP("padds", PADDS);
    AOP("psub" , PSUB );
    AOP("psubs", PSUBS);
    AOP("pmul" , PMUL );
    AOP("pmuls", PMULS);
    AOP("pdvd" , PDVD );
    AOP("pdvds", PDVDS);
    AOP("pmod" , PMOD );
    AOP("pmods", PMODS);
    AOP("plft" , PLFT );
    AOP("prft" , PRFT );
    AOP("parft", PARFT);
    AOP("psgs" , PSGS );
    AOP("pasgs", PASGS);
    AOP("pcct" , PCCT );
    AOP("rwm"  , RWM  );
    AOP("rpm"  , RPM  );
    AOP("rwp"  , RWP  );
    AOP("wbw"  , WBW  );
    AOP("wbp"  , WBP  );
    AOP("opt"  , OPT  );
    AOP("syn"  , SYN  );
    AOP("done" , DONE );
}

