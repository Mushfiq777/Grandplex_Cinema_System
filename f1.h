//
// Created by Mushfiqur on 2/16/2022.
//






#ifndef DSTR_ASSIGNMENT_F1_H
#define DSTR_ASSIGNMENT_F1_H
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include "f2.h"
using namespace std;
void searchRecord() {
    cout << "Enter Movie ID OR Name:" << endl;
    string searchName;
    cin >> searchName;
    stringstream ss;
    ss << searchName;
    int searchID;
    ss >> searchID;
    //transverse
     movieInfo* current = head; //create a temp pointer

    if (current == NULL) {
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        cout << "  |                                              NO MOVIES AVAILABLE IN THE SYSTEM                                              |\n";
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
    }
    bool found = false; //boolean

    while (current != NULL) {
        if (current->mID == searchID ) {
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


            found = true;
            break;	//keep infinite loop
        }
        else if(current->mName == searchName){
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
            found = true;
            break;
        }
        else
        {
            current = current->next;
        }
    }

    if (found == false) {
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        cout << "  |                                      NO MOVIES FOUND PLEASE SEARCH AGAIN                                  |\n";
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
    }
}

void filter() {
    int choice1;

    movieInfo *current = head;
    cout << "Filter by: \n"
            "\t1.Genre\n"
            "\t2.3D/2D\n"
            "Enter your choice: " << endl;
    cin >> choice1;
    if (choice1 == 1) {
        cout << "Which genre do you want to filter by?\n"
                "Enter genre: "<<endl;
        string searchG;
        cin >> searchG;
        if (current == NULL) {
            cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
            cout << "  |                                              NO MOVIES AVAILABLE IN THE SYSTEM                                              |\n";
            cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        }else{
            bool Found = false;
            cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
            cout << "  | Movie ID |    | Type |    |  Movie Name  |    |  Genre  |    | Hall No. |    | Price (RM) |    | Quantity |\n";
            cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
            while (current != NULL)
            {

                if (current->mGenre == searchG)
                {

                    cout  << "  |" << setw(7);
                    printf("%04d",current->mID) ;
                    cout <<
                         "|"<<setw(5)<<"|"  << setw(6) << current->mType <<
                         "|    |" << setw(14) << current->mName <<
                         "|    |" << setw(9) << current->mGenre <<
                         "|    |" << setw(10) << current->mHall <<
                         "|    |" << setw(12)   << current->mPrice <<
                         "|    |" << setw(10) << current->mQuantity << "|" << endl;
                    Found = true;
                    current = current->next;


                }
                else
                {
                    current = current->next;

                }


            }
            if (Found == false)
            {
                cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
                cout << "  |                                      NO MOVIES FOUND PLEASE SEARCH AGAIN                                  |\n";
                cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
            }


            }
            }else if (choice1 == 2)
            {
                cout << "Do you want to filter by 3D or 2D?\n"
                "Enter dimension: "<<endl;
                string searchD;
                cin >> searchD;
                if (current == NULL) {
                    cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
                    cout << "  |                                              NO MOVIES AVAILABLE IN THE SYSTEM                                              |\n";
                    cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
                }else{
                    bool Found = false;
                    cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
                    cout << "  | Movie ID |    | Type |    |  Movie Name  |    |  Genre  |    | Hall No. |    | Price (RM) |    | Quantity |\n";
                    cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
                    while (current != NULL)
                    {

                        if (current->mType == searchD)
                        {

                            cout  << "  |" << setw(7);
                            printf("%04d",current->mID) ;
                            cout <<
                                 "|"<<setw(5)<<"|"  << setw(6) << current->mType <<
                                 "|    |" << setw(14) << current->mName <<
                                 "|    |" << setw(9) << current->mGenre <<
                                 "|    |" << setw(10) << current->mHall <<
                                 "|    |" << setw(12)   << current->mPrice <<
                                 "|    |" << setw(10) << current->mQuantity << "|" << endl;
                            Found = true;
                            current = current->next;


                        }
                        else
                        {
                            current = current->next;

                        }


                    }
                    if (Found == false)
                    {
                        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
                        cout << "  |                                      NO MOVIES FOUND PLEASE SEARCH AGAIN                                  |\n";
                        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
                    }


                }


    }else {
        cout << "Invalid input";}

}

void update(){
    cout << "Enter the Movie ID of the Movie that you want to update: ";
    int searchid;
    cin >> searchid;
    cout << "\n";
    movieInfo* current = head;
    if (current == NULL) {
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        cout << "  |                                              NO MOVIES AVAILABLE IN THE SYSTEM                                              |\n";
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
    }
    bool found = false;
    while (current != NULL)
    {
        if(current->mID == searchid)
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
            found = true;
            cout << "Enter updated price: ";
            int updateP;
            cin >> updateP;
            current->mPrice = updateP;
            cout <<"\n";
            cout << "Enter updated quantity: ";
            int updateQ;
            cin >> updateQ;
            current->mQuantity = updateQ;
            cout <<"\n";
            cout << "Price and Quantity updated successfully!\n";
            break;
        }else
        {
            current = current->next;
        }
    }
    if (found == false)
    {
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        cout << "  |                                      NO MOVIES FOUND PLEASE SEARCH AGAIN                                  |\n";
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
    }
}

struct purchaseInfo { //creates a template for a node
    string pName, pType, pGenre, pHall ,pCname,pDate;
    int pTotalPrice, pNoTickets;
    purchaseInfo* next;
};
struct purchaseInfo* head2 = NULL;
void purchaseAdd(){
    struct purchaseInfo* newPurchase = new struct purchaseInfo;
    cout << "Please enter your name:";
    cin >> newPurchase->pCname;
    cout << "Please enter today's date (dd/mm/yyyy):";
    cin >> newPurchase->pDate;


    bool found = false;

    while(true) {
        struct movieInfo *check;
        check = head;
        cout << "Enter the name of the movie you want to purchase: ";
        cin >> newPurchase->pName;
        while (check != NULL) {
            if (newPurchase->pName == check->mName) {
                cout << "\nMovie found! \n";
                cout << "Number of tickets available: "<< check->mQuantity;
                cout << "\nPlease enter the number of tickets you want to purchase:";
                cin >> newPurchase->pNoTickets;
                if (newPurchase->pNoTickets <= check->mQuantity){
                    newPurchase->pTotalPrice = check->mPrice * newPurchase->pNoTickets;
                    check->mQuantity = check->mQuantity - newPurchase->pNoTickets;
                    newPurchase->pName = check->mName;
                    newPurchase->pType = check->mType;
                    newPurchase->pGenre = check->mGenre;
                    newPurchase->pHall = check->mHall;
                    cout << "Your total price is: "<<newPurchase->pTotalPrice;
                    cout << "\nThank you for purchasing! \n";
                    newPurchase->next = head2;
                    head2 = newPurchase;

                    found = true;
                    break;
                }else
                {
                    cout << "\nSorry please enter a lower number, enough tickets not available\n";
                    continue;
                }

            } else {
                check = check->next;

            }
        }
        if(found==true)
        {
            break;
        }else
        {
            cout << "\n Movie not found please enter movie name again\n";
        }
    }
}

void viewPurchase()
{
    struct purchaseInfo* display;

    display = head2;

    if (display == NULL) {
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        cout << "  |                                              NO PURCHASE RECORD FOUND                                     |\n";
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
    }else
    {
        cout << "\n  +-----------------------------------------------------------------------------------------------------------+\n";
        cout << "   | Customer Name |    | Date purchased |    |  Movie Name  |    |  Genre  |    | Type |   | Hall No. |    | Quantity |    | Total Price |\n";
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        while (display != NULL) {
            cout << "  | " << display->pCname <<
                 " |    | " << display->pDate <<
                 " |    | " << display->pName <<
                 " |    | " << display->pGenre <<
                 " |    | " << display->pType <<
                 " |    | "     << display->pHall <<
                 " |    | " << display->pNoTickets << " |   " << "| "<<display->pTotalPrice<<" |" << endl;

            //continue looking for the next node that holds movie info
            display = display->next;
        }
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
    }
}

#endif //DSTR_ASSIGNMENT_F1_H
