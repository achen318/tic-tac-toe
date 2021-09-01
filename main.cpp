#include <iostream>
#include <limits>

// The 3x3 board to store the tic-tac-toe results
char g_board[3][3]{
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}};

// The character value of whose turn it is ('X' or 'O)
char g_turn{'X'};

// Whether or not the game is over
bool g_game_over{false};

void DisplayBoard()
{
    // -------------
    // | 1 | 2 | 3 |
    // |---+---+---|
    // | 4 | 5 | 6 |
    // |---+---+---|
    // | 7 | 8 | 9 |
    // -------------
    std::cout << "\n-------------\n";
    std::cout << "| " << g_board[0][0] << " | " << g_board[0][1] << " | " << g_board[0][2] << " |\n";
    std::cout << "|---+---+---|\n";
    std::cout << "| " << g_board[1][0] << " | " << g_board[1][1] << " | " << g_board[1][2] << " |\n";
    std::cout << "|---+---+---|\n";
    std::cout << "| " << g_board[2][0] << " | " << g_board[2][1] << " | " << g_board[2][2] << " |\n";
    std::cout << "-------------\n\n";
}

char GetWinner()
{
    for (int i{0}; i <= 2; ++i)
    {
        // check if any of the rows are the same
        if (g_board[i][0] == g_board[i][1] && g_board[i][1] == g_board[i][2])
            return g_board[i][0];

        // check if any of the columns are the same
        if (g_board[0][i] == g_board[1][i] && g_board[1][i] == g_board[2][i])
            return g_board[0][i];
    }

    // check if any of the diagonals are the same
    if ((g_board[0][0] == g_board[1][1] && g_board[1][1] == g_board[2][2]) ||
        (g_board[0][2] == g_board[1][1] && g_board[1][1] == g_board[2][0]))
        return g_board[1][1];

    // check if the game is still ongoing
    for (int i{0}; i <= 2; ++i)
    {
        for (int j{0}; j <= 2; ++j)
        {
            const char kBox = g_board[i][j];
            if (!(kBox == 'X' || kBox == 'O'))
                return 'N';
        }
    }

    // no winners, game ended in a draw
    return 'D';
}

void PlayerTurn()
{
    int box_position{};

    std::cout << "It is currently " << g_turn << "'s turn! >>> ";
    std::cin >> box_position;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // check for valid input btwn 1-9
    while (1 > box_position || box_position > 9)
    {
        std::cout << "\nInvalid input! Please input an integer between 1 and 9.\n";
        DisplayBoard();
        std::cout << "It is currently " << g_turn << "'s turn! >>> ";
        std::cin >> box_position;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // floor((n-1)/3) returns row index, (n+2)%3 returns column index
    char &box{g_board[(box_position - 1) / 3][(box_position + 2) % 3]};

    // check if box is empty
    while (box == 'X' || box == 'O')
    {
        std::cout << "\nSorry! This box is occupied!\n";
        DisplayBoard();
        std::cout << "It is currently " << g_turn << "'s turn! >>> ";
        std::cin >> box_position;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // updates box
    box = g_turn;

    if (GetWinner() != 'N')
        g_game_over = true;

    // switches turn
    g_turn = (g_turn == 'X') ? 'O' : 'X';
}

int main()
{
    // run the game
    while (!g_game_over)
    {
        DisplayBoard();
        PlayerTurn();
    }

    // game over, print results
    DisplayBoard();

    std::cout << "\nGAME OVER!\n";

    const char kWinner = GetWinner();
    if (kWinner == 'D')
        std::cout << "It is a draw!";
    else
        std::cout << "Congratulations! " << kWinner << " won!";

    // victory royale
    return EXIT_SUCCESS;
}
