#pragma once

using namespace System;
using namespace System::Drawing;
using namespace System::Resources;
using namespace System::Reflection;
public ref class ImageHelper abstract sealed
{
public:
	static Image^ GetImageResource(String^ resourceName);
};
