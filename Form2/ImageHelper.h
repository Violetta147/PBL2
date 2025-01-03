#pragma once
#include <cliext/map>
#include <cliext/vector>

using namespace System;
using namespace System::Drawing;
using namespace System::Resources;
using namespace System::Reflection;
using namespace System::Drawing::Imaging;
using namespace cliext;
using namespace System::Collections::Generic;
public ref class ImageHelper abstract sealed
{
public:
	static Image^ GetImageResource(String^ resourceName);
	static Color^ GetDominantColor(String^ imagePath);
	static Color^ GetContrastingColor(Color^ color);
	static Color^ LightenColor(Color^ color, float factor);
	
};
