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
        }
        else if (secondary_points != other.secondary_points) {
            return secondary_points > other.secondary_points;
        }
        return goals > other.goals;
    }

    bool operator>(const RankingEntry& other) const {
        if (points != other.points) {
            return points < other.points;
        }
        else if (secondary_points != other.secondary_points) {
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
    std::vector<Player> CFplayers;
    std::vector<Team> CFteams;
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
    Player getPlayer(int index);
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
    void delete_team(Team& gone);
    //void remove_team(Team& gone);

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
    std::vector<Player> search_by_name(std::vector<Player> players, std::string lower);
    std::vector<Team> search_by_team_name(std::vector<Team> teams, std::string lower);
    std::vector<const Match*> list_match_by_TID(std::vector<Match> matches, const int& team_id);
    std::vector<Match> list_upcoming_matches(int num);
    std::vector<Team> list_teams_by_goal_scored(bool (*CompFunc)(int, int));
    std::vector<Team> list_teams_by_goal_conceded(bool (*CompFunc)(int, int));
    std::vector<Team> list_teams_by_wins(bool (*CompFunc)(int, int));
    std::vector<Team> list_teams_by_loses(bool (*CompFunc)(int, int));
    std::vector<Player> list_players_by_team(std::vector<Player> players, int team_id);
    std::vector<Player> list_players_by_nation(std::vector<Player> players, std::string nation);
    std::vector<Player> list_players_by_age(std::vector<Player> players, bool (*CompFunc)(int, int));
    std::vector<Player> list_players_at_age(std::vector<Player> players, int age);
    std::vector<Player> list_players_by_born_year(std::vector<Player> players, int year);
    std::vector<Player> list_players_by_height(std::vector<Player> players, bool (*CompFunc)(int, int));
    std::vector<Player> list_players_by_weight(std::vector<Player> players, bool (*CompFunc)(int, int));
    std::vector<Player> list_players_in_pos(std::vector<Player> players, std::string pos); //...
    std::vector<Player> list_player_by_goal(std::vector<Player> players, bool (*CompFunc)(int, int));
    std::vector<Player> list_player_by_assist(std::vector<Player> players, bool (*CompFunc)(int, int));
    std::vector<Player> list_gk_by_cs(std::vector<Player> players, bool (*CompFunc)(int, int));
    std::vector<Player> list_player_by_rc(std::vector<Player> players, bool (*CompFunc)(int, int));
    std::vector<Player> list_player_by_yc(std::vector<Player> players, bool (*CompFunc)(int, int));
    std::vector<Match> list_matches_by_day(std::vector<Match> matches, std::string occured); //...
    std::vector<Match> list_matches_by_month(std::vector<Match> matches, int month);
    std::vector<Match> list_matches_by_round(std::vector<Match> matches, int round);
    std::vector<Match> list_matches();
    std::vector<Player> list_free_players();

    // Rank
    void generate_ranking();
    void updateRanking();
    void displayRanking() const;
    std::vector<RankingEntry> getRanking()
    {
        return ranking;
    }
    // Display
    void display() const;
};

bool Ascending(int a, int b);

bool Descending(int a, int b);

#endif //TOURNAMENT_H