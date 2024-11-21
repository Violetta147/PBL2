#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Human.h"
#include "../include/nlohmann/json.hpp"

using json = nlohmann::ordered_json;

class Team;
class Match;

class Player : public Human {
    private:
        std::string player_id;
        int jersey_num;
        int team_id;
        const Team* team;
        std::string position;
        int goal;
        int assist;
        int red_card;
        int yellow_card;
        int is_ban;
        int match;
    public:
        // Constructor
        //this doesn't bind team* to any team
        Player();
        Player(const std::string human_id, const std::string& first_name, const std::string& last_name,
            const std::string& country, const std::string& birth, int height,
            int weight, const std::string id, int jersey, int team_id,
            const std::string& pos, int goal = 0, int ass = 0, int red = 0, int yellow = 0,
            int is_ban = 0, int match = 0);

        // Getter and Setter for id
        void setId(std::string id);
        std::string getId() const;

        // Getter and setter for team Id
        void setTId(int team_id);
        int getTId() const;

        // Getter and Setter for team
        void setTeam(const Team* team);
        const Team* getTeam() const;

        // Getter and Setter for J_num
        int getNum() const;
        void setNum(int num);

        // Getter and Setter for pos
        std::string getPosition() const;
        void setPosition(const std::string& pos);

        // Getter and Setter for goal
        int getGoals() const;
        void addGoals(int goals);
        void setGoals(int goals);

        // Getter and Setter for assist
        int getAssists() const;
        void addAssists(int assists);
        void setAssists(int assists);

        // Getter and Setter for rc
        int getRedCards() const;
        void addRedCards(int red);
        void setRedCards(int red);

        // Getter and Setter for yc
        int getYellowCards() const;
        void addYellowCards(int yellow);
        void setYellowCards(int red);

        // Getter and Setter for ban
        int getIsBan() const;
        void setIsBan(int is_ban);

        // Getter and Setter for match
        void setMatch(int match);
        int getMatch() const;
        void upMatch();

        // JSON -> Player
        static Player from_json(const json& j);

        // Player -> JSON
        static void to_json(json& j, const Player& p);

        // Display player information
        void display() const;

        // Leave
        void leave_team();
};

#endif
