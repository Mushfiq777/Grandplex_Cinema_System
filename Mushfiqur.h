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
    cout << "Enter Movie ID OR Name:" << endl;
    string searchID;
    cin >> searchID;

    //transverse
     movieInfo* current = head; //create a temp pointer

    if (current == NULL) {
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        cout << "  |                                              NO MOVIES AVAILABLE IN THE SYSTEM                                              |\n";
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
    }
    bool found = false; //boolean

    while (current != NULL) {
        if (current->mID.compare(searchID) == 0 ) {
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


            found = true;
            break;	//keep infinite loop
        }
        else if(current->mName.compare(searchID) == 0){
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

                    cout << "  |   " << current->mID <<
                         "   |    |  " << current->mType <<
                         "  |    |  " << current->mName <<
                         "   |    |  " << current->mGenre <<
                         " |    |  " << current->mHall <<
                         "  |    |     " << current->mPrice <<
                         "     |    |    " << current->mQuantity << "    |" << endl;
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

                            cout << "  |   " << current->mID <<
                                 "   |    |  " << current->mType <<
                                 "  |    |  " << current->mName <<
                                 "   |    |  " << current->mGenre <<
                                 " |    |  " << current->mHall <<
                                 "  |    |     " << current->mPrice <<
                                 "     |    |    " << current->mQuantity << "    |" << endl;
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
    string searchid;
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
            cout << "  |   " << current->mID <<
                 "   |    |  " << current->mType <<
                 "  |    |  " << current->mName <<
                 "   |    |  " << current->mGenre <<
                 " |    |  " << current->mHall <<
                 "  |    |     "     << current->mPrice <<
                 "     |    |    " << current->mQuantity << "    |" << endl;
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

#endif //DSTR_ASSIGNMENT_MUSHFIQUR_H
