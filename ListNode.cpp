#include "ListNode.h"

Node* Node::deepCopy()
{
	Node* newNode = new Node(data, next == nullptr ? next : next->deepCopy());

	return newNode;
}

Book& Node::getData()
{
	return data;
}

Node*& Node::getNext()
{
	return next;
}
