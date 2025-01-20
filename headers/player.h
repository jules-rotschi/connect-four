#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <memory>

#include "player-controller.h"

class ConnectFourGame;

class Player {
  private:
    std::unique_ptr<PlayerController> m_controller;
  
  public :
    int id;
    char token;
    std::string name;
    bool real;

    Player() = default;
    Player(int id, char token, bool real);
    void let_set_name(std::string &out_name);
    void let_play(ConnectFourGame &game) const;
};

bool operator==(Player const &player_1, Player const &player_2);

#endif