// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.2 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
// BUS_A
// 0x00 : Control signals
//        bit 0  - ap_start (Read/Write/COH)
//        bit 1  - ap_done (Read/COR)
//        bit 2  - ap_idle (Read)
//        bit 3  - ap_ready (Read)
//        bit 7  - auto_restart (Read/Write)
//        others - reserved
// 0x04 : Global Interrupt Enable Register
//        bit 0  - Global Interrupt Enable (Read/Write)
//        others - reserved
// 0x08 : IP Interrupt Enable Register (Read/Write)
//        bit 0  - Channel 0 (ap_done)
//        bit 1  - Channel 1 (ap_ready)
//        others - reserved
// 0x0c : IP Interrupt Status Register (Read/TOW)
//        bit 0  - Channel 0 (ap_done)
//        bit 1  - Channel 1 (ap_ready)
//        others - reserved
// 0x10 : Data signal of ap_return
//        bit 31~0 - ap_return[31:0] (Read)
// 0x18 : Data signal of idx_ret
//        bit 31~0 - idx_ret[31:0] (Read/Write)
// 0x1c : reserved
// 0x20 : Data signal of testreg1
//        bit 31~0 - testreg1[31:0] (Read/Write)
// 0x24 : reserved
// 0x28 : Data signal of testreg2
//        bit 31~0 - testreg2[31:0] (Read/Write)
// 0x2c : reserved
// 0x30 : Data signal of in_mem_offset_0
//        bit 31~0 - in_mem_offset_0[31:0] (Read/Write)
// 0x34 : reserved
// 0x38 : Data signal of in_mem_length_0
//        bit 31~0 - in_mem_length_0[31:0] (Read/Write)
// 0x3c : reserved
// 0x40 : Data signal of clsf_result_0
//        bit 31~0 - clsf_result_0[31:0] (Read/Write)
// 0x44 : reserved
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#define XSNNACC_BUS_A_ADDR_AP_CTRL              0x00
#define XSNNACC_BUS_A_ADDR_GIE                  0x04
#define XSNNACC_BUS_A_ADDR_IER                  0x08
#define XSNNACC_BUS_A_ADDR_ISR                  0x0c
#define XSNNACC_BUS_A_ADDR_AP_RETURN            0x10
#define XSNNACC_BUS_A_BITS_AP_RETURN            32
#define XSNNACC_BUS_A_ADDR_IDX_RET_DATA         0x18
#define XSNNACC_BUS_A_BITS_IDX_RET_DATA         32
#define XSNNACC_BUS_A_ADDR_TESTREG1_DATA        0x20
#define XSNNACC_BUS_A_BITS_TESTREG1_DATA        32
#define XSNNACC_BUS_A_ADDR_TESTREG2_DATA        0x28
#define XSNNACC_BUS_A_BITS_TESTREG2_DATA        32
#define XSNNACC_BUS_A_ADDR_IN_MEM_OFFSET_0_DATA 0x30
#define XSNNACC_BUS_A_BITS_IN_MEM_OFFSET_0_DATA 32
#define XSNNACC_BUS_A_ADDR_IN_MEM_LENGTH_0_DATA 0x38
#define XSNNACC_BUS_A_BITS_IN_MEM_LENGTH_0_DATA 32
#define XSNNACC_BUS_A_ADDR_CLSF_RESULT_0_DATA   0x40
#define XSNNACC_BUS_A_BITS_CLSF_RESULT_0_DATA   32

