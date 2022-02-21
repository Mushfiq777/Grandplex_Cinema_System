//
// Created by Mushfiqur on 2/16/2022.
//






#ifndef DSTR_ASSIGNMENT_MUSHFIQUR_H
#define DSTR_ASSIGNMENT_MUSHFIQUR_H
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include "sam.h"
using namespace std;
void searchRecord() {
    cout << "Enter Movie ID:" << endl;
    string searchID;
    cin >> searchID;

    //transverse
     movieInfo* current = head; //create a temp pointer

    if (current == NULL) {
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        cout << "  |                                              NO MOVIES FOUND                                              |\n";
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
    }

//    bool found = false; //boolean

    while (current != NULL) {
        if (current->mID == searchID) {
            cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
            cout << "  | Movie ID |    | Type |    |  Movie Name  |    |  Genre  |    | Hall No. |    | Price (RM) |    | Quantity |\n";
            cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
            cout << "  |   " << current->mID <<
                 "   |    |  " << current->mType <<
                 "  |    |  " << current->mName <<
                 "   |    |  " << current->mGenre <<
                 " |    |  " << current->mHall <<
                 "  |    |     "     << current->mPrice <<
                 "     |    |    " << current->mQuantity << "    |" << endl;

            //put your update statements here
            //get input from user choose
            //input validation
            //overwrite value, recalculate total mark
            //clue:newrecord

//            found = true;
            break;	//keep infinite loop
        }
        else
        {
            current = current->next;
        }
    }

//    if (found == false) {
//        cout << "\nStudent not found!\n";
//    }
}

#endif //DSTR_ASSIGNMENT_MUSHFIQUR_H
