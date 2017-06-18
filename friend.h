#include <iostream>
#include <fstream>
#include "bookdata.h"

extern BookData book[NUM_BOOKS]; // the array of 'BookData' stuctures

//*********************************************************
// Friend Function To Import Data                         *
//*********************************************************

 std::istream& operator>> (std::istream& input, BookData& book);