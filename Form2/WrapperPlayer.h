#pragma once
#include "include/Tournament.h"
#include "include/Player.h"
#include "include/Team.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;

public ref class WrapperPlayer
{
private:
    Player* nativePlayer; // No const
    String^ player_id;
    int jersey_num;
    int team_id;
    String^ position;
    int goal;
    int assist;
    int redCard;
    int yellowCard;
    int isBan;
    int match;
    String^ playerName;
    String^ teamName;

public:
    // Define properties instead of fields
    property String^ PlayerID
    {
        String^ get()
        {
            return player_id;
        }
        void set(String^ value)
        {
            player_id = value;
        }
    }

    property int JerseyNum
    {
        int get()
        {
            return jersey_num;
        }
        void set(int value)
        {
            jersey_num = value;
        }
    }

    property int TeamID
    {
        int get()
        {
            return team_id;
        }
        void set(int value)
        {
            team_id = value;
        }
    }

    property String^ Position
    {
        String^ get()
        {
            return position;
        }
        void set(String^ value)
        {
            position = value;
        }
    }

    property int Goal
    {
        int get()
        {
            return goal;
        }
        void set(int value)
        {
            goal = value;
        }
    }

    property int Assist
    {
        int get()
        {
            return assist;
        }
        void set(int value)
        {
            assist = value;
        }
    }

    property int RedCard
    {
        int get()
        {
            return redCard;
        }
        void set(int value)
        {
            redCard = value;
        }
    }

    property int YellowCard
    {
        int get()
        {
            return yellowCard;
        }
        void set(int value)
        {
            yellowCard = value;
        }
    }

    property int IsBan
    {
        int get()
        {
            return isBan;
        }
        void set(int value)
        {
            isBan = value;
        }
    }

    property int Match
    {
        int get()
        {
            return match;
        }
        void set(int value)
        {
            match = value;
        }
    }

    property String^ PlayerName
    {
        String^ get()
        {
            return playerName;
        }
        void set(String^ value)
        {
            playerName = value;
        }
    }

    property String^ TeamName
    {
        String^ get()
        {
            return teamName;
        }
        void set(String^ value)
        {
            teamName = value;
        }
    }

    // Constructor that initializes the properties
    WrapperPlayer(Player* player) : nativePlayer(player)
    {
        this->player_id = gcnew String(player->getId().c_str());
        this->jersey_num = player->getNum();
        this->team_id = player->getTId();
        this->position = gcnew String(player->getPosition().c_str());
        this->goal = player->getGoals();
        this->assist = player->getAssists();
        this->redCard = player->getRedCards();
        this->yellowCard = player->getYellowCards();
        this->isBan = player->getIsBan();
        this->match = player->getMatch();
        this->playerName = gcnew String(player->get_Name().c_str());
        this->teamName = gcnew String(player->getTeam()->get_name().c_str());
    }

    // Default constructor for initialization
    WrapperPlayer() : nativePlayer(nullptr)
    {
        this->player_id = gcnew String("");
        this->jersey_num = 0;
        this->team_id = 0;
        this->position = gcnew String("");
        this->goal = 0;
        this->assist = 0;
        this->redCard = 0;
        this->yellowCard = 0;
        this->isBan = 0;
        this->match = 0;
        this->playerName = gcnew String("");
        this->teamName = gcnew String("");
    }
};
