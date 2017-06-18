#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <fstream>
#include "bookdata.h"
#include "strUpper.h"
using namespace std;

const int NUM_BOOKS = 25;	// the number of books in inventory

extern BookData book[NUM_BOOKS]; // the array of 'BookData' stuctures


//*********************************************************
// Constructor                                            *
//*********************************************************


//*********************************************************
// Function setTitle                                      *
//*********************************************************

void BookData::setTitle(char* newTitle, int subscript)
{
	strUpper(newTitle);
	strcpy(book[subscript].bookTitle, newTitle);
}


//*********************************************************
// Function setISBN                                       *
//*********************************************************

void BookData::setISBN(char* newISBN, int subscript)
{
	strUpper(newISBN);
	strcpy(book[subscript].isbn, newISBN);
}

//*********************************************************
// Function setAuthor                                     *
//*********************************************************

void BookData::setAuthor(char* newAuthor, int subscript)
{
	strUpper(newAuthor);
	strcpy(book[subscript].author, newAuthor);
}

//*********************************************************
// Function setPub                                        *
//*********************************************************

void BookData::setPub(char* newPublisher, int subscript)
{
	strUpper(newPublisher);
	strcpy(book[subscript].publisher, newPublisher);
	
}

//*********************************************************
// Function setDateAdded                                  *
//*********************************************************

void BookData::setDateAdded(char* newDate, int subscript)
{
	strcpy(book[subscript].dateAdded, newDate);
}

//*********************************************************
// Function setQty                                        *
//*********************************************************

void BookData::setQty(int newQuantity, int subscript)
{
	book[subscript].qtyOnHand = newQuantity;
}

//*********************************************************
// Function setWholesale                                  *
//*********************************************************

void BookData::setWholesale(double newWholesale, int subscript)
{
	book[subscript].wholesale = newWholesale;
}

//*********************************************************
// Function setRetail                                     *
//*********************************************************

void BookData::setRetail(double newRetail, int subscript)
{
	book[subscript].retail = newRetail;
}

//*********************************************************
// Function isEmpty                                       *
//*********************************************************

int BookData::isEmpty(int subscript)
{
	if (book[subscript].bookTitle[0] == 0)
	{
		return 1;
	}
	else return 0;
}

//*********************************************************
// Function removeBook                                    *
//*********************************************************

void BookData::removeBook(int subscript)
{
	book[subscript].bookTitle[0] = 0;
	book[subscript].isbn[0] = 0;
}
