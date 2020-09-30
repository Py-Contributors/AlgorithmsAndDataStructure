#pragma GCC "Ofast"
#include<bits/stdc++.h>
using namespace std;

bool LinearSearch(vector<int> v1, int target) {
 
 // enhanced for loop
  for(int x : v1)
    if(x == target)
      return true;
      
  return false;
}

int main() {
  int n;
  cin>>n;
  
  vector<int> v1;
  // Enter n space seperated integers
  while(n--){
  int x;
  cin>>x;
  v1.push_back(x);
  }
  
  // Enter element to be found
  int element;
  cin>>element;
  
  string result = LinearSearch(v1, element) ? "Found" : "Not Found" ;
  cout<< result << '\n';
  
  return 0;
}
