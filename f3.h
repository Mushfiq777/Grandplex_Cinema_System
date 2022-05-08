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
                string named = current->mName;
                if (choice == 'Y' || choice == 'y') {

                    movieInfo *first = head;
                    head = head->next;
                    delete first;

                    cout << "\nMovie ID No."<< current->mID <<" and name "<< named<<" got deleted successfully.\n";

                    break;
                }else if(choice == 'N' || choice == 'n')
                {
                    cout << "Record not deleted\n";
                    break;
                }else{
                    cout << "Invalid input\n";
                    continue;
                }
            }else if(current->next == NULL && (current->mID == dID || current->mName == dName)){
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
                string named = current->mName;

                if (choice == 'Y' || choice == 'y') {
                    movieInfo* prev = head;
                    while (prev->next->next != NULL)
                    {
                        prev = prev->next;

                    }
                    delete prev->next;
                    prev->next = NULL;

                    cout << "\nMovie ID No."<< current->mID <<" and name "<< named<<" got deleted successfully.\n";
                    break;
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
            }else if (current->next != NULL && (current->next->mID == dID || current->next->mName == dName)) {
                cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
                cout << "  |                                              MOVIE FOUND!                                                 |\n";
                cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
                cout << "  | Movie ID |    | Type |    |  Movie Name  |    |  Genre  |    | Hall No. |    | Price (RM) |    | Quantity |\n";
                cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
                cout  << "  |" << setw(7);
                printf("%04d",current->next->mID) ;
                cout <<
                     "|"<<setw(5)<<"|"  << setw(6) << current->next->mType <<
                     "|    |" << setw(14) << current->next->mName <<
                     "|    |" << setw(9) << current->next->mGenre <<
                     "|    |" << setw(10) << current->next->mHall <<
                     "|    |" << setw(12)   << current->next->mPrice <<
                     "|    |" << setw(10) << current->next->mQuantity << "|" << endl;
                cout <<"Are you sure you want to delete the record? [Y/N]\n";
                cout << "Enter input:";
                char choice;
                cin >> choice;
                cout << endl;
                found = true;
                string named = current->next->mName;
                int mId = current->next->mID;
                if (choice == 'Y' || choice == 'y') {
                    movieInfo* prev = NULL;
                    movieInfo* todelete = head;
                    prev = current;
                    todelete = current->next;
                    prev->next = todelete->next;
                    delete todelete;
                    cout << "\nMovie ID No."<< mId <<" and name "<< named<<" got deleted successfully.\n";
                    break;
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
