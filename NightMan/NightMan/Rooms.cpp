#include "Hash.h"

void hashMap::roomTypes() {
	for (int i = 1; i < numOfRooms; i++) {
		roomHashTable[i] = new room;
		roomHashTable[i]->kitchen = false;
		if(i<=10) {
			roomHashTable[i]->roomKey = i;
			roomHashTable[i]->bedNum = 2;
			roomHashTable[i]->floor = 1;
			roomHashTable[i]->smoke = true;
			roomHashTable[i]->reserved = "vacant";
			roomHashTable[i]->next = NULL;
		}
		else if((i>10)&&(i<=28)) {
			roomHashTable[i]->roomKey = i;
			roomHashTable[i]->bedNum = 1;
			roomHashTable[i]->floor = 2;
			roomHashTable[i]->smoke = false;
			roomHashTable[i]->reserved = "vacant";
			roomHashTable[i]->next = NULL;
		}
		else if((i>28)&&(i<=32)) {
			roomHashTable[i]->roomKey = i;
			roomHashTable[i]->bedNum = 1;
			roomHashTable[i]->floor = 2;
			roomHashTable[i]->smoke = true;
			roomHashTable[i]->reserved = "vacant";
			roomHashTable[i]->next = NULL;
		}
		else if((i>32)&&(i<=48)) {
			roomHashTable[i]->roomKey = i;
			roomHashTable[i]->bedNum = 2;
			roomHashTable[i]->floor = 3;
			roomHashTable[i]->smoke = false;
			roomHashTable[i]->reserved = "vacant";
			roomHashTable[i]->next = NULL;
		}
		else if((i>48)&&(i<54)) {
			roomHashTable[i]->roomKey = i;
			roomHashTable[i]->bedNum = 3;
			roomHashTable[i]->floor = 4;
			roomHashTable[i]->kitchen = true;
			roomHashTable[i]->smoke = true;
			roomHashTable[i]->reserved = "vacant";
			roomHashTable[i]->next = NULL;
		}
	}
}

int hashMap::roomSearch(int bedNum, char smoke) {
	bool vacancy;
	int reserveRoom;
	if (bedNum == 1) {
		vacancy = true;
		if (smoke == 'N') {
			for (int x = 11; x <= 28; x++) {
				if (roomHashTable[x]->reserved == "vacant") {
					vacancy = false;
					cout << "Room number " << x << " is available!" << endl;
					reserveRoom = x;
					break;
				}
			}
		}
		else if (smoke == 'Y') {
			for (int y = 29; y <= 32; y++) {
				if (roomHashTable[y]->reserved == "vacant") {
					vacancy = false;
					cout << "Room number " << y << " is available!" << endl;
					reserveRoom = y;
					break;
				}
			}
		}
	}
	else if (bedNum == 2) {
		vacancy = true;
		if (smoke == 'N') {
			for (int a = 33; a <= 48; a++) {
				if (roomHashTable[a]->reserved == "vacant") {
					vacancy = false;
					cout << "Room number " << a << " is available!" << endl;
					reserveRoom = a;
					break;
				}
			}
		}
		else if (smoke == 'Y') {
			for (int b = 1; b <= 10; b++) {
				if (roomHashTable[b]->reserved == "vacant") {
					vacancy = false;
					cout << "Room number " << b << " is available!" << endl;
					reserveRoom = b;
					break;
				}
			}
		}
	}
	else if(bedNum == 3){
		vacancy = true;
		for (int z = 49; z < numOfRooms; z++) {
			if (roomHashTable[z]->reserved == "vacant") {
				vacancy = false;
				cout << "Room number " << z << " is available!" << endl;
				reserveRoom = z;
				break;
			}
		}
	}
	if (vacancy == true) {
		cout << "No room available!" << endl;
	}
	return reserveRoom;
}

void hashMap::checkIn() {
	int numOfBeds, roomToReserve;
	char smokeRoom = 'Y' , check;
	here:
	cout << "Enter the number of beds you'd like: ";
	cout << endl;
	cin >> numOfBeds;
	if ((numOfBeds != 1) && (numOfBeds != 2) && (numOfBeds != 3)) {
		goto here;
	}
	if ((numOfBeds == 1) || (numOfBeds == 2)) {
		cout << "Would you like a smoking room? Y/N" << endl;
		cin >> smokeRoom;
	}
	roomToReserve = roomSearch(numOfBeds, smokeRoom);
	cout << "Would you like to book this room? Y/N" << endl;
	cin >> check;
		if (check == 'Y') {
			roomHashTable[roomToReserve]->reserved = "booked";
		}
		else if (check == 'N') {
			cout << "Book with us later..." << endl;
		}
}