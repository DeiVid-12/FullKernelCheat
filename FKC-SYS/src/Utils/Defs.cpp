#include "Defs.hpp"

void Utils::Log(PCCH format, ...)
{
	/*CHAR message[512];
	va_list _valist;
	va_start(_valist, format);
	const ULONG N = _vsnprintf_s(message, sizeof(message) - 1, format, _valist);
	message[N] = L'\0';

	vDbgPrintExWithPrefix("[FKC]", DPFLTR_IHVDRIVER_ID, DPFLTR_ERROR_LEVEL, message, _valist);

	va_end(_valist);*/
}

NTSTATUS Utils::Sleep(ULONGLONG milliseconds)
{
	LARGE_INTEGER delay;
	ULONG* split;

	milliseconds *= 1000000;

	milliseconds /= 100;

	milliseconds = -milliseconds;

	split = (ULONG*)&milliseconds;

	delay.LowPart = *split;

	split++;

	delay.HighPart = *split;


	KeDelayExecutionThread(KernelMode, 0, &delay);

	return STATUS_SUCCESS;
}
