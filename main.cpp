#include <iostream>
#include <windows.h>
using namespace std;

int const avilableSlots = 1000;
int booksID[avilableSlots] = {0};
string booksTitle[avilableSlots];
string booksAuthors[avilableSlots];
bool booksStatus[avilableSlots] {0};
int currentPosition = 0;

void welcome() {
    system("Color 0e");
    cout << endl;
    cout << " @@       @@  @@@@@@@  @@      @@@@@@@  @@@@@@@@  @@@@    @@@@  @@@@@@@\n";
    cout << " @@   @   @@  @@       @@      @@       @@    @@  @@  @  @  @@  @@\n";
    cout << " @@  @@@  @@  @@@@@@   @@      @@       @@    @@  @@   @@   @@  @@@@@@\n";
    cout << " @@ @@ @@ @@  @@       @@      @@       @@    @@  @@        @@  @@@\n";
    cout << " @@@     @@@  @@@@@@@  @@@@@@  @@@@@@@  @@@@@@@@  @@        @@  @@@@@@@\n\n\n";
    Sleep(3000);
}

int getAvailableSlot() {
    return currentPosition == 0 ? 0 : currentPosition;
}

int increaseCurrentPosition() {
    return currentPosition++;
}

int decreaseCurrentPosition() {
    return currentPosition--;
}

void add(string title, string author) {
    int slot = getAvailableSlot();
    int bookID = slot + 1;
    booksID[slot] = bookID;
    booksTitle[slot] = title;
    booksAuthors[slot] = author;
    booksStatus[slot] = true;
    increaseCurrentPosition();
    cout << "New Slot added successfully\n"
         << "Slot id = " << bookID << endl;
}

bool isFound(int id) {
    return booksID[--id] != 0;
}

void update(int id, string title, string author) {
    if (!isFound(id)) {
        cout << "Slot not found" << endl;
        return;
    }
    int bookIndex = id - 1;
    booksTitle[bookIndex] = title;
    booksAuthors[bookIndex] = author;
    cout << "Slot updated successfully\n";
}

void update(int id, string title) {
    if (!isFound(id)) {
        cout << "Slot not found" << endl;
        return;
    }
    int bookIndex = id - 1;
    booksTitle[bookIndex] = title;
    cout << "Slot updated successfully\n";
}

void remove(int id) {
    if (!isFound(id)) {
        cout << "Slot not found" << endl;
        return;
    }
    int bookIndex = id - 1;
    booksID[bookIndex] = 0;
    booksTitle[bookIndex] = "";
    booksAuthors[bookIndex] = "";
    booksStatus[bookIndex] = false;
    decreaseCurrentPosition();
    cout << "Slot deleted successfully\n";
}

void borrow(int id) {
    if (!isFound(id)) {
        cout << "Slot not found" << endl;
        return;
    }
    int bookIndex = id - 1;
    if (!booksStatus[bookIndex]) {
        cout << "Book is not available" << endl;
        return;
    }
    booksStatus[bookIndex] = false;
    cout << "Book with ID = " << id << " has been successfully borrowed.\n";
}

void lend(int id) {
    if (!isFound(id)) {
        cout << "Slot not found" << endl;
        return;
    }
    int bookIndex = id - 1;
    if (booksStatus[bookIndex]) {
        cout << "Book is already available" << endl;
        return;
    }
    booksStatus[bookIndex] = true;
    cout << "Book with ID = " << id << " has been successfully returned.\n";
}

void displayMenu() {
    cout << "\n\n\n";
    cout << "Book Management System\n";
    cout << "1. Add Book\n";
    cout << "2. Update Book\n";
    cout << "3. Remove Book\n";
    cout << "4. Borrow Book\n";
    cout << "5. Return Book\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    welcome();

    displayMenu();
    while (true) {
        int choice, id;
        string title, author;
        cin >> choice;

        switch (choice) {
            case 1: // Add Book
                cout << "Enter title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter author: ";
                getline(cin, author);
                add(title, author);
                displayMenu();
                break;

            case 2: // Update Book
                cout << "Enter book ID to update: ";
                cin >> id;
                cout << "Enter new title (or press Enter to skip): ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter new author (or press Enter to skip): ";
                getline(cin, author);
                if (title.empty() && author.empty()) {
                    cout << "No updates provided.\n";
                } else if (title.empty()) {
                    update(id, author);
                } else if (author.empty()) {
                    update(id, title);
                } else {
                    update(id, title, author);
                }
                displayMenu();
                break;

            case 3: // Remove Book
                cout << "Enter book ID to remove: ";
                cin >> id;
                remove(id);
                displayMenu();
                break;

            case 4: // Borrow Book
                cout << "Enter book ID to borrow: ";
                cin >> id;
                borrow(id);
                displayMenu();
                break;

            case 5: // Return Book
                cout << "Enter book ID to return: ";
                cin >> id;
                lend(id);
                displayMenu();
                break;

            case 6: // Exit
                cout << "Exiting the system.\n";
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}
