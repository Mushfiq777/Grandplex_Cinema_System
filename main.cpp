#include <iostream>
#include <cstdlib>
#include "sam.h"
#include "Mushfiqur.h"
using namespace std;
int main() {

    movieRecord("0001", "3D", "John Wick", "Action", "Hall 1", 20.00, 20);
    movieRecord("0002", "2D", "Ocean's 8", "Comedy", "Hall 5", 15.00, 25);
    movieRecord("0003","3D",  "Malignant", "Horror", "Hall 2", 20.00, 10);
    movieRecord("0004", "2D", "The Purge", "Horror", "Hall 3", 15.00, 18);

    displayMovieRecord();
//    searchRecord();
    return 0;
}


