#ifndef TEAM_H
#define TEAM_H

#include <string>
#include <vector>
#include <iostream>
#include "../include/nlohmann/json.hpp"

using json = nlohmann::ordered_json;

class Player; // Forward declaration
class Coach;  // Forward declaration

class Team {
    private:
        int team_id; //key can't be changed
        std::string name;
        std::string abbreviation; //can we change this?
        std::string stadium;
        const int founded_year;//can't be changed but if wrong init founded_year?
        std::vector<const Player*> players;
        const Coach* coach;
        int wins;
        int loses;
        int ties;
        int goal_scored;
        int goal_conceded;
    public:
        // Constructor
        Team();
        Team(int id, const std::string& name, const std::string& abbre, const std::string& stadium, const int founded_year,
            int wins = 0, int loses = 0, int ties = 0, int goal_scored = 0, int goal_conceded = 0);
		Team& operator = (const Team& team);

        // Getter and setter for id
        int get_id() const;
        void set_id(int id);

        // Getter and setter for name
        std::string get_name() const;
        void set_name(const std::string& name);

        // Getter and setter for abbre
        std::string get_abb() const;
        void set_abb(const std::string& abb);

        // Getter and setter for stadium
        std::string get_stadium() const;
        void set_stadium(const std::string& stadium);

        // Getter for founded_year
        int get_founded_year() const;

        // Getter for players
        const std::vector<const Player*>& get_players() const; //:(
        void add_player(const Player* player);
        void add_coach(const Coach* coach);
        //void show_players();

        // Getter and setter for coach
        const Coach* get_coach() const;
        void set_coach(const Coach* coach);

        // Getter for wins, loses, ties
        int get_wins() const;
        int get_ties() const;
        int get_loses() const;

        // Setter for wins, loses, ties
        void set_wins(int wins);
        void set_ties(int ties);
        void set_loses(int loses);
        void up_win();
        void up_lose();
        void up_tie();

        // Getter for goal_scored, goal_conceded
        int get_goal_scored() const;
        int get_goal_conceded() const;

        // Setter for goal_scored, goal_conceded
        void set_goal_scored(int goal_scored);
        void add_goal_scored(int goal_scored);
        void set_goal_conceded(int goal_conceded);
        void add_goal_conceded(int goal_conceded);

        // Display
        void displayInfo() const;

        // Team->Json
        static void to_json(json& j, const Team& t);

        // Json->Team
        static Team from_json(const json& j);

        // Get number of players
        int get_player_count() const;

        // List of players
        void list_all_players() const;

        // Points
        int get_points() const;
        int get_secondary_points() const;

        // Match
        int get_matches() const;

        // Remove
        void remove_player(Player* player);
        void remove_coach();
};

#endif // TEAM_H
