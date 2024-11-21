#ifndef COACH_H
#define COACH_H

#include <string>
#include <iostream>
#include "Human.h"
#include "../include/nlohmann/json.hpp"

using json = nlohmann::ordered_json;

class Team;

class Coach : public Human {
private:
    std::string coach_id;
    int team_id;
    const Team* team;
    int wins;
    int loses;
    int ties;
public:
    // Constructor
    Coach();
    Coach(const std::string& human_id, const std::string& first_name, const std::string& last_name, const std::string& country,
          const std::string& birth, int height, int weight, const std::string& coach_id, int team_id, int wins = 0, int loses = 0, int ties = 0);

    // Getter for id
    std::string get_id() const;

    // Setter for id
    void set_id(std::string coach_id);

    // Getter for team
    const Team* get_team() const;

    // Setter for team
    void set_team(const Team* team);

    // Getter for team_id
    int get_TId() const;

    // Setter for team_id
    void set_TId(int team_id);

    // Getter for match
    int get_match() const;

    // Getter for wins, loses, ties
    int get_wins() const;
    int get_loses() const;
    int get_ties() const;

    // Upter, setter for wins, loses, ties
    void up_wins();
    void up_loses();
    void up_ties();
    void set_wins(int wins);
    void set_loses(int loses);
    void set_ties(int ties);

    // Display coach info
    void display() const;

    // JSON -> Coach
    static Coach from_json(const json& j);

    // Coach -> JSON
    static void to_json(json& j, const Coach& c);

    // Leave
    void leave_team();
};


#endif // COACH_H
