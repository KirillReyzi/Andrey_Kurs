#pragma once
#include <iostream>

using namespace std;

class Node2
{
private:
	int data;
	Node2* next;

public:
	Node2(int initdata)
	{
		data = initdata;
		next = NULL;
	}

	int getData()
	{
		return data;
	}

	Node2* getNext() { return next; }

	void SetData(int newData)
	{
		data = newData;
	}

	void setNext(Node2* newnext) { next = newnext; }

};

class Stack_int
{
private:
	Node2* head;

public:
	Stack_int();
	~Stack_int();
	
	bool isEmpty();  //Checking for emptiness
	int size();  //Output Stack_int size
	void push_back(int);  //Adding to the end
	void pop_back(); //Removing the end
	int top();  //top output
	void add(int);  //add an element
	void write();  //Output Stack_int
	void replacement(int);  //replacing an element
	void clear(); //clearing the Stack_int
	void output_result(); //Output result Stack_int
};


#pragma region function
Stack_int::Stack_int()
{
	head = NULL;
}

Stack_int::~Stack_int()
{
	while (head != NULL)
	{
		Node2* next = head->getNext();
		delete head;
		head = next;
	}
}

bool Stack_int::isEmpty() { return head == NULL; }

int Stack_int::size()
{
	Node2* current = head;
	int count = 0;

	while (current != NULL)
	{
		count++;
		current = current->getNext();
	}

	return count;
}

void Stack_int::push_back(int item)
{
	Node2* current = head;
	while (current->getNext() != NULL)
	{
		current = current->getNext();
	}

	Node2* temp = new Node2(item);
	current->setNext(temp);
	current = temp;
}

void Stack_int::pop_back()
{
	Node2* current = head;
	Node2* previous = NULL;
	while (current->getNext() != NULL)
	{
		previous = current;
		current = current->getNext();
	}
	previous->setNext(current->getNext());
}

int Stack_int::top()
{
	Node2* current = head;
	while (current->getNext() != NULL)
	{
		current = current->getNext();
	}

	return current->getData();
}

void Stack_int::add(int item)
{
	Node2* temp = new Node2(item);
	temp->setNext(head);
	head = temp;
}

void Stack_int::write()
{
	ofstream protocol_out("protocol.txt", ios::out | ios::app);
	Node2* current = head;
	while (current != NULL)
	{
		cout << current->getData() << "; ";
		protocol_out << current->getData();
		current = current->getNext();
	}
}

void Stack_int::replacement(int item)
{
	Node2* temp = new Node2(item);
	head = temp;
}

void Stack_int::clear()
{
	Node2* current = head;
	while (current->getNext() != NULL)
	{
		head = current->getNext();
		current = current->getNext();
	}
	head = NULL;
}

void Stack_int::output_result()
{
	ofstream result("result.txt", ios::out | ios::app);
	Node2* current = head;

	result << "\nThe expression is equal to:" << endl;
	while (current != NULL)
	{
		result << current->getData();
		current = current->getNext();
	}
}
#pragma endregion