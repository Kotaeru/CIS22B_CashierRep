#include <iostream>
#include <iomanip>
#include<string>
#include "bookinfo.h"
#include "bookdata.h"
using namespace std;

const int NUM_BOOKS = 25;
extern BookData book[NUM_BOOKS]; // the array of 'BookData' stuctures. "extern" is used to tell the compiler that the data was declared somewhere else

const int STR_SIZE = 51; // represents the maximum string size
const int PRECISION = 2; // the decimal precision

//********************************************
// bookInfo function                         *
//********************************************

void bookInfo(string isbn, string title, string author,
	string publisher, string date, int qty,
	double wholeSale, double retail, int num)
{
	// display company name and screen title
	cout << "\t\t\tSerendipity Booksellers\n";
	cout << "\t\t\t    Book Information\n\n";

	// display information items
	cout << "ISBN: " << book[num].isbn << endl;
		

	cout << "Title: " << book[num].bookTitle << endl;

	cout << "Author: " << book[num].author << endl;
		
	cout << "Publisher: " << book[num].publisher << endl;
		
	cout << "Date Added: " << book[num].dateAdded << endl;
		

	cout << "Quantity-On-Hand: " << book[num].qtyOnHand << endl;
		
	cout << "Wholesale Cost: "
		<< fixed
		<< showpoint
		<< setprecision(PRECISION)
		<< book[num].wholesale
		<< "\n";

	cout << "Retail Price: "
		<< fixed
		<< showpoint
		<< setprecision(PRECISION)
		<< book[num].retail
		<< "\n";

	cout << endl << endl;

}	// end function bookInfo