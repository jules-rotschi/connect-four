#ifndef INCLUDE_PLAYER
#define INCLUDE_PLAYER

#include <string>
#include "../headers/player-controller.h"
#include "../headers/connect-four-game.h"

class Player {
  private:
    PlayerController m_controller;
  
  public :
    int id;
    char token;
    std::string name;

    Player(int id, char token);
    void let_set_name(std::string &name_variable);
    void let_play(ConnectFourGame &game);
};

bool operator==(Player const &player_1, Player const &player_2) {
  return player_1.id == player_2.id;
}

#endif