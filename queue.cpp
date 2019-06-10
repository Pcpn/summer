// queue using linkedlist..............




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
   //getTail function in the linkedlist.....................
   
   Node * getTail(){
              int cnt = 0;
              Node * current = head;
              while(cnt != numberofItems()){
                 
                    current= current-> next;
                    cnt++;
                    }
   return current;
   
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


//Queue.........


//queue function ...................




class queue{
      public:
      Node * front;
      Node * end;
      linkedlist l1;
      
      //constructor.................
      queue(){
         front = l1.head;
         end = l1.getTail();
         
      
      
      }
//count function for queue................

int count(){
 return l1.numberofItems();
 }
 
 //Display function for queue...........
 void display(){
             l1.display();
             }
             
 //enqueue function for queue.............
 
 void enqueue (int newvalue){
 
             l1.insert(newvalue);
             front = l1.head;
             }
             
//dequeue function for queue....................

void dequeue(){
        if (front != NULL){
                           l1.deleteAt(count());
                           front = l1.head;
                           end = l1.getTail();
                           }
                           
               else{
               cout<<"no more elements to dequeue"<<endl;
               }
      }
};





int main(){
    
   
    queue q1;
           q1.enqueue(0);
           q1.enqueue(7);
           q1.enqueue(9);
           q1.enqueue(8);
           q1.enqueue(3);
           q1.display();
           cout << " number of items " << q1.count() << endl;
           q1.dequeue();
           q1.display();
           q1.dequeue();
	   q1.display();
           q1.dequeue();
           q1.display();
           q1.dequeue();
           q1.display();
           q1.dequeue();
           q1.display();
           cout << " number of items " << q1.count() << endl;
                      
    
    
    
    
       
    
    
    
}
