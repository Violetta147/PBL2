#ifndef MATCH_H
#define MATCH_H

#include <string>
#include <vector>
#include <iostream>
#include "nlohmann/json.hpp"

using json = nlohmann::ordered_json;

class Event;
class Player;
class Team;

class Match {
    private:
        int match_id;
        int home_team_id;
        int away_team_id;
        const Team* home_team;
        const Team* away_team;
        std::string date;
        std::string time;
        std::vector<std::string> home_lineup_id;
        std::vector<std::string> away_lineup_id;
        std::vector<const Player*> home_lineup;
        std::vector<const Player*> away_lineup;
        int home_score;
        int away_score;
        std::vector<Event> events;
        int updated;
    public:
        // Constructor
        Match();
        Match(int match_id, int home_id, int away_id, std::string date, std::string time, int updated = 0);

        // Setters and Getters
        void setHomeTeamId(int id);
        void setAwayTeamId(int id);
        void setHomeTeam(const Team* team);
        void setAwayTeam(const Team* team);
        void setDate(const std::string& date);
        void setTime(const std::string& time);
        void setHomeLineup(const std::vector<const Player*>& lineup);
        void setAwayLineup(const std::vector<const Player*>& lineup);
        void setHomeLineupId(const std::vector<std::string>& lineup_id);
        void setAwayLineupId(const std::vector<std::string>& lineup_id);
        void setHomeScore(int score);
        void setAwayScore(int score);
        void addEvent(const Event& event);
        void update();

        int getMatchId() const;
        int getHomeTeamId() const;
        int getAwayTeamId() const;
        const Team* getHomeTeam() const;
        const Team* getAwayTeam() const;
        std::string getDate() const;
        std::string getTime() const;
        const std::vector<const Player*>& getHomeLineup() const;
        const std::vector<const Player*>& getAwayLineup() const;
        const std::vector<std::string>& getHomeLineupId() const;
        const std::vector<std::string>& getAwayLineupId() const;
        int getHomeScore() const;
        int getAwayScore() const;
        std::vector<Event>& getEvents();
        const std::vector<Event>& getEvents() const;
        void displayMatchSummary() const;
        void displayMatch() const;
        int get_updated() const;

        // Match to Json
        static void to_json(json& j, const Match& m);

        // JSON to match
        static Match from_json(const json& j);
};

#endif
