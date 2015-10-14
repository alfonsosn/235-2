#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include "Node.h"
#include "Stack.h"

using namespace std;

void fillBooks(Stack & emptyStack);
int compareRecursively(Stack & newRecords, Stack & registeredValleys);
bool valleyIsHigher(Node * currDay, Node * prevValley);
int lastValleyDiff(Node * currDay, Node * prevDay);

int main(){
	Stack newRecords, registeredValleys, results; 
	int lastValley; 

	fillBooks(newRecords);

	while(!newRecords.isEmpty()){
		lastValley = compareRecursively(newRecords, registeredValleys);
		results.push(lastValley);
	}

	// newRecords.display();

	return 0;
}

void fillBooks(Stack & emptyStack){
	// emptyStack.push(45);
	// emptyStack.push(40);
	// emptyStack.push(50);
	// emptyStack.push(70);
	// emptyStack.push(60);
	// emptyStack.push(80);
	// emptyStack.push(85);
	// emptyStack.push(75);
	// emptyStack.push(60);
	// emptyStack.push(70);
	emptyStack.push(60,  3);
	emptyStack.push(80,  2);
	emptyStack.push(100, 1);
}

int compareRecursively(Stack & newRecords, Stack & registeredValleys){
	int daysSince = 0;	 

	//base case
	if (registeredValleys.isEmpty()){
		// cout << newRecords.top()->data << " = " << newRecords.top()->index << endl;
		registeredValleys.push(newRecords.pop());
		// cout <<  registeredValleys.top()->data << endl;
	}
	
	//in case the prev valley record is higher (average case)
	else if (valleyIsHigher(newRecords.top(), registeredValleys.top())){
		daysSince = lastValleyDiff(newRecords.top(), registeredValleys.top());
		// cout << daysSince << " is the difference between " << newRecords.top()->index << " - " << registeredValleys.top()->data << endl;
		registeredValleys.push(newRecords.pop());
	}

	else if (!valleyIsHigher(newRecords.top(), registeredValleys.top())){
		compareRecursively(newRecords, registeredValleys);
	}

	return daysSince;
}

bool valleyIsHigher(Node * currDay, Node * prevValley){
	return prevValley->data > currDay->data;
}

int lastValleyDiff(Node * currDay, Node * prevDay){
	cout << currDay->data << " is currday and its index " << currDay->index << endl;
	cout << prevDay->data << " is prevDay and its index " << prevDay->index << endl;
	int toReturn = (currDay->index - prevDay->index) - 1;
	cout << "toReturn is equal to  " << toReturn << endl;
	return toReturn;
}