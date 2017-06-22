#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "bookinfo.h"
using namespace std;

const int STR_SIZE  = 51; // represents the maximum string size
const int PRECISION =  2; // the decimal precision

//********************************************
// bookInfo function                         *
//********************************************

void bookInfo(char isbn[STR_SIZE], char title[STR_SIZE], char author[STR_SIZE], 
			  char publisher[STR_SIZE], char date[STR_SIZE], int qty,
			  double wholeSale, double retail)
{
	// display company name and screen title
	
	system("cls");

	cout << "Serendipity Booksellers\n";
	cout << "    Book Information\n\n";

	// display information items
	cout << "ISBN: " 
		 << isbn 
		 << "\n";

	cout << "Title: " 
		 << title 
		 << "\n";

	cout << "Author: " 
		 << author 
		 << "\n";

	cout << "Publisher: " 
		 << publisher 
		 << "\n";

	cout << "Date Added: " 
		 << date	
		 << "\n";

	cout << "Quantity-On-Hand: " 
		 << qty 
		 << "\n";

	cout << "Wholesale Cost: " 
		 << fixed 
		 << showpoint 
		 << setprecision(PRECISION) 
		 << wholeSale	
		 << "\n";

	cout << "Retail Price: " 
		 << fixed 
		 << showpoint 
		 << setprecision(PRECISION) 
		 << retail 
		 << "\n";

	cout << endl << endl;

}	// end function bookInfo

