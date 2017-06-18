#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "reports.h"
#include "bookdata.h"

using namespace std;

const int	NUM_WIDTH	=  6;	// the numeric display length
const int	TITLE_WIDTH = 26;	// the title display length
const int	PRECISION	=  2;	// the decimal precision

extern BookData book[NUM_BOOKS]; // the array of 'BookData' structures

//********************************************
// repListing function                       *
//********************************************

void repListing()
{
	char repDate[STR_SIZE];	// stores today's date
	
	// prompt the user to enter today's date
	cout << "\nEnter Today's Date(MM/DD/YY): ";
	cin >> repDate;

	cout << endl << endl;

	// display company name

	system("cls");

	cout << "Serendipity Booksellers Inventory Listing\n\n";

	// display date
	cout << "Date:\t\t\t"
		 << repDate;

	// display inventory information by record, then by field
	char end[] = {'\0'};

	for (int i = 0; i < NUM_BOOKS; i++)
	{
		if (strcmp(book[i].isbn, end) != 0 ) // do not print an empty record
		{
			cout << "\n_____________________________________________________";

			cout << "\n\nTitle:\t\t\t"
				 << book[i].bookTitle;

			cout << "\nISBN:\t\t\t"
				 << book[i].isbn;

			cout << "\nAuthor:\t\t\t"
				 << book[i].author;

			cout << "\nPublisher:\t\t"
				 << book[i].publisher;

			cout << "\nDate Added:\t\t"
				 << book[i].dateAdded;

			cout << fixed
				 << showpoint
				 << right
				 << setprecision(PRECISION);

			cout << "\nQuantity On Hand:\t"
					<< book[i].qtyOnHand;

			cout << "\nWholesale Cost:\t\t"
			     << book[i].wholesale;

			cout << "\nRetail Price:\t\t"
				 << book[i].retail;
		}
	}

	cout << "\n\n_____________________________________________________";
	cout << "\n\nEnd of Inventory Report.\n\n\n";

	system("Pause");

}

//********************************************
// repWholesale function                     *
//********************************************

void repWholesale()
{
	char repDate[STR_SIZE];	// stores today's date
	

	// prompt the user to enter today's date
	cout << "\nEnter Today's Date(MM/DD/YY): ";
	cin >> repDate;

	// display header

	system("cls");

	cout << "Serendipity Booksellers\n";
	cout << "Wholesale Value Listing\n\n";

	// display date
	cout << "Date: "
			<< repDate
			<< endl;

	// display item headings
	cout << "\nTitle\t\t\t  ISBN\t\tQuantity\tWholesale\n";
	cout << "_________________________________________________________________\n\n";

	double	itemSubTot	= 0;
	double	subTot		= 0;
	char	end[]		= {'\0'};

	for (int i = 0; i < NUM_BOOKS; i++)
	{
		if (strcmp(book[i].isbn, end) != 0 ) // do not print empty records
		{
			cout << "\n"
				 << left
				 << setw(TITLE_WIDTH)
				 << book[i].bookTitle;

			cout << left
				 << setw(ISBN_WIDTH)
				 << book[i].isbn;

			cout << right
				 << setw(NUM_WIDTH)
				 << book[i].qtyOnHand
				 << "\t";

			cout << fixed
				 << showpoint
				 << right
				 << setprecision(PRECISION);

			cout << setw(NUM_WIDTH)
				 << "\t$ "
				 << book[i].wholesale;

			itemSubTot = book[i].qtyOnHand * book[i].wholesale;
			subTot += itemSubTot;
		}
	}

	cout << "\n\n\nTotal Wholesale Value:  $ "
		 << subTot
		 << endl;

	cout << "_________________________________________________________________\n";

	cout << "\nEnd of Wholesale Report.\n\n\n";

	// Pause so that user can read report
	cout << "Press Enter to continue...";
	cin.ignore();
	cin.get();
}

//********************************************
// repRetail function                        *
//********************************************

void repRetail()
{
	char repDate[STR_SIZE];	// stores today's date
	
	// prompt the user to enter today's date
	cout << "\nEnter Today's Date(MM/DD/YY): ";
	cin >> repDate;

	cout << endl << endl;

	// display header

	system("cls");

	cout << "Serendipity Booksellers\n";
	cout << " Retail Value Listing\n\n";

	// display date
	cout << "Date: "
		 << repDate
		 << endl;

	// display item headings
	cout << "\nTitle\t\t\t  ISBN\t\tQuantity\tRetail\n";
	cout << "_________________________________________________________________\n\n";

	double	itemSubTot	= 0;
	double	subTot		= 0;
	char	end[]		= {'\0'};

	for (int i = 0; i < NUM_BOOKS; i++)
	{
		if (strcmp(book[i].isbn, end) != 0 ) // do not print empty records
		{
			cout << "\n"
				 << left
				 << setw(TITLE_WIDTH)
				 << book[i].bookTitle;

			cout << left
				 << setw(ISBN_WIDTH)
				 << book[i].isbn;

			cout << fixed
				 << showpoint
				 << right
				 << setprecision(PRECISION);

			cout << right
				 << setw(NUM_WIDTH)
				 << book[i].qtyOnHand
				 << "\t";

			cout << setw(NUM_WIDTH)
				 << "\t$ "
				 << book[i].retail;

			itemSubTot = book[i].qtyOnHand * book[i].retail;
			subTot += itemSubTot;
		}
	}

	cout << "\n\n\nTotal Retail Value:  $" << subTot << endl;
	cout << "_________________________________________________________________\n\n";
	cout << "\nEnd of Retail Report.\n\n\n";

	system("pause");
}

//********************************************
// repQty function                           *
//********************************************

void repQty()
{
	int	 id	   [NUM_BOOKS];		// array to track original order of subscripts
	int* idPtr [NUM_BOOKS];		// pointer to tracking array
	int* qtyPtr[NUM_BOOKS];		// array of pointers to qtyOnHand array

	for(int i = 0; i < NUM_BOOKS; i++)
	{
		id[i]		= i;
		idPtr[i]	= &id[i];
		qtyPtr[i]	= &book[i].qtyOnHand;
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
				tempId	 = idPtr [index];
				maxIndex = index;
			}
		}
		qtyPtr	[maxIndex]	= qtyPtr[startScan];
		idPtr	[maxIndex]	= idPtr	[startScan];
		qtyPtr	[startScan] = maxValue;
		idPtr	[startScan] = tempId;
	}

	char repDate[STR_SIZE];	// stores today's date

	// prompt the user to enter today's date
	cout << "\nEnter Today's Date(MM/DD/YY): ";
	cin >> repDate;

	cout << endl << endl;

	// display header

	system("cls");

	cout << "Serendipity Booksellers\n";
	cout << "Quantity Listing\n\n";

	// display date
	cout << "Date: "
		 << repDate
		 << endl;

	// display item headings

	cout << "\nTitle\t\t\t  ISBN\t\tQuantity\n";
	cout << "\_______________________________________________________\n";
	char end[] = {'\0'};

	for (int j = 0; j < NUM_BOOKS; j++)
	{
		if (strcmp(book[*(idPtr[j])].isbn, end) != 0 ) // do not print empty records
		{
			cout << "\n"
				 << left
				 << setw(TITLE_WIDTH)
				 << book[*(idPtr[j])].bookTitle;

			cout << left
				 << setw(ISBN_WIDTH)
				 << book[*(idPtr[j])].isbn;

			cout << right
				 << setw(NUM_WIDTH)
				 << *qtyPtr[j]
				 << "\n";
		}
	}
	cout << "_______________________________________________________\n";
	cout << "\nEnd of Quantity Report.\n\n\n";

	system("pause");
}

//********************************************
// repCost function                          *
//********************************************

void repCost()
{
	int		id[NUM_BOOKS];			// array to track original order of subscripts
	int*	idPtr[NUM_BOOKS];		// pointer to tracking array
	double* wholePtr[NUM_BOOKS];	// array of pointers to wholesale array

	for(int i = 0; i < NUM_BOOKS; i++)
	{
		id[i]		= i;
		idPtr[i]	= &id[i];
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
				maxValue	= wholePtr[index];
				tempId		= idPtr[index];
				maxIndex	= index;
			}
		}

		wholePtr[maxIndex]	= wholePtr[startScan];
		idPtr[maxIndex]		= idPtr[startScan];
		wholePtr[startScan] = maxValue;
		idPtr[startScan]	= tempId;
	}

	char repDate[STR_SIZE];	// stores today's date

	// prompt the user to enter today's date
	cout << "\nEnter Today's Date(MM/DD/YY): ";
	cin >> repDate;

	cout << endl << endl;

	// display header
	system("cls");

	cout << "Serendipity Booksellers\n";
	cout << "   Cost Listing\n\n";

	// display date
	cout << "Date: "
		 << repDate
		 << endl;

	// display item headings
	cout << "\nTitle\t\t\t  ISBN\t\tQuantity\tWholesale\n";
	cout << "_________________________________________________________________\n\n";

	char end[] = {'\0'};

	for (int j = 0; j < NUM_BOOKS; j++)
	{
		if (strcmp(book[*(idPtr[j])].isbn, end) != 0 ) // do not print empty records
		{
			cout << left
				 << setw(TITLE_WIDTH)
				 << book[*(idPtr[j])].bookTitle;

			cout << left
				 << setw(ISBN_WIDTH)
				 << book[*(idPtr[j])].isbn;

			cout << fixed
				 << showpoint
				 << right
				 << setprecision(PRECISION);

			cout << right
				 << setw(NUM_WIDTH)
				 << book[*(idPtr[j])].qtyOnHand;

			cout << setw(NUM_WIDTH)
				 << "\t$ "
				 << *wholePtr[j]
				 << "\n";
		}
	}

	cout << "_________________________________________________________________\n";
	cout << "\nEnd of Cost Report.\n\n\n";
	
	system("pause");
}

//********************************************
// repAge function                           *
//********************************************

void repAge()
{
	int id[NUM_BOOKS];			// array to track original order of subscripts
	int* idPtr[NUM_BOOKS];		// pointer to tracking array
	char* datePtr[NUM_BOOKS];	// array of pointers to dateAdded array

	for(int i = 0; i < NUM_BOOKS; i++)
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
	char*   maxValue;

	for (startScan = 0; startScan < NUM_BOOKS - 1; startScan++)
	{
		maxIndex = startScan;
		maxValue = datePtr[startScan];
		tempId = idPtr[startScan];
		for (int index = startScan + 1; index < NUM_BOOKS; index++)
		{
			if (strcmp(datePtr[index], maxValue) > 0)
			{
				maxValue	= datePtr[index];
				tempId		= idPtr[index];
				maxIndex	= index;
			}
		}

		datePtr[maxIndex]	= datePtr[startScan];
		idPtr[maxIndex]		= idPtr[startScan];
		datePtr[startScan]  = maxValue;
		idPtr[startScan]	= tempId;
	}

	char repDate[STR_SIZE];	// stores today's date

	// prompt the user to enter today's date
	cout << "\nEnter Today's Date(MM/DD/YY): ";
	cin >> repDate;

	cout << endl << endl;

	// display header
	system("cls");

	cout << "Serendipity Booksellers\n";
	cout << "    Age Listing\n\n";

	// display date
	cout << "Date: "
		 << repDate
		 << endl;

	// display item headings
	cout << "\nTitle\t\t\t  ISBN\t\tQuantity\tDate Added\n";
	cout << "_________________________________________________________________\n\n";

	char end[] = {'\0'};

	for (int j = 0; j < NUM_BOOKS; j++)
	{
		if (strcmp(book[*(idPtr[j])].isbn, end) != 0 ) // do not print empty records
		{
			cout << left
				 << setw(TITLE_WIDTH)
				 << book[*(idPtr[j])].bookTitle;

			cout << left
				 << setw(ISBN_WIDTH)
				 << book[*(idPtr[j])].isbn;

			cout << fixed
				 << showpoint
				 << right
				 << setprecision(PRECISION);

			cout << right
				 << setw(NUM_WIDTH)
				 << book[*(idPtr[j])].qtyOnHand;

			cout << setw(NUM_WIDTH)
				 << "\t"
				 << book[*(idPtr[j])].dateAdded
				 << "\n";
		}
	}

	cout << "_________________________________________________________________\n";
	cout << "\nEnd of Age Report.\n\n\n";

	system("pause");

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
		cout << "Serendipity Booksellers\n";
		cout << "Reports\n\n";

		// display information items
		cout << "1.Inventory Listing\n";
		cout << "2.Inventory Wholesale Value\n";
		cout << "3.Inventory Retail Value\n";
		cout << "4.Listing by Quantity\n";
		cout << "5.Listing by Cost\n";
		cout << "6.Listing by Age\n";
		cout << "7.Return to the Main Menu\n\n";

		// display user prompt
		cout << "Enter Your Choice: ";
		cin >> choice;

		// validate the user's input
		while (choice < 1 || choice > 7)
		{
			cout << "\nPlease enter a number in the range 1 - 7.\n";

			cout << "\tEnter Your Choice: ";
			cin >> choice;
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
					cout << "\nYou selected item 7.\n";
						break;

			}	// end switch

	}	// end the 'Reports Menu' while loop

	cout << endl << endl;

}	// end function reports



