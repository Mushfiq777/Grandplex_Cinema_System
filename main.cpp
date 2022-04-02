#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "f2.h"
#include "f1.h"
#include "f3.h"
using namespace std;

int main() {

    movieRecord(0001, "3D", "Superman", "Action", "Hall1", 20.00, 20);
    movieRecord(0002, "2D", "Uncharted", "Comedy", "Hall5", 15.00, 25);
    movieRecord(0003,"3D",  "Malignant", "Horror", "Hall2", 20.00, 10);
    movieRecord(00047, "2D", "Anabella", "Horror", "Hall3", 15.00, 18);
    movieRecord(005,"3D","Hangover","Comedy","Hall4",10.00,22);
    movieRecord(0006,"3D","Spiderman","Action","Hall4",12.00,25);


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
            case 1:
                displayMovieRecord();
                addNewMovie();
                break;
            case 2:
                displayMovieRecord();
                break;
            case 3:
                searchRecord();
                break;
            case 4:
                filter();
                break;
            case 5:
                update();
                break;
            case 6:
                break;
            case 7:
                deleting();
                break;
            case 8:
                purchaseAdd();
                break;
            case 9:
                viewPurchase();
                break;
            case 10:
                break;
            case 11:
                break;
            case 12:
                break;
            default:
                cout << "Invalid selection \n";
                break;
        }
        if(choice==12)
        {
            break;
        }else
        {
            continue;
        }
    }



    return 0;
}


