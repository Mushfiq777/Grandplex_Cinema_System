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
#include <cstring>

#include "f2.h"
using namespace std;

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

void sortMA(){
    movieInfo* current = head, *index = NULL;
    int tempID, tempPrice, tempQ;
    string tempName, tempType, tempGenre, tempHall;


    if (head==NULL){
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        cout << "  |                                              NO MOVIES AVAILABLE IN THE SYSTEM                            |\n";
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
    }else
    {

        while(current != NULL){
            index = current->next;

            while(index != NULL){
                if(current->mID > index->mID){
                    tempID = index->mID;
                    tempName = index->mName;
                    tempGenre = index->mGenre;
                    tempHall = index->mHall;
                    tempPrice = index->mPrice;
                    tempQ = index->mQuantity;
                    tempType = index->mType;
                    /***************/
                    index->mID = current->mID;
                    index->mName = current->mName;
                    index->mType = current->mType;
                    index->mGenre = current->mGenre;
                    index->mQuantity = current->mQuantity;
                    index->mHall = current->mHall;
                    index->mPrice = current->mPrice;
                    /**************/
                    current->mID = tempID ;
                    current->mName = tempName;
                    current->mPrice = tempPrice;
                    current->mQuantity = tempQ;
                    current->mHall = tempHall;
                    current->mGenre = tempGenre;
                    current->mType = tempType;
                }
                index = index->next;
            }
            current = current->next;
        }
        current = head;
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        cout << "  |                                               NOW SHOWING                                                 |\n";
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        cout << "  | Movie ID |    | Type |    |  Movie Name  |    |  Genre  |    | Hall No. |    | Price (RM) |    | Quantity |\n";
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        while(current != NULL){
            cout  << "  |" << setw(7);
            printf("%04d",current->mID) ;
            cout <<
                 "|"<<setw(5)<<"|"  << setw(6) << current->mType <<
                 "|    |" << setw(14) << current->mName <<
                 "|    |" << setw(9) << current->mGenre <<
                 "|    |" << setw(10) << current->mHall <<
                 "|    |" << setw(12)   << current->mPrice <<
                 "|    |" << setw(10) << current->mQuantity << "|" << endl;
            current = current->next;

        }
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";

    }
}

void sortMD(){
    movieInfo* current = head, *index = NULL;
    int tempID, tempPrice, tempQ;
    string tempName, tempType, tempGenre, tempHall;

    if (head==NULL){
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        cout << "  |                                              NO MOVIES AVAILABLE IN THE SYSTEM                            |\n";
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
    }else
    {

        while(current != NULL){
            index = current->next;

            while(index != NULL){
                if(current->mID < index->mID){
                    tempID = index->mID;
                    tempName = index->mName;
                    tempGenre = index->mGenre;
                    tempHall = index->mHall;
                    tempPrice = index->mPrice;
                    tempQ = index->mQuantity;
                    tempType = index->mType;
                    /***************/
                    index->mID = current->mID;
                    index->mName = current->mName;
                    index->mType = current->mType;
                    index->mGenre = current->mGenre;
                    index->mQuantity = current->mQuantity;
                    index->mHall = current->mHall;
                    index->mPrice = current->mPrice;
                    /**************/
                    current->mID = tempID ;
                    current->mName = tempName;
                    current->mPrice = tempPrice;
                    current->mQuantity = tempQ;
                    current->mHall = tempHall;
                    current->mGenre = tempGenre;
                    current->mType = tempType;

                }
                index = index->next;
            }
            current = current->next;
        }
        current = head;
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        cout << "  |                                               NOW SHOWING                                                 |\n";
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        cout << "  | Movie ID |    | Type |    |  Movie Name  |    |  Genre  |    | Hall No. |    | Price (RM) |    | Quantity |\n";
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        while(current != NULL){
            cout  << "  |" << setw(7);
            printf("%04d",current->mID) ;
            cout <<
                 "|"<<setw(5)<<"|"  << setw(6) << current->mType <<
                 "|    |" << setw(14) << current->mName <<
                 "|    |" << setw(9) << current->mGenre <<
                 "|    |" << setw(10) << current->mHall <<
                 "|    |" << setw(12)   << current->mPrice <<
                 "|    |" << setw(10) << current->mQuantity << "|" << endl;
            current = current->next;

        }
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";

    }
}

void sortMPA(){
    movieInfo* current = head, *index = NULL;
    int tempID, tempPrice, tempQ;
    string tempName, tempType, tempGenre, tempHall;


    if (head==NULL){
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        cout << "  |                                              NO MOVIES AVAILABLE IN THE SYSTEM                            |\n";
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
    }else
    {

        while(current != NULL){
            index = current->next;

            while(index != NULL){
                if(current->mPrice > index->mPrice){
                    tempID = index->mID;
                    tempName = index->mName;
                    tempGenre = index->mGenre;
                    tempHall = index->mHall;
                    tempPrice = index->mPrice;
                    tempQ = index->mQuantity;
                    tempType = index->mType;
                    /***************/
                    index->mID = current->mID;
                    index->mName = current->mName;
                    index->mType = current->mType;
                    index->mGenre = current->mGenre;
                    index->mQuantity = current->mQuantity;
                    index->mHall = current->mHall;
                    index->mPrice = current->mPrice;
                    /**************/
                    current->mID = tempID ;
                    current->mName = tempName;
                    current->mPrice = tempPrice;
                    current->mQuantity = tempQ;
                    current->mHall = tempHall;
                    current->mGenre = tempGenre;
                    current->mType = tempType;
                }
                index = index->next;
            }
            current = current->next;
        }
        current = head;
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        cout << "  |                                               NOW SHOWING                                                 |\n";
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        cout << "  | Movie ID |    | Type |    |  Movie Name  |    |  Genre  |    | Hall No. |    | Price (RM) |    | Quantity |\n";
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        while(current != NULL){
            cout  << "  |" << setw(7);
            printf("%04d",current->mID) ;
            cout <<
                 "|"<<setw(5)<<"|"  << setw(6) << current->mType <<
                 "|    |" << setw(14) << current->mName <<
                 "|    |" << setw(9) << current->mGenre <<
                 "|    |" << setw(10) << current->mHall <<
                 "|    |" << setw(12)   << current->mPrice <<
                 "|    |" << setw(10) << current->mQuantity << "|" << endl;
            current = current->next;

        }
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";

    }
}

void sortMPD(){
    movieInfo* current = head, *index = NULL;
    int tempID, tempPrice, tempQ;
    string tempName, tempType, tempGenre, tempHall;


    if (head==NULL){
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        cout << "  |                                              NO MOVIES AVAILABLE IN THE SYSTEM                            |\n";
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
    }else
    {

        while(current != NULL){
            index = current->next;

            while(index != NULL){
                if(current->mPrice < index->mPrice){
                    tempID = index->mID;
                    tempName = index->mName;
                    tempGenre = index->mGenre;
                    tempHall = index->mHall;
                    tempPrice = index->mPrice;
                    tempQ = index->mQuantity;
                    tempType = index->mType;
                    /***************/
                    index->mID = current->mID;
                    index->mName = current->mName;
                    index->mType = current->mType;
                    index->mGenre = current->mGenre;
                    index->mQuantity = current->mQuantity;
                    index->mHall = current->mHall;
                    index->mPrice = current->mPrice;
                    /**************/
                    current->mID = tempID ;
                    current->mName = tempName;
                    current->mPrice = tempPrice;
                    current->mQuantity = tempQ;
                    current->mHall = tempHall;
                    current->mGenre = tempGenre;
                    current->mType = tempType;
                }
                index = index->next;
            }
            current = current->next;
        }
        current = head;
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        cout << "  |                                               NOW SHOWING                                                 |\n";
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        cout << "  | Movie ID |    | Type |    |  Movie Name  |    |  Genre  |    | Hall No. |    | Price (RM) |    | Quantity |\n";
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        while(current != NULL){
            cout  << "  |" << setw(7);
            printf("%04d",current->mID) ;
            cout <<
                 "|"<<setw(5)<<"|"  << setw(6) << current->mType <<
                 "|    |" << setw(14) << current->mName <<
                 "|    |" << setw(9) << current->mGenre <<
                 "|    |" << setw(10) << current->mHall <<
                 "|    |" << setw(12)   << current->mPrice <<
                 "|    |" << setw(10) << current->mQuantity << "|" << endl;
            current = current->next;

        }
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";

    }
}

void sortMQA(){
    movieInfo* current = head, *index = NULL;
    int tempID, tempPrice, tempQ;
    string tempName, tempType, tempGenre, tempHall;


    if (head==NULL){
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        cout << "  |                                              NO MOVIES AVAILABLE IN THE SYSTEM                            |\n";
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
    }else
    {

        while(current != NULL){
            index = current->next;

            while(index != NULL){
                if(current->mQuantity > index->mQuantity){
                    tempID = index->mID;
                    tempName = index->mName;
                    tempGenre = index->mGenre;
                    tempHall = index->mHall;
                    tempPrice = index->mPrice;
                    tempQ = index->mQuantity;
                    tempType = index->mType;
                    /***************/
                    index->mID = current->mID;
                    index->mName = current->mName;
                    index->mType = current->mType;
                    index->mGenre = current->mGenre;
                    index->mQuantity = current->mQuantity;
                    index->mHall = current->mHall;
                    index->mPrice = current->mPrice;
                    /**************/
                    current->mID = tempID ;
                    current->mName = tempName;
                    current->mPrice = tempPrice;
                    current->mQuantity = tempQ;
                    current->mHall = tempHall;
                    current->mGenre = tempGenre;
                    current->mType = tempType;
                }
                index = index->next;
            }
            current = current->next;
        }
        current = head;
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        cout << "  |                                               NOW SHOWING                                                 |\n";
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        cout << "  | Movie ID |    | Type |    |  Movie Name  |    |  Genre  |    | Hall No. |    | Price (RM) |    | Quantity |\n";
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        while(current != NULL){
            cout  << "  |" << setw(7);
            printf("%04d",current->mID) ;
            cout <<
                 "|"<<setw(5)<<"|"  << setw(6) << current->mType <<
                 "|    |" << setw(14) << current->mName <<
                 "|    |" << setw(9) << current->mGenre <<
                 "|    |" << setw(10) << current->mHall <<
                 "|    |" << setw(12)   << current->mPrice <<
                 "|    |" << setw(10) << current->mQuantity << "|" << endl;
            current = current->next;

        }
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";

    }
}

void sortMQD(){
    movieInfo* current = head, *index = NULL;
    int tempID, tempPrice, tempQ;
    string tempName, tempType, tempGenre, tempHall;


    if (head==NULL){
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        cout << "  |                                              NO MOVIES AVAILABLE IN THE SYSTEM                            |\n";
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
    }else
    {

        while(current != NULL){
            index = current->next;

            while(index != NULL){
                if(current->mQuantity < index->mQuantity){
                    tempID = index->mID;
                    tempName = index->mName;
                    tempGenre = index->mGenre;
                    tempHall = index->mHall;
                    tempPrice = index->mPrice;
                    tempQ = index->mQuantity;
                    tempType = index->mType;
                    /***************/
                    index->mID = current->mID;
                    index->mName = current->mName;
                    index->mType = current->mType;
                    index->mGenre = current->mGenre;
                    index->mQuantity = current->mQuantity;
                    index->mHall = current->mHall;
                    index->mPrice = current->mPrice;
                    /**************/
                    current->mID = tempID ;
                    current->mName = tempName;
                    current->mPrice = tempPrice;
                    current->mQuantity = tempQ;
                    current->mHall = tempHall;
                    current->mGenre = tempGenre;
                    current->mType = tempType;
                }
                index = index->next;
            }
            current = current->next;
        }
        current = head;
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        cout << "  |                                               NOW SHOWING                                                 |\n";
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        cout << "  | Movie ID |    | Type |    |  Movie Name  |    |  Genre  |    | Hall No. |    | Price (RM) |    | Quantity |\n";
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        while(current != NULL){
            cout  << "  |" << setw(7);
            printf("%04d",current->mID) ;
            cout <<
                 "|"<<setw(5)<<"|"  << setw(6) << current->mType <<
                 "|    |" << setw(14) << current->mName <<
                 "|    |" << setw(9) << current->mGenre <<
                 "|    |" << setw(10) << current->mHall <<
                 "|    |" << setw(12)   << current->mPrice <<
                 "|    |" << setw(10) << current->mQuantity << "|" << endl;
            current = current->next;

        }
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";

    }
}


void sortMNA(){
    movieInfo* current = head, *index = NULL;
    int tempID, tempPrice, tempQ;
    string tempName, tempType, tempGenre, tempHall;


    if (head==NULL){
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        cout << "  |                                              NO MOVIES AVAILABLE IN THE SYSTEM                            |\n";
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
    }else
    {

        while(current != NULL){
            index = current->next;

            while(index != NULL){
                const char *c = current->mName.c_str();
                const char *i = index->mName.c_str();
                int result = strcmp(i,c);
                if(result < 0){
                    tempID = index->mID;
                    tempName = index->mName;
                    tempGenre = index->mGenre;
                    tempHall = index->mHall;
                    tempPrice = index->mPrice;
                    tempQ = index->mQuantity;
                    tempType = index->mType;
                    /***************/
                    index->mID = current->mID;
                    index->mName = current->mName;
                    index->mType = current->mType;
                    index->mGenre = current->mGenre;
                    index->mQuantity = current->mQuantity;
                    index->mHall = current->mHall;
                    index->mPrice = current->mPrice;
                    /**************/
                    current->mID = tempID ;
                    current->mName = tempName;
                    current->mPrice = tempPrice;
                    current->mQuantity = tempQ;
                    current->mHall = tempHall;
                    current->mGenre = tempGenre;
                    current->mType = tempType;
                }
                index = index->next;
            }
            current = current->next;
        }
        current = head;
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        cout << "  |                                               NOW SHOWING                                                 |\n";
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        cout << "  | Movie ID |    | Type |    |  Movie Name  |    |  Genre  |    | Hall No. |    | Price (RM) |    | Quantity |\n";
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        while(current != NULL){
            cout  << "  |" << setw(7);
            printf("%04d",current->mID) ;
            cout <<
                 "|"<<setw(5)<<"|"  << setw(6) << current->mType <<
                 "|    |" << setw(14) << current->mName <<
                 "|    |" << setw(9) << current->mGenre <<
                 "|    |" << setw(10) << current->mHall <<
                 "|    |" << setw(12)   << current->mPrice <<
                 "|    |" << setw(10) << current->mQuantity << "|" << endl;
            current = current->next;

        }
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";

    }
}
void sortMND(){
    movieInfo* current = head, *index = NULL;
    int tempID, tempPrice, tempQ;
    string tempName, tempType, tempGenre, tempHall;


    if (head==NULL){
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        cout << "  |                                              NO MOVIES AVAILABLE IN THE SYSTEM                            |\n";
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
    }else
    {

        while(current != NULL){
            index = current->next;

            while(index != NULL){
                const char *c = current->mName.c_str();
                const char *i = index->mName.c_str();
                int result = strcmp(i,c);
                if(result > 0){
                    tempID = index->mID;
                    tempName = index->mName;
                    tempGenre = index->mGenre;
                    tempHall = index->mHall;
                    tempPrice = index->mPrice;
                    tempQ = index->mQuantity;
                    tempType = index->mType;
                    /***************/
                    index->mID = current->mID;
                    index->mName = current->mName;
                    index->mType = current->mType;
                    index->mGenre = current->mGenre;
                    index->mQuantity = current->mQuantity;
                    index->mHall = current->mHall;
                    index->mPrice = current->mPrice;
                    /**************/
                    current->mID = tempID ;
                    current->mName = tempName;
                    current->mPrice = tempPrice;
                    current->mQuantity = tempQ;
                    current->mHall = tempHall;
                    current->mGenre = tempGenre;
                    current->mType = tempType;
                }
                index = index->next;
            }
            current = current->next;
        }
        current = head;
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        cout << "  |                                               NOW SHOWING                                                 |\n";
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        cout << "  | Movie ID |    | Type |    |  Movie Name  |    |  Genre  |    | Hall No. |    | Price (RM) |    | Quantity |\n";
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        while(current != NULL){
            cout  << "  |" << setw(7);
            printf("%04d",current->mID) ;
            cout <<
                 "|"<<setw(5)<<"|"  << setw(6) << current->mType <<
                 "|    |" << setw(14) << current->mName <<
                 "|    |" << setw(9) << current->mGenre <<
                 "|    |" << setw(10) << current->mHall <<
                 "|    |" << setw(12)   << current->mPrice <<
                 "|    |" << setw(10) << current->mQuantity << "|" << endl;
            current = current->next;

        }
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";

    }
}
void sortMHA(){
    movieInfo* current = head, *index = NULL;
    int tempID, tempPrice, tempQ;
    string tempName, tempType, tempGenre, tempHall;


    if (head==NULL){
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        cout << "  |                                              NO MOVIES AVAILABLE IN THE SYSTEM                            |\n";
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
    }else
    {

        while(current != NULL){
            index = current->next;

            while(index != NULL){
                const char *c = current->mHall.c_str();
                const char *i = index->mHall.c_str();
                int result = strcmp(i,c);
                if(result < 0){
                    tempID = index->mID;
                    tempName = index->mName;
                    tempGenre = index->mGenre;
                    tempHall = index->mHall;
                    tempPrice = index->mPrice;
                    tempQ = index->mQuantity;
                    tempType = index->mType;
                    /***************/
                    index->mID = current->mID;
                    index->mName = current->mName;
                    index->mType = current->mType;
                    index->mGenre = current->mGenre;
                    index->mQuantity = current->mQuantity;
                    index->mHall = current->mHall;
                    index->mPrice = current->mPrice;
                    /**************/
                    current->mID = tempID ;
                    current->mName = tempName;
                    current->mPrice = tempPrice;
                    current->mQuantity = tempQ;
                    current->mHall = tempHall;
                    current->mGenre = tempGenre;
                    current->mType = tempType;
                }
                index = index->next;
            }
            current = current->next;
        }
        current = head;
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        cout << "  |                                               NOW SHOWING                                                 |\n";
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        cout << "  | Movie ID |    | Type |    |  Movie Name  |    |  Genre  |    | Hall No. |    | Price (RM) |    | Quantity |\n";
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        while(current != NULL){
            cout  << "  |" << setw(7);
            printf("%04d",current->mID) ;
            cout <<
                 "|"<<setw(5)<<"|"  << setw(6) << current->mType <<
                 "|    |" << setw(14) << current->mName <<
                 "|    |" << setw(9) << current->mGenre <<
                 "|    |" << setw(10) << current->mHall <<
                 "|    |" << setw(12)   << current->mPrice <<
                 "|    |" << setw(10) << current->mQuantity << "|" << endl;
            current = current->next;

        }
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";

    }
}
void sortMHD(){
    movieInfo* current = head, *index = NULL;
    int tempID, tempPrice, tempQ;
    string tempName, tempType, tempGenre, tempHall;


    if (head==NULL){
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        cout << "  |                                              NO MOVIES AVAILABLE IN THE SYSTEM                            |\n";
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
    }else
    {

        while(current != NULL){
            index = current->next;

            while(index != NULL){
                const char *c = current->mHall.c_str();
                const char *i = index->mHall.c_str();
                int result = strcmp(i,c);
                if(result > 0){
                    tempID = index->mID;
                    tempName = index->mName;
                    tempGenre = index->mGenre;
                    tempHall = index->mHall;
                    tempPrice = index->mPrice;
                    tempQ = index->mQuantity;
                    tempType = index->mType;
                    /***************/
                    index->mID = current->mID;
                    index->mName = current->mName;
                    index->mType = current->mType;
                    index->mGenre = current->mGenre;
                    index->mQuantity = current->mQuantity;
                    index->mHall = current->mHall;
                    index->mPrice = current->mPrice;
                    /**************/
                    current->mID = tempID ;
                    current->mName = tempName;
                    current->mPrice = tempPrice;
                    current->mQuantity = tempQ;
                    current->mHall = tempHall;
                    current->mGenre = tempGenre;
                    current->mType = tempType;
                }
                index = index->next;
            }
            current = current->next;
        }
        current = head;
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        cout << "  |                                               NOW SHOWING                                                 |\n";
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        cout << "  | Movie ID |    | Type |    |  Movie Name  |    |  Genre  |    | Hall No. |    | Price (RM) |    | Quantity |\n";
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        while(current != NULL){
            cout  << "  |" << setw(7);
            printf("%04d",current->mID) ;
            cout <<
                 "|"<<setw(5)<<"|"  << setw(6) << current->mType <<
                 "|    |" << setw(14) << current->mName <<
                 "|    |" << setw(9) << current->mGenre <<
                 "|    |" << setw(10) << current->mHall <<
                 "|    |" << setw(12)   << current->mPrice <<
                 "|    |" << setw(10) << current->mQuantity << "|" << endl;
            current = current->next;

        }
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";

    }
}
#endif //Grandplex_Cinema_System_F3_H
