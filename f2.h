//
// Created by Mushfiqur on 2/21/2022.
//

#ifndef DSTR_ASSIGNMENT_F2_H
#define DSTR_ASSIGNMENT_F2_H
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <sstream>

//#include "Mushfiqur.h"
using namespace std;

struct movieInfo { //creates a template for a node
    string  mName, mType, mGenre, mHall;
    int mID, mPrice, mQuantity;
    movieInfo* next;
};

struct movieInfo* head = NULL;

void movieRecord(int mID, string mType, string mName, string mGenre, string mHall, int mPrice, int mQuantity) { //creates new movie record (hardcoded)
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
    struct movieInfo* check; //transverse to find existing ID

    check = head; //points to the beginning of the LL
    while(true){
//        cin.ignore();

        cout << "Enter Movie ID: ";
        cin >> newMovieRecord->mID;
//        getline(cin,newMovieRecord->mID);
        cout << endl;


        if(!cin.fail())
        {
            while (check != NULL)
            { //move through the nodes until the end of the LL
                if (newMovieRecord->mID == check->mID) { //while looking at all node value, check if value cin = to any existing movie ID
                    cout << "Sorry that movie ID already exists! Please re-enter a valid movie ID: "; //validates whether the movie ID exists or not and if it does, ask the user to re-enter a valid movie ID
                    cin >> newMovieRecord->mID;
                    check = head;

                }
                else {
                    check = check->next;
                }
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            break;
        }else
        {
            cout << "Invalid input try again\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

        }






    }



    cout << "Enter movie name: ";
    cin >> newMovieRecord->mName;
    cout << endl;
    check = head; //points to the beginning of the LL

    while (check != NULL) { //move through the nodes until the end of the LL
        if (newMovieRecord->mName == check->mName) { //while looking at all node value, check if value cin = to any existing movie name
            cout << "Sorry that movie name already exists! Please re-enter a valid movie name: \n"; //validates whether the movie name exists or not and if it does, ask the user to re-enter a valid movie name
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
        cout << endl;

        if (movTyp == "2D" || movTyp == "3D") {
            newMovieRecord->mType = movTyp;
            break;
        }
        else
        {
            cout << "Invalid input please enter again";
            cout << endl;

        }
    }

    //get movie genre and input validation
    while (true) {
        cout << "Please enter the movie genre [Action/Horror/Comedy/Sci-fi]: ";
        cin >> newMovieRecord->mGenre;
        cout << endl;

        if (newMovieRecord->mGenre == "Action" || newMovieRecord->mGenre == "Horror" || newMovieRecord->mGenre == "Comedy" || newMovieRecord->mGenre == "Sci-fi")
        {
            break;
        }
        else
        {
            cout << "Invalid input please enter again\n";
        }
    }

    //get hall number and input validation
    while (true) {
        cout << "Please enter the hall number [Hall<hall no.>]: ";
        cin >> newMovieRecord->mHall;
        cout << endl;

        if (newMovieRecord->mHall == "Hall1" || newMovieRecord->mHall == "Hall2" || newMovieRecord->mHall == "Hall3" || newMovieRecord->mHall == "Hall4" || newMovieRecord->mHall == "Hall5")
        {
            break;
        }
        else
        {
            cout << "Invalid input please enter again";
            cout << endl;

        }
    }

    //get movie price and input validation
    while (true) {
        int y=0;
        cout << "Please enter the price in integers: ";
        cin >>  y;
        cout << endl;

        if (cin.fail())
        {
            cout << "Invalid Input! \n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            newMovieRecord->mPrice = y;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }

    //get available quantity of the movie and input validation
    while (true)
    {
        int x = 0;
        cout << "Please enter the quantity in integers: ";
        cin >> x;
        cout << endl;

        if (cin.fail())
        {
            cout << "Invalid Input! Please enter again\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

        }
        else
        {
            newMovieRecord->mQuantity = x;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
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

            cout  << "  |" << setw(7);
            printf("%04d",displayMovie->mID) ;
            cout <<
                 "|"<<setw(5)<<"|"  << setw(6) << displayMovie->mType <<
                 "|    |" << setw(14) << displayMovie->mName <<
                 "|    |" << setw(9) << displayMovie->mGenre <<
                 "|    |" << setw(10) << displayMovie->mHall <<
                 "|    |" << setw(12)   << displayMovie->mPrice <<
                 "|    |" << setw(10) << displayMovie->mQuantity << "|" << endl;

            //continue looking for the next node that holds movie info
            displayMovie = displayMovie->next;
        }
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
    }
}

#endif //DSTR_ASSIGNMENT_F2_H
