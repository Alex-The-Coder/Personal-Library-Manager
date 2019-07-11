#include "BookIterator.h"

BookIterator::BookIterator()
{
	this->node = nullptr;
}

BookIterator::BookIterator(Node* node)
{
	this->node = node;
}

Book& BookIterator::operator*()
{
	return node->getData();
}

void BookIterator::operator++()
{
	if (node == nullptr)
	{
		return;
	}

	node = node->getNext();
}

bool BookIterator::operator!=(const BookIterator& rhs)
{
	return rhs.node != node;
}
