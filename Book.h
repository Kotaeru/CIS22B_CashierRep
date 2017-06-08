#include <string>
using namespace std;

struct Date
{
	int month;
	int day;
	int year;
};

class Book
{
private:
	int isbn;
	string title;
	string author;
	string publisher;
	Date dateAdded;
	int quantity;
	double cost;
	double price;

public:
	//constructors & destructor
	Book(int i, string t, string a, string p, Date d, int q, double c, double pr)
	{
		isbn = i;
		title = t;
		author = a;
		publisher = p;
		dateAdded = d;
		quantity = q;
		cost = c;
		price = pr;
	}
	//getters & setters
	Date getDate()
	{
		return dateAdded;
	}
	int getQuantity()
	{
		return quantity;
	}
	double getCost()
	{
		return cost;
	}
	int compareQuantity(Book b)
	{
		return this.quantity - b.getQuantity();
	}
	double compareCost(Book b)
	{
		return this.cost - b.getCost();
	}
	int compareDate(Book b)
	{
		if (this.dateAdded.year > b.getDate().year)
		{
			return 1;
		}
		else if (this.dateAdded.year < b.getDate().year)
		{
			return -1;
		}
		else if (this.dateAdded.month > b.getDate().month)
		{
			return 1;
		}
		else if (this.dateAdded.month < b.getDate().month)
		{
			return -1;
		}
		else if (this.dateAdded.day > b.getDate().day)
		{
			return 1;
		}
		else if (this.dateAdded.day < b.getDate().day)
		{
			return -1;
		}
		else
		{
			return 0;
		}
	}
};