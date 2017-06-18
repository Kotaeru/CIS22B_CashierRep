#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "mainmenu.h"
#include "bookdata.h"
using namespace std;

BookData book[NUM_BOOKS];				// the array of 'BookData' stuctures


int main()
{
	int choice = 0; // stores user's choice
	string filename;
	ifstream input;

	do
	{
		cout << "Please enter the directory of the text file to import data: ";
		getline(cin, filename);

		input.open(filename);

	} while (input.fail() == true);

	// display the 'Main Menu' until item 4 is selected
	while (choice != 4)
	{
	    system("cls");  // Clears the screen before displaying main menu
		// display company name and screen title
		cout << "\nSerendipity Booksellers\n";
		cout << "Main Menu\n\n";

		// display menu items
		cout << "\n1.Cashier Module\n";
		cout << "2.Inventory Database Module\n";
		cout << "3.Report Module\n";
		cout << "4.Exit\n\n";

		// display user prompt
		cout << "Enter Your Choice: ";
		cin >> choice;

		// validate the user's input
		while (choice < 1 || choice > 4)
		{
			cout << "\nPlease enter a number in the range 1 - 4.\n\n";

			cout << "Enter Your Choice: ";
			cin >> choice;
		}

		// call the selected function
		switch (choice)
		{
			case 1:
				cashier();
					break;

			case 2:
				invMenu();
					break;

			case 3:
				reports();
					break;

			case 4:
				cout << "\nThank You for Visiting Serendipity Booksellers!\n\n";
				exit(0);
					break;

		}	// end switch

	}	// end the 'Main Menu' while loop

	cout << endl << endl;

	return 0;
}
