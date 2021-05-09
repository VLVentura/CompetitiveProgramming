#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define all(X) X.begin(), X.end()

int main() {
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    while(t--) {
        map<int, int> m;
        int n, p, i = 0, r = 0;
        cin >> n;

        while(i++ < n) {
            cin >> p;
            if(m.find(p) == m.end()) m[p] = i;
            else r = p;
        }
        
        m.erase(r);
        cout << (*m.begin()).second << "\n";
    }

    return 0;
}
