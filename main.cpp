#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include <sstream>
#include "f2.h"
#include "f1.h"
#include "f3.h"
using namespace std;
void showMenu()
{
    while(true)
    {
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        cout << "  |                                WELCOME TO GRANDPLEX MOVIE TICKETING SYSTEM                                |\n";
        cout << "  |                                         WHAT WOULD YOU LIKE TO DO?                                        |\n";
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        cout << "  |                                      1. Add new movie record                                              |\n";
        cout << "  |                                      2. Display all available movies                                      |\n";
        cout << "  |                                      3. Search for movie                                                  |\n";
        cout << "  |                                      4. Category filter                                                   |\n";
        cout << "  |                                      5. Update movie record                                               |\n";
        cout << "  |                                      6. Sort movie record                                                 |\n";
        cout << "  |                                      7. Delete movie record                                               |\n";
        cout << "  |                                      8. Add new transaction                                               |\n";
        cout << "  |                                      9. View transactions                                                 |\n";
        cout << "  |                                     10. Sort transactions                                                 |\n";
        cout << "  |                                     11. View details of a transaction                                     |\n";
        cout << "  |                                     12. Exit                                                              |\n";
        cout << "  +-----------------------------------------------------------------------------------------------------------+\n";
        cout << "\nEnter your choice: ";
        int choice;
        cin >> choice;
        cout <<endl;
        switch (choice) {
            case 1: {
                bool t = true;
                do
                {
                    displayMovieRecord();
                    addNewMovie();
                    cout << "Continue to main menu (press 1) or add another movie(press 2)?\nEnter choice: ";
                    int c;
                    cin >> c;
                    cout << endl;
                    switch(c)
                    {
                        case 1:
                            t= false;
                            break;

                        case 2:
                            break;
                        default:
                            cout << "Invalid selection please input again!\n";
                            cout << "Continue to main menu (press 1) or add another movie(press 2)?\nEnter choice: ";
                            cin >> c;
                            cout << endl;
                    }
                }while(t);
            }


                break;
            case 2: {
                bool t = true;
                do {
                    displayMovieRecord();
                    cout << "Continue to main menu (press 1) or display again?(press 2)?\nEnter choice: ";
                    int c;
                    cin >> c;
                    cout << endl;
                    switch (c) {
                        case 1:
                            t = false;
                            break;

                        case 2:
                            break;
                        default:
                            cout << "Invalid selection please input again!\n";
                            cout << "Continue to main menu (press 1) or display again?(press 2)?\nEnter choice: ";
                            cin >> c;
                            cout << endl;
                    }
                } while (t);
            }
                break;
            case 3:
            {
                bool t = true;
                do {
                    searchRecord();
                    cout << "Continue to main menu (press 1) or search again?(press 2)?\nEnter choice: ";
                    int c;
                    cin >> c;
                    cout << endl;
                    switch (c) {
                        case 1:
                            t = false;
                            break;

                        case 2:
                            break;
                        default:
                            cout << "Invalid selection please input again!\n";
                            cout << "Continue to main menu (press 1) or search again?(press 2)?\nEnter choice: ";
                            cin >> c;
                            cout << endl;
                    }
                } while (t);
                break;
            }
            case 4:
            {
                bool t = true;
                do {
                    filter();
                    cout << "Continue to main menu (press 1) or filter again?(press 2)?\nEnter choice: ";
                    int c;
                    cin >> c;
                    cout << endl;
                    switch (c) {
                        case 1:
                            t = false;
                            break;

                        case 2:
                            break;
                        default:
                            cout << "Invalid selection please input again!\n";
                            cout << "Continue to main menu (press 1) or filter again?(press 2)?\nEnter choice: ";
                            cin >> c;
                            cout << endl;
                    }
                } while (t);
                break;
            }
            case 5:
            {
                bool t = true;
                do {
                    update();
                    cout << "Continue to main menu (press 1) or update again?(press 2)?\nEnter choice: ";
                    int c;
                    cin >> c;
                    cout << endl;
                    switch (c) {
                        case 1:
                            t = false;
                            break;

                        case 2:
                            break;
                        default:
                            cout << "Invalid selection please input again!\n";
                            cout << "Continue to main menu (press 1) or update again?(press 2)?\nEnter choice: ";
                            cin >> c;
                            cout << endl;
                    }
                } while (t);
                break;
            }
            case 6:
                break;
            case 7:
            {
                bool t = true;
                do {
                    deleting();
                    cout << "Continue to main menu (press 1) or delete again?(press 2)?\nEnter choice: ";
                    int c;
                    cin >> c;
                    cout << endl;
                    switch (c) {
                        case 1:
                            t = false;
                            break;

                        case 2:
                            break;
                        default:
                            cout << "Invalid selection please input again!\n";
                            cout << "Continue to main menu (press 1) or delete again?(press 2)?\nEnter choice: ";
                            cin >> c;
                            cout << endl;
                    }
                } while (t);
                break;
            }
            case 8:
            {
                bool t = true;
                do {
                    purchaseAdd();
                    cout << "Continue to main menu (press 1) or add another purchase?(press 2)?\nEnter choice: ";
                    int c;
                    cin >> c;
                    cout << endl;
                    switch (c) {
                        case 1:
                            t = false;
                            break;

                        case 2:
                            break;
                        default:
                            cout << "Invalid selection please input again!\n";
                            cout << "Continue to main menu (press 1) or add another purchase?(press 2)?\nEnter choice: ";
                            cin >> c;
                            cout << endl;
                    }
                } while (t);
                break;
            }
            case 9:
            {
                bool t = true;
                do {
                    viewPurchase();
                    cout << "Continue to main menu (press 1) or view purchases again?(press 2)?\nEnter choice: ";
                    int c;
                    cin >> c;
                    cout << endl;
                    switch (c) {
                        case 1:
                            t = false;
                            break;

                        case 2:
                            break;
                        default:
                            cout << "Invalid selection please input again!\n";
                            cout << "Continue to main menu (press 1) or view purchases again?(press 2)?\nEnter choice: ";
                            cin >> c;
                            cout << endl;
                    }
                } while (t);
                break;
            }
            case 10:
                break;
            case 11:
                break;
            case 12:
                break;
            default:
                cout << "Invalid selection \n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                break;
        }
        if(choice==12)
        {
            break;
        }
    }



}
int main() {

    movieRecord(1000, "3D", "Superman", "Action", "Hall1", 20.00, 20);
    movieRecord(2267, "2D", "Uncharted", "Comedy", "Hall5", 15.00, 25);
    movieRecord(3333,"3D",  "Malignant", "Horror", "Hall2", 20.00, 10);
    movieRecord(4557, "2D", "Anabella", "Horror", "Hall3", 15.00, 18);
    movieRecord(1555,"3D","Hangover","Comedy","Hall4",10.00,22);
    movieRecord(62,"3D","Spiderman","Action","Hall4",12.00,25);


    showMenu();

}


