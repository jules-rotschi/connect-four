#include <iostream>
#include "../headers/connect-four-game.h"

bool ConnectFourGame::play_token(int column, Player player) {
  bool played = false;
  for (int line = 0; line < std::size(m_grid); line++) {
    if (line == std::size(m_grid) - 1 || m_grid[line + 1][column] != ' ') {
      m_grid[line][column] = player.id;
      played = true;
      break;
    }
  }
  if (!played) {
    std::cout << "La colonne est pleine" << std::endl;
    return false;
  }
  return true;
}

bool ConnectFourGame::check_winner(Player &player) {
  bool win = false;
  for (int line = 0; line < std::size(m_grid); line++) {
    for (int box = 0; box < std::size(m_grid[line]); box++) {

      bool horizontal =
        box <= std::size(m_grid[line]) - 4
        && m_grid[line][box] == player.id
        && m_grid[line][box] == m_grid[line][box + 1]
        && m_grid[line][box] == m_grid[line][box + 2]
        && m_grid[line][box] == m_grid[line][box + 3];
      
      bool vertical =
        line <= std::size(m_grid) - 4
        && m_grid[line][box] == player.id
        && m_grid[line][box] == m_grid[line + 1][box]
        && m_grid[line][box] == m_grid[line + 2][box]
        && m_grid[line][box] == m_grid[line + 3][box];
      
      bool diagonal =
        line <= std::size(m_grid) - 4
        && m_grid[line][box] == player.id
        && ((box <= std::size(m_grid[line]) - 4
        && m_grid[line][box] == m_grid[line + 1][box + 1]
        && m_grid[line][box] == m_grid[line + 2][box + 2]
        && m_grid[line][box] == m_grid[line + 3][box + 3])
        || (box >= 3
        && m_grid[line][box] == m_grid[line + 1][box - 1]
        && m_grid[line][box] == m_grid[line + 2][box - 2]
        && m_grid[line][box] == m_grid[line + 3][box - 3]));

      if (horizontal || vertical || diagonal) {
        win = true;
        break;
      }
    }
  }
  return win;
}

void ConnectFourGame::switch_player(Player &current_player) {
  if (current_player == m_player_1) {
    current_player = m_player_2;
    return;
  }
  if (current_player == m_player_2) {
    current_player = m_player_1;
  }
}

void ConnectFourGame::print_grid() {
  std::cout << " 1 2 3 4 5 6 7 " << std::endl;
  for (const auto &line : m_grid) {
    for (const auto &box : line) {
      char character_to_display = ' ';
      if (box == m_player_1.id) {
        character_to_display = m_player_1.token;
      }
      if (box == m_player_2.id) {
        character_to_display = m_player_2.token;
      }
      std::cout << "|" << character_to_display;
    }
    std::cout << "|\n";
  }
  std::cout << std::endl;
}

ConnectFourGame::ConnectFourGame(Player player_1, Player player_2)
  : m_player_1(player_1), m_player_2(player_2) {
  std::array<int, 7> default_line;
  default_line.fill(0);
  m_grid.fill(default_line);
}

void ConnectFourGame::start() {
  Player *winner;
  Player *current_player = &m_player_1;
  while (true) {
    print_grid();
    current_player->let_play(*this);
    if (check_winner(*current_player)) {
      winner = current_player;
      break;
    }
    switch_player(*current_player);
  }
  std::cout << winner->name << " a gagné !" << std::endl;
  print_grid();
}