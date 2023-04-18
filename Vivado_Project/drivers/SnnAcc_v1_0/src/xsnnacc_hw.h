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
// 0x18 : Data signal of image_base_addr
//        bit 31~0 - image_base_addr[31:0] (Read/Write)
// 0x1c : reserved
// 0x20 : Data signal of image_length
//        bit 31~0 - image_length[31:0] (Read/Write)
// 0x24 : reserved
// 0x28 : Data signal of weight_base_addr
//        bit 31~0 - weight_base_addr[31:0] (Read/Write)
// 0x2c : reserved
// 0x30 : Data signal of idx_img
//        bit 31~0 - idx_img[31:0] (Read/Write)
// 0x34 : reserved
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#define XSNNACC_BUS_A_ADDR_AP_CTRL               0x00
#define XSNNACC_BUS_A_ADDR_GIE                   0x04
#define XSNNACC_BUS_A_ADDR_IER                   0x08
#define XSNNACC_BUS_A_ADDR_ISR                   0x0c
#define XSNNACC_BUS_A_ADDR_AP_RETURN             0x10
#define XSNNACC_BUS_A_BITS_AP_RETURN             32
#define XSNNACC_BUS_A_ADDR_IMAGE_BASE_ADDR_DATA  0x18
#define XSNNACC_BUS_A_BITS_IMAGE_BASE_ADDR_DATA  32
#define XSNNACC_BUS_A_ADDR_IMAGE_LENGTH_DATA     0x20
#define XSNNACC_BUS_A_BITS_IMAGE_LENGTH_DATA     32
#define XSNNACC_BUS_A_ADDR_WEIGHT_BASE_ADDR_DATA 0x28
#define XSNNACC_BUS_A_BITS_WEIGHT_BASE_ADDR_DATA 32
#define XSNNACC_BUS_A_ADDR_IDX_IMG_DATA          0x30
#define XSNNACC_BUS_A_BITS_IDX_IMG_DATA          32

