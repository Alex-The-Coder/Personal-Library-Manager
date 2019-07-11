#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "LinkedList.h"
using namespace std;

void trimString(string&);
void loadData(istream&, LinkedList&, LinkedList&);
void outputData(ostream&, LinkedList&, bool);

int main()
{
	ifstream input("booklist.txt");
	LinkedList bookshelf;
	LinkedList loaned;
	loadData(input, bookshelf, loaned);
	input.close();

	ofstream shelfOutput("bookshelf.txt");
	ofstream loanedOutput("booksOnLoan.txt");

	outputData(shelfOutput, bookshelf, false);
	shelfOutput.close();
	outputData(loanedOutput, loaned, true);
	loanedOutput.close();

	return 0;
}

void trimString(string& str)
{
	while (isspace(str.at(0)))
	{
		str = str.substr(1, str.length());
	}
	while (isspace(str.at(str.length() - 1)))
	{
		str = str.substr(0, str.length() - 1);
	}
}

void loadData(istream& input, LinkedList& bookshelf, LinkedList& loaned)
{
	int total;
	input >> total;
	for (int i = 0; i < total; i++)
	{
		char type;
		input >> type;
		if (type == 'A')
		{
			int width;
			int length;
			int pages;
			string lastName;
			string firstName;
			string title;
			input >> width >> length >> pages >> lastName >> firstName;
			input.ignore();
			getline(input, title);
			trimString(title);

			Book book(title, lastName, firstName, width, length, pages);
			bookshelf.addElement(book);
		}
		else if (type == 'L')
		{
			string lastName;
			string firstName;
			int returnMonth;
			int returnDay;
			int returnYear;
			string title;
			input >> lastName >> firstName >> returnMonth >> returnDay >> returnYear;
			input.ignore();
			getline(input, title);
			trimString(title);

			if (!bookshelf.containsElement(title))
			{
				if (loaned.containsElement(title))
				{
					cout << title << " ALREADY LOANED OUT" << endl;
				}
				else
				{
					cout << title << " NOT IN LIBRARY" << endl;
				}
			}
			else
			{
				Book book = bookshelf.removeElement(title);
				book.loanOut(lastName, firstName, returnMonth, returnDay, returnYear);
				loaned.addElement(book);
			}
		}
		else
		{
			string title;
			input.ignore();
			getline(input, title);
			trimString(title);

			if (loaned.containsElement(title))
			{
				Book book = loaned.removeElement(title);
				book.markReturned();
				bookshelf.addElement(book);
			}
		}
	}
}

void outputData(ostream& output, LinkedList& data, bool loaned)
{
	output << data.getSize() << endl;
	if (data.getSize() < 1)
	{
		return;
	}

	int id = 1;
	if (loaned)
	{
		string date = "";
		for (Book& book : data)
		{
			const BookLoan* loan = book.getLoan();
			if (date != loan->getReturnDate())
			{
				date = loan->getReturnDate();
				output << date << endl;
			}
			output << id++ << ". " << book.getTitle() << " borrowed by " << loan->getFirstName() << ' ' << loan->getLastName() << endl;
		}
	}
	else
	{
		for (Book& book : data)
		{
			output << id++ << ". " << book.getTitle() << " by " << book.getAuthorFirstName() << " " << book.getAuthorLastName()
				<< " (" << book.getWidth() << "x" << book.getLength() << ", " << book.getPages() << " p)" << endl;
		}
	}
}
