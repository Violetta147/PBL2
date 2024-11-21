#include "../include/file_handler.h"

std::vector<Player> read_players(std::string filename) {
    std::ifstream p_file_in(filename);
    if (!p_file_in.is_open()) {
        std::cerr << "Cannot open file " << filename << "to read" << std::endl;
        exit(1);
    }

    json p_j;
    p_file_in >> p_j;
    p_file_in.close();

    std::vector<Player> players;

    for (const auto& player_json : p_j["players"]) {
        players.push_back(Player::from_json(player_json));
    }

    return players;
}

std::vector<Coach> read_coaches(std::string filename) {
    std::ifstream coach_file_in(filename);
    if (!coach_file_in.is_open()) {
        std::cerr << "Cannot open file " << filename << "to read" << std::endl;
        exit(2);
    }

    json coach_json;
    coach_file_in >> coach_json;
    coach_file_in.close();

    std::vector<Coach> coaches;
    for (const auto& c_json : coach_json["coaches"]) {
        coaches.push_back(Coach::from_json(c_json));
    }

    return coaches;
}

std::vector<Team> read_teams(std::string filename) {
    std::ifstream t_file_in(filename);
    if (!t_file_in.is_open()) {
        std::cerr << "Cannot open file " << filename << "to read" << std::endl;
        exit(3);
    }

    json t_j;
    t_file_in >> t_j;
    t_file_in.close();

    std::vector<Team> teams;

    for (const auto& team_json : t_j["teams"]) {
        teams.push_back(Team::from_json(team_json));
    }

    return teams;
}

std::vector<Match> read_matches(std::string filename) {
    std::ifstream file_in(filename);
    if (!file_in.is_open()) {
        std::cerr << "Cannot open file " << filename << "to read" << std::endl;
        exit(4);
    }

    json j;
    file_in >> j;
    file_in.close();

    std::vector<Match> matches;

    for (const auto& team_json : j["matches"]) {
        matches.push_back(Match::from_json(team_json));
    }

    return matches;
}

Tournament read_tournament(std::string filename) {
    std::string filepath = "data/" + filename;
    std::ifstream file_in(filepath);
    if (!file_in.is_open()) {
        std::cerr << "Cannot open file " << filename << " to read" << std::endl;
        exit(9);
    }

    json j;
    file_in >> j;
    file_in.close();

    Tournament tournament = Tournament::from_json(j);
    return tournament;
}

void write_players(std::string filename, const std::vector<Player>& players) {
    std::ofstream p_file_out(filename);
    if (!p_file_out.is_open()) {
        std::cerr << "Cannot open file " << filename << "to write" << std::endl;
        exit(5);
    }

    json p_j_out;
    for (const auto& player : players) {
        json player_json;
        Player::to_json(player_json, player);
        p_j_out["players"].push_back(player_json);
    }

    p_file_out << p_j_out.dump(4);
    p_file_out.close();
}

void write_teams(std::string filename, const std::vector<Team>& teams) {
    std::ofstream t_file_out(filename);
    if (!t_file_out.is_open()) {
        std::cerr << "Cannot open file " << filename << "to write" << std::endl;
        exit(6);
    }

    json t_j_out;
    for (const auto& team : teams) {
        json team_json;
        Team::to_json(team_json, team);
        t_j_out["teams"].push_back(team_json);
    }

    t_file_out << t_j_out.dump(4);
    t_file_out.close();
}

void write_coaches(std::string filename, const std::vector<Coach>& coaches) {
    std::ofstream coach_file_out(filename);
    if (!coach_file_out.is_open()) {
        std::cerr << "Cannot open file " << filename << "to write" << std::endl;
        exit(7);
    }

    json c_out;
    for (const auto& coach : coaches) {
        json c_json;
        Coach::to_json(c_json, coach);
        c_out["coaches"].push_back(c_json);
    }

    coach_file_out << c_out.dump(4);
    coach_file_out.close();
}

void write_matches(std::string filename, const std::vector<Match>& matches) {
    std::ofstream m_file_out(filename);
    if (!m_file_out.is_open()) {
        std::cerr << "Cannot open file " << filename << "to write" << std::endl;
        exit(8);
    }

    json m_out;
    for (const auto& match : matches) {
        json m_json;
        Match::to_json(m_json, match);
        m_out["matches"].push_back(m_json);
    }

    m_file_out << m_out.dump(4);
    m_file_out.close();
}

void write_tournament(std::string filename, const Tournament& tournament) {
    std::string filepath = "data/" + filename;
    std::ofstream file_out(filepath);
    if (!file_out.is_open()) {
        std::cerr << "Cannot open file " << filepath << "to write" << std::endl;
        exit(10);
    }

    json j;

    Tournament::to_json(j, tournament);
    file_out << j.dump(4);
    file_out.close();
}
