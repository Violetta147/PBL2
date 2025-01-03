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
    String^ DOB;
    String^ CMND;
    String^ nation;
    int weight;
    int height;

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
    property String^ DateOfBirth
    {
        String^ get()
        {
            return DOB;
        }
        void set(String^ value)
        {
            DOB = value;
        }
    }
    property String^ CCCD
    {
        String^ get()
        {
			return CMND;
        }
		void set(String^ value)
		{
			CMND = value;
		}
    }
	property String^ Nation
	{
		String^ get()
		{
			return nation;
		}
		void set(String^ value)
		{
			nation = value;
		}
	}
	property int Weight
	{
		int get()
		{
			return weight;
		}
		void set(int value)
		{
			weight = value;
		}
	}
    property int Height
    {
        int get()
        {
            return height;
        }
        void set(int value)
        {
            height = value;
        }
    }
    // Constructor that initializes the properties
    WrapperPlayer(Player* player)
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
		this->DOB = gcnew String(player->get_birth().c_str());
		this->CMND = gcnew String(player->get_Id().c_str());
		this->nation = gcnew String(player->get_nation().c_str());
		this->weight = player->get_weight();
		this->height = player->get_height();
    }

    // Default constructor for initialization
	WrapperPlayer()
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
    }
	String^ getFirstName()
	{
		return playerFirstName;
	}
	String^ getLastName()
	{
		return playerLastName;
	}
	System::Void setFirstName(String^ value)
	{
		playerFirstName = value;
	}
	System::Void setLastName(String^ value)
	{
		playerLastName = value;
	}
};

