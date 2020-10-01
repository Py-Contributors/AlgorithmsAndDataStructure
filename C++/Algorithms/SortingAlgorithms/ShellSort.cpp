/*
Short Introduction:-
Shell sort is a highly efficient sorting algorithm and is based on insertion sort algorithm.
This algorithm avoids large shifts as in case of insertion sort, if the smaller value is to the far right 
and has to be moved to the far left.This algorithm uses insertion sort on a widely spread elements, first to sort 
them and then sorts the less widely spaced elements. This spacing is termed as interval.

Complexities:-
Worst case time complexity = O(n2)
Best case complexity = O(nlog(n)).
Space complexity = O(1).
*/


#include<iostream>
using namespace std;
/*Method to sort the list/array*/
void shellSort(int sort[],int size){
    for(int gap=size/2;gap>0;gap/=2){
        for(int i=gap;i<size;i++){
            int temp=sort[i];
            int j;
            for(j=i;j>=gap&&sort[j-gap]>temp;j-=gap){
                sort[j]=sort[j-gap];
            }
            sort[j]=temp;
        }
    }
}
//main program
int main(){
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int sort[size];
    cout<<"Enter the Elements to be sorted:";
    for(int i=0;i<size;i++){
        cin>>sort[i];
    }
    shellSort(sort,size);
    cout<<"Array after sorting is: ";
    for(int i=0;i<size;i++){
        cout<<sort[i]<<" ";
    }
    cout<<endl;
    return 0;
}
/*       Output
Enter the size of the array: 5                                                                                                                
9 5 8 1 4                                                                                                                                                                                                                                                                                      
Array after sorting is: 1 4 5 8 9         
*/
