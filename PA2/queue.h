//Cpp program to implement Queue using stacks (NO other data structure is allowed)
#include <string>
#include <bits/stdc++.h>
#include "stack.h"
using namespace std;

class Queue {
private:
	Stack s1, s2;
public:
	//Enqueu a person to the queue according to his/her privilege
	void enQueue(Person* p){

		while(s1.top() && p -> getPrivilege() < s1.top() -> getPrivilege()) {
			Person* elem = s1.top(); 
			s1.pop();
			s2.push(elem);
		}

		s1.push(p);


		while(s2.empty() == false){
			Person* elem2 = s2.top();
			s2.pop();
			s1.push(elem2);
		}

	}
	//Dequeue a person from the queue
	Person* deQueue(){
		Person* elem3 = s1.top();
		s1.pop();
		return elem3;
	}
	//Display Queue
	void display(){

		while(s1.empty() == false){
			cout << s1.top() -> getName() << " ";
			Person* elem4 = s1.top();
			s1.pop();
			s2.push(elem4);
		}
		cout << endl;

		while(s2.empty() == false){
			Person* elem5 = s2.top();
			s2.pop();
			s1.push(elem5);
		}
	}
};


