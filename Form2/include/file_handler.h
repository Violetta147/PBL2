#include "../include/Match.h"
#include "../include/Coach.h"
#include "../include/Event.h"
#include "../include/Player.h"
#include "../include/Team.h"
#include "../include/Tournament.h"
#include "../include/nlohmann/json.hpp"

#include <iostream>
#include <fstream>

std::vector<Player> read_players(std::string filename);

std::vector<Coach> read_coaches(std::string filename);

std::vector<Team> read_teams(std::string filename);

std::vector<Match> read_matches(std::string filename);

Tournament read_tournament(std::string filename);

void write_players(std::string filename, const std::vector<Player>& players);

void write_teams(std::string filename, const std::vector<Team>& teams);

void write_coaches(std::string filename, const std::vector<Coach>& coaches);

void write_matches(std::string filename, const std::vector<Match>& matchs);

void write_tournament(std::string filename, const Tournament& tournament);
