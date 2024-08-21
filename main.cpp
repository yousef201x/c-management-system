#include <iostream>
#include <windows.h>
using namespace std;

void welcome(){
    system("Color 0e");
    cout << endl;
    cout << " @@       @@  @@@@@@@  @@      @@@@@@@  @@@@@@@@  @@@@    @@@@  @@@@@@@\n";
    cout << " @@   @   @@  @@       @@      @@       @@    @@  @@  @  @  @@  @@\n";
    cout << " @@  @@@  @@  @@@@@@   @@      @@       @@    @@  @@   @@   @@  @@@@@@\n";
    cout << " @@ @@ @@ @@  @@       @@      @@       @@    @@  @@        @@  @@@\n";
    cout << " @@@     @@@  @@@@@@@  @@@@@@  @@@@@@@  @@@@@@@@  @@        @@  @@@@@@@\n\n\n";
    Sleep(6000);
    system("cls");
}

int const avilableSlots = 1000 ;
int booksID[avilableSlots] = {0};
string booksTitle[avilableSlots];
string booksAuthors[avilableSlots];
bool booksStatus[avilableSlots] {0};
int currentPosition = 0 ;

int getAvilableSlot(){
    return currentPosition == 0 ? 0 : currentPosition ;
}

int increaseCurrentPosition(){
    return currentPosition++ ;
}

int decreaseCurrentPosition(){
    return currentPosition-- ;
}

void add(string title ,  string author){
    int slot = getAvilableSlot() ;
    int bookID = slot + 1;
    booksID[slot] = bookID ;
    booksTitle[slot] = title ;
    booksAuthors[slot] = author ;
    booksStatus[slot] = true ;
    increaseCurrentPosition() ;
    cout << "New Slot added successfully\n"
    <<"Slot id = " << bookID << endl;
}

bool isFound(int id){
    return booksID[--id] != 0;
}

void notFound(int id){
    if(!isFound(id)){
        cout << "Slot not found" ;
        return;
    }
}

void update(int id , string title , string author){
    int bookIndex = id - 1 ;
    booksTitle[bookIndex] = title ;
    booksAuthors[bookIndex] = author ;
    cout << "Slot updated successfully\n";
}

void update(int id , string title){
    notFound(id);
    int bookIndex = id - 1 ;
    booksTitle[bookIndex] = title ;
    cout << "Slot updated successfully\n";
}

void remove(int id){
    notFound(id);
    int bookIndex = id - 1 ;
    booksID[bookIndex] = 0 ;
    booksTitle[bookIndex] = '\0';
    booksAuthors[bookIndex] = '\0' ;
    booksStatus[bookIndex] = 0 ;
    decreaseCurrentPosition() ;
    cout << "Slot deleted successfully\n";
}


int main() {
    return 0;
}
