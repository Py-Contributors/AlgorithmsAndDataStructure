// Search fibonacci number


#include <iostream>
using namespace std;

int FiboSearch(int n){

  if ((n==0)||(n==1)){
      return 1;
    }
  else{
    return FiboSearch(n-1)+FiboSearch(n-2);
  }
}

int main(void){
  cout << FiboSearch(8) << endl; //example
  return 0;
}
	
      
