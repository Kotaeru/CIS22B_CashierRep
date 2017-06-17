#include <fstream>
#include <string.h>
#include "reports.h"


const int STR_SIZE = 51;   // represents the maximum string size for bookTitle
const int ISBN_WIDTh = 14;	// the ISBN display length
const int AU_SIZE = 31;     // the maximum number of characters for author string
//const int NUM_BOOKS = 20;	// the number of books in inventory

// BookData structure declaration.

class BookData
{

public:
	std::string bookTitle,	// stores the tile of a book
		isbn,	    // stores the isbn number of a book
		author,       // stores the book author's name
		publisher,	        // stores the book publisher's name
		dateAdded;	        // stores the date a book was added into inventory
	int	qtyOnHand;		        // stores the quantity on hand of a book
	double wholesale,	        // stores the wholesale price of a book
		retail;		        // stores the retail price of a book


	friend std::istream& operator>>(std::istream &infile, BookData& book);

	void setTitle(std::string);
	void setISBN(std::string);
	void setAuthor(std::string);
	void setPub(std::string);
	void setDateAdded(std::string);
	void setQty(int);
	void setWholesale(double);
	void setRetail(double);
	bool isEmpty();
	void removeBook();

	};