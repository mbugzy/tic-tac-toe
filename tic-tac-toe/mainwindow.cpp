
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "style.h"
#include "dos.h"
#include <QTimer>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton_friend->setStyleSheet(style::actButton());
    ui->pushButton_AI->setStyleSheet(style::defButton());
    ui->pushButton_clear->setStyleSheet(style::defButton());
    ui->centralwidget->setStyleSheet(style::backGrondWindow());
    newGame();
    timer = new QTimer(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



int is_win(int arr[SIZE], int turnAmount) {
    int wins[8][3] = {
        {5, 8, 0},
        {2, 1, 7},
        {3, 4, 6},
        {5, 2, 3},
        {8, 1, 4},
        {0, 7, 6},
        {5, 1, 6},
        {0, 1, 3}
    };
    for (int i = 0; i < 8; i++)
        if (arr[wins[i][0]] == arr[wins[i][1]] && arr[wins[i][0]] == arr[wins[i][2]])
            return arr[wins[i][0]];
    if(turnAmount >= 9)
        return 3;
    return 0;
}

int minimax(int arr[SIZE], int depth, bool isAITurn)
{
    int score = 0, bestScore = 0;
    if(is_win(arr, depth) != 0){
        if(isAITurn)
            return -1;
        else
            return 1;
    }
    else
        if(depth < 9){
            if(isAITurn){
                bestScore = -100;
                for(int i = 0; i < SIZE; i++)
                    if(arr[i] == 0){
                        arr[i] = 2;
                        score = minimax(arr, depth + 1, false);
                        arr[i] = 0;
                        if(score > bestScore)
                            bestScore = score;
                    }
                return bestScore;
            }
            else{
                bestScore = 100;
                for(int i = 0; i < SIZE; i++)
                    if(arr[i] == 0){
                        arr[i] = 1;
                        score = minimax(arr, depth + 1, true);
                        arr[i] = 0;
                        if(score < bestScore)
                            bestScore = score;
                    }
                return bestScore;
            }
        }
        else
            return 0;
}

int searchAIMove(int arr[SIZE], int turnAmount)
{
    int index=-1, score = 0, bestScore = -100;
    for(int i = 0; i < SIZE; i++)
        if(arr[i] == 0){
            arr[i] = 2;
            score = minimax(arr, turnAmount + 1, false);
            arr[i] = 0;
            if(score > bestScore){
                bestScore = score;
                index = i;
            }
        }
    return index;
}


void MainWindow::newGame()
{
    QGridLayout* area = qobject_cast<QGridLayout*>(ui->Area->layout());
    for(int i = 0; i < SIZE; i++){
        QPushButton* button = qobject_cast<QPushButton*>(area->itemAt(i)->widget());
        button->setStyleSheet(style::areaButtonDefault());
        button->setText("");
    }
    for(int i = 0; i < SIZE; i++){
        pos[i] = 0;
    }
    game = true;
    turnCount = 0;
    turn = firstTurn;
    if(firstTurn)
        if(AIPressed)
            ui->label_win_lose->setText("Player");
        else
            ui->label_win_lose->setText("Player1");
    else
        ui->label_win_lose->setText("Player2");
    if(AIPressed && !turn)
        //turnO(searchAIMove(pos, turnCount));
        turnO(rand()%10-1);
}


void MainWindow::turnO(int index)
{
    QGridLayout* area = qobject_cast<QGridLayout*>(ui->Area->layout());
    QPushButton* button = qobject_cast<QPushButton*>(area->itemAt(index)->widget());
    button->setStyleSheet(style::areaButtonO());
    button->setText("O");
    pos[index]=2;
    ui->label_win_lose->setText("Player1");
    turnCount++;
    turn = !turn;
}


void MainWindow::is_pushed_af(int value)
{
    if(value==1){
        ui->pushButton_AI->setStyleSheet(style::actButton());
        ui->pushButton_frie
            nd->setStyleSheet(style::defButton());
    }
    else{
        ui->pushButton_friend->setStyleSheet(style::actButton());
        ui->pushButton_AI->setStyleSheet(style::defButton());
    }
}

void MainWindow::on_pushButton_AI_clicked()
{
    is_pushed_af(1);
    AIPressed = true;
    newGame();
}

void MainWindow::on_pushButton_friend_clicked()
{
    is_pushed_af(0);
    AIPressed = false;
    newGame();
}


void MainWindow::actOnArea(int index)
{
    if(game && pos[index] == 0){
        QGridLayout* area = qobject_cast<QGridLayout*>(ui->Area->layout());
        if(turn){
            QPushButton* button = qobject_cast<QPushButton*>(area->itemAt(index)->widget());
            button->setStyleSheet(style::areaButtonX());
            button->setText("X");
            ui->label_win_lose->setText("Player2");
            pos[index]=1;
            turnCount++;
            turn = !turn;
        }
        else
            turnO(index);
        if(AIPressed && is_win(pos, turnCount) == 0){
            //turnO(rand()%10-1);
            turnO(searchAIMove(pos, turnCount));

        }
        if(is_win(pos, turnCount) != 0){
            game=false;
            if(is_win(pos, turnCount) == 1)
                if(AIPressed)
                    ui->label_win_lose->setText("Player won");
                else
                    ui->label_win_lose->setText("Player1 won");
            else if(is_win(pos, turnCount) == 2)
                if(AIPressed)
                    ui->label_win_lose->setText("Computer won");
                else
                    ui->label_win_lose->setText("Player2 won");

            else if(is_win(pos, turnCount) == 3)
                ui->label_win_lose->setText("It's a draw");
        }
    }
}


void MainWindow::on_pushButton_1_clicked()
{
    actOnArea(5);
}

void MainWindow::on_pushButton_2_clicked()
{
    actOnArea(8);
}

void MainWindow::on_pushButton_3_clicked()
{
    actOnArea(0);
}

void MainWindow::on_pushButton_4_clicked()
{
    actOnArea(2);
}

void MainWindow::on_pushButton_5_clicked()
{
    actOnArea(1);
}

void MainWindow::on_pushButton_6_clicked()
{
    actOnArea(7);
}

void MainWindow::on_pushButton_7_clicked()
{
    actOnArea(3);
}

void MainWindow::on_pushButton_8_clicked()
{
    actOnArea(4);
}

void MainWindow::on_pushButton_9_clicked()
{
    actOnArea(6);
}

void MainWindow::on_pushButton_clear_clicked()
{
    firstTurn = !firstTurn;
    newGame();
}
