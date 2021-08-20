# SigScanner
 Windows internal signature scanner

Example
```cpp
#include "../SigScanner/SigScanner/sig_scanner.h"
#include "pointers.h"

pointers::pointers()
{
    memory::pattern_batch main_batch;

    main_batch.add("Is session running", "74 ? 83 3D 30 50 9D 00", [this](memory::handle ptr)
        {
            m_is_session_running = ptr.add(2).as<bool*>();
        });
    main_batch.run(memory::module(nullptr));
}
```

You can also add patterns like this
```cpp
main_batch.add("Is session running", ("\x74\x00\x83\x3D\x30\x50\x9D\x00", "x?xxxxxx"), [this](memory::handle ptr)
        {
            m_is_session_running = ptr.add(2).as<bool*>();
        });
```
