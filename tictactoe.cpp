#include "tictactoe.h"
#include "ui_tictactoe.h"

char g_board[9]{
    ' ', ' ', ' ',
    ' ', ' ', ' ',
    ' ', ' ', ' '};

char g_turn{'X'};

bool g_game_over{false};

int g_x_score{0};
int g_o_score{0};

TicTacToe::TicTacToe(QWidget *parent) : QMainWindow(parent),
                                        ui(new Ui::TicTacToe)
{
    ui->setupUi(this);

    QPushButton *num_buttons[9];

    for (int i{0}; i < 9; ++i)
    {
        const QString kButtonName{"pushButton_" + QString::number(i + 1)};
        num_buttons[i] = TicTacToe::findChild<QPushButton *>(kButtonName);

        num_buttons[i]->setText(QString(g_board[i]));
        connect(num_buttons[i], SIGNAL(released()), this, SLOT(BoxPressed()));
    }
}

TicTacToe::~TicTacToe()
{
    delete ui;
}

void TicTacToe::BoxPressed()
{
    QPushButton *button{(QPushButton *)sender()};

    const int kIndex{button->objectName().back().digitValue() - 1};

    // only proceed if the box is empty and the game is not over
    if (g_board[kIndex] == ' ' && !g_game_over)
    {
        QLabel *turn_label{ui->turnLabel};

        // updates box in both the button and array
        button->setText(QString(g_turn));
        g_board[kIndex] = g_turn;

        // checks for a winner
        const char kWinner{GetWinner()};

        if (kWinner != 'N')
        {
            if (kWinner == 'D')
                turn_label->setText(QString("It is a draw!"));
            else
            {
                turn_label->setText(QString("Congratulations! " + QString(kWinner) + " won!"));

                // TODO: Add score
                const QString kLabelName{QString(QChar(tolower(kWinner))) + "ScoreLabel"};
                QLabel score_label{TicTacToe::findChild<QLabel *>(kLabelName)};
            }

            // prevents the game from continuing
            g_game_over = true;
            return;
        }

        // switches turn
        g_turn = (g_turn == 'X') ? 'O' : 'X';
        turn_label->setText(QString("It is currently " + QString(g_turn) + "'s turn!"));
    }
}

char TicTacToe::GetWinner()
{
    for (int i{0}; i <= 2; ++i)
    {
        // checks if any of the rows are the same
        const char kCenterRow{g_board[3 * i + 1]};

        if (kCenterRow != ' ' && g_board[3 * i] == kCenterRow && kCenterRow == g_board[3 * i + 2])
            return g_turn;

        // checks if any of the columns are the same
        const char kCenterCol{g_board[i + 3]};

        if (kCenterCol != ' ' && g_board[i] == kCenterCol && kCenterCol == g_board[i + 6])
            return g_turn;
    }

    // checks if any of the diagonals are the same
    const char kCenterDiag{g_board[4]};

    if (kCenterDiag != ' ' &&
        ((g_board[0] == kCenterDiag && kCenterDiag == g_board[8]) || (g_board[2] == kCenterDiag && kCenterDiag == g_board[6])))
        return g_turn;

    // checks if the game is still ongoing
    for (int i{0}; i <= 8; ++i)
    {
        if (g_board[i] == ' ')
            return 'N';
    }

    // no winners, game ends in a draw
    return 'D';
}
