#include <iostream>

#include "Queue.h"
#include "Node.h"

using namespace std;

Queue::Queue(){
	head = NULL;
	tail = NULL;
}


bool Queue::isEmpty(){
	if(head == NULL) return true;
	else             return false;
};


//for enqueue the opposite will happen
void Queue::enqueue(int num){
	Node *newNode = new Node;
	newNode->data = num;

	if(isEmpty()){
		head = newNode;
		tail = newNode;
	}
	
	else{
		newNode->next = head;
		head = newNode;
	}
}

int Queue::dequeue(){
	Node *iterator = NULL;
	int numToReturn;

	if(head == tail){
		numToReturn = head->data;
		head = tail = NULL;
	}

	else{
		numToReturn = tail->data; 
		
		iterator = head;
		while(iterator->next != tail){
			iterator = iterator->next;
		}

		tail = iterator;
	}

	return numToReturn;
}


int Queue::size(){
	int count = 0;

	if (isEmpty()) return 0;

	if (head != NULL){
		Node * iterator = head;
		int count = 1;
		
		while(iterator != tail){
			iterator = iterator->next;
			count++;
		}
		
	}

	return count;
}

void Queue::display(){
	Node * iterator = head;

	while(iterator != tail) {
		cout << iterator->data << endl;
		iterator = iterator->next;
	}
	cout << iterator->data << endl;
}



