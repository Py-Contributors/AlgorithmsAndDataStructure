#include<bits/stdc++.h>
using namespace std;
#define MAX 100000

void merge(int *a,int low,int mid,int high){
int temp[MAX];
int i=low;
int j=mid+1;
int k = low;

while(i<=mid&&j<=high){
    if(a[i]<a[j]){
    temp[k++] = a[i];
    i++;
    }
    else{
    temp[k++] = a[j];
    j++;
    }
}
while(i<=mid)
temp[k++] = a[i++];

while(j<=high)
temp[k++]= a[j++];

for(i=low;i<=high;i++)
a[i] = temp[i];

}
void mergeSort(int *a,int low,int high){
if(low<high){
    int mid= (low+high)/2;
    mergeSort(a,low,mid);
    mergeSort(a,mid+1,high);
    merge(a,low,mid,high);
    }
}



void print(int *a,int n){
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }
}

int main(){
int a[MAX];
int n,num;
cout<<"Enter the number of elements in the array: ";
cin>>n;
cout<<"Enter the elements " ;
for(int i=0;i<n;i++){
    cin>>num;
    a[i]=num;
    }
mergeSort(a,0,n-1);
print(a,n);
return 0;
}
