#include "include/game.h"

QList<QPushButton *> Game::board()
{
    return board_;
}

void Game::append_to_board(QPushButton *box)
{
    board_.append(box);
}

char Game::box(int index)
{
    return board_.at(index)->text().toStdString()[0];
}

void Game::set_box(int index, char value)
{
    board_[index]->setText(QString(value));
}

char Game::turn()
{
    return turn_;
}

void Game::set_turn(char turn)
{
    turn_ = turn;
}

bool Game::game_over()
{
    return game_over_;
}

void Game::set_game_over(bool game_over)
{
    game_over_ = game_over;
}

int Game::get_and_increment_x_score()
{
    return ++x_score_;
}

int Game::get_and_increment_o_score()
{
    return ++o_score_;
}

void Game::NewGame()
{
    for (int i{0}; i < 9; ++i)
    {
        set_box(i, '\0');
    }

    set_turn('X');
    set_game_over(false);
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
