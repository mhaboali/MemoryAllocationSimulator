#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>
#include <QString>
#include <QDebug>
#include <QVector>
#include <string>
#include <QLabel>
#include <QLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <algorithm>
#include <QScrollArea>
#include <QScrollBar>
#include <QPair>
#include <bits/stdc++.h>

using namespace std;

QVector<QString> split(QString s,QChar c);
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QVBoxLayout *vertical;
    QWidget *window ;
    QPushButton *startBP;
    QHBoxLayout *hor;
    QWidget* wid;
    int MemSize,methodology;
    QVector<pair<int,int>>HOLES;
    QVector<QVector<QString>>Process;

public slots :
    void removegui();
    void start();
};

#endif // MAINWINDOW_H
