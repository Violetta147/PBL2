#include "../include/Player.h"
#include "../include/Coach.h"
#include "../include/Team.h"
#include "../include/Event.h"
#include "../include/Match.h"



// Constructor
Event::Event() {}
Event::Event(std::string player_id, EventType event, int minute, int side)
    : player_id(player_id), event(event), minute(minute), side(side) {}

// Getter for player id
std::string Event::get_player_id() const {
    return player_id;
}

// Setter for player id
void Event::set_player_id(std::string player_id) {
    this->player_id = player_id;
}

// Getter for player
const Player* Event::get_player() const {
    return player;
}

// Setter for player
void Event::set_player(const Player* player) {
    this->player = player;
}

// Getter for event type
EventType Event::get_event() const {
    return event;
}

// Setter for event type
void Event::set_event(EventType e) {
    event = e;
}

// Getter for minute
int Event::get_minute() const {
    return minute;
}

// Setter for minute
void Event::set_minute(int time) {
    minute = time;
}

// Getter for side
int Event::get_side() const {
    return side;
}

// Setter for side
void Event::set_side(int side) {
    this->side = side;
}

// Display event details
void Event::display_event() const {
    std::cout << "Player ID: " << player_id << ", ";
    std::cout << "Event: ";
    switch (event) {
        case GOAL: std::cout << "Goal"; break;
        case ASSIST: std::cout << "Assist"; break;
        case YELLOW: std::cout << "Yellow Card"; break;
        case RED: std::cout << "Red Card"; break;
        default: std::cout << "Unknown Event"; break;
    }
    std::cout << ", Minute: " << minute << std::endl;
}

void Event::to_json(json& j, const Event& e) {
    std::string event_str;
    switch (e.event) {
        case GOAL: event_str = "GOAL"; break;
        case ASSIST: event_str = "ASSIST"; break;
        case YELLOW: event_str = "YELLOW"; break;
        case RED: event_str = "RED"; break;
    }

    j = json{
        {"player_id", e.player_id},
        {"event", event_str},
        {"minute", e.minute},
        {"side", e.side}
    };
}

Event Event::from_json(const json& j) {
    std::string player_id = j.at("player_id").get<std::string>();
    std::string event_str = j.at("event").get<std::string>();
    EventType event_type;

    if (event_str == "GOAL") {
        event_type = GOAL;
    } else if (event_str == "ASSIST") {
        event_type = ASSIST;
    } else if (event_str == "YELLOW") {
        event_type = YELLOW;
    } else if (event_str == "RED") {
        event_type = RED;
    }

    int minute = j.at("minute").get<int>();
    int side = j.at("side").get<int>();
    return Event(player_id, event_type, minute, side);
}
