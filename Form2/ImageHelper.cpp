#include "ImageHelper.h"

Image^ ImageHelper::GetImageResource(String^ resourceName)
{
	System::Reflection::Assembly^ assembly = System::Reflection::Assembly::GetExecutingAssembly();
	System::Resources::ResourceManager^ rm = gcnew System::Resources::ResourceManager("Form2.MyResource", assembly);
	System::Object^ resource = rm->GetObject(resourceName);
	if (resource == nullptr)
	{
		Console::WriteLine("Resource not found: " + resourceName);
	}
	if (resource->GetType() == array<Byte>::typeid)
	{
		array<Byte>^ bytes = (array<Byte>^)resource;
		System::IO::MemoryStream^ ms = gcnew System::IO::MemoryStream(bytes);
		return Image::FromStream(ms);
	}
	return (Image^)resource;
}