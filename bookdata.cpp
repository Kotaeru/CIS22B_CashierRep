#include <fstream>
#include "bookdata.h"
#include "strupper.h"
#include <string>

using namespace std;

const int NUM_BOOKS = 25;        // the maximum number of books
extern BookData book[NUM_BOOKS]; // the array of 'BookData' stuctures. "extern" is used to tell the compiler that the data was declared somewhere else


//*********************************************************
// Function setTitle                                      *
//*********************************************************

void BookData::setTitle(string newTitle)
{
	bookTitle = newTitle;
}

//*********************************************************
// Function setISBN                                       *
//*********************************************************

void BookData::setISBN(string newISBN)
{
	isbn = newISBN;
}

//*********************************************************
// Function setAuthor                                     *
//*********************************************************

void BookData::setAuthor(string newAuthor)
{
	author = newAuthor;
}

//*********************************************************
// Function setPub                                        *
//*********************************************************

void BookData::setPub(string newPub)
{
	publisher = newPub;
}

//*********************************************************
// Function setDateAdded                                  *
//*********************************************************

void BookData::setDateAdded(string newDate)
{
	dateAdded = newDate;
}

//*********************************************************
// Function setQty                                        *
//*********************************************************

void  BookData::setQty(int newQuantity)
{
	qtyOnHand = newQuantity;
}

//*********************************************************
// Function setWholesale                                  *
//*********************************************************

void  BookData::setWholesale(double newWholesale)
{
	wholesale = newWholesale;
}

//*********************************************************
// Function setRetail                                     *
//*********************************************************

void  BookData::setRetail(double newRetail)
{
	retail = newRetail;
}

//*********************************************************
// Function isEmpty                                       *
//*********************************************************

bool  BookData::isEmpty()
{
	if (bookTitle.empty())
	{
		return true;
	}
	else return false;
}

//*********************************************************
// Function removeBook                                    *
//*********************************************************

void  BookData::removeBook()
{
	bookTitle = "";
	isbn = "";
}

//*********************************************************
// Function Import Data                                   *
//*********************************************************

 istream& operator>>(istream &infile, BookData& book) {

	
	 infile >> book.isbn;
	 infile >> book.author;
	 infile >> book.publisher;
	 infile >> book.dateAdded;
	 infile >> book.qtyOnHand;
	 infile >> book.wholesale;
	 infile >> book.retail;
		
	return infile;
}

