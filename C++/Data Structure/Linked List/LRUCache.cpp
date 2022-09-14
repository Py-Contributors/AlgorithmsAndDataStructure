#include <bits/stdc++.h>
using namespace std;

class LRUCache{
public:
    map<int, int> mymap;
    list<int> ls;
    int cp;

    LRUCache(int capacity){
    cp=capacity;
    mymap.clear();
    ls.clear();
    }

    int get(int key){
    if(mymap.find(key)==mymap.end()) return 0;

    ls.remove(key);
    ls.push_front(key);
    return mymap[key];
    }

    void put(int key, int value){
    if(mymap.find(key)==mymap.end()){
        if(ls.size()==cp){
            int last = ls.back();
            ls.pop_back();
            mymap.erase(last);
        }

        mymap[key]=value;
        ls.push_front(key);
    }else{
    ls.remove(key);
    ls.push_front(key);
    mymap[key]=value;
    }
    }
};

int main(){

    LRUCache cache(3);
    cout<<"The processed Cache is:"<<endl;
    cache.put(1,3);
    cache.put(4,2);
    cout<<cache.get(1)<<" ";  // returns 3

    cache.put(5,6);
    cout<<cache.get(7)<<" "; //returns 0
    cout<<cache.get(5)<<" "; //returns 6

    cache.put(7,4); //evicts key 4

    cout<<cache.get(4)<<" ";  //returns 0
    cout<<cache.get(1)<<" "; //returns 3
    cout<<cache.get(5)<<" "; //returns 6

return 0;

}
