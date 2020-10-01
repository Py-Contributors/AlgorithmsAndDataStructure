#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>& arr, int l,int m,int r){
    int n1=m-l+1,n2=r-m;
    int left[n1],right[n2];
    for(int i=0;i<n1;i++){
        left[i]=arr[l+i];
    }
    for(int j=0;j<n2;j++){
        right[j]=arr[m+j+1];
    }

    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(left[i]<=right[j]){
            arr[k]=left[i];
            i++;
            k++;
        }
        else{
            arr[k]=right[j];
            j++;
            k++;
        }
        

    }
    while(i<n1){
        arr[k]=left[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=right[j];
        k++;
        j++;
    }
}
void merge_sort(vector<int>& arr, int l,int r) {
if(l<r){
    int m=l+(r-l)/2;
    merge_sort(arr,l, m);
    merge_sort(arr,m+1, r);
    merge(arr,l,m,r);
}
}

int main() {
    int size;
    cin>>size;
    vector<int>vec;
    for (int i=0;i<size;i++) {
        int p;
        cin>>p;
        vec.push_back(p);

    }
    merge_sort(vec,0, size-1);
    for (int i=0;i<size;i++) {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}
