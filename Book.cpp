#include "Book.h"

Book::Book(string& title, string& authorLastName, string& authorFirstName, int width, int length, int pages)
{
	this->title = title;
	this->authorLastName = authorLastName;
	this->authorFirstName = authorFirstName;
	this->width = width;
	this->length = length;
	this->pages = pages;
	this->loan = nullptr;
}

Book::~Book()
{
	if (loan != nullptr)
	{
		delete loan;
		loan = nullptr;
	}
}

Book::Book(const Book& orig)
{
	this->title = orig.title;
	this->authorLastName = orig.authorLastName;
	this->authorFirstName = orig.authorFirstName;
	this->width = orig.width;
	this->length = orig.length;
	this->pages = orig.pages;

	if (orig.loan != nullptr)
	{
		this->loan = orig.loan->copy();
	}
	else
	{
		this->loan = nullptr;
	}
}

Book& Book::operator=(const Book& copy)
{
	if (this != &copy)
	{
		this->title = copy.title;
		this->authorLastName = copy.authorLastName;
		this->authorFirstName = copy.authorFirstName;
		this->width = copy.width;
		this->length = copy.length;
		this->pages = copy.pages;

		if (this->loan != nullptr)
		{
			delete this->loan;
			this->loan = nullptr;
		}

		if (copy.loan != nullptr)
		{
			this->loan = copy.loan->copy();
		}
	}

	return *this;
}

bool Book::isLoaned()
{
	return loan != nullptr;
}

int Book::getArea()
{
	return width * length;
}

string& Book::getTitle()
{
	return title;
}

const BookLoan* Book::getLoan()
{
	return loan;
}

string& Book::getAuthorLastName()
{
	return authorLastName;
}

string& Book::getAuthorFirstName()
{
	return authorFirstName;
}

int Book::getWidth()
{
	return width;
}

int Book::getLength()
{
	return length;
}

int Book::getPages()
{
	return pages;
}

int Book::compareTo(Book& other)
{
	if (loan != nullptr && other.loan != nullptr)
	{
		return loan->compareTo(*(other.loan));
	}
	else
	{
		if (other.getArea() != getArea())
		{
			return getArea() - other.getArea();
		}

		return pages - other.pages;
	}
}

void Book::loanOut(string& lastName, string& firstName, int returnMonth, int returnDay, int returnYear)
{
	this->loan = new BookLoan(lastName, firstName, returnMonth, returnDay, returnYear);
}

void Book::markReturned()
{
	if (loan != nullptr)
	{
		delete loan;
		loan = nullptr;
	}
}
