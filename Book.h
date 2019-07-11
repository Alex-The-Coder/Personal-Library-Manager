#ifndef BOOK_H_
#define BOOK_H_

#include <string>
#include "BookLoan.h"
using namespace std;

class Book
{
private:
	string title;
	string authorLastName;
	string authorFirstName;
	int width;
	int length;
	int pages;
	BookLoan* loan;
public:
	Book(string& title, string& authorLastName, string& authorFirstName, int width, int length, int pages);
	~Book();
	Book(const Book& orig);
	Book& operator=(const Book& copy);

	bool isLoaned();

	int getArea();

	string& getTitle();

	const BookLoan* getLoan();

	string& getAuthorLastName();

	string& getAuthorFirstName();

	int getWidth();

	int getLength();

	int getPages();

	int compareTo(Book& other);

	void loanOut(string& lastName, string& firstName, int returnMonth, int returnDay, int returnYear);

	void markReturned();
};

#endif /* BOOK_H_ */
