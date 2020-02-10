#include "Hash.h"

hashMap::hashMap() {
    retrieveGuestBook();
    //guestTable();
	roomTypes();
}

QString getTime() {
    QDateTime dt = QDateTime::currentDateTime();
    QString str2 = dt.toString();
    str2.chop(6); // remove -0500
    return str2;
}

int hashMap::hash(string key) {
	int hash = 100;
	int index;
	for (int i = 0; i < key.length(); i++) {
        hash += (int)key[i];
	}
	index = hash % tableSize;
	return index;
}


hashMap::~hashMap() {
	writeGuestBook();
	roomTypes();
    cout << "DONE" << endl;
}
