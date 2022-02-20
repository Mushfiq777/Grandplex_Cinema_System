//
// Created by Mushfiqur on 2/16/2022.
//

#ifndef DSTR_ASSIGNMENT_SAMANTHA_H
#define DSTR_ASSIGNMENT_SAMANTHA_H

#endif //DSTR_ASSIGNMENT_SAMANTHA_H


//Samantha your code goes here
#include <iostream>
#include <cstdlib>
using namespace std;

struct movieInfo { //creates a template for a node
    string mID, mName, mType, mGenre, mHall;
    int mPrice, mQuantity;
    movieInfo* next;
};

struct movieInfo* head = NULL;

void movieRecord(string mID, string mType, string mName, string mGenre, string mHall, int mPrice, int mQuantity) {
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

void displayMovieRecord() {
    struct movieInfo* displayMovie;

    displayMovie = head;

    if (displayMovie == NULL) {
        cout << "No movie record found\n";
    }

    //header to display movie details
    cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
    cout << "  |                                               NOW SHOWING                                                 |\n";
    cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
    cout << "  | Movie ID |    | Type |    |  Movie Name  |    |  Genre  |    | Hall No. |    | Price (RM) |    | Quantity |\n";
    cout << "  +-----------------------------------------------------------------------------------------------------------+";

    while (displayMovie != NULL) {
        cout << "\n  |   " << displayMovie->mID <<
             "   |    |  " << displayMovie->mType <<
             "  |    |  " << displayMovie->mName <<
             "   |    | " << displayMovie->mGenre <<
             "  |    |  " << displayMovie->mHall <<
             "  |    |     "     << displayMovie->mPrice <<
             "     |    |    " << displayMovie->mQuantity << "    |" << endl;

        //continue looking for the next node that holds movie info
        displayMovie = displayMovie->next;
    }
    cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
}
