#pragma once

#include "all.h"
#include "pattern.h"

namespace memory
{
	class pattern_batch
	{
	public:
		explicit pattern_batch() = default;
		~pattern_batch() noexcept = default;

		void add(std::string name, pattern pattern, std::function<void(memory::handle)> callback);
		void run(range region, bool report_found = true);

		struct entry
		{
			std::string m_name;
			pattern m_pattern;
			std::function<void(memory::handle)> m_callback;

			explicit entry(std::string name, pattern pattern, std::function<void(memory::handle)> callback) :
				m_name(name),
				m_pattern(pattern),
				m_callback(callback)
			{}
		};

	private:
		std::vector<entry> m_entries;
	};
}
