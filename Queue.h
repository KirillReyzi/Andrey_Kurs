#pragma once
#include <iostream>

using namespace std;

class Node
{
private:
	string data;
	Node* next;
	bool minus;

public:
	Node(string initdata, bool key)
	{
		data = initdata;
		next = NULL;
		minus = key;
	}

	string getData()
	{
		return data;
	}

	bool setMinus() { return minus; }

	Node* getNext() { return next; }

	void SetData(string newData)
	{
		data = newData;
	}

	void setNext(Node* newnext) { next = newnext; }

};

class Queue
{
private:
	Node* head;

public:
	Queue();
	~Queue();

	bool isEmpty();  //Checking for emptiness
	int size();  //Output queue size
	void push_back(string, bool);  //Adding to the end
	void pop_back();  //Removing the end
	string top();  //top output
	void add(string, bool);  //add an element
	void write();  //Output queue
	string output(int);  //Output by index
	void output_result();  //Output result queue
	bool check_minus();
};

//function
#pragma region function
Queue::Queue()
{
	head = NULL;
}

Queue::~Queue()
{
	while (head != NULL)
	{
		Node* next = head->getNext();
		delete head;
		head = next;
	}
}

bool Queue::isEmpty() { return head == NULL; }

int Queue::size()
{
	Node* current = head;
	int count = 0;

	while (current != NULL)
	{
		count++;
		current = current->getNext();
	}

	return count;
}

void Queue::push_back(string item, bool key)
{
	Node* current = head;
	while (current->getNext() != NULL)
	{
		current = current->getNext();
	}

	Node* temp = new Node(item, key);
	current->setNext(temp);
	current = temp;
}

void Queue::pop_back()
{
	Node* current = head;
	Node* previous = NULL;
	while (current->getNext() != NULL)
	{
		previous = current;
		current = current->getNext();
	}
	previous->setNext(current->getNext());
}

string Queue::top()
{
	Node* current = head;
	while (current->getNext() != NULL)
	{
		current = current->getNext();
	}

	return current->getData();
}

void Queue::add(string item, bool key)
{
	Node* temp = new Node(item, key);
	temp->setNext(head);
	head = temp;
}

void Queue::write()
{
	ofstream protocol_out("protocol.txt", ios::out | ios::app);
	Node* current = head;
	while (current != NULL)
	{
		cout << current->getData();
		protocol_out << current->getData();
		current = current->getNext();
	}
}

string Queue::output(int index)
{
	Node* current = head;
	int i = 0;
	while (i != index)
	{
		current = current->getNext();
		i++;
	}
	return current->getData();
}

void Queue::output_result()
{
	ofstream result("result.txt", ios::out | ios::app);
	Node* current = head;

	result << "Expression in postfix form" << endl;
	while (current != NULL)
	{
		result << current->getData();
		current = current->getNext();
	}
}

bool Queue::check_minus()
{
	Node* current = head;
	while (current->getNext() != NULL)
	{
		current = current->getNext();
	}

	return current->setMinus();
}
#pragma endregion