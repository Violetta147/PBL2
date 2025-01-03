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
Color^ ImageHelper::GetDominantColor(String^ imagePath)
{
    try
    {   
        Console::WriteLine(imagePath);
        Bitmap^ bitmap = gcnew Bitmap(imagePath);
        Dictionary<Color, int>^ colorFrequency = gcnew Dictionary<Color, int>(); // To store the color frequencies
        int width = bitmap->Width;
        int height = bitmap->Height;

        // Lock bits for fast pixel processing
        Rectangle rect = Rectangle(0, 0, width, height);
        BitmapData^ bitmapData = bitmap->LockBits(rect, ImageLockMode::ReadOnly, PixelFormat::Format24bppRgb);

        // Access raw pixel data
        IntPtr ptr = bitmapData->Scan0;
        int stride = bitmapData->Stride;
        int bytes = Math::Abs(stride) * height;
        array<Byte>^ pixelData = gcnew array<Byte>(bytes);
        System::Runtime::InteropServices::Marshal::Copy(ptr, pixelData, 0, bytes);

        // Traverse pixels and count frequencies
        for (int y = 0; y < height; ++y)
        {
            for (int x = 0; x < width; ++x)
            {
                int index = y * stride + x * 3;
                Byte b = pixelData[index];
                Byte g = pixelData[index + 1];
                Byte r = pixelData[index + 2];

                Color color = Color::FromArgb(255, r, g, b);
                // Increment frequency
                if (!colorFrequency->ContainsKey(color))
                {
                    colorFrequency[color] = 1;
                }
                else
                {
                    colorFrequency[color]++;
                }
            }
        }

        // Unlock the bits
        bitmap->UnlockBits(bitmapData);

        // Find the most dominant color
        Color^ dominantColor;
        int maxFrequency = 0;
        for each (KeyValuePair<Color, int> ^ pair in colorFrequency)
        {
            if (pair->Value > maxFrequency)
            {
                maxFrequency = pair->Value;
                dominantColor = pair->Key;
            }
        }

        return dominantColor;
    }
    catch (Exception^ ex)
    {
        Console::WriteLine("Error: " + ex->Message);
        return Color::Black; // Return a default color on error
    }
}
Color^ ImageHelper::GetContrastingColor(Color^ color)
{
	// Calculate the luminance of the color
	double luminance = (0.299 * color->R + 0.587 * color->G + 0.114 * color->B) / 255.0;
	// Choose white or black depending on the luminance
	return luminance > 0.5 ? Color::Black : Color::White;
}
Color^ ImageHelper::LightenColor(Color^ color, float factor)
{
	int r = Math::Min((int)(color->R + (255 - color->R) * factor), 255);
	int g = Math::Min((int)(color->G + (255 - color->G) * factor), 255);
	int b = Math::Min((int)(color->B + (255 - color->B) * factor), 255);

	return Color::FromArgb(color->A, r, g, b);
}
