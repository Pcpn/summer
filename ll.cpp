#include <iostream>
using namespace std;
//Creating class of Node............

class Node {
    public:
    int value;
    Node * next; 
    // constructor
    Node(int newvalue)
    {value = newvalue;
    next = NULL;}
};
//Create class of linkedlist..............

class linkedlist{
    public:
    Node * head;
//Constructor...........
    linkedlist(){
        head = NULL;
    }
    //insert function for the linkedlist.............
    
    void insert(int newvalue){
        Node * temp = new Node(newvalue);
        temp->next = head;
        head = temp;
    }

//Display function for  the linkedlist.............

    void display(){
        Node * current = head;
        while(current != NULL){
            cout << current->value << "->";
            current = current-> next;
        }
        cout << "NULL" << endl;
    }
//Conunt the numberofItems function in the linkedlsit.........

    int numberofItems(){
        // start at head
        Node * current =  head;
        int count = 0;
        while (current != NULL){
            count++;
            current = current->next;
        }
        return count;
    }
//Find the ppsition of pointer in the linkedlist.............

    Node * getPos(int pos){
        int cnt = 0;
        Node * current = head;
        while(cnt < (pos-1)){
            current = current->next; 
            cnt++;
        }
        return current;
    }
//inserAt function for the linkedlist.................

    void insertAt(int newvalue, int pos){
        // Check validity of pos.
        if(pos < 1 || (pos > (numberofItems()+1))){ 
            cout << "Not a valid position" << endl;
            return;
        }

        // Reach to pos-1
        Node * current = getPos(pos-1);
        
        //Links update
        if(pos==1) 
            insert(newvalue);
        else{
            // Create a new node
            Node *temp = new Node(newvalue);
            temp -> next = current->next;
            current -> next = temp;
        }
    }
//Delete function for the linkedlist...........

void delet(){ 
             Node*temp = head;
             head = head-> next;
             delete temp;
             }
//DeleteAt fucntion for  the linkedlist.............

void deleteAt(int pos){ 
                      Node* current  = head;
                      Node* temp = head;
                      if (pos>=1&&pos<=numberofItems())
                      { if ( pos == 1){ delet();}
                        else{ int c= 1;
                              while(c!= (pos-1)){
                                                 current = current -> next;
                                                 c++;
                                                 }
                                                 temp = current -> next ;
                                                 current -> next = (current -> next )-> next ;
                                                 delete temp;
                              }
                       } 
}  

};

int main(){
    linkedlist l1;
    for(int i = 4 ; i > 0 ; i--){
        l1.insert(i);
    }
    cout<<"1). The given linkedlist is: ";
    l1.display();
    cout << "2). NumberofItems in the given linkedlist is  : " << l1.numberofItems() << endl;

    //l1.insertAt(11,1);
    //l1.insertAt(10,2);
    cout<<"3). The position of the pointer in the linkedlist is : ";
    cout << l1.getPos(3)->value << endl;
    cout<<"4). After insertion at 1st position of the given linkedlist is :";
    l1.insertAt(11,1);
    l1.display();
    cout<<"5). Again after insertion at 2nd position of the given linkedlist is: ";
    
    l1.insertAt(10,2);
    l1.display();
    cout<<"6). After deletion at 1st postion of the given linkedlist is:";
    l1.deleteAt(1);
    l1.display();
    
}