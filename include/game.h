#ifndef GAME_H
#define GAME_H

#include "ui_tictactoe.h"

using Box = QList<QPushButton *>;

struct Winner
{
    char winner{};
    QList<Box> winning_combos{};
};

class Game
{
public:
    /**
     * @returns a QList of QPushButton pointers.
     */
    Box board();

    /**
     * @brief Add a QPushButton pointer to board().
     * 
     * This method should only be called in the initial game setup.
     * 
     * @param box A pointer to a QPushButton.
     */
    void append_to_board(QPushButton *box);

    /**
     * @param index An integer value between 0 and 8.
     * @returns the QPushButton text ('X', 'O', '\\0') that is at index in board().
     */
    char box(int index);

    /**
     * @brief Set the text for the box at the given index in board().
     * 
     * @param index An integer value between 0 and 8.
     * @param value The char value (should only be 'X' or 'O') to be set in the box.
     */
    void set_box(int index, char value);

    /**
     * @returns the current player ('X', 'O').
     */
    char turn();

    /**
     * @brief Set turn() to turn.
     * 
     * @param turn The char value ('X', 'O') of the new player turn.
     */
    void set_turn(char turn);

    /**
     * @returns whether or not the game is over.
     */
    bool game_over();

    /**
     * @brief Set the game_over() value to be true or false.
     * 
     * @param game_over Whether or not the game is over.
     */
    void set_game_over(bool game_over);

    /**
     * @brief Add 1 to x_score and return it.
     * 
     * @returns the integer value of player X.
     */
    int get_and_increment_x_score();

    /**
     * @brief Add 1 to o_score and return it.
     * 
     * @returns the integer value of player O.
     */
    int get_and_increment_o_score();

    /**
     * @brief Clear the board and set player_turn() to 'X'.
     */
    void NewGame();

    /**
     * @brief Return the winning player (or none) and the boxes that resulted in the win.
     * 
     * @returns a Winner struct consisting of a winner char and the winning combos.
     */
    Winner GetWinner();

private:
    /**
     * @brief Return a QList of QPushButton pointers out of 3 indices.
     * 
     * @param a the first index.
     * @param b the second index.
     * @param c the third index.
     * @returns a QList of QPushButton pointers.
     */
    Box GetBox(int a, int b, int c);

    /**
     * @brief Check if the text of an array's elements are equal.
     * 
     * @param arr a QList of QPushButton pointers.
     * @returns whether or not the text in all of the QPushButtons are equal.
     */
    bool AreContentEqual(Box arr);

    Box board_{};

    char turn_{'X'};

    bool game_over_{false};

    int x_score_{0};
    int o_score_{0};
};

#endif // GAME_H
