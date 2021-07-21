//============================================================================
// Name        : Lab1-3.cpp
// Author      : Warren Outlaw
// Date		   : 5-6-18
// Course      : CS-260 R5784
// Version     : 1.0
// Copyright   : Copyright © 2017 SNHU COCE
// Description : Lab 1-3 Up to Speed in C++
//============================================================================

#include <algorithm>
#include <iostream>

using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

// Data structure to hold bid information together as a single unit of storage.
struct bidInfo {
	string title;
	string fund;
	string vehicle;
	double amount;
};

/**
 * Display the bid values passed in data structure
 *
 * @param ?type? data structure containing the bid info
 */
void displayBid(bidInfo bid) {
    cout << "Title: " << bid.title << endl;
    cout << "Fund: " << bid.fund << endl;
    cout << "Vehicle: " << bid.vehicle << endl;
    cout << "Bid Amount: " << bid.amount << endl;

    return;
}

/**
 * Simple C function to convert a string to a double
 * after stripping out unwanted char
 *
 * credit: http://stackoverflow.com/a/24875936
 *
 * @param ch The character to strip out
 */

// I moved this function up to avoid errors in getBid()
double strToDouble(string str, char ch) {
    str.erase(remove(str.begin(), str.end(), ch), str.end());
    return atof(str.c_str());
}

/**
 * Prompt user for bid information and store input values in data structure
 *
 * @return data structure containing the bid info
 */
bidInfo getBid() {
    bidInfo userBid;

    cout << "Enter title: ";
    cin.ignore();
    string title;
    getline(cin, userBid.title);

    cout << "Enter fund: ";
    string fund;
    cin >> userBid.fund;

    cout << "Enter vehicle: ";
    cin.ignore();
    string vehicle;
    getline(cin, userBid.vehicle);

    cout << "Enter amount: ";
    cin.ignore();
    string strAmount;
    getline(cin, strAmount);
    userBid.amount = strToDouble(strAmount, '$');

    return userBid;
}

/**
 * The one and only main() method
 */
int main() {

    // Instance of data structure to hold bid information
	bidInfo bid1;

    // Loop to display menu until exit chosen
    int choice = 0;
    while (choice != 9) {
        cout << "Menu:" << endl;
        cout << "  1. Enter Bid" << endl;
        cout << "  2. Display Bid" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        // Method calls based on user input choice
        switch (choice) {
            case 1:
            	bid1 = getBid();
                break;
            case 2:
                displayBid(bid1);
                break;
        }
    }

    cout << "Good bye." << endl;

    return 0;
}
