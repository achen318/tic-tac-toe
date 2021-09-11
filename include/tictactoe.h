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
    /**
     * @brief Construct a new TicTacToe object.
     * 
     * @param parent A pointer to a QWidget parent.
     */
    TicTacToe(QWidget *parent = nullptr);

    /**
     * @brief Destroy the TicTacToe object.
     */
    ~TicTacToe();

private:
    Ui::TicTacToe *ui;

private slots:
    /**
     * @brief Logic for when a box emits a released() signal.
     */
    void BoxPressed();
    /**
     * @brief Logic for when the new game button emits a released() signal.
     */
    void NewGame();
};

#endif // TICTACTOE_H
