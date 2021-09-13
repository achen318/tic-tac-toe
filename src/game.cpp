#include "include/game.h"

Box Game::board()
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

Winner Game::GetWinner()
{
    Winner winner;

    QList<Box> possible_arrs{
        // rows
        GetBox(0, 1, 2),
        GetBox(3, 4, 5),
        GetBox(6, 7, 8),

        // columns
        GetBox(0, 3, 6),
        GetBox(1, 4, 7),
        GetBox(2, 5, 8),

        // diagonals
        GetBox(0, 4, 8),
        GetBox(2, 4, 6),
    };

    for (Box arr : possible_arrs)
    {
        if (arr[0]->text() != '\0' && AreContentEqual(arr))
        {
            winner.winner = turn();
            winner.winning_combos.append(arr);

            return winner;
        }
    }

    // Check if the game is still ongoing
    for (int i{0}; i < 9; ++i)
    {
        if (box(i) == '\0')
        {
            winner.winner = 'N';
            return winner;
        }
    }

    // There are no winners, end the game in a draw
    winner.winner = 'D';
    return winner;
}

Box Game::GetBox(int a, int b, int c)
{
    Box box{};

    box.append(board_.at(a));
    box.append(board_.at(b));
    box.append(board_.at(c));

    return box;
}

bool Game::AreContentEqual(Box arr)
{
    return arr[0]->text() == arr[1]->text() && arr[1]->text() == arr[2]->text();
}
