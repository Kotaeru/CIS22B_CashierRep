#define _CRT_SECURE_NO_WARNINGS
#include "friend.h"
#include <iostream>
#include <fstream>
#include <string>

std::ifstream& operator>> (std::ifstream& input, BookData& book)
{
	
	input >> book.bookTitle;
	input >> book.bookTitle;
	input >> book.isbn;
	input >> book.author;
	input >> book.publisher;
	input >> book.dateAdded;
	input >> book.qtyOnHand;
	input >> book.wholesale;
	input >> book.retail;	

	return input;
}
