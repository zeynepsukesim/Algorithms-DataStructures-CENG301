#include<iostream>
using namespace std;
typedef struct BusNode {
	string number;
	string drivername;	
	string driversurname;
	BusNode *next;
} BusNode;

BusNode * readInput(int * start, int * finish){
	BusNode * head = new BusNode();
	BusNode * current = head;
	cin>>*start>>*finish;
    while(true){

		string number,name,surname;
		cin>>number>>name>>surname;
		if(number=="")
			break;

		BusNode* newBus = new BusNode();
		newBus -> number = number;
		newBus -> drivername = name;
		newBus -> driversurname = surname;

		current->next = newBus;
		current = newBus;

	}

	head = head -> next;
	
	return head;
	
}

BusNode * scheduleBusesWeekly(BusNode *head, int start, int finish){
	BusNode* headSchedule = new BusNode();

	BusNode* current = headSchedule;
	BusNode* current2 = head;


	int count = 0; 
	while(count < (finish - start + 1) * 7) {
		BusNode* scheduledBus = new BusNode();
		scheduledBus -> number = current2 -> number;
		scheduledBus -> drivername = current2 -> drivername;
		scheduledBus -> driversurname = current2 -> driversurname;

		current2 = current2 -> next;

		if(current2 == NULL) {
			current2 = head;
		}


		current -> next = scheduledBus;
		current = scheduledBus;


		count++;
	}

	headSchedule = headSchedule -> next;
	return headSchedule;
	
}
void printWeeklySchedule(BusNode *headSchedule, int start, int finish){
	string weekdays[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

	for(int i = 0; i < 7 ; i++) {
		cout << weekdays[i] << endl;
		cout << "-----------------" << endl;
		for(int j = start; j <= finish; j++){
			cout << j << ":00 " << headSchedule -> number << " " << headSchedule -> drivername << " " << headSchedule -> driversurname << endl;
		headSchedule = headSchedule -> next;

		}
	}
}

void addBusNode(BusNode * head, string number, string name, string surname){

	BusNode* addedBus = new BusNode();

	while(head -> next != NULL) {
		head = head -> next;
	}

	addedBus -> number = number;
	addedBus -> drivername =  name;
	addedBus -> driversurname = surname;

	head -> next = addedBus;

}

void deleteBusNode(BusNode * head, string number){
	BusNode* prev = NULL;
	while(head -> number != number){
		prev = head;
		head = head -> next;
	}

	if(prev==NULL){
		*head = *(head->next);
	}else{
		prev -> next = head -> next;
	}
}

void listAllBus(BusNode *head){

	while(head != NULL) {
		cout << head -> number << endl;
		head = head -> next;
	}
	cout << "\n";
}


