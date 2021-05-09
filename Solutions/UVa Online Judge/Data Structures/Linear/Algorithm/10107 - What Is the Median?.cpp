#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#endif

using namespace std;
using ll = long long;

#define nl '\n'
#define all(X) X.begin(), X.end()

int main() {
    ios_base::sync_with_stdio(false);

    ll x;
    vector<ll> vec;
    while(cin >> x) {
        vec.push_back(x);
        sort(all(vec));
        if(vec.size() % 2 != 0) 
            cout << vec[(int) floor((vec.size() - 1) / 2)] << nl;
        else{
            int mid = (int) floor((vec.size() - 1) / 2);
            cout << (ll) floor((vec[mid] + vec[mid + 1]) / 2) << nl;
        }
    }

    return 0;
}
