#include <iostream>
#include <memory>

#include "connect-four-game.h"
#include "player.h"
#include "input.h"
#include "grid.h"

bool ConnectFourGame::play_token(int column, Player const &player) {
  return m_grid->play_token(column, player.id);
}

bool ConnectFourGame::check_winner(Player const &player) const {
  return m_grid->check_winner(player.id);
}

void ConnectFourGame::switch_current_player() {
  if (m_current_player == m_player_1) {
    m_current_player = m_player_2;
    return;
  }
  if (m_current_player == m_player_2) {
    m_current_player = m_player_1;
  }
}

void ConnectFourGame::print_grid() const {
  m_grid->print(*m_player_1, *m_player_2);
}

ConnectFourGame::ConnectFourGame(Player *player_1, Player *player_2)
  : m_player_1(player_1), m_player_2(player_2) {
  m_grid = std::make_unique<Grid>();
}

void ConnectFourGame::start() {
  Player *winner;
  m_current_player = m_player_1;
  while (true) {
    print_grid();
    m_current_player->let_play(*this);
    if (check_winner(*m_current_player)) {
      winner = m_current_player;
      break;
    }
    if (m_grid->is_full()) {
      break;
    }
    switch_current_player();
  }
  print_grid();
  if (winner) {
    std::cout << winner->name << " a gagné !\n" << std::endl;
  } else {
    std::cout << "Match null !\n" << std::endl;
  }
}

bool ConnectFourGame::is_grid_empty() const {
  return m_grid->is_empty();
}

Grid ConnectFourGame::copy_grid() const {
  return Grid(*m_grid);
}

void initialize_players(Player &player_1, Player &player_2) {
  int players_count = 0;

  std::cout << "Combien de joueurs réels ? (1 ou 2) ";
  auto player_count_validator = [](int count) -> bool { return (count == 1 || count == 2); };
  input(players_count, player_count_validator, "Vous devez être 1 ou 2 joueurs pour jouer. Entre 1 ou 2 : ");

  char player_first = ' ';

  if (players_count == 1) {
    std::cout << "Veux-tu commencer à jouer ? (O/N) ";
    auto player_first_validator = [](char player_first) -> bool { return (player_first == 'O' || player_first == 'N'); };
    input(player_first, player_first_validator, "Entre \"O\" ou \"N\" : ");
  }

  player_1 = { 1, 'O', player_first == 'O' || players_count == 2 };
  player_2 = { 2, 'X', player_first == 'N' || players_count == 2 };
}