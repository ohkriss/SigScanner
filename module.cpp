#include "all.h"
#include "module.h"

namespace memory
{
	module::module(HMODULE mod) :
		range(mod, 0)
	{
		auto dos_header = m_base.as<IMAGE_DOS_HEADER*>();
		auto nt_header = m_base.add(dos_header->e_lfanew).as<IMAGE_NT_HEADERS*>();
		m_size = nt_header->OptionalHeader.SizeOfImage;
		m_mod_name = find_filename(mod);
	}

	module::module(std::nullptr_t) :
		module(GetModuleHandle(nullptr))
	{
	}

	module::module(std::string_view mod_name) :
		module(GetModuleHandleA(mod_name.data()))
	{	
	}

	module::module(std::wstring_view mod_name) :
		module(GetModuleHandleW(mod_name.data()))
	{
	}

	handle module::get_export(std::string_view symbol_name)
	{
		return GetProcAddress(m_base.as<HMODULE>(), symbol_name.data());
	}

	TCHAR* module::find_filename(HMODULE mod)
	{
		TCHAR buf[MAX_PATH] = { 0 };
		DWORD buf_size = sizeof(buf) / sizeof(*buf);
		GetModuleFileName(mod, buf, buf_size);
	    return PathFindFileName(buf);
	}
}
