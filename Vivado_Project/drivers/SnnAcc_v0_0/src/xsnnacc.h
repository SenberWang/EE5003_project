// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.2 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XSNNACC_H
#define XSNNACC_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xsnnacc_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#else
typedef struct {
    u16 DeviceId;
    u32 Bus_a_BaseAddress;
} XSnnacc_Config;
#endif

typedef struct {
    u32 Bus_a_BaseAddress;
    u32 IsReady;
} XSnnacc;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XSnnacc_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XSnnacc_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XSnnacc_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XSnnacc_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XSnnacc_Initialize(XSnnacc *InstancePtr, u16 DeviceId);
XSnnacc_Config* XSnnacc_LookupConfig(u16 DeviceId);
int XSnnacc_CfgInitialize(XSnnacc *InstancePtr, XSnnacc_Config *ConfigPtr);
#else
int XSnnacc_Initialize(XSnnacc *InstancePtr, const char* InstanceName);
int XSnnacc_Release(XSnnacc *InstancePtr);
#endif

void XSnnacc_Start(XSnnacc *InstancePtr);
u32 XSnnacc_IsDone(XSnnacc *InstancePtr);
u32 XSnnacc_IsIdle(XSnnacc *InstancePtr);
u32 XSnnacc_IsReady(XSnnacc *InstancePtr);
void XSnnacc_EnableAutoRestart(XSnnacc *InstancePtr);
void XSnnacc_DisableAutoRestart(XSnnacc *InstancePtr);
u32 XSnnacc_Get_return(XSnnacc *InstancePtr);

void XSnnacc_Set_idx_ret(XSnnacc *InstancePtr, u32 Data);
u32 XSnnacc_Get_idx_ret(XSnnacc *InstancePtr);
void XSnnacc_Set_testreg1(XSnnacc *InstancePtr, u32 Data);
u32 XSnnacc_Get_testreg1(XSnnacc *InstancePtr);
void XSnnacc_Set_testreg2(XSnnacc *InstancePtr, u32 Data);
u32 XSnnacc_Get_testreg2(XSnnacc *InstancePtr);
void XSnnacc_Set_in_mem_offset_0(XSnnacc *InstancePtr, u32 Data);
u32 XSnnacc_Get_in_mem_offset_0(XSnnacc *InstancePtr);
void XSnnacc_Set_in_mem_length_0(XSnnacc *InstancePtr, u32 Data);
u32 XSnnacc_Get_in_mem_length_0(XSnnacc *InstancePtr);
void XSnnacc_Set_clsf_result_0(XSnnacc *InstancePtr, u32 Data);
u32 XSnnacc_Get_clsf_result_0(XSnnacc *InstancePtr);

void XSnnacc_InterruptGlobalEnable(XSnnacc *InstancePtr);
void XSnnacc_InterruptGlobalDisable(XSnnacc *InstancePtr);
void XSnnacc_InterruptEnable(XSnnacc *InstancePtr, u32 Mask);
void XSnnacc_InterruptDisable(XSnnacc *InstancePtr, u32 Mask);
void XSnnacc_InterruptClear(XSnnacc *InstancePtr, u32 Mask);
u32 XSnnacc_InterruptGetEnabled(XSnnacc *InstancePtr);
u32 XSnnacc_InterruptGetStatus(XSnnacc *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
