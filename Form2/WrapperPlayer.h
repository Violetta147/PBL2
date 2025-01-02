#pragma once
#include "include/Tournament.h"
#include "include/Player.h"
#include "include/Team.h"
#include "Ultility.h"

using namespace System;
using namespace System::Collections;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace System::ComponentModel;

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
    String^ playerFirstName;
	String^ playerLastName;
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

    property bool IsBan
    {
		bool get()
		{
			return isBan == 1;
		}
		void set(bool value)
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
			return playerFirstName + " " + playerLastName;
		}
		void set(String^ value)
		{
			array<String^>^ names = value->Split(' '); // Split the string by something else than space if needed
			playerFirstName = names[0];
			playerLastName = names[1];
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
		this->playerFirstName = gcnew String(player->get_first_name().c_str());
        this->playerLastName = gcnew String(player->get_last_name().c_str());
        this->teamName = player->getTeam() ? gcnew String(player->getTeam()->get_name().c_str()) : nullptr; //nullptr; 
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
		this->playerFirstName = gcnew String("");
		this->playerLastName = gcnew String("");
        this->teamName = gcnew String("");
		nativePlayer = new Player();
    }
	//method to convert all data of WrapperPlayer to Player without using msclr::interop::marshal_as<std::string>
    void ConvertToNativePlayer()
    {
		//using StringToStlWString method to convert System::String to std::wstring
		std::string player_id_string;
        Ultility::StringToStlString(player_id, player_id_string);
		std::string position_string;
        Ultility::StringToStlString(position, position_string);
		std::string playerFirstName_string;
        Ultility::StringToStlString(playerFirstName, playerFirstName_string);
		std::string playerLastName_string;
        Ultility::StringToStlString(playerLastName, playerLastName_string);
		std::string teamName_string;
        Ultility::StringToStlString(teamName, teamName_string);
		//set all data to nativePlayer
		nativePlayer->setId(player_id_string);
		nativePlayer->setNum(jersey_num);
		nativePlayer->setTId(team_id);
		nativePlayer->setPosition(position_string);
		nativePlayer->setGoals(goal);
		nativePlayer->setAssists(assist);
		nativePlayer->setRedCards(redCard);
		nativePlayer->setYellowCards(yellowCard);
		nativePlayer->setIsBan(isBan);
		nativePlayer->setMatch(match);
		nativePlayer->set_first_name(playerFirstName_string);
		nativePlayer->set_last_name(playerLastName_string);
		//not set team name, team* yet
    }
	Player* GetNativePlayer()
	{
		return nativePlayer;
	}
};

