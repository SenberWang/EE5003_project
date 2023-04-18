// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.2 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xsnnacc.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XSnnacc_CfgInitialize(XSnnacc *InstancePtr, XSnnacc_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Bus_a_BaseAddress = ConfigPtr->Bus_a_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XSnnacc_Start(XSnnacc *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSnnacc_ReadReg(InstancePtr->Bus_a_BaseAddress, XSNNACC_BUS_A_ADDR_AP_CTRL) & 0x80;
    XSnnacc_WriteReg(InstancePtr->Bus_a_BaseAddress, XSNNACC_BUS_A_ADDR_AP_CTRL, Data | 0x01);
}

u32 XSnnacc_IsDone(XSnnacc *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSnnacc_ReadReg(InstancePtr->Bus_a_BaseAddress, XSNNACC_BUS_A_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XSnnacc_IsIdle(XSnnacc *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSnnacc_ReadReg(InstancePtr->Bus_a_BaseAddress, XSNNACC_BUS_A_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XSnnacc_IsReady(XSnnacc *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSnnacc_ReadReg(InstancePtr->Bus_a_BaseAddress, XSNNACC_BUS_A_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XSnnacc_EnableAutoRestart(XSnnacc *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSnnacc_WriteReg(InstancePtr->Bus_a_BaseAddress, XSNNACC_BUS_A_ADDR_AP_CTRL, 0x80);
}

void XSnnacc_DisableAutoRestart(XSnnacc *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSnnacc_WriteReg(InstancePtr->Bus_a_BaseAddress, XSNNACC_BUS_A_ADDR_AP_CTRL, 0);
}

u32 XSnnacc_Get_return(XSnnacc *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSnnacc_ReadReg(InstancePtr->Bus_a_BaseAddress, XSNNACC_BUS_A_ADDR_AP_RETURN);
    return Data;
}
void XSnnacc_Set_image_base_addr(XSnnacc *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSnnacc_WriteReg(InstancePtr->Bus_a_BaseAddress, XSNNACC_BUS_A_ADDR_IMAGE_BASE_ADDR_DATA, Data);
}

u32 XSnnacc_Get_image_base_addr(XSnnacc *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSnnacc_ReadReg(InstancePtr->Bus_a_BaseAddress, XSNNACC_BUS_A_ADDR_IMAGE_BASE_ADDR_DATA);
    return Data;
}

void XSnnacc_Set_image_length(XSnnacc *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSnnacc_WriteReg(InstancePtr->Bus_a_BaseAddress, XSNNACC_BUS_A_ADDR_IMAGE_LENGTH_DATA, Data);
}

u32 XSnnacc_Get_image_length(XSnnacc *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSnnacc_ReadReg(InstancePtr->Bus_a_BaseAddress, XSNNACC_BUS_A_ADDR_IMAGE_LENGTH_DATA);
    return Data;
}

void XSnnacc_Set_weight_base_addr(XSnnacc *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSnnacc_WriteReg(InstancePtr->Bus_a_BaseAddress, XSNNACC_BUS_A_ADDR_WEIGHT_BASE_ADDR_DATA, Data);
}

u32 XSnnacc_Get_weight_base_addr(XSnnacc *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSnnacc_ReadReg(InstancePtr->Bus_a_BaseAddress, XSNNACC_BUS_A_ADDR_WEIGHT_BASE_ADDR_DATA);
    return Data;
}

void XSnnacc_Set_idx_img(XSnnacc *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSnnacc_WriteReg(InstancePtr->Bus_a_BaseAddress, XSNNACC_BUS_A_ADDR_IDX_IMG_DATA, Data);
}

u32 XSnnacc_Get_idx_img(XSnnacc *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSnnacc_ReadReg(InstancePtr->Bus_a_BaseAddress, XSNNACC_BUS_A_ADDR_IDX_IMG_DATA);
    return Data;
}

void XSnnacc_InterruptGlobalEnable(XSnnacc *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSnnacc_WriteReg(InstancePtr->Bus_a_BaseAddress, XSNNACC_BUS_A_ADDR_GIE, 1);
}

void XSnnacc_InterruptGlobalDisable(XSnnacc *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSnnacc_WriteReg(InstancePtr->Bus_a_BaseAddress, XSNNACC_BUS_A_ADDR_GIE, 0);
}

void XSnnacc_InterruptEnable(XSnnacc *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XSnnacc_ReadReg(InstancePtr->Bus_a_BaseAddress, XSNNACC_BUS_A_ADDR_IER);
    XSnnacc_WriteReg(InstancePtr->Bus_a_BaseAddress, XSNNACC_BUS_A_ADDR_IER, Register | Mask);
}

void XSnnacc_InterruptDisable(XSnnacc *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XSnnacc_ReadReg(InstancePtr->Bus_a_BaseAddress, XSNNACC_BUS_A_ADDR_IER);
    XSnnacc_WriteReg(InstancePtr->Bus_a_BaseAddress, XSNNACC_BUS_A_ADDR_IER, Register & (~Mask));
}

void XSnnacc_InterruptClear(XSnnacc *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSnnacc_WriteReg(InstancePtr->Bus_a_BaseAddress, XSNNACC_BUS_A_ADDR_ISR, Mask);
}

u32 XSnnacc_InterruptGetEnabled(XSnnacc *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XSnnacc_ReadReg(InstancePtr->Bus_a_BaseAddress, XSNNACC_BUS_A_ADDR_IER);
}

u32 XSnnacc_InterruptGetStatus(XSnnacc *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XSnnacc_ReadReg(InstancePtr->Bus_a_BaseAddress, XSNNACC_BUS_A_ADDR_ISR);
}

