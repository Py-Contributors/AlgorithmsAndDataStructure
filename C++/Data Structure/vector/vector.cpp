#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*Vectors are same as dynamic arrays with the ability to resize itself 
automatically when an element is inserted or deleted*/
void iterate_over_vector(auto start,auto end)
{
	for(auto i=start;i!=end;i++)
	{
		cout<<*i<<" ";
	}
	cout<<endl;
}
void insert_element(vector <int> &test,auto pos,int value)
{
	// O(n+m)
	test.insert(pos,value);  
}
void erase_element(vector <int> &test,auto pos)
{
	//  O(n)
	test.erase(pos);  
}
bool is_vector_empty(vector <int> &test)
{
	return test.empty();
}

int main()
{
	vector <int> test;
	test.push_back(5);              // 	add 5 at the end    O(1)
	test.push_back(4);              // 	added 4 after 5      O(1)
	test.push_back(8);              //	Vector elements are placed in contiguous storage.
	test.push_back(1);				//	O(1)							
	/*   Iterate over vector
		begin() – Returns an iterator pointing to the first element in the vector
		end() – Returns an iterator pointing to the theoretical element that follows the last element in the vector  */
		
	cout<<"Initial vector: ";
	iterate_over_vector(test.begin(),test.end());        
	cout<<"Size of vector: "<<test.size()<<endl;
	
	insert_element(test,test.begin()+2,5);              //insert element at given iterator	
	cout<<"vector after insertion: ";                  	
	iterate_over_vector(test.begin(),test.end());
	cout<<"Size of vector: "<<test.size()<<endl;
	test.pop_back();                                    //delete last element
	erase_element(test,test.begin()+1);                 //erase element at given iterator
	
	cout<<"vector after erasing some elements: ";
	iterate_over_vector(test.begin(),test.end());
	cout<<"Size of vector: "<<test.size()<<endl;
	cout<<"Is vector empty: "<<is_vector_empty(test)<<endl;
	
 	test.clear();                       // remove all the elements of the vector container
 	
 	cout<<"Is vector empty: "<<is_vector_empty(test)<<endl;
	
	return 0;
}

/*
output:

Initial vector: 5 4 8 1
Size of vector: 4 
vector after insertion: 5 4 5 8 1
Size of vector: 5
vector after erasing some elements: 5 5 8
Size of vector: 3
Is vector empty: 0
Is vector empty: 1 
*/
