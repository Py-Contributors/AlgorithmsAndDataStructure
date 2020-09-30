  
/*Title - Insertion Sort
It will perform sorting operation on an array
time complexity - O(n^2)*/
#include<iostream>
using namespace std;
void insertsort(int ele[],int size)
{
    int value,hole;
    for(int i=1;i<size;i++)
    {
        value=ele[i];
        hole=i;
        while((hole>0)&&(ele[hole-1]>value))
        {
            ele[hole]=ele[hole-1];
            hole=hole-1;
        }
      ele[hole]=value;  

    }
}
void display(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int arr[]={10,4,2,8,9,1,6,7,3,5};
    insertsort(arr,10);
    display(arr,10);



}