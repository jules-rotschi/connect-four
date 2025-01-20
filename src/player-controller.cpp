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
      std::cout << "La colonne est complète, choisis-en une autre ! ";
    }
  }
  std::cout << "\n";
}

AIController::AIController() {}

void AIController::let_player_set_name(Player &player, std::string &out_name) const {
  out_name = "IA";
  player.name = out_name;
}

void AIController::let_player_play(Player const &player, ConnectFourGame &game) const {
  std::cout << player.name << ", à toi de jouer !\n" << std::endl;
  if (game.is_grid_empty()) {
    game.play_token(4, player);
  }
  std::array<bool, 7> possible_moves;
  possible_moves.fill(true);

  Grid current_grid = game.copy_grid();

  for (int i = 0; i < 7; i++) {
    if (current_grid.is_column_full(i)) {
      possible_moves[i] = false;
    }
  }

  int possible_moves_count = 0;

  for (bool const move : possible_moves) {
    possible_moves_count += move;
  }

  if (possible_moves_count == 1) {
    for (int i = 0; i < 7; i++) {
      if (possible_moves[i]) {
        game.play_token(i, player);
      }
    }
  }

  Grid virtual_grid;

  for (int i = 0; i < 7; i++) {
    virtual_grid = current_grid;
    virtual_grid.play_token(i, player.id);
    if (virtual_grid.check_winner(player)) {
      game.play_token(i, player);
    }
  }  
}