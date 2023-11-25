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

    timer = new QTimer(this);

    time.setHMS(0, 1, 0);

    connect(timer, &QTimer::timeout, this, &MainWindow::updTime);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Start_clicked()
{
    i = 0;

    shuffle(this->quizMap.box.begin(),this->quizMap.box.end(), std::mt19937(std::random_device()()));
    ui->label->setText(this->quizMap.QmapNum[this->quizMap.box[i]]);

    ui->answerLTitle->clear();
    ui->answerL->clear();
    ui->answerL_2->clear();
    ui->answerL_3->clear();
    ui->answerL_4->clear();
    ui->answerL_5->clear();

    time.setHMS(0, 1, 0);
    ui->tTime->setText("Stellar quiz starts now! Time left: " + time.toString("m:ss"));
    timer->start(1000);
}


void MainWindow::on_Next_clicked()
{

    time.setHMS(0, 1, 0);
    ui->tTime->setText("Time left: " + time.toString("m:ss"));

    ui->answer->clear();

    QString answer = ui->answer->text();

    if (answer == this->quizMap.Qmap[this->quizMap.box[i]] && i < 5){
        score += 5 - i;
    }

    i++;
    ui->label->setText(this->quizMap.QmapNum[this->quizMap.box[i]]);
    if (i == 5){
        timer->stop();
        ui->tTime->setText("Quiz finished!");
        ui->Next->setText("Check answers");
        ui->label->setText("Now check your answers! ");
        i++;
    }else if(i > 5){
        timer->stop();
        ui->tTime->setText("Quiz finished!");
        ui->ans->setText("Your score " + QString::number(score));
        ui->answerLTitle->setText("Correct answers here! ");
        ui->answerL->setText(this->quizMap.QmapNum[this->quizMap.box[0]] + " - > " + this->quizMap.Qmap[this->quizMap.box[0]]);
        ui->answerL_2->setText(this->quizMap.QmapNum[this->quizMap.box[1]] + " - > " + this->quizMap.Qmap[this->quizMap.box[1]]);
        ui->answerL_3->setText(this->quizMap.QmapNum[this->quizMap.box[2]] + " - > " + this->quizMap.Qmap[this->quizMap.box[2]]);
        ui->answerL_4->setText(this->quizMap.QmapNum[this->quizMap.box[3]] + " - > " + this->quizMap.Qmap[this->quizMap.box[3]]);
        ui->answerL_5->setText(this->quizMap.QmapNum[this->quizMap.box[4]] + " - > " + this->quizMap.Qmap[this->quizMap.box[4]]);
    }
}

void MainWindow::updTime()
{
        time = time.addSecs(-1);
    if(time.toString("m:ss") == "0:00"){
        i++;
        ui->tTime->setText("Your time is up! Next question is comming now!");
        ui->label->setText(this->quizMap.QmapNum[this->quizMap.box[i]]);
        ui->answer->clear();
        time.setHMS(0, 1, 0);
    }else if (time.toString("m:ss") == "0:05"){
        ui->tTime->setText("Time left: " + time.toString("m:ss") + " FIVE");
    }else if (time.toString("m:ss") == "0:04"){
        ui->tTime->setText("Time left: " + time.toString("m:ss") + " FOUR!!");
    }else if (time.toString("m:ss") == "0:03"){
        ui->tTime->setText("Time left: " + time.toString("m:ss") + " THREE!!!");
    }else if (time.toString("m:ss") == "0:02"){
        ui->tTime->setText("Time left: " + time.toString("m:ss") + " TWO!!!!");
    }else if (time.toString("m:ss") == "0:01"){
        ui->tTime->setText("Time left: " + time.toString("m:ss") + " ONE!!!!!");
    }
    else{
        ui->tTime->setText("Time left: " + time.toString("m:ss"));
    }

        if (i == 5){
        timer->stop();
        ui->tTime->setText("Quiz finished!");
        ui->Next->setText("Check answers");
        ui->label->setText("Now check your answers! ");
        i++;
        }else if(i > 5){
        timer->stop();
        ui->ans->setText("Your score " + QString::number(score));
        ui->answerLTitle->setText("Correct answers here! ");
        ui->answerL->setText(this->quizMap.QmapNum[this->quizMap.box[0]] + " - > " + this->quizMap.Qmap[this->quizMap.box[0]]);
        ui->answerL_2->setText(this->quizMap.QmapNum[this->quizMap.box[1]] + " - > " + this->quizMap.Qmap[this->quizMap.box[1]]);
        ui->answerL_3->setText(this->quizMap.QmapNum[this->quizMap.box[2]] + " - > " + this->quizMap.Qmap[this->quizMap.box[2]]);
        ui->answerL_4->setText(this->quizMap.QmapNum[this->quizMap.box[3]] + " - > " + this->quizMap.Qmap[this->quizMap.box[3]]);
        ui->answerL_5->setText(this->quizMap.QmapNum[this->quizMap.box[4]] + " - > " + this->quizMap.Qmap[this->quizMap.box[4]]);
        }

}


