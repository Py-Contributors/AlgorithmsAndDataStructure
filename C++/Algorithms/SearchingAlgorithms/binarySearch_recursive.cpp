#include <stdio.h>

// Recursive Version of Binary Search
int binsrch(int *a,int x,int low,int high){
	int mid;
	if(low>high) return -1;
	mid=(low+high)/2;
	return x==a[mid]?mid:x<a[mid]?
						binsrch(a,x,low,mid-1):
						binsrch(a,x,mid+1,high);
}

int main(){
	
	// Initialize an array of numbers
	int a[10]={1,4,15,122,240,260,350};
	
	// Call the function
	int i=binsrch(a,122,0,6);
	
	// Print the index
	printf("%d",i);
	
}
