#include<bits/stdc++.h>
using namespace std;
int n;

int queen[20]; // to store the ith queen pos (ith queen pos => col num in which its saved)

bool check(int row,int col){
    // here we have to check from 0 to row whether any queen(queen[row]) can attk the cur level
    for(int i=0;i<row;i++){
        int pre_row=i;
        int pre_col=queen[i];

        // rows cant collide so chill
        // checking for cols: if any pre_col and present col are same, then collision so not crt

        // other is checking diagonally : syntax is abs(row-pre_row)==abs(col-pre_col) 
        // checking whether distance btw 2 rows are same and 2 cols are same :if same then 
        // there is a common diagonal btw them i.e 45 degrees
        // why abs means slope can be pos or negative
        if(pre_col==col or abs(row-pre_row)==abs(col-pre_col)) return false;
    }
    return true;
}
int rec(int level){
    // here rec means that the the number of ways a queen can be positioned 
    //from this level(row) to last level(nth)

    // base case 
    if(level==n) {
        for(auto x:queen) cout<<x+1<<" ";
        cout<<endl;
        return 1;} 
    // means u have crossed from 0 to n-1 rows and came out of board , so u made an arrangement 
    // return 1 for the this arrangement count

// exploring and computation
    int ans=0;
    //going for all the choices 
    for(int col=0;col<n;col++){
        // validation of the choices

        // calling a check function as to decide a queen in the cur level,we need the information of the 
        // previous arrangement queens to check if the cur queen can be attacked by them or not;
        if(check(level,col)){
            // if valid : store in queen arrays
            queen[level]=col;
            // moving to next 
            ans+=rec(level+1);

            // while backtracking, changes made above should be reverted
            queen[level]=-1;
        }
    }
// return the ans;
    return ans; // no of ways to position remaining queens from cur level/ row
}
int main(){
    cin>>n; // how many N X N chess board
    memset(queen,-1,sizeof(queen));
    cout<<rec(0);
}