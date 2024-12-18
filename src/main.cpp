#include <iostream>
#include <array>
#include <limits>
#include "../headers/player.h"
#include "../headers/connect-four-game.h"

int main(int argc, char **argv) {
  Player player_1 { 1, 'O' };
  Player player_2 { 2, 'X' };

  std::string player_name { "" };

  std::cout << "Joueur 1, entre ton nom : ";
  player_1.let_set_name(player_name);

  std::cout << "Joueur 2, entre ton nom : ";
  player_2.let_set_name(player_name);

  ConnectFourGame game { player_1, player_2 };
  game.start();

  return 0;
}