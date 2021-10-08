#include<bits/stdc++.h>
#include<iostream>
using namespace std;
const int alpha=26;
struct node{
    node* child[alpha];
   bool end;
   int countchild;
};
node* getnode(){
    node* pnode=new node;
    pnode->end=false;
    pnode->countchild=0;
    for(int i=0;i<alpha;i++){
        pnode->child[i]=NULL;
    }
    return pnode;
}
void insert(node* root,string key){
    node* pcrawl=root;
    int size=key.length();
    for(int i=0;i<size;i++){
        int index=key[i]-'a';
        if(!pcrawl->child[index]){
            pcrawl->child[index]=getnode();
        }
        pcrawl->countchild+=1;
        pcrawl=pcrawl->child[index];
        
    }
    pcrawl->end=true;
}

bool search(node* root,string key){
    node* pcrawl=root;
     int size=key.length();
    for(int i=0;i<size;i++){
        int index=key[i]-'a';
        if(!pcrawl->child[index]){
            return false;
        }
        pcrawl=pcrawl->child[index];
    }
    return (pcrawl!=NULL and pcrawl->end);
}
int searchchild(node* root,string key){
    node* pcrawl=root;
     int size=key.length();
    for(int i=0;i<size;i++){
        int index=key[i]-'a';
        if(!pcrawl->child[index]){
            return 0;
        }
        pcrawl=pcrawl->child[index];
    }
    if (pcrawl==NULL){
      return 0;
    }
    else{
        return pcrawl->countchild;
    }
}
int main(){
    int n;
    string s,s1,s2;
    node* root=getnode();
    cin>>n;
   cin.sync();
    for(int i=0;i<n;i++){
        getline(cin,s);
       
        bool find=false;
        s1="";
        s2="";
        for(unsigned int i=0;i<s.length();i++){
           if(s[i]==' '){
               find=true;
               continue;
           }
           if(!find){
               s1+=s[i];
           }
           else{
               s2+=s[i];
           }
        }
      
        if(s1.compare("add")==0){
          insert(root,s2);
          
        }
        else{
           
            cout<<searchchild(root,s2)<<endl;
        }

    }
}