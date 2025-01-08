#include <iostream>
#include <limits>
#include "../headers/player-controller.h"
#include "../headers/player.h"
#include "../headers/connect-four-game.h"

void PlayerController::let_player_set_name(Player &player, std::string &name_variable) {}
void PlayerController::let_player_play(Player const &player, ConnectFourGame &game) {}

RealPlayerController::RealPlayerController() {}

void RealPlayerController::let_player_set_name(Player &player, std::string &name_variable) {
  while (!(std::cin >> name_variable) || name_variable.length() < 2) {
    if (std::cin.eof()) {
      throw std::runtime_error("Le flux a été fermé");
    } else if (std::cin.fail()) {
      std::cout << "Entrée invalide. Recommence : ";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } else {
      std::cout << "Ton nom doit comporter au moins deux lettres. Entre un nom plus long : ";
    }
  }
  std::cout << "\n";
  player.name = name_variable;
}

void RealPlayerController::let_player_play(Player const &player, ConnectFourGame &game) {
  std::cout << player.name << ", à toi de jouer ! Entre le numéro de la colonne où tu veux jouer (entre 1 et 7): ";
  int column { 0 };
  bool is_token_played {false};
  while (!is_token_played) {
    while (!(std::cin >> column) || column > 7 || column < 1) {
      if (std::cin.eof()) {
        throw std::runtime_error("Le flux a été fermé !\n");
      } else if (std::cin.fail()) {
        std::cout << "Entrée invalide. Recommence : ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      } else {
        std::cout << "Les colonnes sont numérotées de 1 à 7. Entre un nombre compris dans cet intervalle : ";
      }
    }
    is_token_played = game.play_token(column, player);
    if (!is_token_played) {
      std::cout << "La colonne est complète, choisis-en une autre ! ";
    }
  }
  std::cout << "\n";
}