#include "Memory.hpp"
#include "../Utils/NTStructs.hpp"

NTSTATUS Core::Memory::Read(ULONG ProcessId, PEPROCESS Process, PVOID SourceAddress, PVOID TargetAddress, SIZE_T Size)
{
	SIZE_T Bytes{ 0 };
	NTSTATUS Status{ MmCopyVirtualMemory(Process, SourceAddress, PsGetCurrentProcess(), TargetAddress, Size, KernelMode, &Bytes) };

	if (!NT_SUCCESS(Status))
		return STATUS_UNSUCCESSFUL;

	return STATUS_SUCCESS;
}

NTSTATUS Core::Memory::Write(ULONG ProcessId, PEPROCESS Process, PVOID SourceAddress, PVOID TargetAddress, SIZE_T Size)
{
	SIZE_T Bytes{ 0 };
	NTSTATUS Status{ MmCopyVirtualMemory(PsGetCurrentProcess(), SourceAddress, Process, TargetAddress, Size, KernelMode, &Bytes) };

	if (!NT_SUCCESS(Status))
		return STATUS_UNSUCCESSFUL;

	return STATUS_SUCCESS;
}

NTSTATUS Core::Memory::GetProcessByName(CHAR* ProcessName, PEPROCESS* Process)
{
    PEPROCESS SysProcess = PsInitialSystemProcess;
    PEPROCESS CurEntry = SysProcess;
    CHAR ImageName[15];

    do
    {
        RtlCopyMemory((PVOID)(&ImageName), (PVOID)((uintptr_t)CurEntry + 0x450) /*EPROCESS->ImageFileName*/, sizeof(ImageName));

        if (strstr(ImageName, ProcessName))
        {
            ULONG ActiveThreads;
            RtlCopyMemory((PVOID)&ActiveThreads, (PVOID)((uintptr_t)CurEntry + 0x498) /*EPROCESS->ActiveThreads*/, sizeof(ActiveThreads));
            if (ActiveThreads)
            {
                *Process = CurEntry;
                return STATUS_SUCCESS;
            }
        }

        PLIST_ENTRY list = (PLIST_ENTRY)((uintptr_t)(CurEntry)+0x2F0);
        CurEntry = (PEPROCESS)((uintptr_t)list->Flink - 0x2F0);

    } while (CurEntry != SysProcess);

    return STATUS_NOT_FOUND;
}