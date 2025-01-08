#ifndef INCLUDE_PLAYER
#define INCLUDE_PLAYER

#include <string>

class PlayerController;
class ConnectFourGame;

class Player {
  private:
    PlayerController *m_controller;
  
  public :
    int id;
    char token;
    std::string name;

    Player(int id, char token);
    void let_set_name(std::string &name_variable);
    void let_play(ConnectFourGame &game);
};

bool operator==(Player const &player_1, Player const &player_2);

#endif