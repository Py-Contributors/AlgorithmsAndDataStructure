/*
finding the element ele using exponential search
*/

#include <bits/stdc++.h>
using namespace std;

int binary_search(int arr[], int, int, int);

//exponential search - returns the position of first occurrence of ele in array
int exponential_search(int arr[], int size, int ele)
{

    //If ele is present at arr[0]
    if (arr[0] == ele)
        return 0;

    //loop for finding the range
    //binary search to find the ele
    int i = 1;
    for (; i < size && arr[i] <= ele; i = i * 2){}

    //binary search to find the search ele within the array range
    return binary_search(arr, i / 2, min(i, size), ele);
}

//Recursive binary search -  returns the location of the search ele
int binary_search(int arr[], int left, int right, int ele)
{
    if (right >= left)
    {

        //middle element location in the array
        int middle = left + (right - left) / 2;

        //If the ele is present at the arr[middle] location
        if (arr[middle] == ele)
            return middle;

        //If the ele is smaller the middle element than
        //the ele is present in left subarray
        if (arr[middle] > ele)
        {
            return binary_search(arr, left, middle - 1, ele);

            //ele present in right subarray
            return binary_search(arr, middle + 1, right, ele);
        }
    }

    //If the search element is not present the array
    return -1;
}

//starting point
int main(void)
{
    //variables declaration
    int size, i, ele;
    int * arr;

    //asking for no.of elements to be added 
    cout<<"How many numbers you would like to add? "<<"\n";
    cin>>size;
    
    try
    {
        arr = new int[size];
        if(arr == nullptr){
            cout << "Error: memory could not be allocated";
            throw 505;
        }
        else{
            cout<<"Enter the numbers: "<<"\n";
            for(i=0; i < size; i++){
                cin>>arr[i];
            }
        }
        cout<<"Enter the element to be search?"<<"\n";
        cin>>ele;
        int result = exponential_search(arr, size, ele);

        //displaying the result whether the element is present or not
        (result == -1) ? printf("Element is not present in array")
                    : printf("Element is present at index %d",
                                result+1);
        
    }
    //catching the unknown error
    catch(...)
    {
        cout<<"Error occurred";
    }
    
    return 0;
}