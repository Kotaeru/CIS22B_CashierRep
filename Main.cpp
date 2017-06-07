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

using namespace std;

void cashierModule();
void InventoryDatabaseModule();
void reportModule();
void bookInformation();

//Main menu with options to access the modules created 
//Don't worry about making it look nice just yet. It just needs to work right now.
int main()
{
	int choice;
	bool valid = false;

	cout << "<Insert Name Here>" << endl;
	cout << "Main Menu" << endl << endl;

	cout << "1. Cashier Module" << endl;
	cout << "2. Inventory Database Module" << endl;
	cout << "3. Report Module" << endl;
	cout << "4. Exit" << endl << endl;

	cout << "Enter Your Choice: ";
	cin >> choice;

	cout << endl;

	while (valid == false) // while valid is false
	{

		if (choice >= 1 && choice <= 4)// if choice is greater than or equal to 1, and less than or equal to 4
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

	switch (choice)
	{
	case 1: cashierModule(); break;
	case 2: InventoryDatabaseModule(); break;
	case 3: reportModule(); break;
	
	}
	system("Pause");
}

void cashierModule()
{
	cout << "\n<Insert Name Here>" << endl << endl;
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

	cout << "<Insert Name Here>" << endl;
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

	cout << "<Insert Name>" << endl;
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
	cout << "<Insert Name Here" << endl;
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
}
