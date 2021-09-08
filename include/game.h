#ifndef GAME_H
#define GAME_H

#include <array>

class Game
{
public:
    Game();

    char box(int index) { return board_[index]; };
    std::array<char, 9> board() { return board_; };
    char turn() { return turn_; };
    bool game_over() { return game_over_; };
    int x_score() { return x_score_; };
    int o_score() { return o_score_; };

    void set_box(int index, char value) { board_[index] = value; };
    void switch_turn() { turn_ = (turn_ == 'X') ? 'O' : 'X'; };
    void set_game_over(bool game_state) { game_over_ = game_state; };
    void increment_x_score() { ++x_score_; };
    void increment_o_score() { ++o_score_; };

    void NewGame();
    char GetWinner();

private:
    std::array<char, 9> board_{}; // filled with ' '
    char turn_{'X'};

    bool game_over_{false};

    int x_score_{0};
    int o_score_{0};
};

#endif // GAME_H
