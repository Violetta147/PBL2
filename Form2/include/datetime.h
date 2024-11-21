#ifndef DATETIME_H
#define DATETIME_H

#include <ctime>
#include <iomanip>
#include <sstream>
#include <string>
#include <iostream>
#include <stdexcept>
#include <limits>

bool isvalid(const std::string& date);
bool valid_Date(const std::string& date);
std::time_t timestamp(const std::string& date);
bool choose_Date(std::string &Date1, std::string &Date2);
bool is_Exist_Date();
std::string timeToString(const std::time_t& time);
std::string getFormattedDate(const std::time_t& time);
std::string getFormattedTime(const std::time_t& time);
int compareDates(const std::string& date1, const std::string& date2);
int compareTimes(const std::string& time1, const std::string& time2);

#endif
