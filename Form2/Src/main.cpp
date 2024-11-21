#include "../include/Event.h"
#include "../include/Match.h"
#include "../include/Player.h"
#include "../include/Team.h"
#include "../include/Tournament.h"
#include "../include/file_handler.h"
#include "../include/nlohmann/json.hpp"
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>

using json = nlohmann::ordered_json;

int main()
{
    Tournament tour = read_tournament("tournament.json");
    tour.display();
    tour.get_all_data();
    // Match m1(10, 16, 12, "07-11-2024", "22:00");
    // std::vector<std::string> home_lineup = {"P027", "P030", "P031", "P034", "P038", "P039", "P041", "P045", "P048", "P050", "P052"};
    // std::vector<std::string> away_lineup = {"P080", "P081", "P082", "P086", "P088", "P091", "P093", "P094", "P104", "P105", "P106"};
    // m1.setHomeLineupId(home_lineup);
    // m1.setAwayLineupId(away_lineup);
    // Event e1("P030", YELLOW, 10);
    // Event e2("P031", YELLOW, 34);
    // Event e3("P088", YELLOW, 57);
    // Event e4("P030", YELLOW, 83);
    // Event e5("P104", YELLOW, 89);
    // Event e6("P074", GOAL, 90);
    // Event e7("P491", YELLOW, 92);
    // Event e8("P397", GOAL, 82);
    // Event e9("P382", ASSIST, 82);
    // Event e10("P397", GOAL, 91);
    // Event e11("P315", GOAL, 88);
    // Event e12("P316", ASSIST, 88);
    // Event e13("P301", YELLOW, 91);
    // m1.addEvent(e1);
    // m1.addEvent(e2);
    // m1.addEvent(e3);
    // m1.addEvent(e4);
    // m1.addEvent(e5);
    // m1.addEvent(e6);
    // m1.addEvent(e7);
    // m1.addEvent(e8);
    // m1.addEvent(e9);
    // m1.addEvent(e10);
    // m1.addEvent(e11);
    // m1.addEvent(e12);
    // m1.addEvent(e13);

    //tour.edit_match(m1);
    // tour.updateRanking();
    // tour.displayRanking();
    // std::vector<Player> res = tour.list_player_by_rc(Descending);
    // for (int i = 0; i < 10; i++) {
    //     std::cout << res[i].get_Name() << " - Rc: " << res[i].getRedCards() << "- Ban:" << res[i].getIsBan() << std::endl;
    // }
    // std::vector<Match> res = tour.list_matches_by_month(12);
    // for (const auto& m : res) {
    //     m.displayMatchSummary();
    // }
    std::vector<Coach> coaches = tour.getCoaches();
    for (const auto c : coaches) {
        c.display();
    }
}
