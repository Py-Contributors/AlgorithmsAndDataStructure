#include<bits/stdc++.h>
#define F first
#define S second
#define MAX  1000000
using namespace std;
vector<int> xpos;
vector<pair<int,int> > pos;
vector<int> ans[MAX];
bool Nqueens(int n,int x,int y,int &cnt){
    for(auto &p:pos){
        if(p.F==x)  return false;
        if(abs(x-p.F)==abs(y-p.S))  return false;
    }
    pos.push_back({x,y});
    xpos.push_back(x+1);
    if(y==n-1){
        ans[cnt++]=xpos;
        xpos.pop_back();
        pos.pop_back();
        return true;
    }
    bool fg=false;
    for(int i=0;i<n;i++){
           if(Nqueens(n,i,y+1,cnt)) fg=true;
    }
    xpos.pop_back();
    pos.pop_back();
    return fg;
    
}
int main()
 {
	int t; cin>>t;
	while(t--){
	    int n; cin>>n;
	    if(n==2||n==3)  {cout<<-1<<endl; continue;}
	   xpos.clear();
	   for(int i=0;i<MAX;i++)  ans[i].clear();
	   pos.clear();
	   int cc=0;
	   for(int i=0;i<n;i++)
	    Nqueens(n,i,0,cc);
	    int bb=0;
	    for(auto &p:ans){
	        bb++;
	        if(bb>cc)  break;
	        cout<<"[";
	        for(auto &q:p) cout<<q<<" ";
	        cout<<"] "; 
	    }
	    cout<<endl;
	}
	return 0;
}
