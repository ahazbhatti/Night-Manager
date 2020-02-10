#include "Hash.h"

void hashMap::guestTable() {
    ofstream ofs;
    ofs.open("guestbook.txt", fstream::out);
	for (int i = 0; i < tableSize; i++) {
        guestHashTable[i] = new guest;
		guestHashTable[i]->guestKey = 0;
        //guestHashTable[i]->dateOfEntry = stampDate.toString().toStdString();
        guestHashTable[i]->firstName = "empty";
		guestHashTable[i]->lastName = "empty";
		guestHashTable[i]->next = NULL;
        ofs << guestHashTable[i]->guestKey << endl << guestHashTable[i]->firstName << endl << guestHashTable[i]->lastName << endl;
	}
	ofs.close();
}


void hashMap::writeGuestBook()
{
	ofstream ofs;
	ofs.open("guestbook.txt", fstream::out);
	for (int i = 0; i < tableSize; i++) {
        ofs << guestHashTable[i]->guestKey << endl << guestHashTable[i]->firstName << endl << guestHashTable[i]->lastName << endl;
	}
	ofs.close();

}

void hashMap::retrieveGuestBook() {
	ifstream ifs;
	string line;
	int c1 = 0;
	int c2 = 0;
	int c3 = 0;
	ifs.open("guestbook.txt");
	while (getline(ifs, line)) {
		if (c2 == 0) {
			guestHashTable[c1] = new guest;
			guestHashTable[c1]->guestKey = stoi(line);
			c2++;
		}
		else if (c2 == 1) {
			guestHashTable[c1]->firstName = line;
			c2++;
		}
		else if (c2 == 2) {
			guestHashTable[c1]->lastName = line;
			guestHashTable[c1]->next = NULL;
			c2 = 0;
			if (c1 <= 99)
			c1++;
		}
	}
	ifs.close();
}
void hashMap::addGuest(string firstName, string lastName) {
	int index = hash(firstName);
	if (guestHashTable[index]->firstName == "empty") {
		guestHashTable[index]->guestKey = index;
		guestHashTable[index]->firstName = firstName;
		guestHashTable[index]->lastName = lastName;
	}
	else {
		guest* ptr = guestHashTable[index];
		guest* n = new guest;
		n->firstName = firstName;
		n->lastName = lastName;
		n->next = NULL;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = n;
	}
}

int hashMap::numberOfItemsInBucket(int index) {
	int count = 0;
	if (guestHashTable[index]->firstName == "empty") {
		return count;
	}
	else {
		count++;
		guest* ptr = guestHashTable[index];
		while (ptr->next != NULL) {
			count++;
			ptr = ptr->next;
		}
	}
	return count;
}

void hashMap::retrieveGuestID() {
	int guestID;
	int number;
	bool guestCheck = false;
	string firstNameSearch, lastNameSearch;

	cout << "Enter the first name of guest you'd like to retrieve: " << endl;
	cin >> firstNameSearch;
	cout << "Enter the last name of guest you'd like to retrieve: " << endl;
	cin >> lastNameSearch;


	for (int i = 0; i < tableSize; i++) {
		if ((guestHashTable[i]->firstName == firstNameSearch) && (guestHashTable[i]->lastName == lastNameSearch)) {
			guestID = guestHashTable[i]->guestKey;
			guestCheck = true;
			number = numberOfItemsInBucket(i);
			cout << "Guest Found:";
			cout << "-----\n";
			cout << "index = " << i << endl;
			cout << guestHashTable[i]->guestKey << endl;
			cout << guestHashTable[i]->firstName << endl;
			cout << guestHashTable[i]->lastName << endl;
			cout << "-----\n";
		}
	}
	if (guestCheck == false) {
		cout << "Guest Not Found!" << endl;
	}
}

