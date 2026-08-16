#include <Windows.h>
#include <thread>
#include "src/core/hooks/hooks.h"

void Agyzak(HMODULE hModule)
{
	AllocConsole();
	FILE* f = nullptr;
	freopen_s(&f, "CONOUT$", "w", stdout);

	hooks::Init();

	while (!(GetAsyncKeyState(VK_END) & 0x8000))
		std::this_thread::sleep_for(std::chrono::milliseconds(50));

	hooks::Release();

	std::this_thread::sleep_for(std::chrono::milliseconds(1500));
	if (f) fclose(f);
	FreeConsole();
	FreeLibraryAndExitThread(hModule, 0);
}

int __stdcall DllMain(HMODULE hModule, DWORD reson, LPVOID lpReserved)
{
	if (reson == 1)
	{
		DisableThreadLibraryCalls(hModule);
		HANDLE hThread = CreateThread(nullptr, NULL, (LPTHREAD_START_ROUTINE)Agyzak, hModule, NULL, nullptr);
		if (hThread)
			CloseHandle(hThread);
	}
	return TRUE;
}