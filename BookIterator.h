#ifndef BOOKITERATOR_H_
#define BOOKITERATOR_H_

#include "ListNode.h"

class BookIterator
{
private:
	Node* node;
public:
	BookIterator();
	BookIterator(Node* node);

	Book& operator*();
	void operator++();
	bool operator!=(const BookIterator& rhs);
};

#endif /* BOOKITERATOR_H_ */
