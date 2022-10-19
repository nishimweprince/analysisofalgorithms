#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;

struct node { 
  int data; 
  node *next; 
};

class LinkedList
{
    // Head and Tail pointers
    node* head;
    node* tail;

  public:
    // default constructor. Initializing head pointer
    LinkedList()
    {
      head = NULL;
      tail = NULL;
    }
    
    // Parameterized constructor
    LinkedList(int size, LinkedList &li){
    	
    	srand(time(0));
    	
    	for (int i=0; i < size; i++){
    	li.insert_start(rand() % 100);
		}
	}
	
	// Operator overloading
	void operator = (const LinkedList &li){
		this->head = li.head;
		this->tail = tail;
	}
    
    //Linked list destructor
    ~LinkedList(){
	node *current = new node;
	current = head;
	
	while(current != NULL){
		delete current;
		current = current->next;
	}
};
    
    
    //Inserting at the start of the list
    void insert_start(int val) {
      node* temp = new node();
      temp->data = val;
      temp->next = head;
      head = temp;
    }
    
    void insert_end(int value){
    	{
      node *temp=new node;
      temp->data=value;
      temp->next=NULL;
      if(head==NULL)
      {
        head=temp;
        tail=temp;
        temp=NULL;
      }
      else
      {
      	node *last = head;
      	while(last->next != NULL){
        last = last->next;
      }
        last->next=temp;
  }
	}
}

    // Search function, loop over function and return true if the value is found
    bool search(int val)
    {
    node* current = head; // Initialize current
    while (current->next != NULL) {
        if (current->data == val){
        cout<<"Value " << val << " is indeed available in the list!"<<endl;
        return true;
        cout<<endl;
    
	}


	return false;
	cout<<"Value "<<val<<" is not available in this list"<<endl;}

}


        void deleteValue(int val)
    {
      // If the head is to be deleted
      if (head->data == val)
      {
        delete head;
        head = head->next;
        return;
      }

      // If there is only one element in the list
      if (head->next == NULL)
      {
        // If the head is to be deleted. Assign null to the head
        if (head->data == val)
        {
          delete head;
          head = NULL;
          return;
        }
        // else print, value not found
        cout << "Value not available!" << endl;
        return;
      }

      // Else loop over the list and search for the node to delete
      node* temp = head;
      while(temp->next!= NULL)
      {
        // When node is found, delete the node and modify the pointers
        if (temp->next->data == val)
        {
          node* temp_ptr = temp->next->next;
          delete temp->next;
          temp->next = temp_ptr;
          return;
        }
        temp = temp->next;
      }

      // Else, the value was neve in the list
      cout << "Value not available" << endl;
    }
    
    //List elements of the singly linked list
        void display()
{
	node* temp = head;

	// Check for empty list.
	if (head == NULL) {
		cout << "List empty" << endl;
		return;
	}

	// Traverse the list.
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout<<endl<<endl;
}

    /* Function to reverse the linked list */
    void reverseList()
    {
        // Initialize current, previous and next pointers
        node* current = head;
        node *prev = NULL, *next = NULL;
 
        while (current != NULL) {
            // Store next
            next = current->next;
            // Reverse current node's pointer
            current->next = prev;
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
    }
    
    //removeDuplicate() will remove duplicate nodes from the list  
void removeDuplicate() {  
    //Node current will point to head  
    struct node *current = head, *index = NULL, *temp = NULL;  
      
    if(head == NULL) {  
        return;  
    }  
    else {  
        while(current != NULL){  
            //Node temp will point to previous node to index.  
            temp = current;  
            //Index will point to node next to current  
            index = current->next;  
              
            while(index != NULL) {  
                //If current node's data is equal to index node's data  
                if(current->data == index->data) {  
                    //Here, index node is pointing to the node which is duplicate of current node  
                    //Skips the duplicate node by pointing to next node  
                    temp->next = index->next;  
                }  
                else {  
                    //Temp will point to previous node of index.  
                    temp = index;  
                }  
                index = index->next;  
            }  
            current = current->next;  
        }          
    }  
}

};


int main(){
	LinkedList list;
	int val_size, val_start, val_end, val_search, val_delete;
	
	cout<<"This is the start of a set of operations aimed at implementing and manipulating a singly linked list in C++"<<endl<<endl;
	cout<<"Please enter the size (in number value) of your desired linked list: ";
	cin>>val_size;
	
	LinkedList(val_size, list);
	cout<<"Initial list: ";
	list.display();
	
	
	cout<<"We begin to manipulate our linkedlist!"<<endl<<endl;
	
	cout<<"First, we'll start by inserting an element at the start of our linked list. Enter any number of your choice: ";
	cin>>val_start;
	list.insert_start(val_start);
	cout<<"Linked list after inserting "<<val_start<<" at the start!: ";
	list.display();
	
	cout<<"Enter a value to insert at the end of our list: ";
	cin>>val_end;
	list.insert_end(val_end);
	cout<<endl<<"Our updated list: ";
	list.display();
	
	cout<<"Next up, we are going to search for a value! Enter a value to check if it is available in our list: ";
	cin>>val_search;
	list.search(val_search);
	list.display();
	
	cout<<"Enter a value you want to delete from the list: ";
	cin>>val_delete;
	list.deleteValue(val_delete);
	list.display();
	
	cout<<"If you noticed any consecutive duplicate values, we have removed them to get this updated list: ";
	list.removeDuplicate();
	list.display();
	
	cout<<"Lastly, we are going to reverse the list! This is a reversal of the latest list we had: ";
	list.reverseList();
	list.display();
	
	return 0;
}
