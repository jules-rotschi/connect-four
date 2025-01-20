#ifndef GRID_H
#define GRID_H

#include <array>

class Player;

class Grid {
private:
  std::array<std::array<int, 7>, 6> m_data;

public:
  Grid();
  void print(Player const &player_1, Player const &player_2) const;
  bool is_empty() const;
  bool is_column_full(int column) const;
  bool is_full() const;
  bool check_winner(Player const &player) const;
  bool play_token(int column, int player_id);
};

#endif