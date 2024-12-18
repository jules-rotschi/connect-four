#ifndef INCLUDE_PLAYER_CONTROLLER
#define INCLUDE_PLAYER_CONTROLLER

#include "../headers/player.h"
#include "../headers/connect-four-game.h"

class Player;

class PlayerController {
  public:
    virtual void let_player_set_name(Player &player, std::string &name_variable);
    virtual void let_player_play(Player const &player, ConnectFourGame &game);
};

class RealPlayerController : public PlayerController {
  public:
    void let_player_set_name(Player &player, std::string &name_variable) override;
    void let_player_play(Player const &player, ConnectFourGame &game) override;
};

#endif