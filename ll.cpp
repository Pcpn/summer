#include<iostream>
using namespace std;
int i;
//Create a class of Node.................
class Node{
       public:
      
       int value;
        Node*next;
    //Constructor..............
    Node(int newvalue){
       value = newvalue;
        next = NULL;

          }
};


//Creating class of linkedlist...............
class linkedlist{

public:
Node * head;

//constructor................
linkedlist(){
head = NULL;
}
//Insert function...................
void insert(int newvalue){
Node * temp = new Node(newvalue);
temp->next = head;
head = temp;
}

//Delete function.................
void delet(int value){
Node * temp = head;
Node * current= head;

current->next= NULL;
head=temp;

delete temp;
}


//Display function....................
 void display(){
Node * current = head;
while(current != NULL){
cout<<current->value<<"->";
current=current->next;
}
cout<<"NULL"<<endl;
}
//Count the number of items in the linked list........................
int numberofItems(){
//Start at head.............
	Node * current = head;
	int count =0;
	while(current != NULL){
	count++;
	current = current->next;
	}
	return count;

}
//Get the position function to reach a particular node.............
		Node * getPos(int pos){
		int cnt = 0;
		Node * current = head;
		while(cnt , ( pos-1)){
		current=current->next;
		cnt++;
		}
		return current;



}


//InsertAt function......................

void insertAt(int newvalue, int pos){

			//check validity of position................
			if(pos<1 || (pos> (
			numberofItems()+1))){
			cout<<"Not a valid position......"<<endl;
			return;
			}


			//reach to pos-1................
			Node * current= getPos(pos-1);


			//link update..........
			if (pos==1)
			insert(newvalue);



			else{
			//create a new node.............
			Node * temp = new Node(newvalue);
			temp->next=current->next;
			current->next=temp;
			    }
}





};











int main(){
 linkedlist l1;
 for(i=10;i>0;i--){


l1.insert(i);
}
cout<<" The order of the  linkedlist is:  ";
l1.display();
cout<<"The number of items in the linkedlist is :" << l1.numberofItems()<<endl;

//insertAt(6,2);
//insertAt(7,3);
cout<<l1.getPos(9)->value<<endl;
l1.insertAt(11,11);
l1.display();
l1.insertAt(10,1);
l1.display();
l1.delet(4);
l1.display();











return 0;
}
