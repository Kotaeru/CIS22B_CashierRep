#include <cstdlib>
#include <iostream>
#include <iomanip>
#include<string>
#include "reports.h"
#include "bookdata.h"
using namespace std;

const int	NUM_BOOKS = 25;   // the number of books in inventory
const int	NUM_WIDTH = 6;	// the numeric display length
const int	TITLE_WIDTH = 26;	// the title display length
const int	ISBN_WIDTH = 14;	// the ISBN display length
const int	PRECISION = 2;	// the decimal precision

extern BookData book[NUM_BOOKS]; // the array of 'BookData' structures

//********************************************
// repListing function                       *
//********************************************

void repListing()
{
	char repDate[STR_SIZE];	// stores today's date

	// prompt the user to enter today's date
	std::cout << "\n\nEnter Today's Date(MM/DD/YY): ";
	std::cin >> repDate;

	std::cout << endl << endl;

	// display company name
	std::cout << "\n\n\t\tSerendipity Booksellers Inventory Listing\n\n";

	// display date
	std::cout << "Date:\t\t\t"
		<< repDate;

	// display inventory information by record, then by field
	string end = "";

	for (int i = 0; i < NUM_BOOKS; i++)
	{
		if (book[i].isbn.compare(end) == 0) // do not print an empty record
		{
			std::cout << "\n_____________________________________________________";

			std::cout << "\n\nTitle:\t\t\t"
				<< book[i].bookTitle;

			std::cout << "\nISBN:\t\t\t"
				<< book[i].isbn;

			std::cout << "\nAuthor:\t\t\t"
				<< book[i].author;

			std::cout << "\nPublisher:\t\t"
				<< book[i].publisher;

			std::cout << "\nDate Added:\t\t"
				<< book[i].dateAdded;

			std::cout << fixed
				<< showpoint
				<< right
				<< setprecision(PRECISION);

			std::cout << "\nQuantity On Hand:\t"
				<< book[i].qtyOnHand;

			std::cout << "\nWholesale Cost:\t\t"
				<< book[i].wholesale;

			std::cout << "\nRetail Price:\t\t"
				<< book[i].retail;
		}
	}

	std::cout << "\n\n_____________________________________________________";
	std::cout << "\n\nEnd of Inventory Report.\n\n\n";

	// Pause so that user can read report
	std::cout << "Press Enter to continue...";
	std::cin.ignore();
	std::cin.get();
}

//********************************************
// repWholesale function                     *
//********************************************

void repWholesale()
{
	char repDate[STR_SIZE];	// stores today's date

	// prompt the user to enter today's date
	std::cout << "\n\nEnter Today's Date(MM/DD/YY): ";
	std::cin >> repDate;

	std::cout << endl << endl;

	// display header
	std::cout << "\n\n\t\t\tSerendipity Booksellers\n";
	std::cout << "\t\t\tWholesale Value Listing\n\n";

	// display date
	std::cout << "\tDate: "
		<< repDate
		<< endl;

	// display item headings
	std::cout << "\n\tTitle\t\t\t  ISBN\t\tQuantity\tWholesale\n";
	std::cout << "\t_________________________________________________________________\n\n";

	double	itemSubTot = 0;
	double	subTot = 0;
	string end = "";

	for (int i = 0; i < NUM_BOOKS; i++)
	{
		if (book[i].isbn.compare(end)) // do not print empty records
		{
			std::cout << "\n\t"
				<< left
				<< setw(TITLE_WIDTH)
				<< book[i].bookTitle;

			std::cout << left
				<< setw(ISBN_WIDTH)
				<< book[i].isbn;

			std::cout << right
				<< setw(NUM_WIDTH)
				<< book[i].qtyOnHand
				<< "\t";

			std::cout << fixed
				<< showpoint
				<< right
				<< setprecision(PRECISION);

			std::cout << setw(NUM_WIDTH)
				<< "\t$ "
				<< book[i].wholesale;

			itemSubTot = book[i].qtyOnHand * book[i].wholesale;
			subTot += itemSubTot;
		}
	}

	std::cout << "\n\n\n\tTotal Wholesale Value:  $ "
		<< subTot
		<< endl;

	std::cout << "\t_________________________________________________________________\n";

	std::cout << "\n\tEnd of Wholesale Report.\n\n\n";

	// Pause so that user can read report
	std::cout << "Press Enter to continue...";
	std::cin.ignore();
	std::cin.get();
}

//********************************************
// repRetail function                        *
//********************************************

void repRetail()
{
	char repDate[STR_SIZE];	// stores today's date

	// prompt the user to enter today's date
	std::cout << "\n\nEnter Today's Date(MM/DD/YY): ";
	std::cin >> repDate;

	std::cout << endl << endl;

	// display header
	std::cout << "\n\n\t\t\tSerendipity Booksellers\n";
	std::cout << "\t\t\t  Retail Value Listing\n\n";

	// display date
	std::cout << "\tDate: "
		<< repDate
		<< endl;

	// display item headings
	std::cout << "\n\tTitle\t\t\t  ISBN\t\tQuantity\tRetail\n";
	std::cout << "\t_________________________________________________________________\n\n";

	double	itemSubTot = 0;
	double	subTot = 0;
	string end = "";

	for (int i = 0; i < NUM_BOOKS; i++)
	{
		if (book[i].isbn.compare(end) == 0) // do not print empty records
		{
			std::cout << "\n\t"
				<< left
				<< setw(TITLE_WIDTH)
				<< book[i].bookTitle;

			std::cout << left
				<< setw(ISBN_WIDTH)
				<< book[i].isbn;

			std::cout << fixed
				<< showpoint
				<< right
				<< setprecision(PRECISION);

			std::cout << right
				<< setw(NUM_WIDTH)
				<< book[i].qtyOnHand
				<< "\t";

			std::cout << setw(NUM_WIDTH)
				<< "\t$ "
				<< book[i].retail;

			itemSubTot = book[i].qtyOnHand * book[i].retail;
			subTot += itemSubTot;
		}
	}

	std::cout << "\n\n\n\tTotal Retail Value:  $" << subTot << endl;
	std::cout << "\t_________________________________________________________________\n\n";
	std::cout << "\n\tEnd of Retail Report.\n\n\n";

	// Pause so that user can read report
	std::cout << "Press Enter to continue...";
	std::cin.ignore();
	std::cin.get();
}

//********************************************
// repQty function                           *
//********************************************

void repQty()
{
	int	 id[NUM_BOOKS];		// array to track original order of subscripts
	int* idPtr[NUM_BOOKS];		// pointer to tracking array
	int* qtyPtr[NUM_BOOKS];		// array of pointers to qtyOnHand array

	for (int i = 0; i < NUM_BOOKS; i++)
	{
		id[i] = i;
		idPtr[i] = &id[i];
		qtyPtr[i] = &book[i].qtyOnHand;
	}

	// selection sort to place qtyOnHand in descending order
	// ...and track original subscripts to correspond
	// ...with Title and isbn in parallel arrays

	int  startScan;
	int	 maxIndex;
	int* tempId;
	int* maxValue;

	for (startScan = 0; startScan < NUM_BOOKS - 1; startScan++)
	{
		maxIndex = startScan;
		maxValue = qtyPtr[startScan];
		tempId = idPtr[startScan];
		for (int index = startScan + 1; index < NUM_BOOKS; index++)
		{
			if (*(qtyPtr[index]) > *maxValue)
			{
				maxValue = qtyPtr[index];
				tempId = idPtr[index];
				maxIndex = index;
			}
		}
		qtyPtr[maxIndex] = qtyPtr[startScan];
		idPtr[maxIndex] = idPtr[startScan];
		qtyPtr[startScan] = maxValue;
		idPtr[startScan] = tempId;
	}

	char repDate[STR_SIZE];	// stores today's date

	// prompt the user to enter today's date
	std::cout << "\n\nEnter Today's Date(MM/DD/YY): ";
	std::cin >> repDate;

	std::cout << endl << endl;

	// display header
	std::cout << "\n\n\t\t\tSerendipity Booksellers\n";
	std::cout << "\t\t\t  Quantity Listing\n\n";

	// display date
	std::cout << "\tDate: "
		<< repDate
		<< endl;

	// display item headings

	std::cout << "\n\tTitle\t\t\t  ISBN\t\tQuantity\n";
	std::cout << "\t_______________________________________________________\n";
	string end = "";

	for (int j = 0; j < NUM_BOOKS; j++)
	{
		if (book[j].isbn.compare(end) == 0) // do not print empty records
		{
			std::cout << "\n\t"
				<< left
				<< setw(TITLE_WIDTH)
				<< book[*(idPtr[j])].bookTitle;

			std::cout << left
				<< setw(ISBN_WIDTH)
				<< book[*(idPtr[j])].isbn;

			std::cout << right
				<< setw(NUM_WIDTH)
				<< *qtyPtr[j]
				<< "\n";
		}
	}
	std::cout << "\t_______________________________________________________\n";
	std::cout << "\n\tEnd of Quantity Report.\n\n\n";

	// Pause so that user can read report
	std::cout << "Press Enter to continue...";
	std::cin.ignore();
	std::cin.get();
}

//********************************************
// repCost function                          *
//********************************************

void repCost()
{
	int		id[NUM_BOOKS];			// array to track original order of subscripts
	int*	idPtr[NUM_BOOKS];		// pointer to tracking array
	double* wholePtr[NUM_BOOKS];	// array of pointers to wholesale array

	for (int i = 0; i < NUM_BOOKS; i++)
	{
		id[i] = i;
		idPtr[i] = &id[i];
		wholePtr[i] = &book[i].wholesale;
	}

	// selection sort to place Wholesale Cost in descending order
	// ...and track original subscripts to correspond
	// ...with Title, isbn, and qtyOnHand in parallel arrays

	int     startScan;
	int     maxIndex;
	int*    tempId;
	double* maxValue;

	for (startScan = 0; startScan < NUM_BOOKS - 1; startScan++)
	{
		maxIndex = startScan;
		maxValue = wholePtr[startScan];
		tempId = idPtr[startScan];
		for (int index = startScan + 1; index < NUM_BOOKS; index++)
		{
			if (*(wholePtr[index]) > *maxValue)
			{
				maxValue = wholePtr[index];
				tempId = idPtr[index];
				maxIndex = index;
			}
		}

		wholePtr[maxIndex] = wholePtr[startScan];
		idPtr[maxIndex] = idPtr[startScan];
		wholePtr[startScan] = maxValue;
		idPtr[startScan] = tempId;
	}

	char repDate[STR_SIZE];	// stores today's date

	// prompt the user to enter today's date
	std::cout << "\n\nEnter Today's Date(MM/DD/YY): ";
	std::cin >> repDate;

	std::cout << endl << endl;

	// display header
	std::cout << "\n\n\t\t\tSerendipity Booksellers\n";
	std::cout << "\t\t\t    Cost Listing\n\n";

	// display date
	std::cout << "\tDate: "
		<< repDate
		<< endl;

	// display item headings
	std::cout << "\n\tTitle\t\t\t  ISBN\t\tQuantity\tWholesale\n";
	std::cout << "\t_________________________________________________________________\n\n";

	string end = "";

	for (int j = 0; j < NUM_BOOKS; j++)
	{
		if (book[j].isbn.compare(end) == 0) // do not print empty records
		{
			std::cout << "\t"
				<< left
				<< setw(TITLE_WIDTH)
				<< book[*(idPtr[j])].bookTitle;

			std::cout << left
				<< setw(ISBN_WIDTH)
				<< book[*(idPtr[j])].isbn;

			std::cout << fixed
				<< showpoint
				<< right
				<< setprecision(PRECISION);

			std::cout << right
				<< setw(NUM_WIDTH)
				<< book[*(idPtr[j])].qtyOnHand;

			std::cout << setw(NUM_WIDTH)
				<< "\t$ "
				<< *wholePtr[j]
				<< "\n";
		}
	}

	std::cout << "\t_________________________________________________________________\n";
	std::cout << "\n\tEnd of Cost Report.\n\n\n";

	// Pause so that user can read report
	std::cout << "Press Enter to continue...";
	std::cin.ignore();
	std::cin.get();
}

//********************************************
// repAge function                           *
//********************************************

void repAge()
{
	int id[NUM_BOOKS];			// array to track original order of subscripts
	int* idPtr[NUM_BOOKS];		// pointer to tracking array
	string datePtr[NUM_BOOKS];	// array of pointers to dateAdded array

	for (int i = 0; i < NUM_BOOKS; i++)
	{
		id[i] = i;
		idPtr[i] = &id[i];
		datePtr[i] = book[i].dateAdded;
	}

	// selection sort to place DateAdded in descending order
	// ...and track original subscripts to correspond
	// ...with Title, isbn, and qtyOnHand in parallel arrays

	int     startScan;
	int     maxIndex;
	int*    tempId;
	string   maxValue;

	for (startScan = 0; startScan < NUM_BOOKS - 1; startScan++)
	{
		maxIndex = startScan;
		maxValue = datePtr[startScan];
		tempId = idPtr[startScan];
		for (int index = startScan + 1; index < NUM_BOOKS; index++)
		{
			if ((datePtr[index] == maxValue) == true)
			{
				maxValue = datePtr[index];
				tempId = idPtr[index];
				maxIndex = index;
			}
		}

		datePtr[maxIndex] = datePtr[startScan];
		idPtr[maxIndex] = idPtr[startScan];
		datePtr[startScan] = maxValue;
		idPtr[startScan] = tempId;
	}

	char repDate[STR_SIZE];	// stores today's date

	// prompt the user to enter today's date
	std::cout << "\n\nEnter Today's Date(MM/DD/YY): ";
	std::cin >> repDate;

	std::cout << endl << endl;

	// display header
	std::cout << "\n\n\t\t\tSerendipity Booksellers\n";
	std::cout << "\t\t\t    Age Listing\n\n";

	// display date
	std::cout << "\tDate: "
		<< repDate
		<< endl;

	// display item headings
	std::cout << "\n\tTitle\t\t\t  ISBN\t\tQuantity\tDate Added\n";
	std::cout << "\t_________________________________________________________________\n\n";

	string end = "";

	for (int j = 0; j < NUM_BOOKS; j++)
	{
		if (book[j].isbn.compare(end) == 0) // do not print empty records
		{
			std::cout << "\t"
				<< left
				<< setw(TITLE_WIDTH)
				<< book[*(idPtr[j])].bookTitle;

			std::cout << left
				<< setw(ISBN_WIDTH)
				<< book[*(idPtr[j])].isbn;

			std::cout << fixed
				<< showpoint
				<< right
				<< setprecision(PRECISION);

			std::cout << right
				<< setw(NUM_WIDTH)
				<< book[*(idPtr[j])].qtyOnHand;

			std::cout << setw(NUM_WIDTH)
				<< "\t"
				<< book[*(idPtr[j])].dateAdded
				<< "\n";
		}
	}

	std::cout << "\t_________________________________________________________________\n";
	std::cout << "\n\tEnd of Age Report.\n\n\n";

	// Pause so that user can read report
	std::cout << "Press Enter to continue...";
	std::cin.ignore();
	std::cin.get();
}

//********************************************
// reports function                          *
//********************************************

void reports()
{
	int choice = 0; // stores user's choice

	// display the 'Reports Menu' until item 7 is selected
	while (choice != 7)
	{
		system("cls");
		// display company name and screen title
		std::cout << "\n\n\t\t\tSerendipity Booksellers\n";
		std::cout << "\t\t\t\tReports\n\n";

		// display information items
		std::cout << "\t\t1.Inventory Listing\n";
		std::cout << "\t\t2.Inventory Wholesale Value\n";
		std::cout << "\t\t3.Inventory Retail Value\n";
		std::cout << "\t\t4.Listing by Quantity\n";
		std::cout << "\t\t5.Listing by Cost\n";
		std::cout << "\t\t6.Listing by Age\n";
		std::cout << "\t\t7.Return to the Main Menu\n\n";

		// display user prompt
		std::cout << "\t\tEnter Your Choice: ";
		std::cin >> choice;

		// validate the user's input
		while (choice < 1 || choice > 7)
		{
			std::cout << "\n\t\tPlease enter a number in the range 1 - 7.\n";

			std::cout << "\t\tEnter Your Choice: ";
			std::cin >> choice;
		}

		// call the selected function
		switch (choice)
		{
		case 1:
			repListing();
			break;

		case 2:
			repWholesale();
			break;

		case 3:
			repRetail();
			break;

		case 4:
			repQty();
			break;

		case 5:
			repCost();
			break;
		case 6:
			repAge();
			break;

		case 7:
			std::cout << "\n\t\tYou selected item 7.\n";
			break;

		}	// end switch

	}	// end the 'Reports Menu' while loop

	std::cout << endl << endl;

}	// end function reports

