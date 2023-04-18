#ifndef _ALU_HEADER_
#define _ALU_HEADER_

#include "global_vars.h"

_reg_64b ALU(_reg_64b arg_1, _reg_64b arg_2, ap_uint<4> flag);
_reg_64b ALUPE(_reg_64b arg_1, _reg_64b arg_2, ap_uint<4> flag);
_reg_64b_s ALUS(_reg_64b_s arg_1, _reg_64b_s arg_2, ap_uint<4> flag);
_reg_64b_s ALUPES(_reg_64b_s arg_1, _reg_64b_s arg_2, ap_uint<4> flag);

#endif
