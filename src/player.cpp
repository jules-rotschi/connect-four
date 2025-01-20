#include <iostream>

#include "player.h"
#include "player-controller.h"

Player::Player(int id, char token, bool real) : id(id), token(token) {
  if (real) {
    m_controller = std::make_unique<RealPlayerController>();
  } else {
    m_controller = std::make_unique<AIController>();
  }
  name = "Player";
  this->real = real;
}

void Player::let_set_name(std::string &out_name) {
  m_controller->let_player_set_name(*this, out_name);
  name = out_name;
}

void Player::let_play(ConnectFourGame &game) const {
  m_controller->let_player_play(*this, game);
}

bool operator==(Player const &player_1, Player const &player_2) {
  return player_1.id == player_2.id;
}