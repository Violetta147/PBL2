#include "ImageHelper.h"

Image^ ImageHelper::GetImageResource(String^ resourceName)
{
    // Define the base directory where resources are located (you can adjust this to your needs)
    String^ baseDirectory = "Resources//";

    // Construct the image file path
    String^ imagePath = baseDirectory + resourceName + ".png";

    try
    {
        // Check if the file exists before loading it
        if (System::IO::File::Exists(imagePath))
        {
            // Read the image into memory
            array<Byte>^ imageBytes = System::IO::File::ReadAllBytes(imagePath);

            // Create a MemoryStream from the byte array
            System::IO::MemoryStream^ memoryStream = gcnew System::IO::MemoryStream(imageBytes);

            // Return the image loaded from memory
            return System::Drawing::Image::FromStream(memoryStream);
        }
        else
        {
            Console::WriteLine("Image file not found: " + imagePath);
            return nullptr; // Or return a default image
        }
    }
    catch (Exception^ ex)
    {
        // Handle any exceptions, such as invalid image format or IO errors
        Console::WriteLine("Error loading image: " + ex->Message);
        return nullptr; // Or return a default image
    }
}