#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include <map>
#include <QTimer>
#include <QTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    time.setHMS(0, 1, 0);
//    ui->timer->setText(time.toString("m:ss"));
//    timer = new QTimer(this);
//    timer->setInterval(1000);
//    connect(timer, SIGNAL(timeout()), this, SLOT(updTime()));
//    timer->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Start_clicked()
{
    shuffle(this->quizMap.box.begin(),this->quizMap.box.end(), std::mt19937(std::random_device()()));
    ui->label->setText(this->quizMap.QmapNum[this->quizMap.box[i]]);

}


void MainWindow::on_Next_clicked()
{

    QString answer = ui->answer->text();

    if (answer == this->quizMap.Qmap[this->quizMap.box[i]] && i < 5){
        score += 5 - i;
    }

    i++;
    ui->label->setText(this->quizMap.QmapNum[this->quizMap.box[i]]);
    if (i == 5){
        ui->Next->setText("Check answers");
        ui->label->setText("Now check your answers! ");
        i++;
    }else if(i > 5){
        ui->ans->setText("Your score " + QString::number(score));
        ui->answerLTitle->setText("Correct answers here! ");
        ui->answerL->setText(this->quizMap.QmapNum[this->quizMap.box[0]] + " - > " + this->quizMap.Qmap[this->quizMap.box[0]]);
        ui->answerL_2->setText(this->quizMap.QmapNum[this->quizMap.box[1]] + " - > " + this->quizMap.Qmap[this->quizMap.box[1]]);
        ui->answerL_3->setText(this->quizMap.QmapNum[this->quizMap.box[2]] + " - > " + this->quizMap.Qmap[this->quizMap.box[2]]);
        ui->answerL_4->setText(this->quizMap.QmapNum[this->quizMap.box[3]] + " - > " + this->quizMap.Qmap[this->quizMap.box[3]]);
        ui->answerL_5->setText(this->quizMap.QmapNum[this->quizMap.box[4]] + " - > " + this->quizMap.Qmap[this->quizMap.box[4]]);
    }
}

//void MainWindow::updTime()
//{
//    time.addSecs(-1);
//    ui->timer->setText(time.toString("m:ss"));
//}

