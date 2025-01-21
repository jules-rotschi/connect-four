#include <iostream>

#include "grid.h"
#include "player.h"

Grid::Grid() {
  std::array<int, GRID_COLUMN_COUNT> default_line;
  default_line.fill(0);
  m_data.fill(default_line);
}

void Grid::print(Player const &player_1, Player const &player_2) const {
  std::cout << " 1 2 3 4 5 6 7 " << std::endl;
  for (const auto &line : m_data) {
    for (const auto &box : line) {
      char character_to_display = ' ';
      if (box == player_1.id) {
        character_to_display = player_1.token;
      }
      if (box == player_2.id) {
        character_to_display = player_2.token;
      }
      std::cout << "|" << character_to_display;
    }
    std::cout << "|\n";
  }
  std::cout << std::endl;
}

bool Grid::is_empty() const {
  for (const auto &line : m_data) {
    for (const auto &box : line) {
      if (box != 0) return false;
    }
  }
  return true;
}

bool Grid::is_column_full(int column) const {
  return m_data[0][column] != 0;
}

bool Grid::is_full() const {
  for (int i = 0; i < GRID_COLUMN_COUNT; i++) {
    if (!is_column_full(i)) {
      return false;
    }
  }
  return true;
}

bool Grid::check_winner(int player_id) const {
  bool win = false;
  for (int line = 0; line < std::size(m_data); line++) {
    for (int box = 0; box < std::size(m_data[line]); box++) {

      bool horizontal =
        box <= std::size(m_data[line]) - 4
        && m_data[line][box] == player_id
        && m_data[line][box] == m_data[line][box + 1]
        && m_data[line][box] == m_data[line][box + 2]
        && m_data[line][box] == m_data[line][box + 3];
      
      bool vertical =
        line <= std::size(m_data) - 4
        && m_data[line][box] == player_id
        && m_data[line][box] == m_data[line + 1][box]
        && m_data[line][box] == m_data[line + 2][box]
        && m_data[line][box] == m_data[line + 3][box];
      
      bool diagonal =
        line <= std::size(m_data) - 4
        && m_data[line][box] == player_id
        && ((box <= std::size(m_data[line]) - 4
        && m_data[line][box] == m_data[line + 1][box + 1]
        && m_data[line][box] == m_data[line + 2][box + 2]
        && m_data[line][box] == m_data[line + 3][box + 3])
        || (box >= 3
        && m_data[line][box] == m_data[line + 1][box - 1]
        && m_data[line][box] == m_data[line + 2][box - 2]
        && m_data[line][box] == m_data[line + 3][box - 3]));

      if (horizontal || vertical || diagonal) {
        win = true;
        break;
      }
    }
  }
  return win;
}

bool Grid::play_token(int column, int token_id) {
  bool played = false;
  for (int line = 0; line < std::size(m_data); line++) {
    if (m_data[line][column - 1] == 0 && (line == std::size(m_data) - 1 || m_data[line + 1][column - 1] != 0)) {
      m_data[line][column - 1] = token_id;
      played = true;
      break;
    }
  }
  return played;
}