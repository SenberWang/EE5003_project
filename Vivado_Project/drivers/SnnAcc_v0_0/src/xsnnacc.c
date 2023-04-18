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
void XSnnacc_Set_idx_ret(XSnnacc *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSnnacc_WriteReg(InstancePtr->Bus_a_BaseAddress, XSNNACC_BUS_A_ADDR_IDX_RET_DATA, Data);
}

u32 XSnnacc_Get_idx_ret(XSnnacc *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSnnacc_ReadReg(InstancePtr->Bus_a_BaseAddress, XSNNACC_BUS_A_ADDR_IDX_RET_DATA);
    return Data;
}

void XSnnacc_Set_testreg1(XSnnacc *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSnnacc_WriteReg(InstancePtr->Bus_a_BaseAddress, XSNNACC_BUS_A_ADDR_TESTREG1_DATA, Data);
}

u32 XSnnacc_Get_testreg1(XSnnacc *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSnnacc_ReadReg(InstancePtr->Bus_a_BaseAddress, XSNNACC_BUS_A_ADDR_TESTREG1_DATA);
    return Data;
}

void XSnnacc_Set_testreg2(XSnnacc *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSnnacc_WriteReg(InstancePtr->Bus_a_BaseAddress, XSNNACC_BUS_A_ADDR_TESTREG2_DATA, Data);
}

u32 XSnnacc_Get_testreg2(XSnnacc *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSnnacc_ReadReg(InstancePtr->Bus_a_BaseAddress, XSNNACC_BUS_A_ADDR_TESTREG2_DATA);
    return Data;
}

void XSnnacc_Set_in_mem_offset_0(XSnnacc *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSnnacc_WriteReg(InstancePtr->Bus_a_BaseAddress, XSNNACC_BUS_A_ADDR_IN_MEM_OFFSET_0_DATA, Data);
}

u32 XSnnacc_Get_in_mem_offset_0(XSnnacc *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSnnacc_ReadReg(InstancePtr->Bus_a_BaseAddress, XSNNACC_BUS_A_ADDR_IN_MEM_OFFSET_0_DATA);
    return Data;
}

void XSnnacc_Set_in_mem_length_0(XSnnacc *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSnnacc_WriteReg(InstancePtr->Bus_a_BaseAddress, XSNNACC_BUS_A_ADDR_IN_MEM_LENGTH_0_DATA, Data);
}

u32 XSnnacc_Get_in_mem_length_0(XSnnacc *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSnnacc_ReadReg(InstancePtr->Bus_a_BaseAddress, XSNNACC_BUS_A_ADDR_IN_MEM_LENGTH_0_DATA);
    return Data;
}

void XSnnacc_Set_clsf_result_0(XSnnacc *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSnnacc_WriteReg(InstancePtr->Bus_a_BaseAddress, XSNNACC_BUS_A_ADDR_CLSF_RESULT_0_DATA, Data);
}

u32 XSnnacc_Get_clsf_result_0(XSnnacc *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSnnacc_ReadReg(InstancePtr->Bus_a_BaseAddress, XSNNACC_BUS_A_ADDR_CLSF_RESULT_0_DATA);
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

