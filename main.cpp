#include <iostream>
using namespace std;

int const avilableSlots = 1000 ;
int booksID[avilableSlots] = {0};
string booksTitle[avilableSlots];
string booksAuthors[avilableSlots];
bool booksStatus[avilableSlots];
int currentPosition = 0 ;

int getAvilableSlot(){
    return currentPosition == 0 ? 0 : currentPosition ;
}

int increaseCurrentPosition(){
    return currentPosition++ ;
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

void update(int id , string title , string author){
    int bookIndex = id - 1 ;
    booksTitle[bookIndex] = title ;
    booksAuthors[bookIndex] = author ;
    cout << "Slot updated successfully\n";
}

void update(int id , string title){
    int bookIndex = id - 1 ;
    booksTitle[bookIndex] = title ;
    cout << "Slot updated successfully\n";
}


int main() {
    return 0;
}
