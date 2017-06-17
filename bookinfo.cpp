#include <iostream>
#include <iomanip>
#include<string>
#include "bookinfo.h"
using namespace std;

const int STR_SIZE = 51; // represents the maximum string size
const int PRECISION = 2; // the decimal precision

//********************************************
// bookInfo function                         *
//********************************************

void bookInfo(string isbn, string title, string author,
	string publisher, string date, int qty,
	double wholeSale, double retail)
{
	// display company name and screen title
	cout << "\t\t\tSerendipity Booksellers\n";
	cout << "\t\t\t    Book Information\n\n";

	// display information items
	cout << "ISBN: " << isbn << endl;
		

	cout << "Title: " << title << endl;

	cout << "Author: " << author << endl;
		

	cout << "Publisher: " << publisher << endl;
		

	cout << "Date Added: " << date << endl;
		

	cout << "Quantity-On-Hand: " << qty << endl;
		
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