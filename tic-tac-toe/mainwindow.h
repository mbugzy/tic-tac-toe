
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:    
    void on_pushButton_AI_clicked();
    void on_pushButton_friend_clicked();

    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();

    void on_pushButton_clear_clicked();

private:
    Ui::MainWindow *ui;
#define SIZE 9
    void newGame();
    int turnCount = 0;
    void turnO(int index);
    void actOnArea(int index);
    void is_pushed_af(int value);
    bool AIPressed = false;
    bool turn = true;
    bool firstTurn = true;
    bool game = true;
    int pos[SIZE]={0,0,0,0,0,0,0,0,0};
    QTimer* timer;
};

#endif // MAINWINDOW_H
