#ifndef INCLUDE_GAME
#define INCLUDE_GAME

#include <array>
#include <string>

class Player;

typedef std::array<std::array<int, 7>, 6> Grid;

class ConnectFourGame {
  private:
    Grid m_grid;
    Player *m_player_1;
    Player *m_player_2;

    bool check_winner(Player &player);
    void switch_player(Player &current_player);
    void print_grid();
  
  public:
    ConnectFourGame() = delete;
    ConnectFourGame(Player *player_1, Player *player_2);
    void start();
    bool play_token(int column, Player player);
};

#endif