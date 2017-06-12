	/*Kyle Hori, Kevin La
	CIS 22B
	Cash Register Program
	Program to simulate a book store cash register
	Prompt the user to select their option
	In cash register module let user input basic book information and program will bring up price info
	User confirms or denies information on screen
	If confirmed print to standard output a receipt info thing and remove book from inventory file using inventory module functions
	If denied prompt user to reenter information
	In Inventory Module user can look up, add or remove books from inventory file
	Information will be used in Book class as specified in the Project_Specifications pdf
	In the Report module will be able to look through the inventory file and find information specifed by user
	Methods of search and organizations are defined in the Project_Specifications pdf
	*/

	#include<iostream>
	#include<string>
	#include<iomanip>
	#include<fstream>
	#include "Book.h"

	using namespace std;

	int  readInputFile(Book array[]);
	void cashierModule();
	void InventoryDatabaseModule();
	void reportModule();
	void bookInformation();

	int main()
	{
		int choice = 0; // stores user's choice
		int termination = 0;
		Book Data[25];

		termination = readInputFile(Data);

		if (termination == 1)
		{
			return 0;
		}

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
				cashierModule();
				break;

			case 2:
				InventoryDatabaseModule();
				break;

			case 3:
				reportModule();
				break;

			case 4:
				cout << "\nThank You for Visiting Serendipity Booksellers!\n\n";
				exit(0);
				break;

			}	// end switch

		}	// end the 'Main Menu' while loop

		cout << endl << endl;

		system("Pause");
	}

	int readInputFile(Book Data[])
	{
		ifstream inputFile; // Initializing the ifstream variable inputFile used to input the words
		string input; // Initializing the string input variable to store the filename
		string word[25]; // Checks if the word from the inputFile is more than one character, and if so, stores it into the array
		bool correct; // Checks if the user enters the correct choice upon being asked to try again
		bool repeat = true; // Repeats if there is an invalid file name 
		char letter; // the char variable letter will hold the character of the user for the yes or no question

		do // A do while loop that will ask for an input file name until either the user press 'n', 'N', or is the input file name is valid
		{
			cout << "Please enter the input file name \n(If it is not in the same folder with your .cpp, type the full directory) : "; // Prompts the user for the input file name

			cin >> input; // User enters the file name into the input string

			cout << endl;
			inputFile.open(input);

			correct = false;

			while (correct == false)
			{

				if (inputFile.fail() != true) // If the input file opens, it will prompt up, "The program has successfully opened the file!"
				{
					cout << "The program has successfully opened the file!" << endl; // Prompts the user that the file opens


					repeat = false;
					correct = true;
				}

				else // If the input file name fails, the program will prompt the user whether or not they want to try again 
				{
					cout << "Unable to open the file. Would you like to try again (Y/N)?: "; // Prompts the user to type 'Y', 'y', 'n', or 'N'

					cin >> letter; // User input

					cout << endl;

					switch (letter)
					{
					case 'n': case 'N': repeat = false; correct = true; return 1; break;
					case 'y': case 'Y': correct = true; break;
					default: cout << "Please select a valid input." << endl << endl;
					}

				}
			}

		} while (repeat == true);


		for (int i = 0; i < 24; ++i) // A For-loop that will continuously loop until the 1024 elements hold a value
		{

			inputFile >> word[i];
			
			Data[i].setISBN = word[i];

		}

		inputFile.close(); // Closes the input file

		return 0;
	}
	void cashierModule()
	{
		system("cls");  // Clears the screen before displaying main menu

		cout << "\nSerendipity Booksellers" << endl << endl;
		cout << "Date: " << endl << endl;
		cout << left << setw(2) << "Qty  ISBN         Title                Price         Total    " << endl;

		for (int i = 0; i < 62; i++)
		{
			cout << "-";
		}

		cout << endl;
	}

	void InventoryDatabaseModule()
	{
		int choice;
		bool valid = false;

		system("cls");  // Clears the screen before displaying main menu

		cout << "Serendipity Booksellers" << endl;
		cout << "Inventory Database" << endl << endl;

		cout << "1. Look Up A Book" << endl;
		cout << "2. Add A Book" << endl;
		cout << "3. Edit a Book's Record" << endl;
		cout << "4. Delete A Book" << endl;
		cout << "5. Return To Main Menu" << endl << endl;

		cout << "Enter Your Choice: ";
		cin >> choice;

		cout << endl;

		while (valid == false) // while valid is false
		{

			if (choice >= 1 && choice <= 5)// if choice is greater than or equal to 1, and less than or equal to 4
			{
				valid = true; // is true
			}

			else
			{
				cout << "Please Enter A Valid Option!" << endl << endl;// print message

				cout << "Enter Your Choice Here: ";
				cin >> choice;
				cout << endl;
			}
		}
	}

	void reportModule()
	{
		int choice;
		bool valid = false;

		system("cls");  // Clears the screen before displaying main menu

		cout << "Serendipity Booksellers" << endl;
		cout << "Reports" << endl << endl;
		cout << "1. Inventory Listing" << endl;
		cout << "2. Inventory Wholesale Value" << endl;
		cout << "3. Inventory Retail Value" << endl;
		cout << "4. Listing by Quantity" << endl;
		cout << "5. Listing by Cost" << endl;
		cout << "6. Listing by Age" << endl;
		cout << "7. Return to Main Menu" << endl << endl;

		cout << "Enter Your Choice: ";
		cin >> choice;

		while (valid == false) // while valid is false
		{

			if (choice >= 1 && choice <= 7)// if choice is greater than or equal to 1, and less than or equal to 4
			{
				valid = true; // is true
			}

			else
			{
				cout << "Please Enter A Valid Option!" << endl << endl;// print message

				cout << "Enter Your Choice Here: ";
				cin >> choice;
				cout << endl;
			}
		}
	}

	void bookInformation()
	{
		system("cls");  // Clears the screen before displaying main menu

		cout << "Serendipity Booksellers" << endl;
		cout << "Book Information" << endl << endl;

		cout << "ISBN: " << endl;
		cout << "Title: " << endl;
		cout << "Author: " << endl;	
		cout << "Publisher: " << endl;
		cout << "Date Added: " << endl;
		cout << "Quantity-On-Hand: " << endl;
		cout << "Wholesale Cost: " << endl;
		cout << "Retail Price: " << endl;

	}
