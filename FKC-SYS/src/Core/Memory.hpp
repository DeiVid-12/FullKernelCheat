#pragma once
#include "../Utils/Defs.hpp"

namespace Core
{
	class Memory
	{
	public:
		NTSTATUS Read(ULONG ProcessId, PEPROCESS Process, PVOID SourceAddress, PVOID TargetAddress, SIZE_T Size);
		NTSTATUS Write(ULONG ProcessId, PEPROCESS Process, PVOID SourceAddress, PVOID TargetAddress, SIZE_T Size);
		NTSTATUS GetProcessByName(CHAR* ProcessName, PEPROCESS* Process);
	};
}