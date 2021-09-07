#include "include/tictactoe.h"
#include "ui_tictactoe.h"

// ===== GLOBAL VARIABLES =====
constexpr int kNumberOfBoxes{9};

char g_board[kNumberOfBoxes]{
    ' ', ' ', ' ',
    ' ', ' ', ' ',
    ' ', ' ', ' '};


char g_turn{'X'};

bool g_game_over{false};

int g_x_score{0};
int g_o_score{0};

QPushButton *g_boxes[kNumberOfBoxes];
// ============================

TicTacToe::TicTacToe(QWidget *parent) : QMainWindow(parent),
                                        ui(new Ui::TicTacToe)
{
    ui->setupUi(this);

    for (int i{0}; i < kNumberOfBoxes; ++i)
    {
        const QString kButtonName{"pushButton_" + QString::number(i + 1)};
        g_boxes[i] = TicTacToe::findChild<QPushButton *>(kButtonName);
        connect(g_boxes[i], SIGNAL(released()), this, SLOT(BoxPressed()));
    }

    connect(ui->newGameButton, SIGNAL(released()), this, SLOT(NewGame()));
}

TicTacToe::~TicTacToe()
{
    delete ui;
}

void TicTacToe::BoxPressed()
{
    QPushButton *button{(QPushButton *)sender()};

    const int kIndex{button->objectName().back().digitValue() - 1};

    // Proceed only if the box is empty and the game is not over
    if (g_board[kIndex] == ' ' && !g_game_over)
    {
        QLabel *turn_label{ui->turnLabel};

        // Update box in both the button and array
        button->setText(QString(g_turn));
        g_board[kIndex] = g_turn;

        // Check for a winner
        const char kWinner{GetWinner()};

        if (kWinner != 'N')
        {
            if (kWinner == 'D')
                turn_label->setText("It is a draw!");
            else
            {
                turn_label->setText("Congratulations! " + QString(kWinner) + " won!");

                // Add to player score
                QLabel *score_label{};
                int *player_score{};

                if (kWinner == 'X')
                {
                    score_label = ui->xScoreLabel;
                    player_score = &g_x_score;
                }
                else
                {
                    score_label = ui->oScoreLabel;
                    player_score = &g_o_score;
                }

                score_label->setText(QString(kWinner) + ": " + QString::number(++*player_score));
            }

            // Prevent the game from continuing
            g_game_over = true;
            return;
        }

        // Switch player turn
        g_turn = (g_turn == 'X') ? 'O' : 'X';
        turn_label->setText("It is currently " + QString(g_turn) + "'s turn!");
    }
}

char TicTacToe::GetWinner()
{
    for (int i{0}; i <= 2; ++i)
    {
        // Check if any of the rows are the same
        const char kCenterRow{g_board[3 * i + 1]};

        if (kCenterRow != ' ' && g_board[3 * i] == kCenterRow && kCenterRow == g_board[3 * i + 2])
            return g_turn;

        // Check if any of the columns are the same
        const char kCenterCol{g_board[i + 3]};

        if (kCenterCol != ' ' && g_board[i] == kCenterCol && kCenterCol == g_board[i + 6])
            return g_turn;
    }

    // Check if any of the diagonals are the same
    const char kCenterDiag{g_board[4]};

    if (kCenterDiag != ' ' &&
        ((g_board[0] == kCenterDiag && kCenterDiag == g_board[8]) || (g_board[2] == kCenterDiag && kCenterDiag == g_board[6])))
        return g_turn;

    // Check if the game is still ongoing
    for (int i{0}; i <= 8; ++i)
    {
        if (g_board[i] == ' ')
            return 'N';
    }

    // There are no winners, end the game in a draw
    return 'D';
}

void TicTacToe::NewGame()
{
    for (QPushButton *box : g_boxes)
    {
        box->setText("");
    }

    for (int i{0}; i < kNumberOfBoxes; ++i)
    {
        g_board[i] = ' ';
    }

    ui->turnLabel->setText("It is currently X's turn!");
    g_turn = 'X';

    g_game_over = false;
}
