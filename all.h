#pragma once

#include <iostream>
#include <Windows.h>
#include <Shlwapi.h>
#include <vector>
#include <string>
#include <string_view>
#include <functional>
#include <vector>
#include <cstddef>
#include <cstdint>
#include <type_traits>
#include <optional>
#include <stdexcept>

#pragma comment(lib, "Shlwapi.lib")

#define HEX_TO_UPPER(value) "0x" << std::hex << std::uppercase << (DWORD64)value << std::dec << std::nouppercase