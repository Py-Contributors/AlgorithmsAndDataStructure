#include<iostream>
using namespace std;
class Search
{
    int i,flag;

    public:
         int search(int);

};
int Search::search(int number)
{
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    flag=0;
    
    for(i=0;i<10;i++)
    {
        
        if(arr[i]==number)
        {
            cout<<"\nNumber found";
            flag=1;
            return 0;
        }
    }
    if(flag==0)
    {
        cout<<"\nNumber not found";
    }
}
int main()
{
    int number;
    Search obj;
    cout<<"Enter the number you wanna search";
    cin>>number;
    obj.search(number);



}
