#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef pair<int, ii> iii;

#define numV 6

int find(int n, int root[]){
    if(n == root[n]) return n;
    return find(root[n], root);
}

void uniao(int n, int m, int root[], int size[]){
    n = find(n, root);
    m = find(m, root);

    if(n != m){
        if(size[n] < size[m]){
            root[n] = root[m];
            size[n] = size[m];
        }
        else if(size[n] == size[m]){
            if(n < m) root[m] = root[n];
            else root[n] = root[m];
            size[n]++;
            size[m] = size[n];
        }
        else{
            root[m] = root[n];
            size[m] = size[n];
        }
            
    }
}


int main(){
    int root[numV];
    int size[numV];
    int weight, Vec1, Vec2;

    for(int j = 0; j < numV; j++){
        size[j] = 0;
        root[j] = j;
    }

    priority_queue<iii, vector<iii>, greater<iii>> pq;


    //Create Graph
    for(int i = 0; i < 10; i++){
        cin >> weight >> Vec1 >> Vec2;
        pq.push(make_pair(weight, make_pair(Vec1, Vec2)));
    }


    int numMST = numV;
    while (numMST > 1){
        int v, u, w;
        w = pq.top().first;
        u = pq.top().second.first;
        v = pq.top().second.second;
        pq.pop();

        if(find(u, root) != find(v, root)){   
            uniao(u, v, root, size);
            numMST--;
        }

        cout << "After Processing(" << u <<"," << v << "):" << endl;
        for(int i = 0; i < numV; i++){
            if(root[i] == i) cout << "-" << " ";
            else cout << root[i] << " "; 
        }
        cout << endl;

    }


        
    
    
}
