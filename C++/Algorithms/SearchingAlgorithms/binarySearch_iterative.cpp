#include <stdio.h>


// Iterative version of Binary Search
int binsrch(int *a,int x,int low,int high){
	int mid;
	while(low<=high){
		mid=(low+high)/2;
		if(x<a[mid]) 
			high=mid-1;
		else if(x>a[mid])
			low=mid+1;
		else
			return mid;
	}
	return -1;	
}

int main(){
	
	// Initialize an array of numbers
	int a[10]={1,4,15,122,240,260,350};
	
	// Call the function
	int i=binsrch(a,122,0,6);
	
	// Print the index
	printf("%d",i);
	
	return 0;
}
