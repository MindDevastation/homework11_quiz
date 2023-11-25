#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "quiz.h"
#include <map>
#include <QTime>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    quiz quizMap;
    int i = 0;
    int score = 0;
    QTime time;
    QTimer *timer;

private slots:
    void on_Start_clicked();

    void on_Next_clicked();

    void updTime();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
