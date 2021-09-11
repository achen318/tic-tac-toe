#ifndef GAME_H
#define GAME_H

#include "ui_tictactoe.h"

class Game
{
public:
    // Accessors
    QList<QPushButton *> board();
    char box(int index);

    char turn();

    bool game_over();

    int x_score();
    int o_score();

    // Mutators
    void append_to_board(QPushButton *box);
    void set_box(int index, char value);

    void switch_turn();

    void set_game_over(bool game_state);

    void increment_x_score();
    void increment_o_score();

    // Other member functions
    void NewGame();
    char GetWinner();

private:
    QList<QPushButton *> board_{};

    char turn_{'X'};

    bool game_over_{false};

    int x_score_{0};
    int o_score_{0};
};

#endif // GAME_H
