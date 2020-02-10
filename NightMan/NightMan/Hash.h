#pragma once
#include <iostream>
#include <QString>
#include <cstdlib>
#include <fstream>
#include <QTime>
#include <QDate>
#include <QDateTime>

using namespace std;




#ifndef HASHMAP_H
#define HASHMAP_H

class hashMap {
public:
	static const int tableSize = 100;
	static const int numOfRooms = 55;
    //QDateTime stampDate = QDateTime().currentDateTime();
	struct guest {
		int guestKey;
        //QDateTime dateOfEntry;
        string firstName;
        string lastName;
		guest* next;
	};
	guest* guestHashTable[tableSize];
	struct room {
		int roomKey;
		int bedNum;
		int floor;
		bool kitchen;
		bool smoke;
        QString reserved;
		room* next;
	};
	room* roomHashTable[numOfRooms];

	hashMap();
    QString getTime();
    int hash(string key);


	//guestbook.cpp
	void guestTable();
    void addGuest(string firstName, string lastName);
	int numberOfItemsInBucket(int index);
	void retrieveGuestID();
	void writeGuestBook();
	void retrieveGuestBook();


	//roombook.cpp
	void roomTypes();
	int roomSearch(int bedNum, char smoke);
	void checkIn();
	void checkOut();
    ~hashMap();
};
#endif // !HASHMAP_H
