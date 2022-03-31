//
// Created by Mushfiqur on 2/16/2022.
//

#ifndef DSTR_ASSIGNMENT_F3_H
#define DSTR_ASSIGNMENT_F3_H
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <iomanip>

#include "f2.h"
using namespace std;

//struct movieInfo
//{
//    string mid;
//    movieInfo* base;
//};
//struct movieInfo* head = NULL;

void deleting()
{
    movieInfo* current = head;
    bool found = false;

    if (current == NULL)
    {
        cout << "The list seems to be empty\n";
    }
    else
    {
        cout << "Type the Movie ID that you wish to delete:" << endl;
        int dID;
        cin >> dID;
        cout << endl;
        //bool found = false;

        while (current != NULL) {
            if (current->mID == dID) {
                cout << "Delete record ?" << current->mID << ".\nDo you really want to delete the record? [Y/N]\n";
                cout << "Enter input:";
                char choice;
                cin >> choice;
                cout << endl;

                if (choice == 'Y' || choice == 'y') {
                    movieInfo* first = head;
                    first = first->next;
                    delete head;
                    head = first;
                    found = true;
                    cout << "\nMovie ID " << dID << " is deleted.\n";
                }
                else {
                    cout << "The Deletion was unsuccessfull!\n";
                }
                found = true;
                break;
            }
                // !input.is_open()
//            else if (current->next->mID == dID) {
//                cout << "Deleting the movie data with the ID" << dID << ".\nAre you 100% sure? [Y/N]\n";
//                char choice;
//                cout << "Enter input:";
//                cin >> choice;
//
//                if (choice == 'Y' || choice == 'y') {
//                    movieInfo* before = current;
//                    movieInfo* deletiing = current->next;
//                    before->next = deletiing->next;
//                    delete deletiing;
//                    found = true;
//                    cout << "\nDeleted " << dID << " successfully.\n";
//                    break;
//                }
//                else {
//                    cout << "Data not deleted successfully \n";
//                }
//                found = true;
//                break;
//            }
            else {
                current = current->next;
            }
        }
        if (found == false) {
            cout << "Invalid Movie ID\nEnter 1 and try again. Enter 2 to exit" << endl;
            int choice;
            cin >> choice;
            switch (choice) {
                case 1:
                    deleting();
                case 2:
                    exit(0);
            }
        }
    }

}
#endif //DSTR_ASSIGNMENT_F3_H
