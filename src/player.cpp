#include "../headers/player.h"

Player::Player(int id, char token) : id(id), token(token) {
  m_controller = RealPlayerController {};
  name = "Player";
}

void Player::let_set_name(std::string &name_variable) {
  m_controller.let_player_set_name(*this, name_variable);
  name = name_variable;
}

void Player::let_play(ConnectFourGame &game) {
  m_controller.let_player_play(*this, game);
}