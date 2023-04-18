#ifndef _GLOBAL_CTRL_HEADER_
#define _GLOBAL_CTRL_HEADER_

#include "hls_stream.h"
#include "ap_int.h"
#include "ap_mem_if.h"


//test print
//#define TEST_LOG_PRINT 1
//#define TEST_FNL_PRINT 1
//#define TEST_LDW_PSEUDO 1
//#define TEST_WEIGHT_LOAD_PSEUDO 1
//#define TEST_SPIKE_LOAD_PSEUDO 1
//#define TEST_SPK_SCD 1

//top level
#define NUM_TOTAL_CLUSTER 6
#define NUM_PE_PER_CLUSTER 4
#define CLST_ID_WIDTH 3

//instruction segment
#define IMM_CL_LSB 16
#define IMM_CL_MSB 21
#define IMM_CH_LSB 22
#define IMM_CH_MSB 27
#define IMM_BL_LSB 28
#define IMM_BL_MSB 33
#define IMM_BH_LSB 34
#define IMM_BH_MSB 39
#define IMM_B_LSB 0
#define IMM_B_MSB 15
#define IMM_A_LSB 16
#define IMM_A_MSB 31
#define REG_D_LSB 32
#define REG_D_MSB 36
#define REG_C_LSB 37
#define REG_C_MSB 41
#define REG_C_SC_LSB 40
#define REG_C_SC_MSB 44
#define REG_B_SC_LSB 45
#define REG_B_SC_MSB 49
#define REG_A_SC_LSB 50
#define REG_A_SC_MSB 54
#define REG_B_LSB 42
#define REG_B_MSB 46
#define REG_A_LSB 47
#define REG_A_MSB 51
#define FLAG_FL_LSB 53
#define FLAG_FL_MSB 53
#define FLAG_FH_LSB 54
#define FLAG_FH_MSB 54
#define FLAG_I_LSB 55
#define FLAG_I_MSB 55
#define FLAG_C_LSB 56
#define FLAG_C_MSB 56
#define FLAG_P_LSB 57
#define FLAG_P_MSB 57
#define FLAG_S_LSB 58
#define FLAG_S_MSB 58
#define OPCODE_LSB 59
#define OPCODE_MSB 63

#define _bool ap_uint<1>
#define _opcode ap_uint<6>
#define _isa_reg_id ap_uint<5>
#define _imm_sgs ap_uint<6>
#define _mask_pe ap_uint<16>
#define _mask_clst ap_uint<16>
#define _imm_16b ap_uint<16>


//memory width and depth
#define DEPTH_INSTR_MEM 1024
#define WIDTH_INSTR_MEM 64

#define DEPTH_WEIGHT_MEM 5120
#define WIDTH_WEIGHT_MEM 32

#define DEPTH_POTENTIAL_MEM 2048
#define WIDTH_POTENTIAL_MEM 64

#define DEPTH_SPIKE_MEM 2048
#define WIDTH_SPIKE_MEM 32

#define DEPTH_OUTPUT_MEM 1024
#define WIDTH_OUTPUT_MEM 64


//memory type
#define _potential_mem ap_int<WIDTH_POTENTIAL_MEM>
#define _weight_mem ap_int<WIDTH_WEIGHT_MEM>
#define _spike_mem ap_uint<WIDTH_SPIKE_MEM>
#define _instr_mem ap_uint<WIDTH_INSTR_MEM>
#define _output_mem ap_uint<WIDTH_OUTPUT_MEM>


//memory pointer
#define WIDTH_SPIKE_MEM_IDX 12
#define WIDTH_INSTR_MEM_IDX 12
#define WIDTH_OUTPUT_MEM_IDX 12

#define _idx_spike_mem ap_uint<WIDTH_SPIKE_MEM_IDX>
#define _idx_instr_mem ap_uint<WIDTH_INSTR_MEM_IDX>
#define _idx_output_mem ap_uint<WIDTH_OUTPUT_MEM_IDX>


//time step register
#define WIDTH_TIME_STEP 6
#define _reg_timestep ap_uint<WIDTH_TIME_STEP>


//register file
#define DEPTH_REG_FILE 32
#define WIDTH_REG_FILE_IDX 5

#define _reg_32b ap_uint<32>
#define _reg_64b ap_uint<64>

#define _reg_32b_s ap_int<32>
#define _reg_64b_s ap_int<64>

#define _idx_reg_file ap_uint<WIDTH_REG_FILE_IDX>


//registers for specific usage
#define REG_ID_TIMESTEP 1
#define PEREG_ID_TIMESTEP 2


struct sMsgPkg{
	_opcode opcode;
	_bool flags;
    _bool flagp;
    _bool flagc;
    _bool flagi;
    _bool flagfh;
    _bool flagfl;
	_isa_reg_id rega;
	_isa_reg_id regb;
	_isa_reg_id regc;
	_isa_reg_id regd;
    _imm_16b imma;
    _imm_16b immb;
	_imm_sgs immbh;
	_imm_sgs immbl;
	_imm_sgs immch;
	_imm_sgs immcl;
	_reg_64b rcpvalue;
};

struct sRegFileWidePkg{
	_reg_64b RegFile[DEPTH_REG_FILE];
};

struct sSpikeMemPkg{
	_spike_mem SpikeMem[NUM_TOTAL_CLUSTER][DEPTH_SPIKE_MEM];
	_idx_spike_mem IdxSpikeMem[NUM_TOTAL_CLUSTER];
};

struct sOutputMemPkg{
	_output_mem OutputMem[DEPTH_OUTPUT_MEM];
	_idx_output_mem IdxOutputMem[1];
    _idx_output_mem IdxOutputMemLast[1];
};

struct sClstInputPkg{
	_instr_mem InstrMem[DEPTH_INSTR_MEM];
	_idx_instr_mem IdxInstrMem[1];  //IMPORTANT-SPECIFIC REG
    _reg_timestep TimeStep[1];    //IMPORTANT-SPECIFIC REG-REQUIRED TO BE ASSIGNED TO REGFILE
	_bool ClstDone[1];  //IMPORTANT-FLAG ONLY
    _bool ClstSync[1];  //IMPORTANT-FLAG ONLY
	ap_uint<4> ClstID;
};


struct sClstOutputPkg{

};


struct sPEInputPkg{
	ap_uint<4> ClstID;
    ap_uint<4> PEID;
    ap_uint<32> DDR_SEG_OFFSET;
    ap_uint<32> DDR_SEG_OFFSET_1;
    ap_uint<32> DDR_SEG_OFFSET_2;
};


#define MOV   0b00001
#define AND   0b00010
#define OR    0b00011
#define XOR   0b00100
#define LFT   0b00101
#define RFT   0b00110
#define SGS   0b00111
#define CCT   0b01000
#define ADD   0b01001
#define SUB   0b01010
#define MUL   0b01011
#define DVD   0b01100
#define MOD   0b01101
#define JE    0b01110
#define JG    0b01111
#define JL    0b10000
#define JMP   0b10001
#define RDI   0b10010
#define LDW   0b10011
#define WDW   0b10100
#define RWM   0b10101
#define RPM   0b10110
#define WBW   0b10111
#define WBP   0b11000
#define OPT   0b11001
#define SYN   0b11110
#define DONE  0b11111

#define RDS   0b11010


enum ALU_func{
	ALU_AND  = 0b0000,
	ALU_OR   = 0b0001,
	ALU_XOR  = 0b0010,

	ALU_ADD  = 0b0011,
    ALU_SUB  = 0b0100,
    ALU_MUL  = 0b0101,
	ALU_DVD  = 0b0110,
	ALU_MOD  = 0b0111,

    ALU_LFT  = 0b1000,
	ALU_RFT  = 0b1001,

    ALU_JE   = 0b1010,
    ALU_JN   = 0b1011,
    ALU_JG   = 0b1100,
    ALU_JNG  = 0b1101,
    ALU_JL   = 0b1110,
    ALU_JNL  = 0b1111
};


#define ALL_HIGH_64B 0xffffffffffffffff;
#define ALL_LOW_64B 0x0;
#define ALL_HIGH_32B 0xffffffff;
#define ALL_LOW_32B 0x0;

#endif
