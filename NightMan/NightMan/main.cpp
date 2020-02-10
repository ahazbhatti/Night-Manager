#include "homescreen.h"
#include <QApplication>
#include <QTextStream>
#include <iostream>
#include <string>
#include "Hash.h"

using namespace std;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    int choice;
    string first, last;
    //QTextStream qtin(stdin);
    //QString line = qtin.readLine();
    hashMap hashin;
    do {
        cout << "Menu\n1: Add Guest\n2: Search For Guest\n3: Search For Room\n4: Exit\nEnter selection: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter first name: " << endl;
            cin >> first;
            cout << "Enter last name: " << endl;
            cin >> last;
            hashin.addGuest(first, last);
            break;
        case 2:
            hashin.retrieveGuestID();
            break;
        case 3:
            hashin.checkIn();
        }
    } while (choice != 4);

        return a.exec(); //Aye, try messing with it until i'm backok. just watch a basic.
}
