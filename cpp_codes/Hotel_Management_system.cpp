#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>

using namespace std;

class Rm {
    int num;
    bool reserved;
    string guest;

public:
    Rm(int n) : num(n), reserved(false) {}

    void reserve(const string& name) {
        reserved = true;
        guest = name;
    }

    void vacate() {
        reserved = false;
        guest.clear();
    }

    bool isAvailable() const {
        return !reserved;
    }

    int getNum() const {
        return num;
    }

    string getGuest() const {
        return guest.empty() ? "N/A" : guest;
    }

    bool isReserved() const {
        return reserved;
    }
};

class Htl {
    Rm** rooms; // Array of pointers to Rm
    int maxRooms;
    int dispCount = 1;
    ofstream resFile;

public:
    Htl(int maxRms) : maxRooms(maxRms) {
        rooms = new Rm*[maxRooms]; // Allocate an array of pointers
        for (int i = 0; i < maxRooms; i++) {
            rooms[i] = new Rm(i + 1); // Initialize each room with its room number
        }
        resFile.open("hotel_reservations.txt", ios::app);
    }

    ~Htl() {
        for (int i = 0; i < maxRooms; i++) {
            delete rooms[i]; // Free each room
        }
        delete[] rooms; // Free the array of pointers
        if (resFile.is_open()) {
            resFile.close();
        }
    }

    void makeRes(string& name) {
        for (int i = 0; i < maxRooms; i++) {
            if (rooms[i]->isAvailable()) {
                rooms[i]->reserve(name);
                cout << "\n[Success]\nRoom " << rooms[i]->getNum() << " reserved for " << name << ".\n";
                saveResToFile(*rooms[i]);
                return;
            }
        }
        cout << "\n[Failed]\nNo available rooms.\n";
    }

    void cancelRes(int roomNum) {
        for (int i = 0; i < maxRooms; i++) {
            if (rooms[i]->getNum() == roomNum && !rooms[i]->isAvailable()) {
                rooms[i]->vacate();
                cout << "\n[Success]\nReservation for room " << roomNum << " cancelled.\n";
                return;
            }
        }
        cout << "\n[Failed]\nRoom " << roomNum << " is not reserved.\n";
    }

    int getEmptyCount() const {
        int count = 0;
        for (int i = 0; i < maxRooms; i++) {
            if (rooms[i]->isAvailable()) {
                count++;
            }
        }
        return count;
    }

    void display() {
        cout << "\n==================== Room Status ====================\n";
        cout << "Room No.   Guest Name          Status\n";
        cout << "====================================================\n";
        for (int i = 0; i < maxRooms; i++) {
            cout << rooms[i]->getNum() << "\t\t" 
                 << rooms[i]->getGuest() << "\t\t" 
                 << (rooms[i]->isReserved() ? "Reserved" : "Available") << '\n';
        }
        cout << "====================================================\n";
        saveDispToFile();
    }

private:
    void saveResToFile(const Rm& r) {
        if (resFile.is_open()) {
            resFile << "Room " << r.getNum() << " reserved by " << r.getGuest() << '\n';
        }
    }

    void saveDispToFile() {
        string fname = "hotel_display_" + to_string(dispCount++) + ".txt";
        ofstream dispFile(fname);
        if (dispFile) {
            dispFile << "==================== Room Status ====================\n";
            dispFile << "Room No.   Guest Name          Status\n";
            dispFile << "====================================================\n";
            for (int i = 0; i < maxRooms; i++) {
                dispFile << rooms[i]->getNum() << "\t\t" 
                         << rooms[i]->getGuest() << "\t\t" 
                         << (rooms[i]->isReserved() ? "Reserved" : "Available") << '\n';
            }
            dispFile << "====================================================\n";
            cout << "Room status saved to " << fname << ".\n";
        } else {
            cerr << "Error opening display file!\n";
        }
    }
};

int main() {
    Htl hotel(10);
    int choice;

    while (true) {
        cout << "\n==================== Hotel Menu ====================\n"
             << "1. Make a Reservation\n"
             << "2. Cancel a Reservation\n"
             << "3. Check Number of Empty Rooms\n"
             << "4. Display All Room Status\n"
             << "5. Exit\n"
             << "====================================================\n"
             << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string guestName;
            cout << "Enter guest name: ";
            cin.ignore();
            getline(cin, guestName);
            hotel.makeRes(guestName);
        } else if (choice == 2) {
            int roomNum;
            cout << "Enter room number to cancel reservation: ";
            cin >> roomNum;
            hotel.cancelRes(roomNum);
        } else if (choice == 3) {
            cout << "\nNumber of empty rooms: " << hotel.getEmptyCount() << '\n';
        } else if (choice == 4) {
            hotel.display();
        } else if (choice == 5) {
            cout << "Exiting...\n";
            break;
        } else {
            cout << "Invalid choice! Please try again.\n";
        }

        cout << "Press any key to continue...";
        getch();
    }
    return 0;
}