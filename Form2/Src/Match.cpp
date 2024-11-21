#include "../include/Match.h"
#include "../include/Coach.h"
#include "../include/Event.h"
#include "../include/Player.h"
#include "../include/Team.h"

// Constructor
Match::Match() {}
Match::Match(int match_id, int home_id, int away_id, std::string date, std::string time, int updated)
    : match_id(match_id), home_team_id(home_id), away_team_id(away_id), date(date), time(time), updated(updated), home_score(0), away_score(0){
        home_lineup.reserve(11);
        away_lineup.reserve(11);
}

// Setters
void Match::setHomeTeamId(int id)
{
    home_team_id = id;
}
void Match::setAwayTeamId(int id)
{
    away_team_id = id;
}
void Match::setDate(const std::string& date) {
    this->date = date;
}
void Match::setTime(const std::string& time) {
    this->time = time;
}
void Match::setHomeTeam(const Team* team)
{
    home_team = team;
}
void Match::setAwayTeam(const Team* team)
{
    away_team = team;
}

void Match::setHomeLineupId(const std::vector<std::string> &lineup_id)
{
    home_lineup_id = lineup_id;
}

void Match::setAwayLineupId(const std::vector<std::string> &lineup_id)
{
    away_lineup_id = lineup_id;
}

void Match::setHomeLineup(const std::vector<const Player *> &lineup)
{
    home_lineup = lineup;
}

void Match::setAwayLineup(const std::vector<const Player *> &lineup)
{
    away_lineup = lineup;
}

void Match::setHomeScore(int score)
{
    home_score = score;
}

void Match::setAwayScore(int score)
{
    away_score = score;
}

void Match::addEvent(const Event &event)
{
    events.push_back(event);
}

void Match::update() {
    updated = 1;
}

// Getters

int Match::getMatchId() const {
    return match_id;
}

const Team* Match::getHomeTeam() const
{
    return home_team;
}

const Team* Match::getAwayTeam() const
{
    return away_team;
}

int Match::getHomeTeamId() const
{
    return home_team_id;
}

int Match::getAwayTeamId() const
{
    return away_team_id;
}

std::string Match::getDate() const {
    return date;
}

std::string Match::getTime() const {
    return time;
}

const std::vector<const Player *>& Match::getHomeLineup() const
{
    return home_lineup;
}

const std::vector<const Player *>& Match::getAwayLineup() const
{
    return away_lineup;
}

const std::vector<std::string>& Match::getHomeLineupId() const
{
    return home_lineup_id;
}

const std::vector<std::string>& Match::getAwayLineupId() const
{
    return away_lineup_id;
}

int Match::getHomeScore() const
{
    return home_score;
}

int Match::getAwayScore() const
{
    return away_score;
}

std::vector<Event>& Match::getEvents() {
    return events;
}

const std::vector<Event> &Match::getEvents() const
{
    return events;
}

int Match::get_updated() const {
    return updated;
}

// Method to display match summary
void Match::displayMatchSummary() const {
    std::cout << "Match ID: " << match_id << std::endl;
    std::cout << "Date: " << date << std::endl;
    std::cout << "Home Team ID: " << home_team_id << std::endl;
    std::cout << "Away Team ID: " << away_team_id << std::endl;
    std::cout << "Home Team Score: " << home_score << std::endl;
    std::cout << "Away Team Score: " << away_score << std::endl;

    if (!home_lineup_id.empty()) {
        std::cout << "Home Lineup Player IDs: ";
        for (const auto& id : home_lineup_id) {
            std::cout << id << " ";
        }
        std::cout << std::endl;
    }

    if (!away_lineup_id.empty()) {
        std::cout << "Away Lineup Player IDs: ";
        for (const auto& id : away_lineup_id) {
            std::cout << id << " ";
        }
        std::cout << std::endl;
    } else return;

    std::cout << "Match Events: " << std::endl;
    for (const auto& event : events) {
        if (event.get_side() == 0) {
            std::cout << "Team: " << home_team->get_name() << std::endl;
        } else std::cout << "Team: " << away_team->get_name() << std::endl;
        event.display_event();
    }
    std::cout << "---------------------------" << std::endl;
}

void Match::displayMatch() const {
    std::cout << "Match ID: " << match_id << std::endl;
    std::cout << "Date: " << date << std::endl;
    std::cout << "Home Team ID: " << home_team_id << std::endl;
    std::cout << "Away Team ID: " << away_team_id << std::endl;
    std::cout << "Home Team Score: " << home_score << std::endl;
    std::cout << "Away Team Score: " << away_score << std::endl;
    std::cout << "---------------------------" << std::endl;
}

// JSON conversion (to JSON)
void Match::to_json(json &j, const Match &m) {
    j = json{
        {"match_id", m.getMatchId()},
        {"home_team_id", m.getHomeTeamId()},
        {"away_team_id", m.getAwayTeamId()},
        {"date", m.getDate()},
        {"time", m.getTime()},
        {"updated", m.get_updated()},
        {"home_lineup_id", m.getHomeLineupId()},
        {"away_lineup_id", m.getAwayLineupId()},
        {"home_score", m.getHomeScore()},
        {"away_score", m.getAwayScore()},
        {"events", json::array()}
    };

    for (const auto& e : m.getEvents()) {
        json event_json;
        Event::to_json(event_json, e);
        j["events"].push_back(event_json);
    }
}

// JSON conversion (from JSON)
Match Match::from_json(const json& j) {
    Match m(
        j.at("match_id").get<int>(),
        j.at("home_team_id").get<int>(),
        j.at("away_team_id").get<int>(),
        j.at("date").get<std::string>(),
        j.at("time").get<std::string>(),
        j.at("updated").get<int>()
    );

    m.setHomeLineupId(j.at("home_lineup_id").get<std::vector<std::string>>());
    m.setAwayLineupId(j.at("away_lineup_id").get<std::vector<std::string>>());
    m.setHomeScore(j.at("home_score").get<int>());
    m.setAwayScore(j.at("away_score").get<int>());

    for (const auto& event_json : j["events"]) {
        m.addEvent(Event::from_json(event_json));
    }

    return m;
}

