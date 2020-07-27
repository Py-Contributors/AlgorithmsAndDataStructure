#include <iostream>
using namespace std;

int foo [5] = {10, 8, 6, 4, 2};

void sum() {
    // it print sum of all elements
    int i, result = 0;
    
    for(i=0;i<5;i++) {
        result += foo[i];
    }
    cout << "Total sum of array : " << result << endl;
}

void updation() {
    // updation of array
    foo[1] = 20;
    cout << "Array element after updation : ";
    cout << foo[0]<< " ";
    cout << foo[1]<< " ";
    cout << foo[2]<< " ";
    cout << foo[3]<< " ";
    cout << foo[4]<< " ";

}
int main() {
    sum();
    updation();
    return 0;
};