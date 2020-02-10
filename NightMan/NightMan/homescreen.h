#ifndef HOMESCREEN_H
#define HOMESCREEN_H

#include <QMainWindow>
#include <QString>
#include <QMessageBox>
#include <Hash.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    hashMap s;
    explicit MainWindow(QWidget *parent = 0);
    void MainWindow::resetMain();
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked(); // Add Guest
    void on_pushButton_8_clicked(); // Guest Book
    void on_pushButton_10_clicked(); // Enter Guest

    void on_pushButton_9_clicked(); // Cancel

private:
    Ui::MainWindow *ui;
    qint8 userID;
    string guestFirst, guestLast;
    QString userPass;
    int countClicks = 0;
};

#endif // HOMESCREEN_H
