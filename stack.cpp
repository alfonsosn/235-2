#include <iostream>
#include "Stack.h"
#include "Node.h"

using namespace std;

Stack::Stack(){
	count = 0;
	head = NULL;
	tail = NULL;
}

// Stack::Stack();

bool Stack::isEmpty(){
	if(head == NULL) return true;
	else             return false;
};


//for push nothing major will change from add
void Stack::push(int num){
	Node* newNode = new Node();
	newNode->data = num;
	count++;

	if(isEmpty()){
		head = tail = newNode;
		head->next = tail;
	}

	else{
		tail->next = newNode;
		tail = newNode;
	}
}

void Stack::push(int num, int dayIndex){
	Node* newNode = new Node();
	newNode->data = num;
	newNode->index = dayIndex;
	count++;

	if(isEmpty()){
		head = tail = newNode;
		head->next = tail;
	}

	else{
		tail->next = newNode;
		tail = newNode;
	}
}


//pop 
int Stack::pop(){
	Node *iterator = NULL;
	int nodeToReturn = 0;

	if(head == tail){
		nodeToReturn = head->data;
		head = tail = NULL;
	}

	else{
		nodeToReturn = tail->data; 
		iterator = head;

		while(iterator->next != tail){
			iterator = iterator->next;
		}

		tail = iterator;
	}

	count--;
	return nodeToReturn;
}

Node * Stack::top(){
	Node * copy = tail;
	return copy;
}

int Stack::size(){
	return count;
}

void Stack::display(){
	Node * iterator = head;
	while(iterator != NULL){
		cout << iterator->data << endl;
		iterator = iterator->next;
	}

}

