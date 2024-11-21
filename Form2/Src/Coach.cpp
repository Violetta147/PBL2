#include "../include/Player.h"
#include "../include/Coach.h"
#include "../include/Team.h"
#include "../include/Event.h"
#include "../include/Match.h"


// Constructor
Coach::Coach() {}
Coach::Coach(const std::string& human_id, const std::string& first_name, const std::string& last_name, const std::string& country,
             const std::string& birth, int height, int weight, const std::string& coach_id, int team_id, int wins, int loses, int ties)
    : Human(human_id, first_name, last_name, country, birth, height, weight), coach_id(coach_id), team_id(team_id), wins(wins), loses(loses), ties(ties), team(nullptr) {}

// Getter for team
std::string Coach::get_id() const {
    return coach_id;
}

// Setter for team
void Coach::set_id(std::string coach_id) {
    this->coach_id = coach_id;
}

// Getter for team
const Team* Coach::get_team() const {
    return team;
}

// Setter for team
void Coach::set_team(const Team* team) {
    this->team = team;
}

// Getter for team_id
int Coach::get_TId() const {
    return team_id;
}

// Setter for team_id
void Coach::set_TId(int team_id) {
    this->team_id = team_id;
}

// Getter for match
int Coach::get_match() const {
    return wins + loses + ties;
}

// Getter for wins, loses, ties
int Coach::get_wins() const {
    return wins;
}

int Coach::get_loses() const {
    return loses;
}

int Coach::get_ties() const {
    return ties;
}

// Upter for wins, loses, ties
void Coach::up_wins() {
    wins += 1;
}

void Coach::up_loses() {
    loses += 1;
}

void Coach::up_ties() {
    ties += 1;
}

void Coach::set_wins(int wins) {
    this->wins = wins;
}

void Coach::set_loses(int loses) {
    this->loses = loses;
}

void Coach::set_ties(int ties) {
    this->ties = ties;
}

// Json->Coach
Coach Coach::from_json(const json& j) {
    return Coach(
        j.at("human_id").get<std::string>(),
        j.at("first_name").get<std::string>(),
        j.at("last_name").get<std::string>(),
        j.at("country").get<std::string>(),
        j.at("birth").get<std::string>(),
        j.at("height").get<int>(),
        j.at("weight").get<int>(),
        j.at("coach_id").get<std::string>(),
        j.at("team_id").get<int>(),
        j.at("wins").get<int>(),
        j.at("loses").get<int>(),
        j.at("ties").get<int>()
    );
}

// Coach->Json
void Coach::to_json(json& j, const Coach& c) {
    j = json{
        {"human_id", c.get_Id()},
        {"first_name", c.get_first_name()},
        {"last_name", c.get_last_name()},
        {"country", c.get_nation()},
        {"birth", c.get_birth()},
        {"height", c.get_height()},
        {"weight", c.get_weight()},
        {"coach_id", c.get_id()},
        {"team_id", c.get_TId()},
        {"wins", c.get_wins()},
        {"loses", c.get_loses()},
        {"ties", c.get_ties()}
    };
}

// Display coach info
void Coach::display() const {
    std::cout << "Coach ID: " << coach_id << "\n"
              << "Coach name: " << get_Name() << "\n"
              << "Birthday: " << get_birth() << std::endl
              << "Age: " << get_age() << std::endl
              << "Country: " << get_nation() << std::endl
              << "Height: " << get_height() << std::endl
              << "Weight: " << get_weight() << std::endl
              << "Wins: " << get_wins() << std::endl
              << "Loses: " << get_loses() << std::endl
              << "Ties: " << get_ties() << std::endl;
    if (team) {
        std::cout << "Team: " << team->get_name() << "\n";
    } else {
        std::cout << "No team assigned.\n";
    }
}

void Coach::leave_team() {
    set_team(nullptr);
}

