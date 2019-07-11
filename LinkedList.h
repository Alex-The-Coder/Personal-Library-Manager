#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "BookIterator.h"

class LinkedList
{
private:
	Node* front;
	unsigned int size = 0;
	void addNode(Book& data, Node*& previous);
	void removeNode(Node*& node, Node*& previous);
public:
	LinkedList();
	~LinkedList();
	LinkedList(const LinkedList& orig);
	LinkedList& operator=(LinkedList& copy);

	unsigned int getSize();

	BookIterator begin();
	BookIterator end();

	void addElement(Book& book);

	bool containsElement(string& title);

	Book& getElement(string& title);

	Book& getElement(unsigned int index);

	Book removeElement(string& title);
};

#endif /* LINKEDLIST_H_ */
