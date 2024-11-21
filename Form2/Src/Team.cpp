#include "../include/Player.h"
#include "../include/Coach.h"
#include "../include/Team.h"
#include "../include/Event.h"
#include "../include/Match.h"


// Constructor
Team::Team() : founded_year(0) {}
Team::Team(int id, const std::string& name, const std::string& abbre, const std::string& stadium, const int founded_year,
         int wins, int loses, int ties, int goal_scored, int goal_conceded)
    : team_id(id), name(name), abbreviation(abbre), stadium(stadium), founded_year(founded_year), wins(wins), loses(loses),
      ties(ties), goal_scored(goal_scored), goal_conceded(goal_conceded), coach(nullptr) {
        players.reserve(30);
}

Team& Team::operator = (const Team& team) {
	if (this == &team) {
		return *this;
	}
	team_id = team.team_id;
	name = team.name;
	abbreviation = team.abbreviation;
	stadium = team.stadium;
	wins = team.wins;
	loses = team.loses;
	ties = team.ties;
	goal_scored = team.goal_scored;
	goal_conceded = team.goal_conceded;
	coach = team.coach;
	players = team.players;
	return *this;
}


// Getter and setter for id
int Team::get_id() const {
    return team_id;
}
void Team::set_id(int id) {
    this->team_id = id;
}

// Getter and setter for name
std::string Team::get_name() const {
    return name;
}
void Team::set_name(const std::string& name) {
    this->name = name;
}

// Getter and setter for abbre
std::string Team::get_abb() const {
    return abbreviation;
}

void Team::set_abb(const std::string& abb) {
    abbreviation = abb;
}

// Getter and setter for stadium
std::string Team::get_stadium() const {
    return stadium;
}
void Team::set_stadium(const std::string& stadium) {
    this->stadium = stadium;
}

// Getter for founded_year
int Team::get_founded_year() const {
    return founded_year;
}

// Getter for players
const std::vector<const Player*>& Team::get_players() const {
    return players;
}

// Method to add a player
void Team::add_player(const Player* player) {
    players.push_back(player);
}

// Add coach
void Team::add_coach(const Coach* coach) {
     this->coach = coach;
}

// Getter and setter for coach
const Coach* Team::get_coach() const {
    return coach;
}
void Team::set_coach(const Coach* coach) {
    this->coach = coach;
}

// Method to display team information
void Team::displayInfo() const {
    std::cout << "Team ID: " << team_id << std::endl
              << "Team Name: " << name << std::endl
              << "Stadium: " << stadium << std::endl
              << "Founded Year: " << founded_year << std::endl
              << "Goals scored: " << goal_scored << std::endl
              << "Goals conceded: " << goal_conceded << std::endl
              << "Wins: " << wins << std::endl
              << "Loses: " << loses << std::endl
              << "Ties: " << ties << std::endl;
    // Display coach info if available
    if (coach) {
        std::cout << "Coach: " << coach->get_Name() << std::endl;
    } else {
        std::cout << "Coach: No coach assigned." << std::endl;
    }
}

// Getter for wins, loses, ties
int Team::get_wins() const {
    return wins;
}

int Team::get_ties() const {
    return ties;
}

int Team::get_loses() const {
    return loses;
}

// Setter for wins, loses, ties
void Team::set_wins(int wins) {
    this->wins = wins;
}

void Team::set_ties(int ties) {
    this->ties = ties;
}

void Team::set_loses(int loses) {
    this->loses = loses;
}

void Team::up_win() {
    wins += 1;
}

void Team::up_lose() {
    loses += 1;
}

void Team::up_tie() {
    ties += 1;
}

// Getter for goal_scored, goal_conceded
int Team::get_goal_scored() const {
    return goal_scored;
}

int Team::get_goal_conceded() const {
    return goal_conceded;
}

// Setter for goal_scored, goal_conceded
void Team::set_goal_scored(int goal_scored) {
    this->goal_scored = goal_scored;
}

void Team::add_goal_scored(int goal_scored) {
    this->goal_scored += goal_scored;
}

void Team::set_goal_conceded(int goal_conceded) {
    this->goal_conceded = goal_conceded;
}

void Team::add_goal_conceded(int goal_conceded) {
    this->goal_conceded += goal_conceded;
}

void Team::to_json(json& j, const Team& t) {
    j = json{
        {"team_id", t.get_id()},
        {"name", t.get_name()},
        {"abbreviation", t.get_abb()},
        {"stadium", t.get_stadium()},
        {"founded_year", t.get_founded_year()}
    };
}

Team Team::from_json(const json& j) {
    return Team(
        j.at("team_id").get<int>(),
        j.at("name").get<std::string>(),
        j.at("abbreviation").get<std::string>(),
        j.at("stadium").get<std::string>(),
        j.at("founded_year").get<int>()
    );
}

// Get number of players
int Team::get_player_count() const {
    return players.size();
}

// List of players
void Team::list_all_players() const {
    for (int i = 0; i < players.size(); i++) {
        std::cout << players[i]->get_Name() << std::endl;
    }
    return;
}

// Points
int Team::get_points() const {
    return wins * 3 + ties;
}

int Team::get_secondary_points() const {
    return (goal_scored - goal_conceded);
}

// Matches
int Team::get_matches() const {
    return wins + loses + ties;
}

// Remove
void Team::remove_player(Player* playerToRemove) {
    auto it = std::remove(players.begin(), players.end(), playerToRemove);
    if (it != players.end()) {
        players.erase(it, players.end());
    }
}

void Team::remove_coach() {
    set_coach(nullptr);
}
