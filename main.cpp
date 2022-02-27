#include <iostream>
#include <cstdlib>
#include "sam.h"
#include "Mushfiqur.h"
using namespace std;
int main() {

    movieRecord("0001", "3D", "John Wick", "Action", "Hall1", 20.00, 20);
    movieRecord("0002", "2D", "Ocean's 8", "Comedy", "Hall5", 15.00, 25);
    movieRecord("0003","3D",  "Malignant", "Horror", "Hall2", 20.00, 10);
    movieRecord("0004", "2D", "The Purge", "Horror", "Hall3", 15.00, 18);
    movieRecord("0005","3D","Ice Age 4","Comedy","Hall4",10.00,22);
    movieRecord("0006","3D","Spiderman","Action","Hall4",12.00,25);
    displayMovieRecord();
//    filter();
//    searchRecord();
    update();
    displayMovieRecord();
    //
    return 0;
}


