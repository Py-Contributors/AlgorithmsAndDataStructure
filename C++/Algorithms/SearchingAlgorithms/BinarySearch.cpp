/*Title - Binary Search
It will perform binary search for the accepted element from the user.
time complexity - o(log(n))*/

#include<iostream>
using namespace std;
int binary(int start,int endd,int arr[],int no)
{
int midd=(start+endd)/2;
   if(start>=endd)
    {
        cout<<"Element not found!";
        return -1;
    }

    else if((arr[start]==no)||(arr[endd]==no)||(arr[midd]==no))
    {
        cout<<"Element found!";

        return 1;

    }
    else if(no>arr[midd])
    {

        binary(midd+1,endd,arr,no);

    }
    else
        {
          return binary(start,midd-1,arr,no);
        }

}

int main()
{
    int arr[]={10,20,30,40,50,60,70,80,90,100};
    int n=10,element;
    cout<<"Enter the element to be searched";
    cin>>element;
    binary(0,n,arr,element);

}
