#include <iostream>

using namespace std;

struct node
{
	node *next;
	node *prev;
	int data;
};

class DLinkedList{
public: 
	DLinkedList(int* arr, int arrSize);
	void addToHead(int data);
	void printFromHead();
	void printFromTail();
private: 
	node *head = new node;
	node *tail = new node;
};

DLinkedList::DLinkedList(int *arr, int arrSize){
	head->prev = tail;
	tail->next = head; 
	tail->prev = nullptr;
	head->next = nullptr;
	for(int i = 0; i <= arrSize-1; i++){
		addToHead(*(arr+i));

	}
}
void DLinkedList::addToHead(int data){
	//adds a node to head
	//does not account for no items being in head or tail
	//leaves 2 0 vals
	node *tmp = new node;
	tmp->data = data;
	tmp->prev = head;
	tmp->next = nullptr;
	tmp->prev->next = tmp;
	//cout << "data: " << data << " tmp data:  " << tmp->data << " tmp->next:  " << tmp->next << " tmp->prev data:  " << tmp->prev->data << endl;
	head = tmp;
	//cout << "data: " << data << " head data: " << head->data << " head->next: " << head->next << " head->prev data: " << head->prev->data << endl;

}

void DLinkedList::printFromHead(){
	node *tmp = new node;
	tmp = head;
	while(tmp->prev->prev != nullptr){
		cout << tmp->data << endl;
		tmp = tmp->prev;
	}
}

void DLinkedList::printFromTail(){
	node *tmp = new node;
	tmp = tail->next;
	while(tmp->next != nullptr){
		cout << tmp->data << endl;
		tmp = tmp->next;
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	int data[] = {9,3,6,2,6,8,2,4,8};
	int size = sizeof(data)/sizeof(int);
	DLinkedList *dll = new DLinkedList(data, size);
	dll->printFromTail();
	return 0;
}