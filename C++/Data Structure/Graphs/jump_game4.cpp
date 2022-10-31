// **OBSERVATIONS** 
// 1. Given that we can **jump to the previous and next neighbour if they are within the limits** from the current position.
// 2. We can also **jump to the same element which is present in the array but at different index** .

// Atlast we have to return the **minimum number of steps to reach the end (n-1 th index )**

// **LOGIC**
// **1**. Here we are using BFS Algorithm. 
// Then the immediate question is why???? 

// **Reason**

// **Whenever there is an unwieghted graph and we want to retrive the shortest path or minimum steps to reach the destination** , we use **BFS**  , **as it takes all the neighbouring guys from the current node and this process repeats for every node** .

// **Thus the total visualisation will be like we are generating hotspots/ rainbows on each node. Therefore the spread to the entire graph takes minimum effort** .

// Thus , by moving forward
// **2**. The question is very easy but few changes to be made on applying BFS.
// **3**. According to Observations, here **for the current element its friends are the previous and next neighbours, and same guys** . 
// So we will create **a hashmap of node and his same guys**

// The other data structures needed are :- ***queue :- Pushing the indexes  ; 
// Visited array (bool type ) :- To mark which nodes are visited***
// And a **step variable** :- Counts the steps to till we have reach the end.
// **4**. Starting the BFS,  push 0 as its the first index and mark it as visted. Begin the loop until the queue becomes empty :
// 		* Take the **front element** . **If its the n-1 th index , directly return the step** ;
// 		* **Else take its previous and next guys and put in its friends list** ;
// 		* Start **traversing the neighbours list which contains same guys, prev guy and next guy**.
//     	* If they are **within the range and still not visited** :- Mark them as visited and push them
    	
// **One important point of this whole question is, after visiting the neighbours list, plz clear the list** The reason is : 

// **Removing the visited ones to reduce the repetitive work;
// As the children are already visted and no use for the coming iterations for 
// any further guy in coming iterations bcz we have already used that path and didnt got the answer ,so not allowing to use this path**

// " **To tell in simple manner, everytime we are reducing the size of the friendslist, so that the search space is reducing.** "

// *Code* 
// ```
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return 0;   //  edge case : )
        unordered_map<int,list<int>>mp;    // ele -> all its same guys 
        for(int i=0;i<n;i++) mp[arr[i]].push_back(i);
        queue<int>q;
        vector<bool>vis(n,false);
        q.push(0); vis[0]=true;
        int step=0;
        while(!q.empty()){
            
            int sz=q.size();
            while(sz--){
                int fr=q.front(); q.pop();
                if(fr==n-1) return step; // if u reached the last ind then return count step;
                // else now vist all its neighs who are i+1,i-1 and same guys 
                list<int>& neigh=mp[arr[fr]];
                neigh.push_back(fr-1); 
                neigh.push_back(fr+1);
                // since the left and right guys of ith ele are not there in its list
				
                // so now iterate through neigh who are within the range and not vis
                for(auto x: neigh){
                    if(x>=0 and x<n and !vis[x]){q.push(x); vis[x]=true;}
                }
                neigh.clear();  // removing the visited ones to reduce the reptiive work;
                // as the children are already visted and no use for the coming iterations for 
                // any further guy in coming iterations; bcz we have already used that path and didnt got the ans ,so not allowing to use this path;
            }
            step++; // counting the steps
        }
        return 0;
    }
};
