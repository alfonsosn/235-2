#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include "Queue.h"
#include "Stack.h"

using namespace std;

int main(){

	Stack stack;
	Queue queue;

	for (int i = 0; i < 10; i++){
		queue.enqueue(i);
	}

	cout << "Queue before: " << endl;

	queue.display();

	while(!queue.isEmpty()){
		stack.push(queue.dequeue());
	}

	cout << "Queue after: " << endl;

	while(!stack.isEmpty()){
		queue.enqueue(stack.pop());
	}

	queue.display();

	return 0;
}

