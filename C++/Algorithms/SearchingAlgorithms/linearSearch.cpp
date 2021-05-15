#include <iostream>
#define ll long long
using namespace std;
ll linearSearch(ll arr[], ll n, ll x)
{
    for (ll i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    ll arr[] = {0, 1, 2, 3, 4, 5};
    ll x = 4;
    cout << linearSearch(arr, 6, 4) << endl;
    return 0;
}