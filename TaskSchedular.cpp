#include<iostream>
using namespace std;

struct Task{
	int id;
	string title;
	string desc;
	string dueDate;
	Task* next;
	Task* prev;
};

class TaskScheduler{
	private:
		Task* head;
		
	public:
         TaskScheduler(){
		this->head = NULL;
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

int main(){
	TaskScheduler list;
    list.addTask(1 ,"Quiz", "Task 1", "12/12/2020");
    list.addTask(2, "Project Work" ,"Task 2", "11/01/2022");

    cout<<"Tasks in the scheduler:"<<endl;
    list.displayTasks();
}