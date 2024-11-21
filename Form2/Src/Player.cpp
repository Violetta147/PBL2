#include "../include/Player.h"
#include "../include/Team.h"

// Constructor
Player::Player() {}
Player::Player(const std::string human_id, const std::string &first_name,
               const std::string &last_name, const std::string &country,
               const std::string &birth, int height, int weight, const std::string id, int jersey,
               int team_id, const std::string &pos, int goal, int ass, int red, int yellow,
               int is_ban, int match)
    : Human(human_id, first_name, last_name, country, birth, height, weight), player_id(id),
      jersey_num(jersey), team_id(team_id), team(nullptr), position(pos), goal(goal), assist(ass),
      red_card(red), yellow_card(yellow), is_ban(is_ban), match(match)
{
}

// Getter and Setter for id
void Player::setId(std::string id)
{
    player_id = id;
}

std::string Player::getId() const
{
    return player_id;
}

// Getter and setter for team Id
void Player::setTId(int t_id)
{
    team_id = t_id;
}

int Player::getTId() const
{
    return team_id;
}

// Getter and Setter for team
void Player::setTeam(const Team *t)
{
    team = t;
}

const Team *Player::getTeam() const
{
    return team;
}

// Getter and Setter for jersey number
int Player::getNum() const
{
    return jersey_num;
}

void Player::setNum(int num)
{
    jersey_num = num;
}

// Getter and Setter for position
std::string Player::getPosition() const
{
    return position;
}

void Player::setPosition(const std::string &pos)
{
    position = pos;
}

// Getter and Setter for goals
int Player::getGoals() const
{
    return goal;
}

void Player::addGoals(int goals)
{
    goal += goals;
}

void Player::setGoals(int goals)
{
    goal = goals;
}

// Getter and Setter for assists
int Player::getAssists() const
{
    return assist;
}

void Player::addAssists(int assists)
{
    assist += assists;
}

void Player::setAssists(int assists)
{
    assist = assists;
}

// Getter and Setter for red cards
int Player::getRedCards() const
{
    return red_card;
}

void Player::addRedCards(int red)
{
    red_card += red;
}

void Player::setRedCards(int red)
{
    red_card = red;
}

// Getter and Setter for yellow cards
int Player::getYellowCards() const
{
    return yellow_card;
}

void Player::addYellowCards(int yellow)
{
    yellow_card += yellow;
}

void Player::setYellowCards(int yellow)
{
    yellow_card = yellow;
}

// Getter and Setter for ban status
int Player::getIsBan() const
{
    return is_ban;
}

void Player::setIsBan(int is_ban)
{
    this->is_ban = is_ban;
}

// Getter and Setter for match
void Player::setMatch(int match)
{
    this->match = match;
}

int Player::getMatch() const
{
    return match;
}

void Player::upMatch() {
    match += 1;
}

// JSON -> Player
Player Player::from_json(const json &j)
{
    return Player(
        j.at("human_id").get<std::string>(), j.at("first_name").get<std::string>(),
        j.at("last_name").get<std::string>(), j.at("country").get<std::string>(),
        j.at("birth").get<std::string>(), j.at("height").get<int>(), j.at("weight").get<int>(),
        j.at("player_id").get<std::string>(), j.at("jersey_num").get<int>(),
        j.at("team_id").get<int>(), j.at("position").get<std::string>());
}

// Player -> JSON
void Player::to_json(json &j, const Player &p)
{
    j = json{{"human_id", p.get_Id()},
             {"first_name", p.get_first_name()},
             {"last_name", p.get_last_name()},
             {"country", p.get_nation()},
             {"birth", p.get_birth()},
             {"height", p.get_height()},
             {"weight", p.get_weight()},
             {"player_id", p.getId()},
             {"jersey_num", p.getNum()},
             {"team_id", p.getTId()},
             {"position", p.getPosition()}};
}

// Display player information
void Player::display() const
{
    std::cout << "Player ID: " << player_id << "\n"
              << "Player name: " << get_Name() << "\n"
              << "Birthday: " << get_birth() << std::endl
              << "Age: " << get_age() << std::endl
              << "Country: " << get_nation() << std::endl
              << "Height: " << get_height() << std::endl
              << "Weight: " << get_weight() << std::endl
              << "Jersey Number: " << jersey_num << "\n"
              << "Position: " << position << "\n"
              << "Goals: " << goal << "\n"
              << "Assists: " << assist << "\n"
              << "Red Cards: " << red_card << "\n"
              << "Yellow Cards: " << yellow_card << "\n"
              << "Is Banned: " << (is_ban ? "Yes" : "No") << "\n"
              << "Matches Played: " << match << std::endl;
    if (team) {
        std::cout << "Team: " << team->get_name() << "\n";
    } else {
        std::cout << "No team assigned.\n";
    }
}

// Leave
void Player::leave_team() {
    setTeam(nullptr);
}
