// disjoint sets using path compression and union

#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node* parent;
	int rank;
};

class disjointSet{
public:
	map<int,node*> mapp;
	void makeSet(int data){
		node *n  = new node;
		n->data = data;
		n->rank = 0;
		n->parent = n;
		mapp[data] = n;

	}

	void Union(int data1, int data2){
		node *n1 = mapp[data1];
		node *n2 = mapp[data2];

		node *parent1  = find_parent(n1);
		node *parent2  = find_parent(n2);

		// if the are part of same set do nothing
		if(parent1->data == parent2->data){
			return;
		}

		//else whoever's rank is higher becomes parent of othe
		if(parent1->rank >= parent2->rank){
			if(parent1->rank == parent2->rank){
				 //increment rank only if both sets have same rank
				parent1->rank = parent1->rank + 1;
			}
			parent2->parent = parent1;

		}
		else{
			parent1->parent = parent2;
		}

	}

     
     
	// Finds the representative of this set
	node* find_parent(node *tmp){
		node *parent = tmp->parent;
		if(parent == tmp){
			return parent;
		}

		tmp->parent = find_parent(tmp->parent);  // path compression
		return tmp->parent;
	}

	// find set of this given element
	int findSet(int data){
		return find_parent(mapp[data])->data;
	}
};


int main(){

		disjointSet ds;
        ds.makeSet(1);
        ds.makeSet(2);
        ds.makeSet(3);
        ds.makeSet(4);
        ds.makeSet(5);
        ds.makeSet(6);
        ds.makeSet(7);

        ds.Union(1, 2);
        ds.Union(2, 3);
        ds.Union(4, 5);
        ds.Union(6, 7);
        ds.Union(5, 6);
        ds.Union(3, 7);

        cout<<(ds.findSet(1))<<endl;
        cout<<(ds.findSet(2))<<endl;
        cout<<(ds.findSet(3))<<endl;
        
}
