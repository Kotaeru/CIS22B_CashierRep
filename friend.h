#include <iostream>
#include <fstream>
#include "bookdata.h"

const int NUM_BOOKS = 25;	// the number of books in inventory

extern BookData book[NUM_BOOKS]; // the array of 'BookData' stuctures

//*********************************************************
// Friend Function To Import Data                         *
//*********************************************************

std::istream& operator>> (std::istream& inputFile, BookData& book)
{
	while (inputFile.eof() != true)
	{
		for (int i = 0; i < 24; i++)
		{
			inputFile >>
				book[i].bookTitle >>
				book[i].isbn >>
				book[i].author >>
				book[i].publisher >>
				book[i].dateAdded >>
				book[i].qtyOnHand >>
				book[i].wholesale >>
				book[i].retail;
		}
	}
	return inputFile;
}