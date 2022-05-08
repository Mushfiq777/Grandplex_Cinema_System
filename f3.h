//
// Created by Mushfiqur on 2/16/2022.
//

#ifndef Grandplex_Cinema_System_F3_H
#define Grandplex_Cinema_System_F3_H
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>

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
        cout << "No movies found in the system\n";
    }
    else
    {
        cout << "Type the Movie ID or name that you wish to delete:" << endl;
        string dName;

        cin >> dName;
        cout << endl;
        stringstream ss;
        ss << dName;
        int dID;
        ss >> dID;

        while (current != NULL) {
            if(head->mID==dID || head->mName == dName)
            {
                cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
                cout << "  |                                              MOVIE FOUND!                                                 |\n";
                cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
                cout << "  | Movie ID |    | Type |    |  Movie Name  |    |  Genre  |    | Hall No. |    | Price (RM) |    | Quantity |\n";
                cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
                cout  << "  |" << setw(7);
                printf("%04d",current->mID) ;
                cout <<
                     "|"<<setw(5)<<"|"  << setw(6) << current->mType <<
                     "|    |" << setw(14) << current->mName <<
                     "|    |" << setw(9) << current->mGenre <<
                     "|    |" << setw(10) << current->mHall <<
                     "|    |" << setw(12)   << current->mPrice <<
                     "|    |" << setw(10) << current->mQuantity << "|" << endl;
                cout <<"Are you sure you want to delete the record? [Y/N]\n";
                cout << "Enter input:";
                char choice;
                cin >> choice;
                cout << endl;
                found = true;
                if (choice == 'Y' || choice == 'y') {
                    movieInfo *first = head;
                    first = first->next;
                    delete head;
                    head = first;

                    cout << "\nMovie ID No."<< current->mID <<" and name "<< current->mName<<" got deleted successfully.";
                }else if(choice == 'N' || choice == 'n')
                {
                    cout << "Record not deleted\n";
                    break;
                }else{
                    cout << "Invalid input\n";
                    continue;
                }
            }else if (current->mID == dID || current->mName == dName) {
                cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
                cout << "  |                                              MOVIE FOUND!                                                 |\n";
                cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
                cout << "  | Movie ID |    | Type |    |  Movie Name  |    |  Genre  |    | Hall No. |    | Price (RM) |    | Quantity |\n";
                cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
                cout  << "  |" << setw(7);
                printf("%04d",current->mID) ;
                cout <<
                     "|"<<setw(5)<<"|"  << setw(6) << current->mType <<
                     "|    |" << setw(14) << current->mName <<
                     "|    |" << setw(9) << current->mGenre <<
                     "|    |" << setw(10) << current->mHall <<
                     "|    |" << setw(12)   << current->mPrice <<
                     "|    |" << setw(10) << current->mQuantity << "|" << endl;
                cout <<"Are you sure you want to delete the record? [Y/N]\n";
                cout << "Enter input:";
                char choice;
                cin >> choice;
                cout << endl;
                found = true;

                if (choice == 'Y' || choice == 'y') {
                    movieInfo* todelete = current->next;
                    current->next = todelete->next;
                    delete todelete;
                    cout << "\nMovie ID No."<< current->mID <<" and name "<< current->mName<<" got deleted successfully.";

                }
                else if(choice == 'N' || choice == 'n')
                {
                    cout << "Record not deleted\n";
                    break;
                }
                else {
                    cout << "Invalid input\n";
                    continue;
                }
            }else {
                current = current->next;
            }

        }
        if (!found) {
            cout << "Invalid Movie ID\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');


        }
    }

}
#endif //Grandplex_Cinema_System_F3_H
