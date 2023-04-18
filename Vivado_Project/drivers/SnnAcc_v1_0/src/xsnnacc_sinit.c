// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.2 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xsnnacc.h"

extern XSnnacc_Config XSnnacc_ConfigTable[];

XSnnacc_Config *XSnnacc_LookupConfig(u16 DeviceId) {
	XSnnacc_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XSNNACC_NUM_INSTANCES; Index++) {
		if (XSnnacc_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XSnnacc_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XSnnacc_Initialize(XSnnacc *InstancePtr, u16 DeviceId) {
	XSnnacc_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XSnnacc_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XSnnacc_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

