//
// Created by Mushfiqur on 2/21/2022.
//

#ifndef DSTR_ASSIGNMENT_SAM_H
#define DSTR_ASSIGNMENT_SAM_H
#include <iostream>
#include <cstdlib>
#include "Mushfiqur.h"
using namespace std;
struct movieInfo { //creates a template for a node
    string mID, mName, mType, mGenre, mHall;
    int mPrice, mQuantity;
    movieInfo* next;
};

struct movieInfo* head = NULL;

void movieRecord(string mID, string mType, string mName, string mGenre, string mHall, int mPrice, int mQuantity) { //creates new movie record (hardcoded)
    //adds a new movie record
    struct movieInfo* newMovie = new struct movieInfo;

    newMovie->mID = mID;
    newMovie->mType = mType;
    newMovie->mName = mName;
    newMovie->mGenre = mGenre;
    newMovie->mHall = mHall;
    newMovie->mPrice = mPrice;
    newMovie->mQuantity = mQuantity;

    //points the node that holds info of new movie to the same MA of current head; either NULL or first node connected to head
    newMovie->next = head;

    //points the head to the MA of the new node created; inserts the node holding new movie info at the beginning of the list
    head = newMovie;
}

void addNewMovie() { //accepts new movie record from user
    struct movieInfo* newMovieRecord = new struct movieInfo;

    cout << "Enter Movie ID: ";
    cin >> newMovieRecord->mID;

    struct movieInfo* check; //transverse to find existing ID

    check = head; //points to the beginning of the LL

    while (check != NULL) { //move through the nodes until the end of the LL
        if (newMovieRecord->mID == check->mID) { //while looking at all node value, check if value cin = to any existing movie ID
            cout << "Sorry that movie ID already exists! Please re-enter a valid movie ID: "; //validates whether the movie ID exists or not and if it does, ask the user to re-enter a valid movie ID
            cin >> newMovieRecord->mID;
            check = head;

        }
        else {
            check = check->next;
        }
    }

    cout << "Enter movie name: ";
    cin >> newMovieRecord->mName;
    check = head; //points to the beginning of the LL

    while (check != NULL) { //move through the nodes until the end of the LL
        if (newMovieRecord->mName == check->mName) { //while looking at all node value, check if value cin = to any existing movie name
            cout << "Sorry that movie name already exists! Please re-enter a valid movie name: "; //validates whether the movie name exists or not and if it does, ask the user to re-enter a valid movie name
            cin >> newMovieRecord->mName;
            check = head;
        }
        else {
            check = check->next;
        }
    }

    //get movie type and input validation
    while (true) {
        string movTyp;
        cout << "Please enter the movie type [2D/3D]: ";
        cin >> movTyp;
        if (movTyp == "2D" || movTyp == "3D") {
            newMovieRecord->mType = movTyp;
            break;
        }
        else
        {
            cout << "Invalid input please enter again";
        }
    }

    //get movie genre and input validation
    while (true) {
        cout << "Please enter the movie genre [Action/Horror/Comedy/Sci-fi]: ";
        cin >> newMovieRecord->mGenre;

        if (newMovieRecord->mGenre == "Action" || newMovieRecord->mGenre == "Horror" || newMovieRecord->mGenre == "Comedy" || newMovieRecord->mGenre == "Sci-fi")
        {
            break;
        }
        else
        {
            cout << "Invalid input please enter again";
        }
    }

    //get hall number and input validation
    while (true) {
        cout << "Please enter the hall number [Hall<hall no.>]: ";
        cin >> newMovieRecord->mHall;

        if (newMovieRecord->mHall == "Hall1" || newMovieRecord->mHall == "Hall2" || newMovieRecord->mHall == "Hall3" || newMovieRecord->mHall == "Hall4" || newMovieRecord->mHall == "Hall5")
        {
            break;
        }
        else
        {
            cout << "Invalid input please enter again";
        }
    }

    //get movie price and input validation
    while (true) {
        int y;
        cout << "Please enter the price in integers: ";
        cin >> y;
        if (cin.fail())
        {
            cout << "Invalid Input! Please enter again\n";
        }
        else
        {
            newMovieRecord->mPrice = y;
            break;
        }
    }

    //get available quantity of the movie and input validation
    while (true)
    {
        int x;
        cout << "Please enter the quantity in integers: ";
        cin >> x;
        if (cin.fail())
        {
            cout << "Invalid Input! Please enter again\n";
        }
        else
        {
            newMovieRecord->mQuantity = x;
            break;
        }
    }

    //points the node that holds info of new movie to the same MA of current head; either NULL or first node connected to head
    newMovieRecord->next = head;

    //points the head to the MA of the new node created; inserts the node holding new movie info at the beginning of the list
    head = newMovieRecord;
}

void displayMovieRecord() {
    struct movieInfo* displayMovie;

    displayMovie = head;

    if (displayMovie == NULL) {
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        cout << "  |                                              NO MOVIES FOUND                                              |\n";
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
    }
    else {
        //header to display movie details
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        cout << "  |                                               NOW SHOWING                                                 |\n";
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        cout << "  | Movie ID |    | Type |    |  Movie Name  |    |  Genre  |    | Hall No. |    | Price (RM) |    | Quantity |\n";
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";

        while (displayMovie != NULL) {
            cout << "  |   " << displayMovie->mID <<
                 "   |    |  " << displayMovie->mType <<
                 "  |    |  " << displayMovie->mName <<
                 "   |    |  " << displayMovie->mGenre <<
                 " |    |  " << displayMovie->mHall <<
                 "  |    |     "     << displayMovie->mPrice <<
                 "     |    |    " << displayMovie->mQuantity << "    |" << endl;

            //continue looking for the next node that holds movie info
            displayMovie = displayMovie->next;
        }
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
    }
}

void showMenu() {
    cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
    cout << "  |                                WELCOME TO GRANDPLEX MOVIE TICKETING SYSTEM                                |\n";
    cout << "  |                                         WHAT WOULD YOU LIKE TO DO?                                        |\n";
    cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
    cout << "  |                                      1. Add new movie record                                              |\n";
    cout << "  |                                      2. Display all available movies                                      |\n";
    cout << "  |                                      3. Search for movie                                                  |\n";
    cout << "  |                                      4. Category filter                                                   |\n";
    cout << "  |                                      5. Update movie record                                               |\n";
    cout << "  |                                      6. Sort movie record                                                 |\n";
    cout << "  |                                      7. Delete movie record                                               |\n";
    cout << "  |                                      8. Add new transaction                                               |\n";
    cout << "  |                                      9. View transactions                                                 |\n";
    cout << "  |                                     10. Sort transactions                                                 |\n";
    cout << "  |                                     11. View details of a transaction                                     |\n";
    cout << "  |                                     12. Exit                                                              |\n";
}

void menu() {

    showMenu();
    cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
    cout << "  |                                       Please enter your choice below:                                     |\n";
    int choice;
    cout << "                                                        ";
    cin >> choice;
    cout << "  +-----------------------------------------------------------------------------------------------------------+\n";

    while (choice != 12) {
        switch (choice) {
            case 1:
                displayMovieRecord();
                addNewMovie();
                break;
            case 2:
                displayMovieRecord();
                break;
            case 3:
                searchRecord();
                break;
            case 4:
                filter();
                break;
            case 5:
                update();
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                break;
            case 11:
                break;
            case 12:
                break;
            default:
                cout << "                                               Invalid Selection!" << endl;
        }
        /*cout << endl;
        showMenu();
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        cout << "  |                                       Please enter your choice below:                                     |\n";
        int choice;
        cout << "                                                        ";
        cin >> choice;
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";*/
    }
}

#endif //DSTR_ASSIGNMENT_SAM_H
