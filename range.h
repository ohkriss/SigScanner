#pragma once

#include "all.h"
#include "fwddec.h"
#include "handle.h"

namespace memory
{
	class range
	{
	public:
		range(handle base, std::size_t sizem);

		handle begin();
		handle end();
		std::size_t size();
		TCHAR* mod_name();

		bool contains(handle h);

		[[nodiscard]] handle scan(pattern const& sig);
		[[nodiscard]] std::vector<handle> scan_all(pattern const& sig);
	protected:
		TCHAR* m_mod_name = nullptr;
		handle m_base;
		std::size_t m_size;
	};
}
