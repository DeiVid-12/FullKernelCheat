#pragma once
#include "Defs.hpp"

extern "C"
NTSTATUS NTAPI MmCopyVirtualMemory
(
	PEPROCESS		SourceProcess,
	PVOID			SourceAddress,
	PEPROCESS		TargetProcess,
	PVOID			TargetAddress,
	SIZE_T			BufferSize,
	KPROCESSOR_MODE PreviousMode,
	PSIZE_T			ReturnSize
);

extern "C"
NTKERNELAPI PVOID PsGetProcessSectionBaseAddress
(
		PEPROCESS Process
);