#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>

#include "mainmenu.h"
#include "bookdata.h"
#include "strUpper.h"

using namespace std;

BookData book[NUM_BOOKS];				// the array of 'BookData' stuctures

int main()
{
	int choice = 0; // stores user's choice
	string filename;
	ifstream input;

	do
	{
		try
		{
			cout << "Please enter the directory of the text file to import data: ";
			getline(cin, filename);

			input.open(filename);

			if (input.fail())
				throw 4562389;
		}

		catch (int x)
		{
			cout << "Unable to open the file. Error #" << x <<  endl << "Please Try Again. " << endl << endl;
		}

	} while (input.fail() == true);

	for (int i = 0; i < NUM_BOOKS - 1; i++) // Inputting and Capitalizing Each Letter that is read
	
	{
			input >> book[i].bookTitle;
			strUpper(book[i].bookTitle);
			input >> book[i].isbn;
			strUpper(book[i].isbn);
			input >> book[i].author;
			strUpper(book[i].author);
			input >> book[i].publisher;
			strUpper(book[i].publisher);
			input >> book[i].dateAdded;
			strUpper(book[i].dateAdded);
			input >> book[i].qtyOnHand;
			input >> book[i].wholesale;
			input >> book[i].retail;	
	}

	// display the 'Main Menu' until item 4 is selected
	while (choice != 4)
	{
	    system("cls");  // Clears the screen before displaying main menu
		// display company name and screen title
		cout << "Serendipity Booksellers\n";
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

				system("pause");
				exit(0);
					break;

		}	// end switch

	}	// end the 'Main Menu' while loop

	cout << endl << endl;

	return 0;
}
