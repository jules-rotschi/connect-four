#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include <string>

class Player;
class ConnectFourGame;

class PlayerController {
  public:
    virtual void let_player_set_name(Player &player, std::string &out_name) const = 0;
    virtual void let_player_play(Player const &player, ConnectFourGame &game) const = 0;
};

class RealPlayerController : public PlayerController {
  public:
    RealPlayerController();
    void let_player_set_name(Player &player, std::string &out_name) const override;
    void let_player_play(Player const &player, ConnectFourGame &game) const override;
};

class AIController : public PlayerController {
  public:
    AIController();
    void let_player_set_name(Player &player, std::string &out_name) const override;
    void let_player_play(Player const &player, ConnectFourGame &game) const override;
};

#endif