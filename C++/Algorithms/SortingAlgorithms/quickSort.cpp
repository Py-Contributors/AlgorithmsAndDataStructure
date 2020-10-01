#include<bits/stdc++.h>
using namespace std;
#define MAX 100000

void swap(int* a,int* b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
int partition(int arr[],int low,int high)
{
    int pivot=arr[high];
    int i=(low-1);
    for(int j=low;j<=high;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return (i+1);
}
void quicksort(int arr[],int low,int high)
{
    if (low<high)
    {
        int pi=partition(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}
void printArray(int arr[],int size)
{
    cout<<"\n";
    
    cout<<endl;
}
int main()
{	
	int n,num,x;
	int arr[MAX];
	cout<<"Enter the number of elements in the array : ";
	cin>>n;
	cout<<"Enter the elements : ";
	for(int i=0;i<n;i++)
    	{
        	cin>>num;
        	arr[i]=num;
    	}
 	quicksort(arr,0,n-1);
    	cout<<"Array after sorting: ";
    	for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    	return 0;
}