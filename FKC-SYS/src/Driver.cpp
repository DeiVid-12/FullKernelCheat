#include "Core/Thread.hpp"

extern "C" NTSTATUS DriverEntry(PDRIVER_OBJECT DriverObject, PUNICODE_STRING RegistryPath)
{
	UNREFERENCED_PARAMETER(DriverObject);
	UNREFERENCED_PARAMETER(RegistryPath);

	Utils::Log("Driver initialized1\r\n");

	HANDLE ThreadHandle{ nullptr };
	OBJECT_ATTRIBUTES ObjectAttributes{ };
	InitializeObjectAttributes(&ObjectAttributes, nullptr, OBJ_KERNEL_HANDLE, nullptr, nullptr);

	NTSTATUS Status{ PsCreateSystemThread(&ThreadHandle, 0, &ObjectAttributes, nullptr, nullptr, reinterpret_cast<PKSTART_ROUTINE>(&Core::Thread), nullptr) };

	return Status;
}