#include <ntddk.h>
namespace Utils
{
	namespace Game
	{
		ULONG Pid{ 0 };
		PEPROCESS Process{ 0 };
		CHAR* ProcessName{ 0 };
		ULONGLONG BaseAddress{ 0 };
	}
}