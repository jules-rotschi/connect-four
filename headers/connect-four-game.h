#ifndef GAME_H
#define GAME_H

#include <array>
#include <string>
#include <memory>

#include "grid.h"

class Player;

class ConnectFourGame {
private:
  std::unique_ptr<Grid> m_grid;
  Player *m_player_1;
  Player *m_player_2;
  Player *m_current_player;

  bool check_winner(Player const &player) const;
  void switch_current_player();
  void print_grid() const;

public:
  ConnectFourGame() = delete;
  ConnectFourGame(Player *player_1, Player *player_2);
  void start();
  bool is_grid_empty() const;
  Grid copy_grid() const;
  bool play_token(int column, Player const &player);
};

void initialize_players(Player &player_1, Player &player_2);

#endif