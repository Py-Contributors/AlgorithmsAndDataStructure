#include <iostream>
#include <vector>

using std::vector;

int binary_search(const vector<int> &a, int x) {
  int left = 0, right = (int)a.size(); 
  int mid = (left +right)/2 ;
  while (left<right)
  { 
    if (a[mid] == x)
    {
      return mid;
    }
    if (a[mid] < x)
    {
      left = mid +1;
    }
    if (a[mid] > x)
    {
      right = mid -1;
    }
    
    mid = (left + right)/2;
    
    
  }
  return -1;
  
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cout<<"Please enter the number of elements in the array\n";
  std::cin >> n;
  std::cout<<"Enter the sorted elements: ";
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout<<"Enter the element to find";
  int m;
  std::cin >> m;
  std::cout << binary_search(a,m) << ' ';
  
}
