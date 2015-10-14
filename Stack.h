#include "Node.h"

#ifndef __STACK_H__
#define __STACK_H__

class Stack
{
public:

	Stack();
		//Postcondition: default constructor.
	bool isEmpty();

	void push(int);

	void push(int, int);

	int pop();

	Node * top();
	
	int size();

	void display();

private:
	int count;
	Node * head;
	Node * tail;

};

#endif