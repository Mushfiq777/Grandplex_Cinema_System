//
// Created by Mushfiqur on 2/16/2022.
//

#ifndef DSTR_ASSIGNMENT_BHARA_H
#define DSTR_ASSIGNMENT_BHARA_H
void addPurchase() {
    struct movieInfo *newPurchase = new struct movieInfo;
    struct movieInfo *checkID;
    checkID = head; //Reading the data
    cout << "Movie ID: "; //Reading the Movie ID
    cin >> newPurchase->mID;

    while (checkID != NULL) {
        if (newPurchase->mID == checkID->mID) { //Validation for duplication
            cout << "The movie id is duplicated! Please retype id again: ";
            cin >> newPurchase->mID;
            checkID = head;
            while (checkID != NULL) {
                if (newPurchase->mID == checkID->mID) { //Validating for duplication
                    cout << "The movie id is duplicated! Please retype id again : ";
                    cin >> newPurchase->mID;
                    checkID = head;
                } else {
                    checkID = checkID->next;
                }
            }
        } else {
            checkID = checkID->next;

        }
    }

    cout << "Type of movie [2D, 3D]: "; //Displaying the user the options for the types of ticket
    cin >> newPurchase->mType;

    cout << "Hall no.? [1, 2, 3, 4, 5]: ";
    cin >> newPurchase->mHall;

    cout << "No. of ticket: ";
    cin >> newPurchase->mQuantity;

    cout << "Total ticket Price: ";
    cin >> newPurchase->mPrice;


    cout << endl;

    newPurchase->next = head; //Big O notation from O(N) become o(1)
    head = newPurchase;
}
#endif //DSTR_ASSIGNMENT_BHARA_H
