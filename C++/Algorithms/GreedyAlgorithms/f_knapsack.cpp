#include <bits/stdc++.h>
#include <iomanip>

typedef long long ll;
using namespace std;

class Items
{
    public:
    ll value;
    ll weight;
    double ratio;
};

bool cmp(Items i1, Items i2)
{
    return (i1.ratio>i2.ratio);
}

int main()
{
    ll n,capacity,tempweight(0),tempval(0);
    double val(0);
    cin >> n >> capacity;
    Items item[n];
    for(ll i=0;i<n;i++)
    {
        cin>>item[i].value>>item[i].weight;
        item[i].ratio = (double)item[i].value/item[i].weight;
        tempweight += item[i].weight;
        tempval += item[i].value;
    }
    if(tempweight < capacity)
    {
        cout<<tempval<<endl;
        exit(0);
    }
    sort(item, item+n, cmp);
    for(ll i=0;i<n;i++)
    {
        if(capacity == 0)
            break;
        else if(item[i].weight < capacity)
        {
            val += item[i].value;
            capacity -= item[i].weight;
        }
        else
        {
            val = val + item[i].ratio*capacity;
            capacity =0;
        }
    }
    cout<<fixed<<setprecision(4)<<val<<endl;
    return 0;
}
