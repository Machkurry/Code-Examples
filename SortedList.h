//SortedList.h
#include<cstddef>
#include<iostream>
#include<string>

using namespace std;

struct NodeType; //forward declaration
typedef NodeType* NodePtr; //define payload type


class SortedList
{
	private:
		NodeType* dataPtr; //points to first node in list
		NodeType* currentPos; //points to anywhere on the list
		NodeType* lastPtr; //points to last node in list
		int length;	
		
	public:
		SortedList(); //default constructor
		~SortedList(); //destructor
		
		//Actions
		void Insert(NodePtr node);
		void Delete(string dName);
		void resetList();
		NodeType* getNextItem();

		
		//Info Gathering
		int GetLength() const;
		bool HasNext() const;
		bool isEmpty() const;
		bool isFull() const;
		
};
