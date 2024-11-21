#ifndef HUMAN_H
#define HUMAN_H

#include <string>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <iostream>

class Human {
    protected:
        std::string human_id;
        std::string first_name;
        std::string last_name;
        std::string country;
        std::string birth;
        int height;
        int weight;
    public:
        Human();
        Human(const std::string human_id, const std::string& first_name, const std::string& last_name, const std::string& country, const std::string& birth, int height, int weight);
        // Getter and setter for Id
        std::string get_Id() const;
        void set_Id(const std::string& Id);
        // Getter and setter for Name
        std::string get_Name() const;
        std::string get_last_name() const;
        std::string get_first_name() const;
        void set_first_name(const std::string& first_name);
        void set_last_name(const std::string& last_name);
        // Getter for Age
        int get_age() const;
        // Getter and setter for Height
        int get_height() const;
        void set_height(int height);
        // Getter and setter for Weight
        int get_weight() const;
        void set_weight(int weight);
        // Getter and setter for Country
        std::string get_nation() const;
        void set_nation(const std::string& nation);
        // Getter and setter for DOB
        std::string get_birth() const;
        void set_birth(const std::string& birth);
};

#endif
