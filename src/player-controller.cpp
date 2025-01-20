#include <iostream>
#include <limits>

#include "input.h"
#include "player-controller.h"
#include "player.h"
#include "connect-four-game.h"

RealPlayerController::RealPlayerController() {}

void RealPlayerController::let_player_set_name(Player &player, std::string &out_name) const {
  std::cout << "Joueur " << player.id << ", entre ton nom : ";
  auto name_validator = [](std::string &name) -> bool { return name.length() >= 2; };
  input(out_name, name_validator, "Ton nom doit comporter au moins deux lettres. Entre un nom plus long : ");
  std::cout << "\n";
  player.name = out_name;
}

void RealPlayerController::let_player_play(Player const &player, ConnectFourGame &game) const {
  std::cout << player.name << ", à toi de jouer ! Entre le numéro de la colonne où tu veux jouer (entre 1 et 7): ";
  int column { 0 };
  bool is_token_played {false};
  auto column_validator = [](int column) -> bool { return column <= 7 || column >= 1; };
  while (!is_token_played) {
    input(column, column_validator, "Les colonnes sont numérotées de 1 à 7. Entre un nombre compris dans cet intervalle : ");
    is_token_played = game.play_token(column, player);
    if (!is_token_played) {
      std::cout << u8"La colonne est complète, choisis-en une autre ! ";
    }
  }
  std::cout << "\n";
}

AIController::AIController() {}

void AIController::let_player_set_name(Player &player, std::string &out_name) const {
  player.name = "AI Player";
}

void AIController::let_player_play(Player const &player, ConnectFourGame &game) const {
  game.play_token(1, player);
}