#include "../include/datetime.h"

#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <ctime>
#include <limits>

// Exception class for date validation errors
class DateValidationException : public std::runtime_error {
public:
    explicit DateValidationException(const std::string& message)
        : std::runtime_error(message) {}
};

// Function to validate the date and time in dd-mm-yyyy or dd-mm-yyyy hh:mm format
bool valid_Date(const std::string& date) {
    std::tm time = {};
    std::istringstream ss(date);

    // Attempt to parse with time and fallback to date-only
    ss >> std::get_time(&time, "%d-%m-%Y %H:%M");
    bool hasTime = !ss.fail();
    if (!hasTime) { // Fallback to date-only format if time parsing failed
        ss.clear();
        ss.str(date);
        ss >> std::get_time(&time, "%d-%m-%Y");
        if (ss.fail()) {
            throw DateValidationException("Failed to parse date: incorrect format.");
        }
    }

    // Check for date range
    if (time.tm_year + 1900 < 1924 || time.tm_year + 1900 > 2144) {
        throw DateValidationException("Date out of acceptable range (1924-2144).");
    }

    // Check for valid month
    if (time.tm_mon < 0 || time.tm_mon > 11) {
        throw DateValidationException("Month value out of range (must be between 1 and 12).");
    }

    // Leap year check and day validity
    bool isLeapYear = ((time.tm_year + 1900) % 4 == 0 && (time.tm_year + 1900) % 100 != 0) || ((time.tm_year + 1900) % 400 == 0);
    int daysInMonth[] = {31, (isLeapYear ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (time.tm_mday < 1 || time.tm_mday > daysInMonth[time.tm_mon]) {
        throw DateValidationException("Day value out of range for the given month.");
    }

    // If time is included, validate hours and minutes
    if (hasTime) {
        if (time.tm_hour < 0 || time.tm_hour > 23) {
            throw DateValidationException("Hour value out of range (must be between 0 and 23).");
        }
        if (time.tm_min < 0 || time.tm_min > 59) {
            throw DateValidationException("Minute value out of range (must be between 0 and 59).");
        }
    }

    return true; // All checks passed
}

// Function to validate the overall format and content of the date string
bool isvalid(const std::string& date) {
    std::string errorMessages;

    // Check format and ":" if present
    if ((date.size() != 10 && date.size() != 16) || date[2] != '-' || date[5] != '-' || (date.size() == 16 && date[13] != ':')) {
        errorMessages += "Date must be in format dd-mm-YYYY or dd-mm-YYYY HH:MM.\n";
    }

    // Check for invalid characters
    for (int i = 0; i < date.size(); i++) {
        if ((i != 2 && i != 5 && i != 13) && !isdigit(date[i])) {
            errorMessages += "Date contains invalid characters.\n";
        }
    }

    // Now call valid_Date and catch its exceptions
    try {
        valid_Date(date);
    } catch (const DateValidationException& e) {
        errorMessages += e.what(); // Append the error message
    }

    // If there were any error messages, throw an exception with all messages
    if (!errorMessages.empty()) {
        throw DateValidationException(errorMessages);
    }

    return true; // If all validations passed
}

// Function to convert date string to timestamp
std::time_t timestamp(const std::string& date) {
    try {
        isvalid(date);
    } catch (const DateValidationException& e) {
        std::cerr << "Validation Error: " << e.what() << std::endl;
        throw; // Re-throw or handle as needed
    }

    std::tm time = {};
    std::istringstream ss(date);

    if (date.size() == 16) {
        ss >> std::get_time(&time, "%d-%m-%Y %H:%M");
    } else {
        ss >> std::get_time(&time, "%d-%m-%Y");
    }

    // Adjust the month and year for mktime
    time.tm_mon -= 1; // Adjust month
    time.tm_year -= 1900; // Adjust year

    return std::mktime(&time);
}

// Function to choose a starting and ending date, ensuring the end date is after the start
bool choose_Date(std::string &Date1, std::string &Date2) {
    std::tm time1 = {};
    std::tm time2 = {};

    // Get the starting date
    do {
        std::cout << "Starting Date (dd-mm-YYYY or dd-mm-YYYY HH:MM): ";
        std::cin >> Date1;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        try {
            isvalid(Date1);
        } catch (const DateValidationException &e) {
            std::cerr << e.what() << std::endl;
            Date1.clear();
        }

    } while (Date1.empty());

    std::istringstream ss1(Date1);
    if (Date1.size() == 16) {
        ss1 >> std::get_time(&time1, "%d-%m-%Y %H:%M");
    } else {
        ss1 >> std::get_time(&time1, "%d-%m-%Y");
    }
    time1.tm_mon -= 1;
    time1.tm_year -= 1900;

    // Get the ending date
    do {
        std::cout << "Ending Date (dd-mm-YYYY or dd-mm-YYYY HH:MM): ";
        std::cin >> Date2;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        try {
            isvalid(Date2);
        } catch (const DateValidationException &e) {
            std::cerr << e.what() << std::endl;
            Date2.clear();
        }

    } while (Date2.empty());

    std::istringstream ss2(Date2);
    if (Date2.size() == 16) {
        ss2 >> std::get_time(&time2, "%d-%m-%Y %H:%M");
    } else {
        ss2 >> std::get_time(&time2, "%d-%m-%Y");
    }
    time2.tm_mon -= 1;
    time2.tm_year -= 1900;

    // Ensure that the start date is before or equal to the end date
    return std::mktime(&time1) <= std::mktime(&time2);
}

std::string timeToString(const std::time_t& time) {
    char* dt = std::ctime(&time);
    std::string timeStr(dt);
    if (!timeStr.empty() && timeStr.back() == '\n') {
        timeStr.pop_back();
    }
    return timeStr;
}

std::string getFormattedDate(const std::time_t& time) {
    std::tm* tm_info = std::localtime(&time);  // Chuyển time_t thành struct tm

    std::ostringstream oss;
    oss << std::put_time(tm_info, "%d-%m-%Y");  // Định dạng thành dd-mm-yyyy
    return oss.str();
}

std::string getFormattedTime(const std::time_t& time) {
    std::tm* tm_info = std::localtime(&time);  // Chuyển time_t thành struct tm

    std::ostringstream oss;
    oss << std::put_time(tm_info, "%H:%M");  // Định dạng thành hh:mm
    return oss.str();
}

int compareDates(const std::string& date1, const std::string& date2) {
    int year1 = std::stoi(date1.substr(6, 4));
    int month1 = std::stoi(date1.substr(3, 2));
    int day1 = std::stoi(date1.substr(0, 2));

    int year2 = std::stoi(date2.substr(6, 4));
    int month2 = std::stoi(date2.substr(3, 2));
    int day2 = std::stoi(date2.substr(0, 2));

    if (year1 != year2) return (year1 < year2) ? -1 : 1;
    if (month1 != month2) return (month1 < month2) ? -1 : 1;
    if (day1 != day2) return (day1 < day2) ? -1 : 1;

    return 0;
}

int compareTimes(const std::string& time1, const std::string& time2) {
    int hour1 = std::stoi(time1.substr(0, 2));
    int minute1 = std::stoi(time1.substr(3, 2));

    int hour2 = std::stoi(time2.substr(0, 2));
    int minute2 = std::stoi(time2.substr(3, 2));

    if (hour1 != hour2) return (hour1 < hour2) ? -1 : 1;
    if (minute1 != minute2) return (minute1 < minute2) ? -1 : 1;

    return 0;
}

