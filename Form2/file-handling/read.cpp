//need a function GUI to receive list of countries after read
//in that function user (like real life) user dropdown choose a country
//it then returns that country in string
#include <iostream>
#include <fstream>
#include <string>
#define FILE_PATH "../data/"

std::string* readCountry(const std::string& filename, int& size)
{
    std::string absfpath = FILE_PATH + filename;
    std::ifstream file(absfpath);
    if (!file)
    {
        std::cout << "Error opening file: " << absfpath << std::endl;
        return nullptr;
    }

    const int init_cap = 10;
    std::string* countryList = new std::string[init_cap];
    size = 0; // Number of countries
    int capacity = init_cap;

    std::string country;
    while (getline(file, country)) { // Read line by line
        // Check if we need to resize the array
        if (size >= capacity) {
            // Double the capacity
            capacity *= 2;
            std::string* newCountryList = new std::string[capacity]; // Allocate new array
            for (int i = 0; i < size; ++i) {
                newCountryList[i] = countryList[i]; // Copy old data
            }
            delete[] countryList; // Free old array
            countryList = newCountryList; // Point to new array
        }
        countryList[size++] = country; // Add country to the array
    }

    return countryList;
}
