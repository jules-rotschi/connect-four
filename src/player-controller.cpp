#include <iostream>
#include <limits>
#include "../headers/player-controller.h"

void RealPlayerController::let_player_set_name(Player &player, std::string &name_variable) {
  while (!(std::cin >> name_variable) || name_variable.length() < 2) {
    if (std::cin.eof()) {
      throw std::runtime_error("Le flux a été fermé !");
    } else if (std::cin.fail()) {
      std::cout << "Entrée invalide." << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } else {
      std::cout << "Ton nom doit comporter au moins deux lettres." << std::endl;
    }
  }
  player.let_set_name(name_variable);
}

void RealPlayerController::let_player_play(Player const &player, ConnectFourGame &game) {
  std::cout << "Entrez le numéro de la colonne où vous voulez jouer (entre 0 et 6): ";
  int column { 0 };
  while (!(std::cin >> column) || column > 7 || column < 1) {
    if (std::cin.eof()) {
      throw std::runtime_error("Le flux a été fermé !");
    } else if (std::cin.fail()) {
      std::cout << "Entrée invalide." << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } else {
      std::cout << "Les colonnes sont numérotées de 1 à 7. Entrez un nombre compris dans cet intervalle." << std::endl;
    }
  }
  game.play_token(column, player);
}