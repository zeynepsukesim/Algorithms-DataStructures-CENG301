#include <iostream>
#include "busSchedule.h"
using namespace std;
int main(){
	int start, finish;
	BusNode * head =  readInput(&start, &finish);
	
	BusNode * headSchedule = scheduleBusesWeekly(head, start, finish);
	printWeeklySchedule(headSchedule, start, finish);
	addBusNode(head, "06GH041", "SAMI", "YILDIZ");
	
	listAllBus(head);
	
	deleteBusNode(head, "06AB090");
	
	listAllBus(head);
	deleteBusNode(head, "06AB097");
	listAllBus(head);
	return 0;
}