#ifndef BOOKLOAN_H_
#define BOOKLOAN_H_

#include <string>
using namespace std;

class BookLoan
{
private:
	string lastName;
	string firstName;
	int returnMonth;
	int returnDay;
	int returnYear;
public:
	BookLoan(const string& lastName, const string& firstName, int returnMonth, int returnDay, int returnYear);

	string getReturnDate() const;
	const string& getFirstName() const;
	const string& getLastName() const;

	int compareTo(BookLoan& other) const;

	BookLoan* copy() const;
};

#endif /* BOOKLOAN_H_ */
