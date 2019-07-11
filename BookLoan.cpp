#include "BookLoan.h"

BookLoan::BookLoan(const string& lastName, const string& firstName, int returnMonth, int returnDay, int returnYear)
{
	this->lastName = lastName;
	this->firstName = firstName;
	this->returnMonth = returnMonth;
	this->returnDay = returnDay;
	this->returnYear = returnYear;
}

string BookLoan::getReturnDate() const
{
	string day = to_string(returnDay);
	if (day.length() < 2)
	{
		day = ('0' + day);
	}

	string date = to_string(returnMonth) + "/" + day + "/" + to_string(returnYear);
	return date;
}

const string& BookLoan::getFirstName() const
{
	return firstName;
}

const string& BookLoan::getLastName() const
{
	return lastName;
}

int BookLoan::compareTo(BookLoan& other) const
{
	if (other.returnYear != returnYear)
	{
		return other.returnYear - returnYear;
	}
	if (other.returnMonth != returnMonth)
	{
		return other.returnMonth - returnMonth;
	}
	if (other.returnDay != returnDay)
	{
		return other.returnDay - returnDay;
	}

	return 0;
}

BookLoan* BookLoan::copy() const
{
	return new BookLoan(lastName, firstName, returnMonth, returnDay, returnYear);
}
