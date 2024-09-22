#include <string>
using namespace std;
class Person{
	private:
		string name;
		int privilege;
		Person * next;
	public:
		Person(){
			this->name = "";
			this->privilege = 0;
			this->next = NULL;
		}
		Person(string name){
			this->name = name;
			this->privilege = 0;
			this->next = NULL;
		}
		Person(string name, int privilege){
			this->name = name;
			this->privilege = privilege;
			this->next = NULL;
		}
		void setName(string name){
			this->name= name;
		}
		void setPrivilege(int privilege){
			this->privilege= privilege;
		}
		void setNextPerson(Person * next){
			this->next = next;
		}
		string getName(){
			return this->name;
		}
		int getPrivilege(){
			return this->privilege;
		}
		Person * getNextPerson(){
			return this->next;
		}

	
};