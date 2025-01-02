#pragma once
#include <string>
using namespace System;
class Ultility
{
public: static void StringToStlString(System::String^ s, std::string& os)
{
    if (s == nullptr)
    {
        os.clear();
        return;
    }

    using namespace System::Runtime::InteropServices;

    // Convert to UTF-8 encoded unmanaged string
    IntPtr pUtf8 = Marshal::StringToHGlobalAnsi(s);
    try
    {
        const char* chars = static_cast<const char*>(pUtf8.ToPointer());
        os = chars; // Assign to std::string
    }
    finally
    {
        // Free unmanaged memory
        Marshal::FreeHGlobal(pUtf8);
    }
}
};
