#include "../include/Tournament.h"
#include "../include/Coach.h"
#include "../include/Event.h"
#include "../include/Match.h"
#include "../include/Player.h"
#include "../include/Team.h"
#include "../include/file_handler.h"
#include "../include/datetime.h"
#include <fstream>

// Constructor
Tournament::Tournament(const std::string name, const std::string &season, int req, State initState)
    : name(name), season(season), team_required(req), state(initState)
{
    std::cout << "Tournament created for season: " << season << std::endl;
    players.reserve(req * 60);
    teams.reserve(req);
    coaches.reserve(req * 2);
    matches.reserve(req * (req - 1));
}

// Destructor
Tournament::~Tournament()
{
    std::cout << "Tournament for season " << season << " is being destroyed." << std::endl;
}

// Setters
void Tournament::setSeason(const std::string &season)
{
    this->season = season;
}

void Tournament::changeState()
{
    if (state == PRE)
    {
        int flag = 0;
        if (players.size() < team_required * 11)
        {
            flag = 1;
            std::cout << "Not enough players(only " << players.size() << " while minimum "
                      << team_required * 11 << ") required!\n";
        }
        std::vector<std::string> player_id;
        for (const auto &p : players)
        {
            if (p.getTeam() == nullptr)
            {
                player_id.push_back(p.getId());
            }
        }
        if (player_id.size() != 0)
        {
            flag = 1;
            std::cout << "Players with id: ";
            for (const auto &id : player_id)
                std::cout << id << " ";
            std::cout << "aren't assigned to any team!\n";
        }
        if (teams.size() != team_required)
        {
            flag = 1;
            std::cout << "Not enough teams(only " << teams.size() << " while " << team_required
                      << " required!\n";
        }
        for (const auto &team : teams)
        {
            if (team.get_players().size() < 11)
            {
                flag = 1;
                std::cout << "Team " << team.get_name() << " only have " << team.get_player_count()
                          << " players(required minimum 11 players)!\n";
            }
            if (team.get_coach() == nullptr)
            {
                flag = 1;
                std::cout << "Team " << team.get_name() << " doesn't have a coach!\n";
            }
        }
        if (flag == 1)
            return;
        else
        {
            this->generate_match();
            state = GO;
            write_tournament("tournament.json", *this);
            return;
        }
    }
    else if (state == GO)
    {
        if (this->get_match_occured() == this->get_match_count() / 2 && this->get_match_updated() == this->get_match_count() / 2)
        {
            state = MID;
            write_tournament("tournament.json", *this);
            return;
        }
        else
        {
            std::cout << "GO turn hasn't came to an endo or not updated all!\n";
            return;
        }
    }
    else if (state == AWAY)
    {
        if (this->get_match_occured() == this->get_match_count() && this->get_match_updated() == this->get_match_count() / 2)
        {
            state = POS;
            write_tournament("tournament.json", *this);
            return;
        }
        else
        {
            std::cout << "Season hasn't came to an end or not updated yet!\n";
            return;
        }
    }
    else if (state == MID)
    {
        state = AWAY;
        write_tournament("tournament.json", *this);
        return;
    }
    else
        return;
}

void Tournament::setReq(int req)
{
    team_required = req;
}

// Getters
std::string Tournament::get_name() const {
    return name;
}

std::string Tournament::getSeason() const
{
    return season;
}

State Tournament::getState() const
{
    return state;
}

int Tournament::getReq() const
{
    return team_required;
}

std::vector<Team> Tournament::getTeams() const {
    return teams;
}

std::vector<Player> Tournament::getPlayers() const {
    return players;
}

std::vector<Coach> Tournament::getCoaches() const {
    return coaches;
}

std::vector<Match> Tournament::getMatches() const {
    return matches;
}

int Tournament::get_team_count() const
{
    return teams.size();
}

int Tournament::get_coach_count() const
{
    return coaches.size();
}

int Tournament::get_match_count() const
{
    return matches.size();
}

int Tournament::get_match_occured() const
{
    int occured = 0;
    std::time_t now = std::time(nullptr);
    now -= 3600 * 2;
    for (const auto& m : matches) {
        std::string time = getFormattedTime(now);
        std::string day = getFormattedDate(now);
        int day_comp = compareDates(m.getDate(), day);
        if (day_comp <= 0) {
            if (day_comp == 0) {
                int time_comp = compareTimes(m.getTime(), time);
                if (time_comp > 0) break;
                    else occured++;
            } else occured++;
        } else break;
    }
    return occured;
}

int Tournament::get_match_updated() const {
    int count = 0;
    for (const auto& m : matches) {
        if (m.get_updated() == 1) {
            count++;
        }
    }
    return count;
}

int Tournament::get_player_count() const
{
    return players.size();
}

Team* Tournament::getTeam(int index) {
    return &teams[index];
}

Coach* Tournament::getCoach(int index) {
    return &coaches[index];
}

int Tournament::get_round() const {
    return (get_match_occured() / (team_required / 2));
}

int Tournament::get_round_updated() const {
    return (get_match_updated() / (team_required / 2));
}

// Add methods
void Tournament::addPlayer(Player &player)
{
    if (this->get_team_count() != team_required) {
        std::cout << "You must add all teams first!\n";
        return;
    }
    if (state == PRE || state == MID) {
        Team* team_ptr = this->find_team_by_id(player.getTId());
        if (team_ptr != nullptr) {
            if (team_ptr->get_players().size() == 30) {
                std::cout << "Team is full of players, you must remove or delete one!\n";
                return;
            }
            else {
                player.setTeam(team_ptr);
                players.push_back(player);
                team_ptr->add_player(find_player_by_id(player.getId()));
                // this->write_all_data();
            }
        }
    } else {
        std::cout << "Cannot add player during this duration!\n";
    }
    return;
}

void Tournament::addTeam(Team& team)
{
    if (this->get_team_count() == team_required) {
        std::cout << "Full teams already cannot add more!\n";
        return;
    }
    if (state == PRE) {
        teams.push_back(team);
        // ....
    } else {
        std::cout << "Cannot add team during this duration!\n";
    }
}

void Tournament::addMatch(Match &match)
{
    if (state == PRE) {
        matches.push_back(match);
        Match* match_ptr = find_match_by_id(match.getMatchId());
        match_ptr->setHomeTeam(find_team_by_id(match_ptr->getHomeTeamId()));
        match_ptr->setAwayTeam(find_team_by_id(match_ptr->getAwayTeamId()));
    } else {
        std::cout << "Cannot add match during this duration!\n";
    }
    return;
}

void Tournament::addCoach(Coach& coach)
{
    if (this->get_team_count() != team_required) {
        std::cout << "You must add all teams first!\n";
        return;
    }
    if (state == PRE || state == MID) {
        Team* team_ptr = this->find_team_by_id(coach.get_TId());
        coach.set_team(team_ptr);
        coaches.push_back(coach);
        team_ptr->add_coach(find_coach_by_id(coach.get_id()));
    } else {
        std::cout << "Cannot add coach during this duration!\n";
    }
    return;
}

// Chuyển đối tượng Tournament sang JSON
void Tournament::to_json(json &j, const Tournament &tournament)
{
    j["name"] = tournament.get_name();
    j["season"] = tournament.getSeason();
    j["team_required"] = tournament.getReq();
    j["state"] = (tournament.getState() == PRE)    ? "PRE"
                 : (tournament.getState() == GO)   ? "GO"
                 : (tournament.getState() == MID)  ? "MID"
                 : (tournament.getState() == AWAY) ? "AWAY"
                                                   : "POS";
}

// Đọc dữ liệu từ file JSON vào đối tượng Tournament
Tournament Tournament::from_json(const json &j)
{
    std::string name = j.at("name").get<std::string>();
    std::string season = j.at("season").get<std::string>();
    int req = j.at("team_required").get<int>();
    std::string state_str = j.at("state").get<std::string>();

    State state;

    if (state_str == "PRE")
    {
        state = PRE;
    }
    else if (state_str == "GO")
    {
        state = GO;
    }
    else if (state_str == "MID")
    {
        state = MID;
    }
    else if (state_str == "AWAY")
    {
        state = AWAY;
    }
    else if (state_str == "POS")
    {
        state = POS;
    }

    return Tournament(name, season, req, state);
}

void Tournament::edit_team(const Team& information)
{
   Team* team = find_team_by_id(information.get_id());
   if (team != nullptr)
   {
        team->set_name(information.get_name());
        team->set_abb(information.get_abb());
        team->set_stadium(information.get_stadium());
   }
   write_team();
}

void Tournament::edit_coach(const Coach& information) // has this pointer to tournament
{
    //right now both information & old coach of team X are both linked to team X if team X has coach
    //team X is having a pointer to old coach
    Coach* target = this->find_coach_by_id(information.get_id()); // cannot be null
    Team* team = this->find_team_by_id(information.get_TId()); //i think it will always true because it loops through all teams in tournament
    if (team && (information.get_TId() != target->get_TId()))
    {
        Coach* old_coach = this->find_coach_by_id(team->get_coach()->get_id()); //if the team has a coach already
        if (old_coach != nullptr)
        {
            old_coach->leave_team();
        }
        team->set_coach(target);
        Team* old_team_of_target = this->find_team_by_id(target->get_TId());
        if (old_team_of_target != nullptr)
        {
            old_team_of_target->remove_coach();
        }
        target->set_team(team);
    }
    target->set_TId(information.get_TId());
    write_coach();
    write_team();
}

void Tournament::edit_player(const Player &information)
{
    // change find to return pointer instead of int
    Player *target = this->find_player_by_id(information.getId()); // temporarily suppose we don't have index passed in edit_player func
    if (target != nullptr)
    {
        // bool isExist = isPlayerExist()
        // human_id
        // player_id
        // country can be set if there is no hashing of id related to country(maybe?)
        // what if edit is to delete old player and add const Player& information
        // assume that information is CORRECT
        target->set_birth(information.get_birth());
        target->set_first_name(information.get_first_name());
        target->set_last_name(information.get_last_name());
        target->set_height(information.get_height());
        target->set_weight(information.get_weight());
        target->setNum(information.getNum());
        target->setPosition(information.getPosition());

        if (information.getTId() != target->getTId())
        {
            // if Team with information.getTID exist, obviously exists because information is
            // CORRECT int idx = return idx of team
            Team* old_team = this->find_team_by_id(target->getTId());
            if (old_team != nullptr) {
                old_team->remove_player(target);
                target->leave_team();
            }

            Team *target_team = this->find_team_by_id(information.getTId()); // this will certainly always return the CORRECT Team
            if (target_team != nullptr) {
                target->setTId(information.getTId());
                target->setTeam(target_team);
                target_team->add_player(target);
            }
        }
    }
    write_player();
    write_team();
}

void Tournament::edit_match(Match& match) {
    Match* target = find_match_by_id(match.getMatchId());
    if (target->getMatchId() > get_round() * (team_required / 2)) {
        std::cout << "This round not started yet!\n";
        return;
    }
    if (target->get_updated() == 1) {
        std::cout << target->get_updated() << std::endl;
        std::cout << "Matched edited!\n";
        return;
    }
    if (((target->getMatchId() - 1) / 10) != get_round_updated()) {
        std::cout << "You must finish pre round first!\n";
        return;
    }
    std::time_t now = std::time(nullptr);
    now -= 3600 * 2;
    std::string time = getFormattedTime(now);
    std::string day = getFormattedDate(now);
    int day_comp = compareDates(target->getDate(), day);
    if (day_comp <= 0) {
        if (day_comp == 0) {
            int time_comp = compareTimes(target->getTime(), time);
            if (time_comp > 0) {
                std::cout << "Match not ended yet!\n";
                return;
            }
        }
    } else {
        std::cout << "Match not ended yet!\n";
        return;
    }

    target->setHomeLineupId(match.getHomeLineupId());
    std::vector<std::string> home_players_id = target->getHomeLineupId();
    std::vector< const Player*> home_players;
    for (int i = 0, num = home_players_id.size(); i < num; i++) {
        Player* play = find_player_by_id(home_players_id[i]);
        home_players.push_back(play);
        play->upMatch();
    }
    target->setHomeLineup(home_players);

    target->setAwayLineupId(match.getAwayLineupId());
    std::vector<std::string> away_players_id = target->getHomeLineupId();
    std::vector<const Player*> away_players;
    for (int i = 0, num = away_players_id.size(); i < num; i++) {
        Player* play = find_player_by_id(home_players_id[i]);
        home_players.push_back(play);
        play->upMatch();
    }
    target->setAwayLineup(away_players);

    std::vector<Event> Events = match.getEvents();
    std::map<std::string, int> foul;
    int home = 0;
    int away = 0;
    for (int i = 0, num = Events.size(); i < num; i++) {
        Player* tegrat = find_player_by_id(Events[i].get_player_id());
        Events[i].set_player(tegrat);
        if (Events[i].get_event() == GOAL) {
            tegrat->addGoals(1);
            if (tegrat->getTId() == target->getHomeTeamId()) {
                home++;
                Events[i].set_side(0);
            } else {
                away++;
                Events[i].set_side(1);
            }
        } else if (Events[i].get_event() == ASSIST) {
            tegrat->addAssists(1);
            if (tegrat->getTId() == target->getHomeTeamId()) {
                Events[i].set_side(0);
            } else {
                Events[i].set_side(1);
            }
        } else if (Events[i].get_event() == YELLOW) {
            tegrat->addYellowCards(1);
            if (tegrat->getTId() == target->getHomeTeamId()) {
                Events[i].set_side(0);
            } else {
                Events[i].set_side(1);
            }
            foul[tegrat->getId()]++;
            if (foul[tegrat->getId()] == 2) {
                tegrat->addRedCards(1);
            }
        } else {
            tegrat->addRedCards(1);
            if (tegrat->getTId() == target->getHomeTeamId()) {
                Events[i].set_side(0);
            } else {
                Events[i].set_side(1);
            }
            tegrat->addRedCards(1);
            foul[tegrat->getId()] = 2;
        }
        target->addEvent(Events[i]);
    }

    Team* meat_emoh = find_team_by_id(target->getHomeTeamId());
    Team* meat_yawa = find_team_by_id(target->getAwayTeamId());

    if (home == away) {
        meat_emoh->up_tie();
        meat_yawa->up_tie();
        find_coach_by_id(meat_emoh->get_coach()->get_id())->up_ties();
        find_coach_by_id(meat_yawa->get_coach()->get_id())->up_ties();
    } else if (home > away) {
        meat_emoh->up_win();
        meat_yawa->up_lose();
        find_coach_by_id(meat_emoh->get_coach()->get_id())->up_wins();
        find_coach_by_id(meat_yawa->get_coach()->get_id())->up_loses();
    } else {
        meat_emoh->up_lose();
        meat_yawa->up_win();
        find_coach_by_id(meat_emoh->get_coach()->get_id())->up_loses();
        find_coach_by_id(meat_yawa->get_coach()->get_id())->up_wins();
    }
    target->setHomeScore(home);
    target->setAwayScore(away);
    meat_emoh->add_goal_scored(home);
    meat_yawa->add_goal_conceded(home);
    meat_emoh->add_goal_conceded(away);
    meat_yawa->add_goal_scored(away);
    updateRanking();

    std::vector<const Player*> home_all_players = meat_emoh->get_players();
    std::vector<const Player*> away_all_players = meat_yawa->get_players();

    for (int i = 0, num = home_players_id.size(); i < num; i++) {
        if (home_all_players[i]->getIsBan() != 0) {
            find_player_by_id(home_all_players[i]->getId())->setIsBan(0);
        }
    }

    for (int i = 0, num = away_players_id.size(); i < num; i++) {
        if (away_all_players[i]->getIsBan() != 0) {
            find_player_by_id(away_all_players[i]->getId())->setIsBan(0);
        }
    }

    for (const auto& a : foul) {
        if (a.second == 2) {
            Player* somebody = find_player_by_id(a.first);
            if (somebody->getTId() == target->getHomeTeamId()) {
                somebody->setIsBan(meat_emoh->get_matches());
            } else {
                somebody->setIsBan(meat_yawa->get_matches());
            }
        }
    }
    target->update();
    write_all_data();
    return;
}

Player *Tournament::find_player_by_id(const std::string &player_id)
{
    for (int i = 0; i < players.size(); ++i)
    {
        if (players[i].getId() == player_id)
            return &players[i];
    }
    return nullptr;
}

// void initializeBasicComponent of APP
//{
// call hidesubmenu
// only show main buttons}
//

Team *Tournament::find_team_by_id(int team_id)
{
    for (int i = 0; i < teams.size(); ++i)
    {
        if (teams[i].get_id() == team_id)
            return &teams[i];
    }
    return nullptr;
}

Coach *Tournament::find_coach_by_id(const std::string &coach_id)
{
    for (int i = 0; i < coaches.size(); i++)
    {
        if (coach_id == coaches[i].get_id())
            return &coaches[i];
    }
    return nullptr;
}

Match *Tournament::find_match_by_id(const int &match_id)
{
    for (int i = 0; i < matches.size(); i++)
    {
        if (match_id == matches[i].getMatchId())
            return &matches[i];
    }
    return nullptr;
}

void Tournament::get_all_data()
{
    std::string playersFile = "data/" + this->getSeason() + "/players.json";
    std::string teamsFile = "data/" + this->getSeason() + "/teams.json";
    std::string matchesFile = "data/" + this->getSeason() + "/matches.json";
    std::string coachesFile = "data/" + this->getSeason() + "/coaches.json";

    this->teams = read_teams(teamsFile);
    this->players = read_players(playersFile);
    this->coaches = read_coaches(coachesFile);
    this->matches = read_matches(matchesFile);

    this->link_all_data();
    generate_ranking();
}

void Tournament::link_all_data()
{
    // Link players and teams
    for (auto &player : players)
    {
        Team *team_ptr = this->find_team_by_id(player.getTId());
        player.setTeam(team_ptr);
        team_ptr->add_player(&player);
    }

    // Link coaches and teams
    for (auto &coach : coaches)
    {
        Team *team_ptr = this->find_team_by_id(coach.get_TId());
        coach.set_team(team_ptr);
        team_ptr->set_coach(&coach);
    }

    if (matches.size() != (team_required - 1) * team_required) return;
    // Link matches and teams, players(not yet have ptr for team to match)
    for (int i = 0, num = (team_required - 1) * 2; i < num; i++) {
        for (int j = 0, cc = team_required / 2; j < cc; j++) {
            int index = 10 * i + j;
            Team *home_team_ptr = this->find_team_by_id(matches[index].getHomeTeamId());
            Team *away_team_ptr = this->find_team_by_id(matches[index].getAwayTeamId());
            matches[index].setHomeTeam(home_team_ptr);
            matches[index].setAwayTeam(away_team_ptr);
            // team->match

            if (matches[index].get_updated() == 0) continue;
            std::vector<const Player*> home_lineup;
            for (int t = 0, sm = matches[index].getHomeLineupId().size(); t < sm; t++)
            {
                Player *player_ptr = this->find_player_by_id(matches[index].getHomeLineupId()[t]);
                home_lineup.push_back(player_ptr);
                player_ptr->upMatch();
            }
            matches[index].setHomeLineup(home_lineup);

            std::vector<const Player *> away_lineup;
            for (int t = 0, sm = matches[index].getAwayLineup().size(); t < sm; t++)
            {
                Player *player_ptr = this->find_player_by_id(matches[index].getAwayLineupId()[t]);
                away_lineup.push_back(player_ptr);
                player_ptr->upMatch();
            }
            matches[index].setAwayLineup(away_lineup);

            std::vector<Event> Events = matches[index].getEvents();
            int home = matches[index].getHomeScore();
            int away = matches[index].getAwayScore();
            for (int k = 0, knum = Events.size(); k < knum; k++) {
                Player* tegrat = find_player_by_id(Events[k].get_player_id());
                Events[k].set_player(tegrat);
                if (Events[k].get_event() == GOAL) {
                    tegrat->addGoals(1);
                } else if (Events[k].get_event() == ASSIST) {
                    tegrat->addAssists(1);
                } else if (Events[k].get_event() == YELLOW) {
                    tegrat->addYellowCards(1);
                } else {
                    tegrat->addRedCards(1);
                }
            }
            if (home == away) {
                home_team_ptr->up_tie();
                away_team_ptr->up_tie();
            } else if (home > away) {
                home_team_ptr->up_win();
                away_team_ptr->up_lose();
            } else {
                home_team_ptr->up_lose();
                away_team_ptr->up_win();
            }
            home_team_ptr->add_goal_scored(home);
            home_team_ptr->add_goal_conceded(away);
            away_team_ptr->add_goal_scored(away);
            away_team_ptr->add_goal_conceded(home);
        }
    }

    traverse_for_ban();
}

void Tournament::traverse_for_ban() {
    int rev = get_match_updated();
    std::vector<int> flint;
    for (int i = 0; i < team_required; i++) {
        flint.push_back(1);
    }
    int clipse = (rev - team_required + 1 > 0) ? rev - team_required + 1 : 0;
    for (int i = rev - 1; i >= clipse; i--) {
        int home = matches[i].getHomeTeamId();
        int away = matches[i].getAwayTeamId();
        if (flint[home - 1] == 1) {
            flint[home - 1]--;
            std::vector<Event> Events = matches[i].getEvents();
            std::map<std::string, int> foul;
            for (int j = 0, num = Events.size(); j < num; j++) {
                if (Events[j].get_side() == 0) {
                    if (Events[j].get_event() == YELLOW) {
                        foul[Events[j].get_player_id()]++;
                        if (foul[Events[j].get_player_id()] == 2) {
                            Player* tegrat = find_player_by_id(Events[j].get_player_id());
                            tegrat->setIsBan(find_team_by_id(home)->get_matches());
                        }
                    } else if (Events[j].get_event() == RED) {
                        Player* tegrat = find_player_by_id(Events[j].get_player_id());
                        tegrat->setIsBan(find_team_by_id(home)->get_matches());
                    }
                }
            }
        }
        if (flint[away - 1] == 1) {
            flint[away - 1]--;
            std::vector<Event> Events = matches[i].getEvents();
            std::map<std::string, int> foul;
            for (int j = 0, num = Events.size(); j < num; j++) {
                if (Events[j].get_side() == 1) {
                    if (Events[j].get_event() == YELLOW) {
                        foul[Events[j].get_player_id()]++;
                        if (foul[Events[j].get_player_id()] == 2) {
                            Player* tegrat = find_player_by_id(Events[j].get_player_id());
                            tegrat->setIsBan(find_team_by_id(away)->get_matches());
                        }
                    } else if (Events[j].get_event() == RED) {
                        Player* tegrat = find_player_by_id(Events[j].get_player_id());
                        tegrat->setIsBan(find_team_by_id(away)->get_matches());
                    }
                }
            }
        }
    }
}

void Tournament::write_all_data() {
    write_team();
    write_player();
    write_coach();
    write_match();
}

void Tournament::write_player() {
    std::string playersFile = "data/" + this->getSeason() + "/players.json";
    write_players(playersFile, players);
}

void Tournament::write_team() {
    std::string teamsFile = "data/" + this->getSeason() + "/teams.json";
    write_teams(teamsFile, teams);
}

void Tournament::write_coach() {
    std::string coachesFile = "data/" + this->getSeason() + "/coaches.json";
    write_coaches(coachesFile, coaches);
}

void Tournament::write_match() {
    std::string matchesFile = "data/" + this->getSeason() + "/matches.json";
    write_matches(matchesFile, matches);
}


// Other methods
void Tournament::generate_match() {
    bool hasFakeTeam = false;
    int numTeams = team_required;
    if (numTeams % 2 != 0) {
        numTeams++;
        hasFakeTeam = true;
    }

    //std::vector<std::pair<int, int>> go_rounds[numTeams - 1];
	std::unique_ptr<std::vector<std::pair<int, int>>[]> go_rounds(new std::vector<std::pair<int, int>>[numTeams - 1]);
    std::vector<int> team_id(numTeams);
    for (int i = 0; i < numTeams; ++i) {
        team_id[i] = i + 1;
    }

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(team_id.begin(), team_id.end(), g);

    for (int round = 0; round < numTeams - 1; ++round) {
        for (int i = 0; i < numTeams / 2; ++i) {
            int home = team_id[i];
            int away = team_id[numTeams - 1 - i];
            if (!(hasFakeTeam && (home == numTeams || away == numTeams))) {
                go_rounds[round].push_back({home, away});
            }
        }
        int first = team_id[1];
        for (int i = 1; i < numTeams - 1; ++i) {
            team_id[i] = team_id[i + 1];
        }
        team_id[numTeams - 1] = first;
    }

    for (int round = 0; round < numTeams - 1; ++round) {
        std::shuffle(go_rounds[round].begin(), go_rounds[round].end(), g);
    }

    //std::vector<std::pair<int, int>> away_rounds[numTeams - 1];
	std::unique_ptr<std::vector<std::pair<int, int>>[]> away_rounds(new std::vector<std::pair<int, int>>[numTeams - 1]);
    std::shuffle(team_id.begin(), team_id.end(), g);

    for (int round = 0; round < numTeams - 1; ++round) {
        for (int i = 0; i < numTeams / 2; ++i) {
            int away = team_id[i];
            int home = team_id[numTeams - 1 - i];
            if (!(hasFakeTeam && (home == numTeams || away == numTeams))) {
                away_rounds[round].push_back({home, away});
            }
        }
        int first = team_id[1];
        for (int i = 1; i < numTeams - 1; ++i) {
            team_id[i] = team_id[i + 1];
        }
        team_id[numTeams - 1] = first;
    }

    for (int round = 0; round < numTeams - 1; ++round) {
        std::shuffle(away_rounds[round].begin(), away_rounds[round].end(), g);
    }

    std::time_t now = std::time(nullptr);
    for (int round = 0; round < numTeams - 1; ++round) {
        for (int i = 0; i < numTeams / 2; i++) {
            std::string date = getFormattedDate(now + 7 * 86400 * round + 86400 * int(4 * i / numTeams));
            if (i % (numTeams / 4) == 0) {
                if (i == 0) {
                    Match match(matches.size() + 1, go_rounds[round][i].first, go_rounds[round][i].second, date, "19:30");
                    addMatch(match);
                }
                else {
                    Match match(matches.size() + 1, go_rounds[round][i].first, go_rounds[round][i].second, date, "02:30");
                    addMatch(match);
                }
            } else if (i < numTeams / 4) {
                Match match(matches.size() + 1, go_rounds[round][i].first, go_rounds[round][i].second, date, "22:00");
                addMatch(match);
            } else if (i != numTeams / 2) {
                Match match(matches.size() + 1, go_rounds[round][i].first, go_rounds[round][i].second, date, "21:00");
                addMatch(match);
            } else {
                Match match(matches.size() + 1, go_rounds[round][i].first, go_rounds[round][i].second, date, "23:30");
                addMatch(match);
            }
        }
    }

    for (int round = 0; round < numTeams - 2; ++round) {
        for (int i = 0; i < numTeams / 2; i++) {
            std::string date = getFormattedDate(now + 7 * 86400 * ((team_required - 1) + round) + 86400 * int(4 * i / numTeams));
            if (i % (numTeams / 4) == 0) {
                if (i == 0) {
                    Match match(matches.size() + 1, away_rounds[round][i].first, away_rounds[round][i].second, date, "19:30");
                    addMatch(match);
                }
                else {
                    Match match(matches.size() + 1, away_rounds[round][i].first, away_rounds[round][i].second, date, "02:30");
                    addMatch(match);
                }
            } else if (i < numTeams / 4) {
                Match match(matches.size() + 1, away_rounds[round][i].first, away_rounds[round][i].second, date, "22:00");
                addMatch(match);
            } else if (i != numTeams / 2) {
                Match match(matches.size() + 1, away_rounds[round][i].first, away_rounds[round][i].second, date, "21:00");
                addMatch(match);
            } else {
                Match match(matches.size() + 1, away_rounds[round][i].first, away_rounds[round][i].second, date, "23:30");
                addMatch(match);
            }
        }
    }

    for (int i = 0; i < numTeams / 2; i++) {
        std::string date = getFormattedDate(now + 7 * 86400 * (numTeams - 1) + 86400 * int(4 * i / numTeams));
        Match match(matches.size() + 1, away_rounds[numTeams - 2][i].first, away_rounds[numTeams - 2][i].second, date, "22:00");
        addMatch(match);
    }
    write_match();
}

bool Ascending(int a, int b) {
    return a < b;
}

bool Descending(int a, int b) {
    return a > b;
}

std::vector<Match> Tournament::list_match_by_TID(const int &team_id)
{
    std::vector<Match> res;
    if (matches.size() != 0) {
        for (int i = 0, num = matches.size(); i < num; i++)
        {
            if (matches[i].getHomeTeamId() == team_id || matches[i].getAwayTeamId() == team_id) {
                matches[i].displayMatchSummary();
                res.push_back(matches[i]);
            }
        }
    }
    return res;
}

std::vector<Player> Tournament::list_players_by_age(bool (*CompFunc)(int, int)) {
    std::vector<Player> res;

    if (!players.empty()) {
        res.push_back(players[0]);

        for (int i = 1, num = players.size(); i < num; i++) {
            bool inserted = false;
            int age = players[i].get_age();
            for (int j = 0; j < res.size(); j++) {
                if (!CompFunc(res[j].get_age(), age)) {
                    res.insert(res.begin() + j, players[i]);
                    inserted = true;
                    break;
                }
            }
            if (!inserted) {
                res.push_back(players[i]);
            }
        }
    }

    for (const auto& player : res) {
        std::cout << player.get_Name() << " - Age: " << player.get_age() << std::endl;
    }

    return res;
}


std::vector<Player> Tournament::list_players_by_born_year(int year) {
    std::vector<Player> res;
    for (int i = 0, num = players.size(); i < num; i++) {
        std::string birth_date = players[i].get_birth();

        if (birth_date.length() >= 10) {
            try {
                int year_int = std::stoi(birth_date.substr(6, 4));
                if (year_int = year) {
                    res.push_back(players[i]);
                }
            } catch (const std::invalid_argument& e) {
                std::cerr << "Error: Unable to convert birth year for player "
                          << players[i].get_Name() << " - Birth date: " << birth_date << std::endl;
            } catch (const std::out_of_range& e) {
                std::cerr << "Error: Birth year out of range for player "
                          << players[i].get_Name() << " - Birth date: " << birth_date << std::endl;
            }
        } else {
            std::cerr << "Warning: Invalid birth date format for player "
                      << players[i].get_Name() << " - Birth date: " << birth_date << std::endl;
        }
    }

    // Print results
    for (const auto& player : res) {
        std::cout << player.get_Name() << " " << player.get_birth() << std::endl;
    }
    return res;
}

std::vector<Player> Tournament::list_players_by_height(bool (*CompFunc)(int, int)) {
    std::vector<Player> res;
    if (!players.empty()) {
        res.push_back(players[0]);
        for (int i = 1, num = players.size(); i < num; i++) {
            bool inserted = false;
            int height = players[i].get_height();
            for (int j = 0; j < res.size(); j++) {
                if (CompFunc(height, res[j].get_height())) {
                    res.insert(res.begin() + j, players[i]);
                    inserted = true;
                    break;
                }
            }
            if (!inserted) {
                res.push_back(players[i]);
            }
        }
    }

    // // In tên cầu thủ đã sắp xếp
    for (const auto& player : res) {
        std::cout << player.get_Name() << " - Height: " << player.get_height() << std::endl;
    }

    return res;
}


std::vector<Player> Tournament::list_players_in_pos(std::string pos) {
    std::vector<Player> res;
    if (players.size() != 0) {
        for (int i = 0, num = players.size(); i < num; i++) {
            if (players[i].getPosition() == pos) {
                res.push_back(players[i]);
            }
        }
    }
    for (int i = 0, num = res.size(); i < num; i++) {
        std::cout << res[i].get_Name() << std::endl;
    }
    return res;
}

std::vector<Player> Tournament::list_player_by_goal(bool (*CompFunc)(int, int)) {
    std::vector<Player> res;
    if (players.size() != 0) {
        res.push_back(players[0]);
        for (int i = 1, num = players.size(); i < num; i++) {
            bool inserted = false;
            int goal = players[i].getGoals();
            for (int j = 0; j < res.size(); j++) {
                if (CompFunc(goal, res[j].getGoals())) {
                    res.insert(res.begin() + j, players[i]);
                    inserted = true;
                    break;
                }
            }
            if (!inserted) {
                res.push_back(players[i]);
            }
        }
    }
    for (const auto& player : res) {
        std::cout << player.get_Name() << " - Goals: " << player.getGoals() << std::endl;
    }

    return res;
}

std::vector<Player> Tournament::list_player_by_assist(bool (*CompFunc)(int, int)) {
    std::vector<Player> res;
    if (!players.empty()) {
        res.push_back(players[0]);
        for (int i = 1, num = players.size(); i < num; i++) {
            bool inserted = false;
            int assist = players[i].getAssists();
            for (int j = 0; j < res.size(); j++) {
                if (CompFunc(assist, res[j].getAssists())) {
                    res.insert(res.begin() + j, players[i]);
                    inserted = true;
                    break;
                }
            }
            if (!inserted) {
                res.push_back(players[i]);
            }
        }
    }

    //In tên cầu thủ đã sắp xếp theo assists
    for (const auto& player : res) {
        std::cout << player.get_Name() << " - Assists: " << player.getAssists() << std::endl;
    }

    return res;
}


std::vector<Player> Tournament::list_player_by_rc(bool (*CompFunc)(int, int)) {
    std::vector<Player> res;
    if (!players.empty()) {
        res.push_back(players[0]);
        for (int i = 1, num = players.size(); i < num; i++) {
            bool inserted = false;
            int rc = players[i].getRedCards();
            for (int j = 0; j < res.size(); j++) {
                if (CompFunc(rc, res[j].getRedCards())) {
                    res.insert(res.begin() + j, players[i]);
                    inserted = true;
                    break;
                }
            }
            if (!inserted) {
                res.push_back(players[i]);
            }
        }
    }

    // In danh sách cầu thủ sắp xếp theo số thẻ đỏ
    for (const auto& player : res) {
        std::cout << player.get_Name() << " - Red Cards: " << player.getRedCards() << " - BAN: " << player.getIsBan() << std::endl;
    }

    return res;
}


std::vector<Player> Tournament::list_player_by_yc(bool (*CompFunc)(int, int)) {
    std::vector<Player> res;
    if (!players.empty()) {
        res.push_back(players[0]);
        for (int i = 1, num = players.size(); i < num; i++) {
            bool inserted = false;
            int yc = players[i].getYellowCards();
            for (int j = 0; j < res.size(); j++) {
                if (CompFunc(yc, res[j].getYellowCards())) {
                    res.insert(res.begin() + j, players[i]);
                    inserted = true;
                    break;
                }
            }
            if (!inserted) {
                res.push_back(players[i]);
            }
        }
    }

    // In danh sách cầu thủ sắp xếp theo số thẻ vàng
    for (const auto& player : res) {
        std::cout << player.get_Name() << " - Yellow Cards: " << player.getYellowCards() << " - BAN: " << player.getIsBan() << std::endl;
    }

    return res;
}


std::vector<Match> Tournament::list_matches_by_day(std::string occured) {
    std::vector<Match> match;
    for (const auto& m : matches) {
        int compResult = compareDates(m.getDate(), occured);
        if (compResult > 0) {
            break;
        } else if (compResult == 0) {
            match.push_back(m);
        }
    }
    for (int i = 0, num = match.size(); i < num; i++) {
        match[i].displayMatchSummary();
    }
    return match;
}

std::vector<Match> Tournament::list_matches_by_month(int month) {
    std::vector<Match> match;
    for (const auto& m : matches) {
        int month_int = std::stoi(m.getDate().substr(3, 2));
        if (month_int == month) match.push_back(m);
    }
    for (int i = 0, num = match.size(); i < num; i++) {
        match[i].displayMatchSummary();
    }
    return match;
}

std::vector<Match> Tournament::list_matches_by_round(int round) {
    std::vector<Match> match;
    for (int i = (round - 1) * int(team_required / 2), num = (round) * int(team_required / 2) ; i < num; i++) {
        match.push_back(matches[i]);
    }
    for (int i = 0, num = match.size(); i < num; i++) {
        match[i].displayMatchSummary();
    }
    return match;
}

std::vector<Match> Tournament::list_matches() {
    for (int i = 0, num = matches.size(); i < num; i++) {
        matches[i].displayMatch();
    }
    return matches;
}

std::vector<Player> Tournament::list_free_players() {
    std::vector<Player> res;
    for (int i = 0, num = players.size(); i < num; i++) {
        if (players[i].getTeam() == nullptr) {
            res.push_back(players[i]);
        }
    }
    return res;
}

// Rank
void Tournament::generate_ranking() {
    for (int i = 0, num = teams.size(); i < num; i++) {
        ranking.push_back({&teams[i], teams[i].get_points(), teams[i].get_secondary_points(), teams[i].get_goal_scored()});
    }
}
void Tournament::updateRanking() {
    ranking.clear();
    generate_ranking();
    std::sort(ranking.begin(), ranking.end());
    return;
}

void Tournament::displayRanking() const {
    std::cout << "Tournament Ranking:\n";
    int rank = 1;
    for (const auto& entry : ranking) {
        std::cout << rank++ << ". " << entry.team->get_abb() << " - " << entry.points << " - " << entry.secondary_points << std::endl;
    }
}

void Tournament::delete_player(Player& gone) {
    if (state != PRE) {
        std::cout << "Cannot delete during this duration!\n";
        return;
    }
    Player* play = find_player_by_id(gone.getId());
    if (play->getTeam() != nullptr) {
        Team* team = find_team_by_id(play->getTId());
        team->remove_player(play);
        play->leave_team();
    }
   players.erase(std::remove_if(players.begin(), players.end(),
             [&](const Player& p) { return &p == play; }), players.end());
    write_player();
    write_team();
}

void Tournament::remove_player(Player& gone) {
    Player* play = find_player_by_id(gone.getId());
    if (play->getTeam() != nullptr) {
        Team* team = find_team_by_id(play->getTId());
        team->remove_player(play);
        play->leave_team();
    }
    write_player();
    write_team();
}

void Tournament::delete_coach(Coach& gone) {
    if (state != PRE) {
        std::cout << "Cannot delete during this duration!\n";
        return;
    }
    Coach* play = find_coach_by_id(gone.get_Id());
    if (play->get_team() != nullptr) {
        Team* team = find_team_by_id(play->get_TId());
        team->remove_coach();
        play->leave_team();
    }
    coaches.erase(std::remove_if(coaches.begin(), coaches.end(),
             [&](const Coach& p) { return &p == play; }), coaches.end());
    write_coach();
    write_team();
}

void Tournament::remove_coach(Coach& gone) {
    Coach* play = find_coach_by_id(gone.get_Id());
    if (play->get_team() != nullptr) {
        Team* team = find_team_by_id(play->get_TId());
        team->remove_coach();
        play->leave_team();
    }
    write_coach();
    write_team();
}

void Tournament::display() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Season: " << season << std::endl;
    std::cout << "State: " << state << std::endl;
    std::cout << "Team participate: " << team_required << std::endl;
}

std::vector<Match> Tournament::list_upcoming_matches(int num) {
    int current = get_match_occured();
    std::vector<Match> res;
    for (int i = 0; i < num; i++) {
        res.push_back(matches[current + i]);
    }
    return res;
}
