#include "Thread.hpp"
#include "../Utils/NTStructs.hpp"
#include "../Utils/Game.hpp"

void Core::Thread(void* Context)
{
	Memory* memory{};
	Utils::Sleep(6000);

	while (memory->GetProcessByName(Utils::Game::ProcessName, &Utils::Game::Process) == STATUS_NOT_FOUND)
	{
		Utils::Log("Please start %s\r\n", Utils::Game::ProcessName);
		Utils::Sleep(2000);
	}
	Utils::Log("Found %s\r\n", Utils::Game::ProcessName);
	Utils::Sleep(16000);

	memory->GetProcessByName(Utils::Game::ProcessName, &Utils::Game::Process);
	Utils::Game::Pid = reinterpret_cast<uint32>(PsGetProcessId(Utils::Game::Process));

	Utils::Log("ProcessId -> %i", Utils::Game::Pid);
	Utils::Game::BaseAddress = reinterpret_cast <uint64>(PsGetProcessSectionBaseAddress(Utils::Game::Process));

	while (true)
	{
		// Cheat functions here
	}
	PsTerminateSystemThread(STATUS_SUCCESS);
}
