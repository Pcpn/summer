//Write the quicksort in increasing  order of any random linkedlist..............
#include<iostream>
using namespace std;



//Sorting element using middle index as pivot............
void quicksort(int *arr, int left, int right){

	int i = left;
	int j = right;
	int temp;
	int pivot = arr[(left + right) / 2];


//Begin the loop for the the quicksort..........
while(i<=j){
     //For the left hand side(smaller value)..........
      while (arr[i] < pivot)
       i++;

	//For the right hand side (bigger value)
	while(arr[j] > pivot)
	j--;

//Begins the swap...............
if(i <= j){
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    i++;
    j--;
 
    }
//end of if................

	}
//end of while .................


//Check if we need to keep sorting to left side.........

if(left < j)
        quicksort(arr, left, j);

//check if we need to keep sorting the right side..................

if(i<right)
        quicksort(arr, i, right);

}
//End of the quicksort.............



int main(){

int list[] = {9, 3, 8, 1, 6, 5, 0, 2, 7, 4  };

cout<<"The unsorted list  : ";

for(int i = 0; i < sizeof(list)/4; i++)
cout<< list[i] <<" ";
cout<<endl;

quicksort(list, 0, sizeof(list) /4 - 1);

cout<<"The sorted list: ";
for(int i = 0; i < sizeof(list) / 4; i++)
cout<< list[i] <<" ";
cout<<endl;



	return 0;
}
