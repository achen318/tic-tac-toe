#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class TicTacToe;
}
QT_END_NAMESPACE

class TicTacToe : public QMainWindow
{
    Q_OBJECT

public:
    TicTacToe(QWidget *parent = nullptr);
    ~TicTacToe();

private:
    Ui::TicTacToe *ui;

private slots:
    void BoxPressed();
    char GetWinner();
};

#endif // TICTACTOE_H
