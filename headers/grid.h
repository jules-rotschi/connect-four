#ifndef GRID_H
#define GRID_H

#include <array>

#define GRID_COLUMN_COUNT 7
#define GRID_LINE_COUNT 6

class Player;

class Grid {
private:
  std::array<std::array<int, GRID_COLUMN_COUNT>, GRID_LINE_COUNT> m_data;

public:
  Grid();
  void print(Player const &player_1, Player const &player_2) const;
  bool is_empty() const;
  bool is_column_full(int column) const;
  bool is_full() const;
  bool check_winner(int player_id) const;
  bool play_token(int column, int player_id);
};

#endif