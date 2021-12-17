#pragma once
#include <iostream>

using namespace std;

class Node1
{
private:
	string data;
	Node1* next;

public:
	Node1(string initdata)
	{
		data = initdata;
		next = NULL;
	}

	string getData()
	{
		return data;
	}

	Node1* getNext() { return next; }

	void SetData(string newData)
	{
		data = newData;
	}

	void setNext(Node1* newnext) { next = newnext; }

};

class Stack
{
	private:
	Node1* head;

public:
	Stack();
	~Stack();

	bool isEmpty();  //Checking for emptiness
	int size();  //Output stack size
	void push_back(string);  //Adding to the end
	void pop_back(); //Removing the end
	string top();  //top output
	void add(string);  //add an element
	void write();  //Output stack
	void replacement(string);  //replacing an element
	void clear(); //clearing the stack
};


#pragma region function
Stack::Stack()
{
	head = NULL;
}

Stack::~Stack()
{
	while (head != NULL)
	{
		Node1* next = head->getNext();
		delete head;
		head = next;
	}
}

bool Stack::isEmpty() { return head == NULL; }

int Stack::size()
{
	Node1* current = head;
	int count = 0;

	while (current != NULL)
	{
		count++;
		current = current->getNext();
	}

	return count;
}

void Stack::push_back(string item)
{
	Node1* current = head;
	while (current->getNext() != NULL)
	{
		current = current->getNext();
	}

	Node1* temp = new Node1(item);
	current->setNext(temp);
	current = temp;
}

void Stack::pop_back()
{
	Node1* current = head;
	Node1* previous = NULL;
	while (current->getNext() != NULL)
	{
		previous = current;
		current = current->getNext();
	}
	previous->setNext(current->getNext());
}

string Stack::top()
{
	Node1* current = head;
	while (current->getNext() != NULL)
	{
		current = current->getNext();
	}

	return current->getData();
}

void Stack::add(string item)
{
	Node1* temp = new Node1(item);
	temp->setNext(head);
	head = temp;
}

void Stack::write()
{
	ofstream protocol_out("protocol.txt", ios::out | ios::app);
	Node1* current = head;
	while (current != NULL)
	{
		cout << current->getData() << "; ";
		protocol_out << current->getData();
		current = current->getNext();
	}
}

void Stack::replacement(string item)
{
	Node1* temp = new Node1(item);
	head = temp;
}

void Stack::clear()
{
	Node1* current = head;
	while (current->getNext() != NULL)
	{
		head = current->getNext();
		current = current->getNext();
	}
	head = NULL;
}
#pragma endregion