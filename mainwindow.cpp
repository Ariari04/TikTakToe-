#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->button_start, &QPushButton::clicked, this, &MainWindow::onButtonClickStart);
    QObject::connect(ui->button1x1, &QPushButton::clicked, this, &MainWindow::onButtonClick1x1);
    QObject::connect(ui->button1x2, &QPushButton::clicked, this, &MainWindow::onButtonClick1x2);
    QObject::connect(ui->button1x3, &QPushButton::clicked, this, &MainWindow::onButtonClick1x3);
    QObject::connect(ui->button2x1, &QPushButton::clicked, this, &MainWindow::onButtonClick2x1);
    QObject::connect(ui->button2x2, &QPushButton::clicked, this, &MainWindow::onButtonClick2x2);
    QObject::connect(ui->button2x3, &QPushButton::clicked, this, &MainWindow::onButtonClick2x3);
    QObject::connect(ui->button3x1, &QPushButton::clicked, this, &MainWindow::onButtonClick3x1);
    QObject::connect(ui->button3x2, &QPushButton::clicked, this, &MainWindow::onButtonClick3x2);
    QObject::connect(ui->button3x3, &QPushButton::clicked, this, &MainWindow::onButtonClick3x3);
}

MainWindow::~MainWindow()
{
    delete ui;
}


bool popsa = 1;
int grid_3x3[3][3];

void MainWindow::check_for_winner(){

    if ((grid_3x3[0][0] + grid_3x3[0][1] + grid_3x3[0][2] == 3) ||
        (grid_3x3[1][0] + grid_3x3[1][1] + grid_3x3[1][2] == 3) ||
        (grid_3x3[2][0] + grid_3x3[2][1] + grid_3x3[2][2] == 3) ||
        (grid_3x3[0][0] + grid_3x3[1][1] + grid_3x3[2][2] == 3) ||
        (grid_3x3[0][2] + grid_3x3[1][1] + grid_3x3[2][0] == 3) ||
        (grid_3x3[0][0] + grid_3x3[1][0] + grid_3x3[2][0] == 3) ||
        (grid_3x3[0][1] + grid_3x3[1][1] + grid_3x3[2][1] == 3) ||
        (grid_3x3[0][2] + grid_3x3[1][2] + grid_3x3[2][2] == 3)){

        for (int i = 0; i < 3; ++i){
            for (int j = 0; j < 3; ++j){
                grid_3x3[i][j] = 1;
            }
        }
        ui->labe_win->setText("X is winner!!");
    }
    else if ((grid_3x3[0][0] + grid_3x3[0][1] + grid_3x3[0][2] == 30) ||
            (grid_3x3[1][0] + grid_3x3[1][1] + grid_3x3[1][2] == 30) ||
            (grid_3x3[2][0] + grid_3x3[2][1] + grid_3x3[2][2] == 30) ||
            (grid_3x3[0][0] + grid_3x3[1][1] + grid_3x3[2][2] == 30) ||
            (grid_3x3[0][2] + grid_3x3[1][1] + grid_3x3[2][0] == 30) ||
            (grid_3x3[0][0] + grid_3x3[1][0] + grid_3x3[2][0] == 30) ||
            (grid_3x3[0][1] + grid_3x3[1][1] + grid_3x3[2][1] == 30) ||
            (grid_3x3[0][2] + grid_3x3[1][2] + grid_3x3[2][2] == 30)){

         for (int i = 0; i < 3; ++i){
             for (int j = 0; j < 3; ++j){
                 grid_3x3[i][j] = 10;
             }
         }
         ui->labe_win->setText("O is winner!!");
    }

}

void MainWindow::onButtonClickStart(){
    ui->label_turn->setText("Start X:");
    ui->labe_win->setText("Nobody win");
    ui->button1x1->setText("Push");
    ui->button1x2->setText("Push");
    ui->button1x3->setText("Push");
    ui->button2x1->setText("Push");
    ui->button2x2->setText("Push");
    ui->button2x3->setText("Push");
    ui->button3x1->setText("Push");
    ui->button3x2->setText("Push");
    ui->button3x3->setText("Push");
    popsa = 1;
    for (int i = 0; i < 3; ++i){
        for (int j = 0; j < 3; ++j){
            grid_3x3[i][j] = 0;
        }
    }
}



void MainWindow::onButtonClick1x1(){


    if (grid_3x3[0][0] != 0)return ;
    if (popsa == 1)
        grid_3x3[0][0] = 1;
    else
        grid_3x3[0][0] = 10;

    if (popsa == 1){
        ui->label_turn->setText("It's turn of O:");
        ui->button1x1->setText("X");
        check_for_winner();
        popsa = 0;
    }
    else {
        ui->label_turn->setText("It's turn of X:");
        ui->button1x1->setText("O");
        check_for_winner();
        popsa = 1;
    }
}


void MainWindow::onButtonClick1x2(){
    if (grid_3x3[0][1] != 0)return ;
    if (popsa == 1)
        grid_3x3[0][1] = 1;
    else
        grid_3x3[0][1] = 10;

    if (popsa == 1){
        ui->label_turn->setText("It's turn of O:");
        ui->button1x2->setText("X");
        check_for_winner();
        popsa = 0;
    }
    else {
        ui->label_turn->setText("It's turn of X:");
        ui->button1x2->setText("O");
        check_for_winner();
        popsa = 1;
    }
}


void MainWindow::onButtonClick1x3(){
    if (grid_3x3[0][2] != 0)return ;
    if (popsa == 1)
        grid_3x3[0][2] = 1;
    else
        grid_3x3[0][2] = 10;

    if (popsa == 1){
        ui->label_turn->setText("It's turn of O:");
        ui->button1x3->setText("X");
        check_for_winner();
        popsa = 0;
    }
    else {
        ui->label_turn->setText("It's turn of X:");
        ui->button1x3->setText("O");
        check_for_winner();
        popsa = 1;
    }
}


void MainWindow::onButtonClick2x1(){
    if (grid_3x3[1][0] != 0)return ;
    if (popsa == 1)
        grid_3x3[1][0] = 1;
    else
        grid_3x3[1][0] = 10;

    if (popsa == 1){
        ui->label_turn->setText("It's turn of O:");
        ui->button2x1->setText("X");
        check_for_winner();
        popsa = 0;
    }
    else {
        ui->label_turn->setText("It's turn of X:");
        ui->button2x1->setText("O");
        check_for_winner();
        popsa = 1;
    }
}

void MainWindow::onButtonClick2x2(){
    if (grid_3x3[1][1] != 0)return ;
    if (popsa == 1)
        grid_3x3[1][1] = 1;
    else
        grid_3x3[1][1] = 10;

    if (popsa == 1){
        ui->label_turn->setText("It's turn of O:");
        ui->button2x2->setText("X");
        check_for_winner();
        popsa = 0;
    }
    else {
        ui->label_turn->setText("It's turn of X:");
        ui->button2x2->setText("O");
        check_for_winner();
        popsa = 1;
    }
}


void MainWindow::onButtonClick2x3(){
    if (grid_3x3[1][2] != 0)return ;
    if (popsa == 1)
        grid_3x3[1][2] = 1;
    else
        grid_3x3[1][2] = 10;

    if (popsa == 1){
        ui->label_turn->setText("It's turn of O:");
        ui->button2x3->setText("X");
        check_for_winner();
        popsa = 0;
    }
    else {
        ui->label_turn->setText("It's turn of X:");
        ui->button2x3->setText("O");
        check_for_winner();
        popsa = 1;
    }
}


void MainWindow::onButtonClick3x1(){
    if (grid_3x3[2][0] != 0)return ;
    if (popsa == 1)
        grid_3x3[2][0] = 1;
    else
        grid_3x3[2][0] = 10;

    if (popsa == 1){
        ui->label_turn->setText("It's turn of O:");
        ui->button3x1->setText("X");
        check_for_winner();
        popsa = 0;
    }
    else {
        ui->label_turn->setText("It's turn of X:");
        ui->button3x1->setText("O");
        check_for_winner();
        popsa = 1;
    }
}


void MainWindow::onButtonClick3x2(){
    if (grid_3x3[2][1] != 0)return ;
    if (popsa == 1)
        grid_3x3[2][1] = 1;
    else
        grid_3x3[2][1] = 10;
    if (popsa == 1){
        ui->label_turn->setText("It's turn of O:");
        ui->button3x2->setText("X");
        check_for_winner();
        popsa = 0;
    }
    else {
        ui->label_turn->setText("It's turn of X:");
        ui->button3x2->setText("O");
        check_for_winner();
        popsa = 1;
    }
}


void MainWindow::onButtonClick3x3(){
    if (grid_3x3[2][2] != 0)return ;
    if (popsa == 1)
        grid_3x3[2][2] = 1;
    else
        grid_3x3[2][2] = 10;

    if (popsa == 1){
        ui->label_turn->setText("It's turn of O:");
        ui->button3x3->setText("X");
        check_for_winner();
        popsa = 0;
    }
    else {
        ui->label_turn->setText("It's turn of X:");
        ui->button3x3->setText("O");
        check_for_winner();
        popsa = 1;
    }
}



