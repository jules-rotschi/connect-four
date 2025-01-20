#include <iostream>
#include <string>
#include <array>
#include <limits>

#include "player.h"
#include "connect-four-game.h"
#include "input.h"

int main(int argc, char **argv) {

  Player player_1;
  Player player_2;

  initialize_players(player_1, player_2);

  std::string player_name;

  player_1.let_set_name(player_name);
  player_2.let_set_name(player_name);

  ConnectFourGame game { &player_1, &player_2 };
  game.start();

  std::cin.get();

  return 0;
}