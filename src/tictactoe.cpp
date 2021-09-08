#include "include/game.h"
#include "include/tictactoe.h"
#include "ui_tictactoe.h"

Game game{};

QPushButton *g_boxes[9];

TicTacToe::TicTacToe(QWidget *parent) : QMainWindow(parent),
                                        ui(new Ui::TicTacToe)
{
    ui->setupUi(this);

    for (int i{0}; i < 9; ++i)
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
    if (game.box(kIndex) == ' ' && !game.game_over())
    {
        QLabel *turn_label{ui->turnLabel};

        // Update box in both the button and array
        button->setText(QString(game.turn()));
        game.set_box(kIndex, game.turn());

        // Check for a winner
        const char kWinner{game.GetWinner()};

        if (kWinner != 'N')
        {
            if (kWinner == 'D')
                turn_label->setText("It is a draw!");
            else
            {
                turn_label->setText("Congratulations! " + QString(kWinner) + " won!");

                // Add to player score
                QLabel *score_label{};
                int player_score{};

                if (kWinner == 'X')
                {
                    score_label = ui->xScoreLabel;
                    game.increment_x_score();
                    player_score = game.x_score();
                }
                else
                {
                    score_label = ui->oScoreLabel;
                    game.increment_o_score();
                    player_score = game.o_score();
                }

                score_label->setText(QString(kWinner) + ": " + QString::number(player_score));
            }

            // Prevent the game from continuing
            game.set_game_over(true);
            return;
        }

        // Switch player turn
        game.switch_turn();
        turn_label->setText("It is currently " + QString(game.turn()) + "'s turn!");
    }
}

void TicTacToe::NewGame()
{
    for (QPushButton *box : g_boxes)
    {
        box->setText("");
    }

    game.NewGame();

    ui->turnLabel->setText("It is currently X's turn!");

    game.set_game_over(false);
}
