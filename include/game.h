#ifndef GAME_H
#define GAME_H

#include "ui_tictactoe.h"

class Game
{
public:
    /**
     * @returns A QList of QPushButton pointers.
     */
    QList<QPushButton *> board();

    /**
     * @param index An integer value between 0 and 8.
     * @returns The QPushButton text ('X', 'O', '\\0') that is at index in board().
     */
    char box(int index);

    /**
     * @returns The current player ('X', 'O').
     */
    char turn();

    /**
     * @returns Whether or not the game is over.
     */
    bool game_over();

    /**
     * @returns Integer score of player X.
     */
    int x_score();

    /**
     * @returns Integer score of player O.
     */
    int o_score();

    /**
     * @brief Add a QPushButton pointer to board().
     * 
     * This method should only be called in the initial game setup.
     * 
     * @param box A pointer to a QPushButton.
     */
    void append_to_board(QPushButton *box);

    /**
     * @brief Set the text for the box at the given index in board().
     * 
     * @param index An integer value between 0 and 8.
     * @param value The char value (should only be 'X' or 'O') to be set in the box.
     */
    void set_box(int index, char value);

    /**
     * @brief Alternate player_turn() between player X and O.
     */
    void switch_turn();

    /**
     * @brief Set the game_over() value to be true or false.
     * 
     * @param game_state Whether or not the game is over.
     */
    void set_game_over(bool game_state);

    /**
     * @brief Add 1 to x_score().
     */
    void increment_x_score();

    /**
     * @brief Add 1 to o_score().
     */
    void increment_o_score();

    /**
     * @brief Clear the board and set player_turn() to 'X'.
     */
    void NewGame();

    /**
     * @brief Get the Winner object
     * 
     * @returns The winning player ('X', 'O').
     */
    char GetWinner();

private:
    QList<QPushButton *> board_{};

    char turn_{'X'};

    bool game_over_{false};

    int x_score_{0};
    int o_score_{0};
};

#endif // GAME_H
