#ifndef EVENT_H
#define EVENT_H

#include "Player.h"

enum EventType {
    GOAL,
    ASSIST,
    YELLOW,
    RED,
};

class Event {
    private:
        std::string player_id;
        const Player* player; //Who involved?
        EventType event; //What happened?
        int minute; //Time of occurrence?
        int side;
    public:
        // Constructor
        Event();
        Event(std::string player_id, EventType event, int minute, int side = 2);

        // Get and set event info
        std::string get_player_id() const;
        void set_player_id(std::string player_id);
        const Player* get_player() const;
        void set_player(const Player* player);
        EventType get_event() const;
        void set_event(EventType e);
        int get_minute() const;
        void set_minute(int time);
        int get_side() const;
        void set_side(int side);

        // Display event
        void display_event() const;

        static void to_json(json& j, const Event& e);

        static Event from_json(const json& j);
};

#endif
