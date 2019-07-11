#include "LinkedList.h"

LinkedList::LinkedList()
{
	front = nullptr;
}

LinkedList::~LinkedList()
{
	while (front != nullptr)
	{
		Node* cur = front;
		front = front->getNext();
		delete cur;
	}
	front = nullptr;
}

LinkedList::LinkedList(const LinkedList& orig)
{
	front = nullptr;

	if (orig.front != nullptr)
	{
		front = orig.front->deepCopy();
	}

	size = orig.size;
}

LinkedList& LinkedList::operator=(LinkedList& copy)
{
	if (this != &copy)
	{
		while (front != nullptr)
		{
			Node* cur = front;
			front = front->getNext();
			delete cur;
		}
		front = nullptr;

		if (copy.front != nullptr)
		{
			front = copy.front->deepCopy();
		}

		size = copy.size;
	}

	return *this;
}

void LinkedList::addNode(Book& data, Node*& previous)
{
	if (previous == nullptr)
	{
		front = new Node(data, front);
		size++;
		return;
	}

	Node* node = new Node(data, previous->getNext());
	previous->getNext() = node;
	size++;
}

void LinkedList::removeNode(Node*& node, Node*& previous)
{
	if (previous == nullptr)
	{
		front = node->getNext();
	}
	else
	{
		previous->getNext() = node->getNext();
	}

	delete node;
	size--;
}

unsigned int LinkedList::getSize()
{
	return size;
}

BookIterator LinkedList::begin()
{
	return BookIterator(front);
}

BookIterator LinkedList::end()
{
	return BookIterator();
}

void LinkedList::addElement(Book& element)
{
	Node* prev = nullptr;
	Node* cur = front;

	if (size == 0)
	{
		addNode(element, prev);
		return;
	}

	while (cur != nullptr)
	{
		if (cur->getData().compareTo(element) < 0)
		{
			addNode(element, prev);
			return;
		}

		prev = cur;
		cur = cur->getNext();
	}

	addNode(element, prev);
}

bool LinkedList::containsElement(string& title)
{
	Node* temp = front;

	while (temp != nullptr)
	{
		if (title == temp->getData().getTitle())
		{
			return true;
		}

		temp = temp->getNext();
	}

	return false;
}

Book& LinkedList::getElement(string& title)
{
	Node* temp = front;

	while (temp != nullptr)
	{
		if (title == temp->getData().getTitle())
		{
			return temp->getData();
		}

		temp = temp->getNext();
	}

	return temp->getData();
}

Book& LinkedList::getElement(unsigned int index)
{
	Node* node = front;

	for (unsigned int i = 0; i < index; i++)
	{
		node = node->getNext();
	}

	return node->getData();
}

Book LinkedList::removeElement(string& title)
{
	Node* prev = nullptr;
	Node* cur = front;

	while (cur != nullptr)
	{
		if (title == cur->getData().getTitle())
		{
			Book data = cur->getData();
			removeNode(cur, prev);

			return data;
		}

		prev = cur;
		cur = cur->getNext();
	}

	return cur->getData();
}
