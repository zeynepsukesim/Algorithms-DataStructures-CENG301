#include <iostream>
#include "person.h"
using namespace std;


typedef struct Node{
	Person person;
	Node* next;
} Node;

class Stack{
private:
	Person* topPerson = NULL;
	Node* head = NULL;
public:
	//Return the top of stack
	Person* top(){
		return topPerson;
	}
	//Return whether stack is empty or not(true/false)
	bool empty(){
		if(topPerson == NULL) {
			return true;	
		}

		else {
			return false;
		}
	}
	//Inserts the person to the stack
	void push(Person* p){
		Node* current = head;
		if(current == NULL){
			current = new Node();
			current -> person = *p;
			head = current;
		}
		else {
			while(current -> next != NULL){
				current = current -> next;
			}
			current -> next = new Node();
			current -> next -> person = *p;
		}
		topPerson = p;		
	}
	//Exctracts the topPerson and assign the next element as topPerson
	void pop(){
		Node* prev = NULL;
		Node* current = head;

		while(current -> next != NULL) {
			prev = current;
			current = current -> next;
		}
		if(prev != NULL){
		prev -> next = NULL;
		topPerson = &(prev -> person);
		}
		else {
			head = NULL;
			topPerson = NULL;
		}
	}
	// Displays the person(s) in stack
	void display(){
		Node* current = head;
		while(current != NULL) {
			cout << current -> person.getName() << endl;
			current = current->next;
		}
	}

};





