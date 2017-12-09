//SortedList.cpp
#include"SortedList.h"
using namespace std;
	
typedef NodeType* NodePtr;
struct NodeType
{
	string name;
	int strength;
	int dexterity;
	int charisma;
	int magic;
	NodePtr link; //pointer for next
};

SortedList::SortedList()
{
	length = 0;
	dataPtr = NULL;
	currentPos = NULL;
	lastPtr = NULL;
}

SortedList::~SortedList()
{
	NodePtr tempPtr;
	NodePtr currPtr = dataPtr;
	
	while(currPtr != NULL)
	{
		tempPtr = currPtr;
		currPtr = currPtr -> link;
		delete tempPtr;
	}
}

void SortedList::Insert(NodePtr node)
{
	NodePtr currPtr;
	NodePtr prevPtr;
	NodePtr newNodePtr;

	newNodePtr = node;

	if (dataPtr == NULL)
	{
		newNodePtr->link = NULL;
		dataPtr = newNodePtr;
		lastPtr = newNodePtr;
	}
	else
	{
		currPtr = dataPtr;
		prevPtr = NULL;

		while (currPtr != NULL && currPtr->name < node->name)
		{
			prevPtr = currPtr;
			currPtr = currPtr->link;
		}

		newNodePtr->link = currPtr;
		if (prevPtr == NULL)
			dataPtr = newNodePtr;
		else
			prevPtr->link = newNodePtr;
		if (currPtr == NULL)
			lastPtr = newNodePtr;
	}
	length++;
}


void SortedList::Delete(string dName)
{
	NodePtr previousPtr = NULL;
	NodePtr currentPtr = dataPtr;
	
	while(currentPtr != NULL && currentPtr -> name != dName && currentPtr -> name < dName)
	{
		previousPtr = currentPtr;
		currentPtr = currentPtr -> link;
	}
	if(currentPtr != NULL && currentPtr -> name == dName)
	{
		if(currentPtr == dataPtr)
			dataPtr = currentPtr -> link;
		else
			previousPtr -> link = currentPtr -> link;
			
		if(currentPtr == lastPtr)
			lastPtr = previousPtr;
		length--;
	}
}

void SortedList::resetList()
{
	currentPos = dataPtr;
}

NodeType* SortedList::getNextItem()
{
	NodeType * node = currentPos;
	currentPos = currentPos -> link;
	return node;
}

int SortedList::GetLength() const
{
	return length;
}

bool SortedList::HasNext() const
{
	return (currentPos != NULL);
}

bool SortedList::isEmpty() const
{
	return (dataPtr == NULL);
}

bool SortedList::isFull() const
{
	return false;
}
