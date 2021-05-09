#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif

using namespace std;

using ll = long long;

#define all(X) X.begin(), X.end()

int main() {
    ios_base::sync_with_stdio(false);

    int t;

    cin >> t;

    while(t--) {
        priority_queue<ll> pq;
        int n;
        while(cin >> n, n) {
            pq.push(n);
        }
        
        ll sum = 0, i = 1;
        while(!pq.empty()) {
            sum += 2 * pow(pq.top(), i++);
            pq.pop();
        }
        if(sum > 0 && sum <= 5e6) cout << sum << '\n';
        else cout << "Too expensive" << '\n';
    }

    return 0;
}
