#include "Node.h"

#ifndef __QUEUE_H__
#define __QUEUE_H__

using namespace std;

class Queue
{
public:
	Queue();
	//Postcondition: default constructor.

	bool isEmpty();

	void enqueue(int);

	int dequeue();
	
	int size();

	void display();

private:

	Node * head;
	Node * tail;

};

#endif