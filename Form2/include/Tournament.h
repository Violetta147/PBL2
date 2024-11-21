#ifndef TOURNAMENT_H
#define TOURNAMENT_H
#include <utility>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include "../include/nlohmann/json.hpp"
#include <map>

using json = nlohmann::ordered_json;

enum State {
    PRE,
    GO,
    MID,
    AWAY,
    POS,
};
class Player;
class Team;
class Coach;
class Match;

struct RankingEntry {
    Team* team;
    int points;
    int secondary_points;
    int goals;

    bool operator<(const RankingEntry& other) const {
        if (points != other.points) {
            return points > other.points;
        } else if (secondary_points != other.secondary_points) {
            return secondary_points > other.secondary_points;
        }
        return goals > other.goals;
    }

    bool operator>(const RankingEntry& other) const {
        if (points != other.points) {
            return points < other.points;
        } else if (secondary_points != other.secondary_points) {
            return secondary_points < other.secondary_points;
        }
        return goals < other.goals;
    }
};


class Tournament
{
    private:
        std::string name;
        std::vector<Player> players;
        std::vector<Team> teams;
        std::vector<Match> matches;
        std::vector<Coach> coaches;
        std::string season;
        int team_required;
        State state;
        std::vector<RankingEntry> ranking;
    public:
        // Constructor, Destructor
        Tournament(const std::string name, const std::string& season, int req, State initState);
        ~Tournament();

        // Setters
        void setSeason(const std::string& season);
        void changeState();
        void setReq(int req);

        // Getters
        std::string get_name() const;
        std::string getSeason() const;
        State getState() const;
        int getReq() const;
        Team* getTeam(int index);
        Coach* getCoach(int index);
        std::vector<Team> getTeams() const;
        std::vector<Player> getPlayers() const;
        std::vector<Coach> getCoaches() const;
        std::vector<Match> getMatches() const;
        int get_team_count() const;
        int get_coach_count() const;
        int get_match_count() const;
        int get_match_occured() const;
        int get_match_updated() const;
        int get_player_count() const;
        int get_round() const;
        int get_round_updated() const;

        // Other methods
        void addPlayer(Player& player);
        void addTeam(Team& team);
        void addMatch(Match& match);
        void addCoach(Coach& coach);

        // Serialization
        static void to_json(json& j, const Tournament& tournament);
        static Tournament from_json(const json& j);

        // Find and edit
        void edit_player(const Player& information);
        void edit_coach(const Coach& information);
        void edit_team(const Team& information);
        void edit_match(Match& match);
        Player* find_player_by_id(const std::string& player_id);
        Team* find_team_by_id(int team_id);
        Coach* find_coach_by_id(const std::string& coach_id);
        Match* find_match_by_id(const int& match_id);
        void delete_player(Player& gone);
        void remove_player(Player& gone);
        void delete_coach(Coach& gone);
        void remove_coach(Coach& gone);

        // Gather all data
        void get_all_data();
        void link_all_data();
        void traverse_for_ban();
        void write_all_data();
        void write_player();
        void write_team();
        void write_coach();
        void write_match();

        // Other method
        void generate_match();
        std::vector<Match> list_match_by_TID(const int& team_id);
        std::vector<Match> list_upcoming_matches(int num);
        std::vector<Player> list_players_by_age(bool (*CompFunc)(int, int));
        std::vector<Player> list_players_by_born_year(int year);
        std::vector<Player> list_players_by_height(bool (*CompFunc)(int, int));
        std::vector<Player> list_players_in_pos(std::string pos); //...
        std::vector<Player> list_player_by_goal(bool (*CompFunc)(int, int));
        std::vector<Player> list_player_by_assist(bool (*CompFunc)(int, int));
        std::vector<Player> list_player_by_rc(bool (*CompFunc)(int, int));
        std::vector<Player> list_player_by_yc(bool (*CompFunc)(int, int));
        std::vector<Match> list_matches_by_day(std::string occured); //...
        std::vector<Match> list_matches_by_month(int month);
        std::vector<Match> list_matches_by_round(int round);
        std::vector<Match> list_matches();
        std::vector<Player> list_free_players();

        // Rank
        void generate_ranking();
        void updateRanking();
        void displayRanking() const;

        // Display
        void display() const;
};

bool Ascending(int a, int b);

bool Descending(int a, int b);

#endif //TOURNAMENT_H
