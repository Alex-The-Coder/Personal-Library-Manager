#ifndef LISTNODE_H_
#define LISTNODE_H_

#include "Book.h"

class Node
{
private:
	Book data;
	Node* next;
public:
	Node(Book data, Node* next = nullptr):
		data(data), next(next) {}

	Node* deepCopy();

	Book& getData();
	Node*& getNext();
};

#endif /* LISTNODE_H_ */
