#include "homescreen.h"
#include "ui_homescreen.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


void MainWindow::resetMain() {
    ui->label->setText("Enter Your ID");
    ui->textEdit_2->setText("");
    ui->textEdit_2->show();
    ui->pushButton->show();
    ui->stackedWidget->setCurrentIndex(0);
}
void MainWindow::on_pushButton_clicked() {
    if (countClicks == 0) {
    userID = (ui->textEdit_2->toPlainText()).toInt();
    ui->textEdit_2->setText("");
    ui->label->setText("Enter Your Password");
    countClicks+=1;
    } else {
         countClicks = 0;
         userPass = ui->textEdit_2->toPlainText();
         ui->textEdit_2->hide();

         ui->pushButton->hide();
         ui->stackedWidget->setCurrentIndex(1);
    }
}

void MainWindow::on_pushButton_2_clicked() { //Guest

    ui->stackedWidget->setCurrentIndex(2);

}

void MainWindow::on_pushButton_8_clicked() { //Guest Book

    ui->stackedWidget->setCurrentIndex(5);

}
void MainWindow::on_pushButton_7_clicked() { //Add Guest

    ui->stackedWidget->setCurrentIndex(4);

}
void MainWindow::on_pushButton_10_clicked(){ //enter guest
    QMessageBox alert;
    alert.setText("Guest Added!");
    ui->stackedWidget->setCurrentIndex(2);
    alert.exec();
    guestFirst = ui->textEdit_4->toPlainText().toStdString();
    guestLast = ui->textEdit_5->toPlainText().toStdString();
    s.addGuest(guestFirst, guestLast);
}
void MainWindow::on_pushButton_3_clicked() { //Rooms

    ui->stackedWidget->setCurrentIndex(3);

}

void MainWindow::on_pushButton_4_clicked() { //logout
    resetMain();
}
void MainWindow::on_pushButton_6_clicked() { //logout
    resetMain();
}
void MainWindow::on_pushButton_5_clicked() { //back

    ui->stackedWidget->setCurrentIndex(1);

}
void MainWindow::on_pushButton_9_clicked(){ //cancel
    ui->stackedWidget->setCurrentIndex(2);
}

MainWindow::~MainWindow()
{
    delete ui;
}
