#pragma once
#include <Windows.h>
#include <vector>


namespace mem
{
	inline uint8_t* ac_base = nullptr;
	inline uint8_t* gl_base = nullptr;

	std::uint8_t* PatternScan(void* module, const char* signature);
	bool Init_Modules();

	template<typename t>
	t read(uintptr_t addr) {
		if (addr < 0xffffff)
			return t();
		if (addr > 0x7fffffff0000)
			return t();

		return *rc<t*>(addr);
	}
	template<typename t>
	bool write(uintptr_t addr, t buffer) {
		*rc<t*>(addr) = buffer;
		return true;
	}
}
