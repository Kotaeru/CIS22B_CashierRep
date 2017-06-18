#include "friend.h"
#include <iostream>

std::istream& operator>> (std::istream& input, BookData& book)
{
	
			input >> 
			book.bookTitle >>
			book.isbn >>
			book.author >>
			book.publisher >>
			book.dateAdded >>
			book.qtyOnHand >>
			book.wholesale >>
			book.retail;	

	return input;
}
