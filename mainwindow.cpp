#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


   this->setFixedSize(1300,900);
    startBP= new QPushButton(this);
    startBP->setGeometry(500,400,200,70);
    startBP->setText("START");
    startBP->show();
    connect(startBP,SIGNAL(clicked(bool)),this,SLOT(start()));
    QInputDialog input(this);
   // input.setFixedSize(500,2000);
    input.setInputMode(QInputDialog::IntInput);
    input.setLabelText("Enter Memory Size : ");
//    if(input.exec()) {
//        int memsize=input.intValue();
//         qDebug()<<memsize;
//         input.setLabelText("Enter number of Holes : ");
//         if(input.exec()){
//             int holenum=input.intValue();
//             qDebug()<<holenum;
//             QVector<QString>holes(holenum);
//             input.setInputMode(QInputDialog::TextInput);
//             for(int i=0;i<holenum;i++){
//                 input.setLabelText("Enter Hole "+QString::number(i)+" address and Size:");
//                 if(input.exec())
//                     holes[i]=input.textValue(),qDebug()<<holes[i];
//                 else i--;

//             }
//         }

//    }
//    QLabel *label=new QLabel;
//    label->setStyleSheet("border: 1px solid black");
//    label->setText("HELLO");








}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::removegui()
{

    delete wid;
   // delete pb;

}

void MainWindow::start()
{
 delete startBP;
    bool ok;
     QInputDialog input(this);
     // input.setFixedSize(500,6000);
      input.setInputMode(QInputDialog::IntInput);
      input.setLabelText("Enter Memory Size : ");

      input.setIntRange(0,1e6);

      if(input.exec()){
          MemSize=input.intValue();
          input.setLabelText("Enter Number of Holes : ");
          if(input.exec()){
              int i=input.intValue();
              input.setLabelText("Enter Hole base Adrees and Size seperated by a space : ");
              input.setInputMode(QInputDialog::TextInput);
              while(i--){
                  if(input.exec()){
                  QVector<QString>v=split(input.textValue(),' ');
                  HOLES.push_back(make_pair(v[0].toInt(),v[1].toInt()));
                  qDebug()<<HOLES[0].first;
                  }

              }
              QStringList list;
              list<< tr("First Fit") << tr("Best Fit") << tr("Worst Fit");

              QString item = QInputDialog::getItem(this, tr("Input"),tr("Choose Methodology :"), list, 0, false, &ok);
              if(ok)
                  methodology=item=="Worst Fit"?2:item=="Best Fit"?1:0;
            qDebug()<<methodology;
            input.setInputMode(QInputDialog::IntInput);
            input.setLabelText("Enter Number of Process");
            input.setIntRange(0,20);
            if(input.exec()){
                i=input.intValue();
                input.setInputMode(QInputDialog::TextInput);
                input.setLabelText("Enter Process name,number of segments and segments(Name and Size) all seperated by a space : ");
                while(i--){
                    if(input.exec())
                        Process.push_back(split(input.textValue(),' '));


                }



            }



          }

      }
      else exit(0);

      qDebug()<<MemSize;

}

QVector<QString> split(QString s, QChar c)
{
    QString temp="";
    QVector<QString>arr;
    for(auto u:s){
        if(u!=c)temp+=u;
        else if(temp!="")arr.push_back(temp),temp="";

    }
    if(temp!="")arr.push_back(temp);
    return arr;

}
