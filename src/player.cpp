#include <iostream>

#include "../headers/player.h"
#include "../headers/player-controller.h"

Player::Player(int id, char token, bool real) : id(id), token(token) {
  if (real) {
    m_controller = new RealPlayerController();
  } else {
    m_controller = new AIController();
  }
  name = "Player";
  this->real = real;
}

void Player::let_set_name(std::string &name_variable) {
  m_controller->let_player_set_name(*this, name_variable);
  name = name_variable;
}

void Player::let_play(ConnectFourGame &game) {
  m_controller->let_player_play(*this, game);
}

bool operator==(Player const &player_1, Player const &player_2) {
  return player_1.id == player_2.id;
}