// ********************************************************
// Starting Out with C++                                  *
// From Control Stuctures through Objects                 *
// seventh edition                                        *
//                                                        *
// Chapter 11 Structured Data                             *
//                                                        *
// Serendipity Booksellers Software Development           *
// Project — Part 11: A Problem-Solving Exercise          *
//                                                        *
// Multi-File Program                                     *
// ********************************************************
#include <string.h>
const int STR_SIZE  = 51;   // represents the maximum string size for bookTitle
const int ISBN_WIDTH = 14;	// the ISBN display length
const int AU_SIZE = 31;     // the maximum number of characters for author string
const int NUM_BOOKS = 20;	// the number of books in inventory

// BookData structure declaration.

struct BookData
{
	char bookTitle[STR_SIZE],	// stores the tile of a book
         isbn[ISBN_WIDTH],	    // stores the isbn number of a book
         author[AU_SIZE],       // stores the book author's name
         publisher[31],	        // stores the book publisher's name
         dateAdded[11];	        // stores the date a book was added into inventory
	int	qtyOnHand;		        // stores the quantity on hand of a book
	double wholesale,	        // stores the wholesale price of a book
           retail;		        // stores the retail price of a book
};

// Function prototypes
void setTitle(char* , int);
void setISBN(char* , int);
void setAuthor(char* , int);
void setPub(char* , int);
void setDateAdded(char* , int);
void setQty(int , int);
void setWholesale(double , int);
void setRetail(double , int);
int isEmpty(int);
void removeBook(int);
