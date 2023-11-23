#include<iostream>
using namespace std;

struct Task{
	int id;
	string title;
	string desc;
	string dueDate;
//  add string category/priority // so that we can search 
	Task* next;
	Task* prev;
};

class TaskScheduler{
	private:
		Task* head;
		
	public:
         TaskScheduler(){
		this->head = NULL;
		 // Here add this.tail=null
	}

    // function to add at first position
    void addTask(int id, string title, string desc, string dueDate){
    Task* task = new Task{id, title, desc, dueDate};   
    task->next = head;
    task->prev = NULL; 

    if(head != NULL){
        head->prev = task;
    }
    head = task; 
}


    // function to display the list
    void displayTasks(){
        Task* temp = head;
        while(temp != NULL){
            cout<<"ID: "<<temp->id<<endl;
            cout<<"Title: "<<temp->title<<endl;
            cout<<"Description: "<<temp->desc<<endl;
            cout<<"Due Date: "<<temp->dueDate<<endl;
        	cout<<" "<<endl;
            temp = temp->next;
        }
    }
};
// Make a functions:
//  that will automatically sort our DOUBLY linked list according to priority etc.
//  that search the Task by by Date (near to far), by priority set by him ( at the start ) .
//  that search by Category i.e fitness category will give all the tasks related to fitness ( we can search by string category/priority already defined in Task Node Stucture.
// that enables user to edit the task first user will search task by name ( added already ) then update it ,Updated Node will go in the Place of which user wants to change.
int main(){
	// add a while loop that is always true and also it will display some list first of all as soon as user enters the app he should get the menu to enter his priority so that we can sort our linkedlist accordingly
	TaskScheduler list;
    int choice, id;
    string title, desc, dueDate;
    cout<<"*********Welcome to Task Scheduler*********"<<endl;
   do {
        cout<<"\n<----Our Menu Card---->\n";
        cout<<"1. Add a task\n";
        cout<<"2. Display the tasks\n";
        cout<<"0. Exit\n";
        cout<<"Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout<<"Enter ID: ";
            cin>>id;
            cout<<"Enter Title: ";
            cin>>title;
            cout<<"Enter Description: ";
            cin>>desc;
            cout<<"Enter Due Date: ";
            cin>>dueDate;
            list.addTask(id, title, desc, dueDate);
            break;

        case 2:
            cout << "\nDisplaying all tasks..."<<endl;
            list.displayTasks();
            break;

        case 3:
             cout<<"Exiting the program"<<endl;
            break;

        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 0);

    return 0;
}
