//
// Created by Mushfiqur on 2/16/2022.
//

#ifndef DSTR_ASSIGNMENT_BHARA_H
#define DSTR_ASSIGNMENT_BHARA_H
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include "sam.h"
using namespace std;
void addPurchase() {
    struct movieInfo *newPurchase = new struct movieInfo;
    struct movieInfo *checkID;
    checkID = head; //Reading the data
    cout << "Movie ID: "; //Reading the Movie ID
    cin >> newPurchase->mID;

    while (checkID != NULL) {
        if (newPurchase->mID == checkID->mID) { //Validation for duplication
            cout << "The movie id is duplicated! Please retype id again: ";
            cin >> newPurchase->mID;
            checkID = head;
            while (checkID != NULL) {
                if (newPurchase->mID == checkID->mID) { //Validating for duplication
                    cout << "The movie id is duplicated! Please retype id again : ";
                    cin >> newPurchase->mID;
                    checkID = head;
                } else {
                    checkID = checkID->next;
                }
            }
        } else {
            checkID = checkID->next;

        }
    }

    cout << "Type of movie [2D, 3D]: "; //Displaying the user the options for the types of ticket
    cin >> newPurchase->mType;

    cout << "Hall no.? [1, 2, 3, 4, 5]: ";
    cin >> newPurchase->mHall;

    cout << "No. of ticket: ";
    cin >> newPurchase->mQuantity;

    cout << "Total ticket Price: ";
    cin >> newPurchase->mPrice;


    cout << endl;

    newPurchase->next = head; //Big O notation from O(N) become o(1)
    head = newPurchase;
}
void PurchaseDetails() {
    int choice;
    cout << "Purchase details Menu" << endl
         << "1. Add Ticket" << endl
         << "2. View all Purchased Ticket list" << endl
         << "3. Main Menu" << endl
         << "Enter you input: ";
    cin >> choice;
    cout << endl;
    switch (choice) {
        case 1:
            addPurchase();
            cout << endl;
            PurchaseDetails();
        case 2:
            cout << "once code done it can be added";
        case 3:

            displayMovieRecord();
            cout << endl;
            PurchaseDetails();
        default:
            cout << "Invalid input!\n";
            PurchaseDetails();
    }
}
#endif //DSTR_ASSIGNMENT_BHARA_H
