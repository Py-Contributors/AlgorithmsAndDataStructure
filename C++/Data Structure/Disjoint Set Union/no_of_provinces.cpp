#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // finding nod1->par equaility with nod2->par;
    // to check whether their same component or not;
    // if they are same locality then we count both as 1,
    // else both are unique 
    void dsu(int x,int y,vector<int>&par){
        int p1=find(x,par),p2=find(y,par);
        if(p1==p2) return;
        else par[p1]=p2;
    }
    // checking their nodes vs parents
    int find(int v,vector<int>&par){
        if(par[v]==-1) return v;
        return par[v]=find(par[v],par);
    }
    int findCircleNum(vector<vector<int>>& mat) {
        int n=mat.size();
        vector<int>par(n,-1);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    dsu(i,j,par);
                }
            }
        }
        // find(); // parent finding
        // together();
        int c=0;
        for(int i=0;i<n;i++){
            if(par[i]==-1) c++;
        }
        return c;
            
    }
};