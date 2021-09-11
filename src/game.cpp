#include "include/game.h"

// Accessors
QList<QPushButton *> Game::board()
{
    return board_;
}

char Game::box(int index)
{
    return board_.at(index)->text().toStdString()[0];
}

char Game::turn()
{
    return turn_;
}

bool Game::game_over()
{
    return game_over_;
}

int Game::x_score()
{
    return x_score_;
}

int Game::o_score()
{
    return o_score_;
}

// Mutators
void Game::append_to_board(QPushButton *box)
{
    board_.append(box);
}

void Game::set_box(int index, char value)
{
    board_[index]->setText(QString(value));
}

void Game::switch_turn()
{
    turn_ = (turn_ == 'X') ? 'O' : 'X';
}

void Game::set_game_over(bool game_state)
{
    game_over_ = game_state;
}

void Game::increment_x_score()
{
    ++x_score_;
}
void Game::increment_o_score()
{
    ++o_score_;
}

// Other member functions
void Game::NewGame()
{
    for (int i{0}; i < 9; ++i)
    {
        set_box(i, '\0');
    }

    turn_ = 'X';
}

char Game::GetWinner()
{
    for (int i{0}; i <= 2; ++i)
    {
        // Check if any of the rows are the same
        const char kCenterRow{box(3 * i + 1)};

        if (kCenterRow != '\0' && box(3 * i) == kCenterRow && kCenterRow == box(3 * i + 2))
            return turn_;

        // Check if any of the columns are the same
        const char kCenterCol{box(i + 3)};

        if (kCenterCol != '\0' && box(i) == kCenterCol && kCenterCol == box(i + 6))
            return turn_;
    }

    // Check if any of the diagonals are the same
    const char kCenterDiag{box(4)};

    if (kCenterDiag != '\0' &&
        ((box(0) == kCenterDiag && kCenterDiag == box(8)) || (box(2) == kCenterDiag && kCenterDiag == box(6))))
        return turn_;

    // Check if the game is still ongoing
    for (int i{0}; i < 9; ++i)
    {
        if (box(i) == '\0')
            return 'N';
    }

    // There are no winners, end the game in a draw
    return 'D';
}
