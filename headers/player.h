#ifndef PLAYER_H
#define PLAYER_H

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
    bool real;

    Player() = default;
    Player(int id, char token, bool real);
    void let_set_name(std::string &name_variable);
    void let_play(ConnectFourGame &game);
};

bool operator==(Player const &player_1, Player const &player_2);

#endif