#ifndef GAME_H
#define GAME_H

#include <array>
#include <string>

class Player;

typedef std::array<std::array<int, 7>, 6> Grid;

class ConnectFourGame {
  private:
    Grid m_grid;
    Player *m_player_1;
    Player *m_player_2;
    Player *m_current_player;

    bool check_winner(Player const &player);
    void switch_current_player();
    void print_grid();
  
  public:
    ConnectFourGame() = delete;
    ConnectFourGame(Player *player_1, Player *player_2);
    void start();
    bool play_token(int column, Player player);
};

void initialize_players(Player &player_1, Player &player_2);

#endif