#include "include/game.h"

Game::Game()
{
    NewGame();
}

void Game::NewGame()
{
    board_.fill(' ');

    turn_ = 'X';
}

char Game::GetWinner()
{
    for (int i{0}; i <= 2; ++i)
    {
        // Check if any of the rows are the same
        const char kCenterRow{board_[3 * i + 1]};

        if (kCenterRow != ' ' && board_[3 * i] == kCenterRow && kCenterRow == board_[3 * i + 2])
            return turn_;

        // Check if any of the columns are the same
        const char kCenterCol{board_[i + 3]};

        if (kCenterCol != ' ' && board_[i] == kCenterCol && kCenterCol == board_[i + 6])
            return turn_;
    }

    // Check if any of the diagonals are the same
    const char kCenterDiag{board_[4]};

    if (kCenterDiag != ' ' &&
        ((board_[0] == kCenterDiag && kCenterDiag == board_[8]) || (board_[2] == kCenterDiag && kCenterDiag == board_[6])))
        return turn_;

    // Check if the game is still ongoing
    for (int i{0}; i < 9; ++i)
    {
        if (board_[i] == ' ')
            return 'N';
    }

    // There are no winners, end the game in a draw
    return 'D';
}
