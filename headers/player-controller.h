#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include <string>

class Player;
class ConnectFourGame;

class PlayerController {
  public:
    virtual void let_player_set_name(Player &player, std::string &name_variable);
    virtual void let_player_play(Player const &player, ConnectFourGame &game);
};

class RealPlayerController : public PlayerController {
  public:
    RealPlayerController();
    void let_player_set_name(Player &player, std::string &name_variable) override;
    void let_player_play(Player const &player, ConnectFourGame &game) override;
};

class AIController : public PlayerController {
  public:
    AIController();
    void let_player_set_name(Player &player, std::string &name_variable) override;
    void let_player_play(Player const &player, ConnectFourGame &game) override;
};

#endif