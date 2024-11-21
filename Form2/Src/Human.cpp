#include "../include/Human.h"

Human::Human() {}
Human::Human(const std::string human_id, const std::string &first_name,
             const std::string &last_name, const std::string &country,
             const std::string &birth, int height, int weight)
    : human_id(human_id), first_name(first_name), last_name(last_name),
      country(country), birth(birth), height(height), weight(weight){}

// Getter and setter for Id
std::string Human::get_Id() const
{
    return human_id;
}

void Human::set_Id(const std::string &Id)
{
    human_id = Id;
}

// Getter and setter for Name
std::string Human::get_Name() const
{
    std::string s = first_name + " " + last_name;
    return s;
}

std::string Human::get_last_name() const
{
    return last_name;
}
std::string Human::get_first_name() const
{
    return first_name;
}

void Human::set_first_name(const std::string &first_name)
{
    this->first_name = first_name;
}

void Human::set_last_name(const std::string &last_name)
{
    this->last_name = last_name;
}

// Getter and setter for age
int Human::get_age() const
{
    std::tm birth = {}; // initialize a tm struct in ctime all 0
    std::istringstream ss(this->birth); // convert birth attribute into a istream + allow using string methods
    ss >> std::get_time(&birth, "%d-%m-%Y"); //transmit data from ss, get_time will slice this data into "dd-mm-yyyy" and assign to birth struct
    if (ss.fail())
    {
        std::cout << this->get_Name() << std::endl;
        throw std::invalid_argument("Invalid date format. Please use dd-mm-yyyy");
    }
    std::time_t now = std::time(nullptr); //calculate the time ELAPSED in secs since Jan, 1st, 1970
    std::tm *now_tm = std::localtime(&now); //create struct tm of local machine time (what time is it now?)
    int age = now_tm->tm_year - birth.tm_year; //year(now) - year(birth) = age
    //if NOT HAPPYBIRTHDAY means hasn't increased age in the same year
    if (now_tm->tm_mon < birth.tm_mon ||
        (now_tm->tm_mon == birth.tm_mon && now_tm->tm_mday < birth.tm_mday))
    {
        age--;
    }
    return age;
}

// Getter and setter for height
int Human::get_height() const
{
    return height;
}

void Human::set_height(int height)
{
    this->height = height;
}

// Getter and setter for weight
int Human::get_weight() const
{
    return weight;
}

void Human::set_weight(int weight)
{
    this->weight = weight;
}

// Getter and setter for country
std::string Human::get_nation() const
{
    return country;
}

void Human::set_nation(const std::string &nation)
{
    this->country = nation;
}

// Getter and setter for DOB
std::string Human::get_birth() const
{
    return birth;
}

void Human::set_birth(const std::string &birth)
{
    this->birth = birth;
}
