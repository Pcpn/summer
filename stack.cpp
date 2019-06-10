//Stacks using linkedlist..............

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
//Find the position of pointer in the linkedlist.............

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

//Stacks............

//creating class of stacks...............

class stack{
        public:
        Node * top;
        linkedlist l1;
        
       //constructor.................
       stack(){
       top = l1.head;
       
       
       
       }
//insert function at stacks................

void push(int newvalue){
    l1.insert(newvalue);
    
    top=l1.head;
    
}
//pop fuction at stacks...........
void pop(){
   if (top !=NULL){
       l1.delet();
       top=l1.head;
       
   }
   else
   {
   cout<<"There is no more element."<< endl;
   
   
     }
}

//count function in stacks..............
int count(){

 return l1.numberofItems();
 
 }
//Display function..............
void display(){
l1.display();
             }           

};







int main(){
    stack s1;
    s1.push(3);
    s1.push(4);
    s1.push(6);
    s1.push(7);
    s1.push(9);
    cout<<"The number of items in stack is: "<< s1.count()<<endl;
    s1.display();
    s1.pop();
    s1.display();
    s1.pop();
    s1.display();
    s1.pop();
    s1.display();
    s1.pop();
    s1.display();
    s1.pop();
    s1.display();
    s1.pop();
    s1.display();
   
   
    
    
    
       
    
    
    
}
